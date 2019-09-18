/*
 * funciones.c
 *
 *  Created on: 11 sep. 2019
 *      Author: alumno
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "get_Input.h"
#include "arrays.h"
#define  CANT 4


int initArray(int *pArray,int limite,int valor)
{
	int ret=-1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			pArray[i]=valor;
		}
		ret=0;
	}
return ret;
}

int printArray(int *pArray,int limite)
{
	int ret=-1;
	int i;
	if(pArray != NULL && limite > 0)
	{
		for(i=0;i<limite;i++)
		{
			printf("\n\t%d",pArray[i]);
		}
		ret=0;
	}
return ret;
}

int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos)
{
	int ret=-1;
	int buffer;
	int i;
	char respuesta;
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
				pArray[i]=buffer;
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
		ret=0;
	}
	return ret;
}

int minimoArrayInt(int *pArray,int limite,int *pMin)
{
	int ret=-1;
	int buffer;
	int i;

	if(pArray != NULL && limite > 0 )
	{
	        buffer= pArray[0];
	        for(i=1;i<limite;i++)
	        {
				if(pArray[i] < buffer)
				{
				  *pMin=buffer;
				}
			}
	        ret=0;
	}
return ret;
}

int maximoArrayInt(int *pArray,int limite,int *pMax)
{
	int ret=-1;
	int buffer;
	int i;

	if(pArray != NULL && limite > 0 )
	{
				 buffer= pArray[0];
	        for(i=1;i<limite;i++)
	        {
				if(pArray[i] > buffer)
				{
				  *pMax=buffer;
				}
			}
	        ret=0;
	}
return ret;
}

int promedioArrayInt(int *pArray,int limite,int *promedio)
{
	int ret=-1;
	int buffer=0;
	int i;

		if(pArray != NULL && limite > 0 )
		{
		        for(i=0;i<limite;i++)
		        {
			  buffer=buffer+pArray[i];
			}
		  *promedio=buffer/limite;
		ret=0;	
		}
return ret;
}

int sumaArrayInt(int *pArray,int limite,int  *suma)
{
	int ret=-1;
	int buffer=0;
	int i;

			if(pArray != NULL && limite > 0 )
			{
			 for(i=0;i<limite;i++)
			  {
			    *suma=buffer+pArray[i];
			  }
			ret=0;
			}	
return ret;
}

int cargarSetDatos(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
{
	int ret=-1;
    int i;
    int buffer;

    for (i=0; i<limite; i++)
    {
        if(getInt(&buffer,"\nIngrese el legajo del alumno: ","Error",1,100,2) == 0)
        {
                aLegajo[i]=buffer;
        }
        else
        {
                aLegajo[i]=0;
        }
        printf("\nIngrese el sexo del alumno: ");
        fflush(stdin);
        scanf("%c",&aSexo[i]);
        printf("\nIngrese la edad del alumno: ");
        scanf("%d", &aEdad[i]);
        printf("\nIngrese la nota 1er Parcial del alumno: ");
        scanf("%d", &aNota1P[i]);
        printf("\nIngrese la nota 2do Parcial del alumno: ");
        scanf("%d", &aNota2P[i]);
        aPromedio[i] = (((float)aNota1P[i]+aNota2P[i])/2);
        ret=0;
       }
    return ret;
}

void printString(int aLegajo, char aSexo,int aEdad,int aNota1P,int aNota2P, float aPromedio)
{
    printf("\n%d        %c     %d       %d         %d           %.2f", aLegajo, aSexo, aEdad, aNota1P, aNota2P, aPromedio);
}

void mostrarEstudiantes(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
{
    int i;
    printf("\nlegajo    sexo   edad   nota1P     nota2P    promedio");
    for (i=0; i<limite; i++)
    {
        printString(aLegajo[i], aSexo[i], aEdad[i], aNota1P[i], aNota2P[i], aPromedio[i]);
    }
}

void ordenarString(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite)
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
}
//Struct
//Struct1
void initArrayStruct(Persona arrayPersona[], int limite, int valor)
{
 int i;
 for(i=0;i<limite;i++)
 {
	 arrayPersona[i].employeedFile=valor;
 }
}
//struct2
int searchFirstOccurrenceStruct(Persona arrayPersona[], int limite,int valor)
{
 int i;
 int ret=-1;

 for(i=0;i<limite;i++)
 {
 	if(arrayPersona[i].employeedFile == valor)
 	{
 	  ret=i;
 	}
 }
return ret;
}

//struct3
void printArrayStruct(Persona arrayPersona[] ,int limite)
{
	int i;

		for(i=0;i<limite;i++)
		{
			if(arrayPersona[i].employeedFile != 1)
		    {
			printf("\n\t%s--%s--%d",arrayPersona[i].name,arrayPersona[i].lastName,arrayPersona[i].employeedFile);
		    }
		}
}

//struct4
void orderArrayStruct(Persona arrayPersona[] ,int limite)
{
	int i,j;
	char auxiliar[];

			for(i=0;i<limite;i++)
			{
				if(arrayPersona[i].employeedFile != 1)
			    {
					continue;
			    }
				for(j=i+1;j<limite;j++)
				{
					if(arrayPersona[j].employeedFile != 1)
								    {
										continue;
								    }
					if(strcmp(arrayPersona[i].lastName,arrayPersona[j].lastName)>0)
					{
						auxiliar=arrayPersona[j];
						arrayPersona[j]=arrayPersona[i];
						arrayPersona[i]=auxiliar;
					}
				}
			}
}
