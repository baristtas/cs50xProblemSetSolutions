#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t  BYTE;

//*filename,counter malloc'd. free edilecek.

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover 'filename'\n");
        return 1;
    }

    int *counter = malloc(sizeof(int)); //free et!!!!!!!!!!!!!!
    if (counter == NULL)
    {
        printf("error. inptr = NULL.\n");
        return 1;
    }
    *counter = 0;

    char *filename = malloc(sizeof(char) * 8); //free etmeyi unutma!!!!!!!!!
    FILE *inptr = fopen(argv[1], "r");

    if (inptr == NULL)
    {
        printf("error. inptr = NULL.\n");
        return 1;
    }
    
    FILE *outptr = NULL;
    int *g = malloc(sizeof(int));
    *g = 0;

    BYTE array[512];
    
    while(1)
    {
        fread (&array,512,1,inptr);
        
        if (array[0] == 0xff && array[1] == 0xd8 && array[2] == 0xff && (array[3] & 0xf0) == 0xe0)
        {
            sprintf(filename,"%03i.jpg", *counter);
            outptr = fopen(filename,"w");

            if (outptr == NULL)
            {
                printf("error. outptr = NULL.\n");
                return 1;
            }
            *g = 1;
            *counter += 1;
        }

        if(*g == 1 && !(feof(inptr)))
        {
            fwrite(&array,512,1,outptr);
        }

        if (feof(inptr))
        {
            fclose(inptr);
            fclose(outptr);

            free(filename);
            free(counter);
            free (g);

            printf("EOF detected. Program exits with exit code 0.\n");
            return 0;
        }
    }
}
