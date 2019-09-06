/*
 * funciones.c
 *
 *  Created on: 4 sep. 2019
 *      Author: alumno
 */


/*
 * Inicializa el array
 *
 *
 *
 */
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "funciones.h"
#define QTY_EDADES 5


int initArray(int* pArray, int limite,int valor)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i]=valor;
		}
	}
return retorno;
}

int initArrayInt(int *pArray, int limite,int valor)
{
	int retorno = -1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i]=valor;
		}
		retorno = 0;
	}
	return retorno;
}



int printArrayInt(int *pArray ,int limite)
{
	int retorno = -1;
	int i;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("\n\t%d",pArray[i]);
		}
		retorno = 0;
	}
	return retorno;
}

int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int retorno = -1;
	int buffer;
	int i=0;
	char respuesta;
	printf("\nDEBUG\n");
	if(pArray != NULL && limite > 0)
	{
		do
		{

			if(	getInt(	&buffer,
						pMensaje,
						pMensajeError,
						minimo,
						maximo,
						reintentos) == 0)
			{
				pArray[i] = buffer;
				i++;
				if(i == limite)
				{
					break;
				}
			}

			printf("Continuar (s/n)? \n");
			__fpurge(stdin); // fflush(stdin)
			scanf("%c",&respuesta);
		}while(respuesta != 'n');
		retorno = i;
	}
	return retorno;
}

int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = -1;
	int buffer;
	do
	{
		printf("%s",pMensaje);
		__fpurge(stdin);
		if(scanf("%d",&buffer)==1 && buffer >= minimo && buffer <= maximo)
		{
			*pResultado = buffer;
			retorno = 0;
			break;
		}
		printf("%s",pMensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return retorno;
}

int minimoArrayInt(int *pArray,int limite,int *pMin)
{

	int i;
	int aux;

	if(pArray != NULL && limite > 0 )
	{
				 aux = pArray[0];
	        for(i=1;i<limite;i++)
	        {
				if(pArray[i] > aux)
				{
				  *pMin = aux;
				}
			}
	}
return 0;
}

int maximoArrayInt(int pArray[],int limite,int *pMax)
{
	int i;
	int aux;

	if(pArray != NULL && limite > 0 )
	{
				 aux = pArray[0];
	        for(i=1;i<limite;i++)
	        {
				if(pArray[i] < aux)
				{
				  *pMax = aux;
				}
			}
	}
return 0;
}

int promedioArrayInt(int *pArray,int limite,int *promedio)
{
	int i;
	int acumulador=0;

		if(pArray != NULL && limite > 0 )
		{
		        for(i=0;i<limite;i++)
		        {
					acumulador = acumulador + pArray[i];
				}
		  *promedio= acumulador / limite;
		}
return 0;
}

int sumaArrayInt(int *pArray,int limite,int *suma)
{
	int i;
	int acumulador=0;

			if(pArray != NULL && limite > 0 )
			{
			 for(i=0;i<limite;i++)
			  {
				*suma= acumulador + pArray[i];
			  }
			}
return 0;
}

