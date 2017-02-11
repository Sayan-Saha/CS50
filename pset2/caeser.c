#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

int main( int argc , string argv[] )
{
 //Checking comand line arguments..
 if( argc<3 )
 {
  printf("Try Again!\n");
  return 1;
 }
 //converting the string to a number..& checking the key..
 int k = atoi(argv[1]);
 if( k==0 )
 {
  printf("Enter A Valid Key!\n");
  return 1;
 }
 for(int j=2;j<argc;j++)
 {
  string s=argv[j];
 for(int i=0,n=strlen(s);i<n;i++)
 {
  //encrypting the message using the key..
  if(islower(s[i]))
  {
   int letter = s[i]-97;
   letter = (letter+k)%26;
   printf("%c",letter+97);
  }
  else if(isupper(s[i]))
  {
   int letter = s[i]-65;
   letter = (letter+k)%26;
   printf("%c",letter+65);
  }
  else
  {
   printf("%c",s[i]);
  }
 }
  printf(" ");
 }
 printf("\n");
}
