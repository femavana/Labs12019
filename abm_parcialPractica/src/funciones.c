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
#define   LCD 1
#define   LED 2
#define   FALSE 1
#define   TRUE  0
#define   CANT 10

//validations

int onlyTextStr(char* aux)
{
int ret=0;
int i;

for(i=0;i<'\0';i++)
{
if((aux[i] != ' ') && (aux[i] < 'a' || aux[i] > 'z') && (aux[i] < 'A' || aux[i] > 'Z'))
{
	ret=-1;
}
}
return ret;
}

void menu()
{
	printf("<>>>>>><<<<<<>");
	printf("\n1-Alta de pantalla");
	printf("\n2-Modificar datos de pantalla");
	printf("\n3-Baja de pantalla");
	printf("\n4-Contratar una publicidad");
	printf("\n5-Modificar condiciones de publicacion:");
	printf("\n6-Cancelar contratacion:");
	printf("\n7-Consulta facturacion:");
	printf("\n8-Listar contrataciones:");
	printf("\n9-Listar pantallas:");
	printf("\n10-Informar:");
	printf("\n\t<>>>>>><<<<<<>");
}

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
		scanf("%f",&buffer);
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
        	size=strlen(bufferStr)-1;
        	if(size>=minSize && size<maxSize)
        	{    strcpy(input,bufferStr);
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
                if(onlyTextStr(bufferStr)==0)
                {
                    strcpy(input,bufferStr);
                    ret=0;
                    break;
                }
                else
                {
                    printf("%s",msgError);
                    retries--;
                }
            }
        }while(retries>=0);
  return ret;
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

int iniciarPantallas(ePantalla* pantallas, int size, int valor)
{
 int ret=-1;
 int i;
 if(pantallas != NULL && size > 0 )
 {
 for(i=0;i<size;i++)
 {
	 pantallas[i].isEmpty=valor;
	 ret=0;
 }
 }
 return ret;
}



int freeSpacePantalla(ePantalla* pantallas, int size,int valor)
{
 int i;
 int ret=-1;

 if(pantallas != NULL && size > 0 )
  {
 for(i=0;i<size;i++)
 {
 	if(pantallas[i].isEmpty == valor)
 	{
 	  ret=i;
 	}
 	else
 	{
 	 printf("\n\tNo hay mas espacio libre...");
 	}
 }
  }
 return ret;
}

int altaPantalla(ePantalla* pantallas,int size,int value)
{
int ret=-1;
int freePosition;
float dayPrice;
int tipe;
char name[20];
char direccion[50];

if(pantallas!= NULL && size > 0 )
{
   freePosition=freeSpacePantalla(pantallas,size,value);
   if(freePosition!=-1)
   {
	pantallas[freePosition].idPantalla++;
	getFloat(&dayPrice,"\nIngrese el precio por dia de la pantalla: ","\nError!!.Ingrese solo numeros",100,1000,2);
	getInt(&tipe,"\nIngrese el tipo de pantalla:  ","\nError!!.Ingrese solo: LCD-1 y LED-2 ",1,2,2);
	getStrChar(direccion,"\nIngrese la direccion de la pantalla: ","\nError!!.",6,50,2);
	getStrChar(name,"\nIngrese el nombre de la pantalla","\nError!!.Ingrese solo letras",3,20,2);
    pantallas[freePosition].precioDia=dayPrice;
	pantallas[freePosition].tipo=tipe;
	strcpy(pantallas[freePosition].nombre,name);
	strcpy(pantallas[freePosition].direccion,direccion);
    pantallas[freePosition].isEmpty=FALSE;
		  ret=0;
   }
	else
	{
		printf("\nNo hay mas lugar!!!");
	}
}
return ret;
}



/*
int initPublicidad(ePublicidad publicacion, int size, int valor)
{
 int ret=-1;
 int i;
 if(publicacion != NULL && size > 0 )
 {
	 for(i=0;i<size;i++)
   {
	 publicacion[i].isEmpty=valor;
	 ret=0;
   }
 }
 return ret;
}

  int searchPantalla(ePublicacion publicidad, int size,int valor)
{
 int i;
 int ret=-1;

 if(publicidad != NULL && size > 0 )
  {
 for(i=0;i<size;i++)
 {
 	if(publicidad[i].isEmpty == valor)
 	{
 	  ret=i;
 	}
 	else
 	{
 	 printf("\n\tNo hay mas espacio libre...");
 	}
 }
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
}*/
