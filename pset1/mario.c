#include<cs50.h>
#include<stdio.h>

int GetPositiveInt();
void HalfPyramid(int height);
int main(void)
    {
         int n = GetPositiveInt();
         printf("Height:%i\n",n);
         HalfPyramid(n);
    }
int GetPositiveInt(void)
    {
         int n;
         do
             {
                  printf("Please Give A Positive Height Less Than 23:");
                  n = GetInt(); 
             }
         while( n<1 || n>23 );
         return n;
     }
void HalfPyramid(int h)
    {
         for(int r=0;r<h;r++)
          {
               for(int s=h-r;s>0;s--)
                 {
                     printf(" ");
                 }
               for(int j=0;j<=r;j++)
                 {
                     printf("#");
                 }
                 printf("\n");
          }
    }
 
