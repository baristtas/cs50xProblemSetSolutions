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

    int resizeValue = atoi(argv[1]);
    char *infile = argv[2];
    char *outfile = argv[3];

    if (!(resizeValue <= 100)) return 1 && fprintf(stderr,"Buyutme katsayisi 0 ile 101 arasında bir pozitif tamsayi olmali.\n");
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
        fprintf(stderr, "Desteklenmeyen dosya bicimi.\n");
        return 4;
    }
    int oldPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int oldBiWidth = bi.biWidth; //doesnt include padding
    int oldBiHeight = bi.biHeight;
    int oldBiSizeImage = bi.biSizeImage; //includes pixels and paddings.

    bi.biWidth *= resizeValue;
    bi.biHeight *= resizeValue;

    int newPadding = (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;

    bi.biSizeImage = ((sizeof(RGBTRIPLE) * bi.biWidth) + newPadding) * abs(bi.biHeight);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    RGBTRIPLE line[resizeValue * sizeof(RGBTRIPLE)];
    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(oldBiHeight); i < biHeight; i++)
    {
        // iterate over pixels in scanline
        for (int j = 0; j < oldBiWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            for (int f = 0; f < resizeValue; f++)
            {
                line[(j * resizeValue) + f] = triple;
            }

        }

        for (int f = 0; f < resizeValue; f++)
        {
            fwrite(line, sizeof(RGBTRIPLE), bi.biWidth, outptr);
        }

        for (int t = 0; t < newPadding; t++)
        {
            fputc(0x00, outptr);
        }

        // skip over padding, if any
        fseek(inptr, oldPadding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}

