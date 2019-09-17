/*
 * get_Input.c
 *
 *  Created on: 12 sep. 2019
 *      Author: femavana
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h
#include <string.h>
#include "get_Input.h"
#include "arrays.h"
#define  CANT 4

//1
int getInt(	int *pResultado,
			char* mensaje,
			char* mensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int ret=-1;
	int buffer;
	do
	{
		printf("%s",mensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado=buffer;
			ret=0;
			break;
		}
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return ret;
}

//2
int getFloat(float *pResultado,
			 char* mensaje,
			 char* msjError,
			 int minimo,
			 int maximo,
			 int reintentos)
{
    int ret = -1;
	float buffer;
	do
	{
		printf("%s",mensaje);
		__fpurge(stdin);
		if(scanf("%f",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			ret = 0;
			break;
		}
		else
		{
		printf("\t%s",msjError);
		reintentos--;
		}
	}while(reintentos >= 0);
	return ret;
}

//3
int getChar( char *pResultado,
			 char* mensaje,
			 char* msjError,
			 int minimo,
			 int maximo,
			 int reintentos)
{
    int ret = -1;
	char buffer;
	do
	{
		printf("%s",mensaje);
		__fpurge(stdin);
		scanf("%c",&buffer);
		if(buffer >= minimo && buffer <= maximo)
		{
			*pResultado=buffer;
			ret = 0;
			break;
		}
		else
		{
		printf("\t%s",msjError);
		reintentos--;
		}
	}while(reintentos >= 0);
	return ret;
}
//4
int getString( char message[],
	       char input[])
{
	printf("message");
	scanf("%s", input);
}
	
//5
int getStringNumbers( char message[],
		      int  input[])
{
	int ret=0;
	char aux[256];
	getString(message,aux);
	if(onlyNumbers(aux)==0)
	{
	  strcpy(input,aux);
	  ret=1;
	}
return ret;
}

//6
int getStringLetters(char message[],
		     char input[])
{
int ret=0;
char aux[256];
	getString(message,aux);
	if(onlyLetters(aux)==0)
	{
	  strcpy(input,aux);
		ret=1;
	}
return ret;
}
//validations

OnlyLetters(char aux[],
            int limite)
{
int ret=0;
char aux[256];
	getString(message,aux);
	for(i=0;i<limite;i++)
	{
         
		ret=1;
	}
return ret;
}

OnlyNumbers(int aux)
{

}
void menu()
{
	printf("<>>>>>>PHONEBOOK<<<<<<>");
	printf("\n1-New user");
	printf("\n2-Delete user");
	printf("\n3-Change user");
	printf("\n4-List users:");
	printf("\n5-Order users by LastName:");
	printf("\n6-Exit:");
}
int searchFirstOccurrence(int array[], int limite,int valor)
{
 int i;
 int ret=-1;
 
 for(i=0;i<limite;i++)
 		{
 			if(array[i]== valor)
 			{
 				ret=i;
 			}
 		}
return ret;
}

