/*
 * get_Input.c
 *
 *  Created on: 12 sep. 2019
 *      Author: femavana
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
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
