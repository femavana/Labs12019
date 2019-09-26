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
#include "abm.h"
#include "getInput.h"
#define   LCD 1
#define   LED 2
#define   FALSE 1
#define   TRUE  0
#define   CANT 10

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
	printf("\n11-Salir:");
	printf("\n\t<>>>>>><<<<<<>");
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



int freeSpacePantalla(ePantalla* pantallas, int size,int valor,int* freePosition)
{
 int i;
 int ret=-1;

 if(pantallas != NULL && size > 0 )
  {
 for(i=0;i<size;i++)
 {
 	if(pantallas[i].isEmpty == valor)
 	{
 	  ret=0;
 	 *freePosition=i;
 	}
 	else
 	{
 	 printf("\n\tNo hay mas espacio libre...");
 	}
 }
  }
 return ret;
}

int altaPantalla(ePantalla* pantallas,int size,int value,int* idPantalla)
{
int ret=-1;
int freePosition;
float dayPrice;
int tipe;
char name[20];
char direccion[50];

if(pantallas!= NULL && size > 0 )
{
   freeSpacePantalla(pantallas,size,value,&freePosition);
   if(freePosition!=-1)
   {
	(*idPantalla)++;
	getFloat(&dayPrice,"\nIngrese el precio por dia de la pantalla: \n","\nError!!.Ingrese solo numeros",100,1000,2);
	getInt(&tipe,"Ingrese el numero del tipo de pantalla 1-LCD 2-LED: \n","\nError!!.Ingrese solo 1 o 2 ",1,2,2);
	getString(direccion,"Ingrese la direccion de la pantalla: \n","\nError!!",6,50,2);
	getString(name,"Ingrese el nombre de la pantalla: \n","\nError!!",3,20,2);
    pantallas[freePosition].precioDia=dayPrice;
	pantallas[freePosition].tipo=tipe;
	pantallas[freePosition].idPantalla=*idPantalla;
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

int printPantallas(ePantalla* pantallas,int size,int value)
{
	int ret=-1;
	int i;

	if(pantallas!= NULL && size > 0 )
	{
		printf("\n");

		for(i=0;i<size;i++)
		{
			if(pantallas[i].isEmpty==value)
			{
		    printf("\n___|ID___|Nombre____|Direccion___|Tipo__|Precio_por_dia__|");
			printf("%d\t%s\t%s\t%d\t%.2f",pantallas[i].idPantalla,pantallas[i].nombre,pantallas[i].direccion,pantallas[i].tipo,pantallas[i].precioDia);
			}
        }
		ret=0;
	}
return ret;
}

int buscarIDPantalla(ePantalla* pantallas,int size,int value, int id,int* posicion)
{
    int ret=-1;
    int i;

    if(pantallas!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(pantallas[i].isEmpty==0)
                continue;
            else if(pantallas[i].idPantalla==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}

int bajaPantalla(ePantalla* pantallas, int size)
{
    int ret=-1;
    int posicion;
    int id;
    if(pantallas!=NULL && size>0)
    {
    	printPantallas(pantallas,CANT,1);
    	getInt(&id,"\n\nIngrese el ID a dar de baja: ","\nERROR.",1,size,2);

        if(buscarIDPantalla(pantallas,size,0,id,&posicion)==0)
        {
            pantallas[posicion].isEmpty=0;
            pantallas[posicion].idPantalla=0;
            pantallas[posicion].tipo=0;
            pantallas[posicion].precioDia=0;
            strcpy(pantallas[posicion].direccion,"");
            strcpy(pantallas[posicion].nombre,"");
            ret=0;
            printf("\tLa baja fue exitosa!!");
        }
        else
        {
        	printf("\nNo existe el ID ingresado");
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
