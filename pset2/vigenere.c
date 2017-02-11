#include<cs50.h>
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char encrypt(int msgChar,string key,int keylen,int j);//function to encrypt message..
int main( int argc , string argv[] )
{
 //checking the input arguments..
 if( argc!=2 )
 {
  printf("Enter A Valid Commandline.\n");
  return 1;
 }
 string key = argv[1];
 int keylen=strlen(key);
 //checking the key..
 for( int i=0; i<keylen; i++ )
 {
  if(isalpha(key[i]))
 {
  printf("Validating Key...");
 }
 else
 {
  printf("Enter A Valid Key!\n");
  return 1;
 }
 }
 //Getting the plain text message..
  printf("\nEnter The Plain Text = ");
  string plainText = GetString();
  int msglen = strlen(plainText);
  int msgChar;
  int j=0;
  //Encrypting the message..
  for( int i=0; i<msglen; i++ )
 {
  msgChar = plainText[i];
  if(isalpha(plainText[i]))
 {
 //Encrypting is done Char By Char..
  encrypt(msgChar,key,keylen,j);
  j++;
 }
 else
 {
 //No encryption is needed if it is not an alphabet..
  printf("%c",plainText[i]);
 }
 }
 printf("\n");
 return 0;
}
char encrypt(int msgChar,string key,int keylen,int j)
{
 //encrypting if message is in lowercase..
 if(islower(msgChar))
 {
  int letter = msgChar-97;
  int k = key[j%keylen];
  //encrypting if key is in lowercase..
  if(islower(key[j%keylen]))
   {
    k=k-97;
   }
   else
   {
   //if key in uppercase..
    k=k-65;
   }
   letter = (letter+k)%26;
   printf("%c",letter+97);
 }
 //encrypting if message is in uppercase..
 else if(isupper(msgChar))
 {
  int letter = msgChar-65;
  int k = key[j%keylen];
  //encrypting if key is in lowercase..
  if(islower(key[j%keylen]))
   {
    k=k-97;
   }
   else
   {
    //if key in uppercase..
    k=k-65;
   }
  letter = (letter+k)%26;
  printf("%c",letter+65);
 }
 return 0;
}
