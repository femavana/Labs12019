/*
 * getInput.c
 *
 *  Created on: 21 sep. 2019
 *      Author: femavana
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>

int getFloat(float *input,
			 char* message,
			 char* msgError,
			 int minSize,
			 int maxSize,
			 int retries)
{
    int ret = -1;
	float buffer;
	do
	{
		printf("%s",message);
		__fpurge(stdin);
		scanf("%f",&buffer);
		if(buffer >= minSize && buffer <= maxSize)
		{
			*input=buffer;
			ret = 0;
			break;
		}
		else
		{
		printf("\t%s",msgError);
		retries--;
		}
	}while(retries >= 0);
	return ret;
}

int getInt(	int *input,
			char* message,
			char* msgError,
			int minSize,
			int maxSize,
			int retries)
{
	int ret=-1;
	int buffer;
	do
	{
		printf("%s",message);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minSize && buffer <= maxSize)
		{
			*input=buffer;
			ret=0;
			break;
		}
		else
		{
		printf("%s",msgError);
		retries--;
		break;
		}
	}while(retries >= 0);
	return ret;
}

int getChar( char *input,
			 char* message,
			 char* msgError,
			 char minimo,
			 char maximo,
			 int retries)
{
    int ret = -1;
	char buffer;
	do
	{
		printf("%s",message);
		__fpurge(stdin);
		scanf("%c",&buffer);
		if(onlyLetter(buffer)==0)
		{
			if(buffer == minimo ||buffer == maximo)
		   {
			*input=buffer;
			ret = 0;
			break;
		   }
		}
		else
		{
		printf("\t%s",msgError);
		retries--;
		break;
		}
	}while(retries >= 0);
return ret;
}

int getStrChar(char* input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries)
{
    int ret=-1;
    char bufferStr[maxSize];

    do{
    if(getString(bufferStr,message,msgError,minSize,maxSize,retries)==0)
            {
                    strcpy(input,bufferStr);
                    ret=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    retries--;
                    break;
                }
        }while(retries>=0);
  return ret;
}

int getString(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int   retries)
{
    int ret=-1;
    char bufferStr[maxSize];
    int size;
     do{
        	printf("%s",message);
        	fgets(bufferStr,sizeof(bufferStr),stdin);
        	size=strlen(bufferStr);
        	if(size>=minSize && size<maxSize)
        	{    strcpy(input,bufferStr);
        	     ret=0;
        	     break;
        	}
     }while(retries>=0);
 return ret;
}

//validations

int onlyLetter(char* aux)
{
int ret=0;
int i=0;
while(aux[i]!= '\0')
{
if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z'))
{
	ret=-1;
	i++;
}
}
return ret;
}

int onlyTextStr(char* aux)
{
int ret=0;
int i=0;
while(aux[i]!= '\0')
{
if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z'))
{
	ret=-1;
	i++;
}
}
return ret;
}

int onlyNumbersStr(char* aux)
{
int ret=0;
int i=0;
for(i=0;i<'\0';i++)
{
if(aux[i]<'0'|| aux[i] > '9')
{
	ret=-1;
}
}
return ret;
}
