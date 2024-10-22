#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#include "wav.h"

int check_format(WAVHEADER header);
int get_block_size(WAVHEADER header);

int main(int argc, char *argv[])
{
    // Ensure proper usage
    // TODO #1
    if (argc != 3)
    {
        printf("Usage: ./reverse inputFile outputFile\n");
        return 1;
    }

    // Remember filenames
    char *infile = argv[1];
    char *outfile = argv[2];

    // Open input file for reading
    // TODO #2
    FILE *inptr = fopen(infile, "rb");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 1;
    }

    // Read header
    // TODO #3
    WAVHEADER header;
    fread(&header, sizeof(WAVHEADER), 1, inptr);

    // Use check_format to ensure WAV format
    // TODO #4
    if (check_format(header) == 1)
    {
        printf("File type not supported\n");
        return 1;
    }

    // Open output file for writing
    // TODO #5
    FILE *outptr = fopen(outfile, "wb");
    if (outptr == NULL)
    {
        fclose(inptr);
        printf("Could not create %s.\n", outfile);
        return 1;
    }

    // Write header to file
    // TODO #6
    fwrite(&header, sizeof(WAVHEADER), 1, outptr);

    // Use get_block_size to calculate size of block
    // TODO #7
    int blockSize = get_block_size(header);

    // Write reversed audio to file
    // TODO #8
    if(fseek(inptr, blockSize, SEEK_END))
    {
        return 1;
    }

    BYTE *buffer = malloc(blockSize);

    while (ftell(inptr) - blockSize > sizeof(WAVHEADER))
    {
        if(fseek(inptr, -2 * blockSize, SEEK_CUR))
        {
            return 1;
        }
        fread(buffer, blockSize, 1, inptr);
        fwrite(buffer, blockSize, 1, outptr);
    }
    free(buffer);
    fclose(inptr);
    fclose(outptr);
}

int check_format(WAVHEADER header)
{
    // TODO #4
    if (header.format[0] == 'W' && header.format[1] == 'A' && header.format[2] == 'V' && header.format[3] == 'E')
    {
        return 0;
    }
    else return 1;

}

int get_block_size(WAVHEADER header)
{
    // TODO #7
    int blockSize = header.numChannels * (header.bitsPerSample / 8);
    return blockSize;
}