/*
 ============================================================================
 Name        : Clase_05.c
 Author      : Navarro Mara Fernanda
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>

#define QTY_EDADES 5
int initArrayInt(int *pArray , int limite, int valor);
int printArrayInt(int *pArray , int limite);
int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);
int maximoMinimoArrayInt(int *pArray,int limite, int* pMax, int* pMin);

int main(void)
{
	int edades[QTY_EDADES];
	int cantidadUsuario;
	int max;
	int min;
	initArrayInt(edades,QTY_EDADES,5);
	cantidadUsuario = getArrayInt(edades,QTY_EDADES,"Edad?\n","Error\n",0,200,2);
	printArrayInt(edades,cantidadUsuario);
	maximoMinimoArrayInt(edades,QTY_EDADES,&max,&min);
	printf("El maximo es:%d y el minimo:%d",max,min);
	return EXIT_SUCCESS;
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
			printf("\n\t%i",pArray[i]);
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

int maximoMinimoArrayInt(int *pArray,int limite,int* pMax,int* pMin)
{
	int retorno = -1;
	int i;
	int max=*pMax;
	int min=*pMin;
	int aux;
	printf("\nDEBUG\n");

	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			if(pArray[i] < max)
			{
			aux= pArray[i];
			*pMax = aux;
			}
		}
		for(i=0;i<limite;i++)
		{
			if(pArray[i] > min )
			{
				aux= pArray[i];
				*pMin = aux;
			}
		}
		retorno = 0;
	}
	return retorno;
}

