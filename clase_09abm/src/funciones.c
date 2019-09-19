/*
 * funciones.c
 *
 *  Created on: 19 sep. 2019
 *      Author: femavana
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define   CANT 2

void menu()
{
	printf("<>>>>>>GuiaTelefonica<<<<<<>");
	printf("\n1-Alta");
	printf("\n2-Baja");
	printf("\n3-Modificar");
	printf("\n4-Listar");
	printf("\n5-Ordenar:");
	printf("\n6-Salir:");
	printf("\n\t<>>>>>><<<<<<>");
}

void initArrayStruct(Persona arrayPersona[], int limite, int valor)
{
 int i;
 for(i=0;i<limite;i++)
 {
	 arrayPersona[i].isEmpty=valor;
 }
}

int searchFreeSpace(Persona arrayPersona[], int limite,int valor)
{
 int i;
 int ret=-1;

 for(i=0;i<limite;i++)
 {
 	if(arrayPersona[i].isEmpty == valor)
 	{
 	  ret=i;
 	 break;
 	}
 		printf("\n\tNo hay mas espacio libre...");
 }
 return ret;
}

void alta(Persona arrayPersona[],int lugarLibre)
{
	char auxNombre[20];
	char auxEdad[20];
	char auxDni[20];
    int  edad;
    int dni;

    getStringNumbers("\nIngrese el DNI de la persona: ","\nError.Ingrese solo numeros!!",auxDni);
    if(searchOccurrence(arrayPersona,CANT,0)!=-1)
    {
	getStringLetters("\nIngrese el nombre de la persona: ","\nError.Ingrese solo letras!!",auxNombre);
	getStringNumbers("\nIngrese la edad de la persona: ","\nError.Ingrese solo numeros!!",auxEdad);
	edad=atoi(auxEdad);
	dni=atoi(auxDni);
	strcpy(arrayPersona[lugarLibre].nombre,auxNombre);
	arrayPersona[lugarLibre].edad=edad;
	arrayPersona[lugarLibre].dni=dni;
	arrayPersona[lugarLibre].isEmpty=1;
    }
    else
    {
    	printf("\n\tEl legajo ingresado ya existe!!");
    }
}

void printArrayStruct(Persona arrayPersona[] ,int limite)
{
	int i;

		for(i=0;i<limite;i++)
		{
			if(arrayPersona[i].isEmpty == 1)
		    {
		    printf("\n\tNombre--\tEdad--\tDNI--");
			printf("\n\t%s--%d--%d",arrayPersona[i].nombre,arrayPersona[i].edad,arrayPersona[i].dni);
		    }
		}
}

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
		printf("%s", mensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return ret;
}

int getString( char message[],
	       char input[])
{
	printf("message");
	scanf("%s", input);
return 0;
}

int getStringNumbers( char message[],
		             char msgError[],
		              char  input[])
{
	int ret=-1;
	char aux[256];
	getString(message,aux);
	if(onlyNumbers(aux)==0)
	{
	  strcpy(input,aux);
	  ret=0;
	}
	else
		{
			printf("\n\t%s", msgError);
		}
return ret;
}

int getStringLetters(char message[],
		     char msgError[],
		     char input[])
{
int ret=-1;
char aux[256];
	getString(message,aux);
	if(onlyLetters(aux)==0)
	{
	  strcpy(input,aux);
		ret=0;
	}
	else
	{
		printf("\n\t%s", msgError);
	}
return ret;
}
//validations

int onlyLetters(char aux[])
{
int ret=-1;
int i=0;
while(aux[i]!= '\0')
{
if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z'))
{
	ret=0;
	i++;
}
}
return ret;
}

int onlyNumbers(char aux[])
{
int ret=-1;
int i=0;
while(aux[i]!= '\0')
{
if(aux[i]<'0'|| aux[i] > '9')
{
	ret=0;
	i++;
}
}
return ret;
}

int searchOccurrence(Persona arrayPersona[], int limite,int valor)
{
 int i;
 int ret=-1;

 for(i=0;i<limite;i++)
 		{
 			if(arrayPersona[i].dni== valor)
 			{
 				ret=i;
 			}
 		}
return ret;
}
