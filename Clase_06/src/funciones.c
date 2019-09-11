/*
 * funciones.c
 *
 *  Created on: 11 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "funciones.h"
#define  CANT 4


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
int cargarSetDatos(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
{
    int i;
    int buffer;
    for (i=0; i<limite; i++)
    {
        //printf("Ingrese el legajo del alumno: ");
        //scanf("%d", &aLegajo[i]);
        if(getInt(&buffer, "+Ingrese el legajo del alumno: ", "Error. ", 1, 100, 2) == 0)
        {
                aLegajo[i]=buffer;
        }else
            {
                aLegajo[i]=0;
            }
        printf("Ingrese el sexo del alumno: ");
        fflush(stdin);
        scanf("%c",&aSexo[i]);
        printf("Ingrese la edad del alumno: ");
        scanf("%d", &aEdad[i]);
        printf("Ingrese la nota 1er Parcial del alumno: ");
        scanf("%d", &aNota1P[i]);
        printf("Ingrese la nota 2do Parcial del alumno: ");
        scanf("%d", &aNota2P[i]);
        aPromedio[i] = (((float)aNota1P[i]+aNota2P[i])/2);
       }
    return 0;
}
int mostrarEstudiante(int aLegajo, char aSexo, int aEdad, int aNota1P,int aNota2P, float aPromedio)
{
    printf("\n%d        %c     %d       %d         %d           %.2f", aLegajo, aSexo, aEdad, aNota1P, aNota2P, aPromedio);

    return 0;
}
int mostrarEstudiantes(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
{
    int i;
    printf("\nlegajo    sexo   edad   nota1P     nota2P    promedio");
    for (i=0; i<limite; i++)
    {
        mostrarEstudiante(aLegajo[i], aSexo[i], aEdad[i], aNota1P[i], aNota2P[i], aPromedio[i]);
    }

    return 0;
}
int ordenarLegajoEstudiantes(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
{
    int i;
    int aux;
    char auxS;
    float auxF;
    int flag=-1;

    while(flag==-1)
    {
        flag=0;
        for (i=0; i<limite-1; i++)
        {
            if(aLegajo[i]<aLegajo[i+1])
            {
                aux= aLegajo[i];
                aLegajo[i]=aLegajo[i+1];
                aLegajo[i+1]=aux;

                auxS= aSexo[i];
                aSexo[i]=aSexo[i+1];
                aSexo[i+1]=auxS;

                aux= aEdad[i];
                aEdad[i]=aEdad[i+1];
                aEdad[i+1]=aux;

                aux= aNota1P[i];
                aNota1P[i]=aNota1P[i+1];
                aNota1P[i+1]=aux;

                aux= aNota2P[i];
                aNota2P[i]=aNota2P[i+1];
                aNota2P[i+1]=aux;

                auxF= aPromedio[i];
                aPromedio[i]=aPromedio[i+1];
                aPromedio[i+1]=auxF;

                flag=-1;
            }
        }
    }

    return 0;
}
