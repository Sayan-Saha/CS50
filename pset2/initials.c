#include<cs50.h>
#include<stdio.h>
#include<string.h>

void printInitials(string name);//function to initials..
int main(void)
{
 //taking input..
 printf("Enter Your Name: ");
 string s = GetString();
 printInitials(s);
}
void printInitials(string s)
{
 //printinh the 1st letter in uppercase..
 if(s[0]>=97 && s[0]<=122) 
  {
  printf("%c",s[0]-32);
  }
 else
  {
   printf("%c",s[0]);
  }
 for(int i=0,n=strlen(s);i<n;i++)
 {
  //printing the letters next to a blank space..
  if( s[i] == ' ' )
  {
   if(s[i+1]>=97 && s[i+1]<=122) 
    {
      printf("%c",s[i+1]-32);
    }
   else
   {
    printf("%c",s[i+1]);
   }
  }
 }
  printf("\n");
}
