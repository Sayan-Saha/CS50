/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 **/

#include <stdio.h>
#include <stdlib.h>
#include<stdint.h>
#include<cs50.h>
#include<string.h>

int main(void)
{
    // open input file 
    FILE* inptr = fopen("card.raw", "r");
    if (inptr == NULL)
    {
        printf("Could not open the file..\n");
        return 1;
    }
    
    int imageCount = 0;
    int fileTrack = 0;
    uint8_t jpg1[4] = {0xff,0xd8,0xff,0xe0};
    uint8_t jpg2[4] = {0xff,0xd8,0xff,0xe1};
    uint8_t buffer[512];
    uint8_t check[4];
    FILE* outptr;
    fread(buffer,512,1,inptr);
        
    while(fread(buffer,512,1,inptr)>0)
    {
        for(int i=0; i<4; i++)
        {
            check[i] = buffer[i];
        }
        if((memcmp(check,jpg1,sizeof(check))==0) || (memcmp(check,jpg2,sizeof(check))==0))
         {
                printf("hi\n");
                char title[8];
                sprintf(title,"%03d.jpg",imageCount);
                
                if( fileTrack == 0 )
                {
                 outptr = fopen(title,"w");
                 fwrite(buffer,sizeof(buffer),1,outptr);
                 fileTrack = 1;   
                }
                
                else if( fileTrack == 1 )
                {
                 fclose(outptr);
                 outptr = fopen(title,"w");
                 fwrite(buffer,sizeof(buffer),1,outptr);
                 imageCount++;   
                }
        }
        else 
        {
            if(fileTrack==1)
            
            {
                fwrite(buffer,sizeof(buffer),1,outptr);
            }
        }
      }
      
      if(outptr)
      {
       fclose(outptr);
      }
      fclose(inptr);
      return 0;
}
