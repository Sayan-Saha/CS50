/**
 * resize.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Resizes a BMP piece by piece, just because.
 */
       
#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char* argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        printf("Usage: ./resize n infile outfile\n");
        return 1;
    }
    // remember filenames and scale
    int scale = atoi(argv[1]);
    char* infile = argv[2];
    char* outfile = argv[3];
    if ( scale<=1 || scale>100 )
    {
     printf("Enter a positive number for scaling <100..\n");
     return 2;
    }

    // open input file 
    FILE* inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        printf("Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE* outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    BITMAPFILEHEADER new_bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);
    new_bf=bf;

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    BITMAPINFOHEADER new_bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);
    new_bi=bi;

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 || 
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 4;
    }
    
    
    new_bi.biWidth = scale * bi.biWidth;
    new_bi.biHeight = scale * bi.biHeight;
    
    
    
    // determine padding for scanlines
    int padding =  (4 - (bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    int new_padding = (4 - (new_bi.biWidth * sizeof(RGBTRIPLE)) % 4) % 4;
    
    new_bf.bfSize = 54 +new_bi.biWidth * abs(new_bi.biHeight) * 3 + abs(new_bi.biHeight) * new_padding;
    new_bi.biSizeImage = (((( new_bi.biWidth * new_bi.biBitCount ) + 31 ) & ~ 31) / 8 ) * abs(new_bi.biHeight);
    
    // write outfile's BITMAPFILEHEADER
    fwrite(&new_bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&new_bi, sizeof(BITMAPINFOHEADER), 1, outptr);


    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(bi.biHeight); i < biHeight; i++)
    {
        
        for(int n=0;n<scale;n++)
        {
        // iterate over pixels in scanline
        for (int j = 0; j < bi.biWidth; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);
        
    for(int m=0;m<scale;m++)
           { 
             // write RGB triple to outfile
             fwrite(&triple, sizeof(RGBTRIPLE), 1, outptr);
           }  
        }

        // skip over padding, if any
        fseek(inptr, padding, SEEK_CUR);

        // then add it back (to demonstrate how)
        for (int k = 0; k < new_padding; k++)
        {
            fputc(0x00, outptr);
        }
        fseek(inptr, -(bi.biWidth*sizeof(RGBTRIPLE)+ padding), SEEK_CUR);

       }
       
       fseek(inptr, bi.biWidth * sizeof(RGBTRIPLE) + padding, SEEK_CUR);

    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // that's all folks
    return 0;
}
