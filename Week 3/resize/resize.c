// Copies a BMP file

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./copy infile outfile\n");
        return 1;
    }

    const int resizeVal = atoi(argv[1]);


    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];

    if (!(resizeVal <= 100)) return 1 && fprintf(stderr,"Buyutme katsayisi 0 ile 101 arasında bir pozitif tamsayi olmali.\n");
    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "%s acilamadi..\n", infile);
        return 2;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "%s olusturulamadi.\n", outfile);
        return 3;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Desteklenmeyen dosya formati.\n");
        return 4;
    }

    int inputHeight = bi.biHeight;
    int inputWidth = bi.biWidth;
    bi.biHeight = (inputHeight * resizeVal);
    bi.biWidth = (inputWidth * resizeVal);
    int outputHeight = bi.biHeight;
    int outputWidth = bi.biWidth;

    // determine padding for scanlines
    int padding = (4 - (inputWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int outPadding = (4 - (outputWidth * sizeof(RGBTRIPLE) % 4) % 4);

    bi.biSizeImage = (((sizeof(RGBTRIPLE) * outputWidth) + outPadding) * abs(outputHeight));
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);


    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    int rgbArray[abs(inputHeight)][inputWidth];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(inputHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < inputWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&rgbArray[i][j], sizeof(RGBTRIPLE), 1, inptr);
            // printf("i:%i j:%i biwt:%d\n",i,j,bi.biWidth);

            // // write RGB triple to outfile
            // fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // // then add it back (to demonstrate how)
        // for (int k = 0; k < outPadding; k++)
        // {
        //     fputc(0x00, outptr);
        // }
    }

    for (int i = 0, biHeight = abs(outputHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < outputWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            for (int x = 0; x < resizeVal; x++)
            {
                fwrite(&rgbArray[i][j], sizeof(RGBTRIPLE), 1, outptr);
                // printf("i:%i j:%i biwt:%d\n",i,j,bi.biWidth);
            }
            // // write RGB triple to outfile
            // fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);

        }

        // skip over padding, if any
        fseek(outptr, outPadding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < outPadding; k++)
        {
            fputc(0x00, outptr);
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
