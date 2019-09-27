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
#define   FALSE 1
#define   TRUE  0
#define   CANT 10

void menu()
{
	printf("<>>>>>><<<<<<>");
	printf("\n1-Alta del asociado");
	printf("\n2-Modificar datos del asociado");
	printf("\n3-Baja del asociado");
	printf("\n4-Nueva llamada");
	printf("\n5-Asignar ambulancia:");
	printf("\n6-Informar:");
	printf("\n7-Salir:");
	printf("\n\t<>>>>>><<<<<<>");
}

int iniciarlizar(Abonado* persona, int size, int valor)
{
 int ret=-1;
 int i;
 if(persona != NULL && size > 0 )
 {
 for(i=0;i<size;i++)
 {
	 persona[i].isEmpty=valor;
	 ret=0;
 }
 }
 return ret;
}

int freeSpace(Abonado* persona, int size,int valor,int* freePosition)
{
 int i;
 int ret=-1;

 if(persona != NULL && size > 0 )
  {
 for(i=0;i<size;i++)
 {
 	if(persona[i].isEmpty== valor)
 	{
 	  ret=0;
 	 *freePosition=i;
 	}
 }
  }
 return ret;
}

int alta(Abonado* persona,int size,int value,int* idAbonado)
{
int ret=-1;
int freePosition;
int edad;
char dni[10];
char name[50];
char apellido[50];

if(persona!= NULL && size > 0 )
{
   if(freeSpace(persona,size,value,&freePosition)==0)
   {
	(*idAbonado)++;
	getString(dni,"Ingrese el DNI del abonado: \n","\nError!!.Ingrese solo numeros ",1,10,2);
	getInt(&edad,"Ingrese edad del abonado: \n","\nError!!.Ingrese solo numeros ",1,100,2);
	getString(apellido,"Ingrese el apellido del abonado: \n","\nError!!",3,50,2);
	getString(name,"Ingrese el nombre del abonado: \n","\nError!!",3,50,2);
	persona[freePosition].edad=edad;
	persona[freePosition].idAbonado=*idAbonado;
	strcpy(persona[freePosition].DNI,dni);
	strcpy(persona[freePosition].nombre,name);
	strcpy(persona[freePosition].apellido,apellido);
    persona[freePosition].isEmpty=1;
		  ret=0;
   }
	else
	{
		printf("\nNo hay mas lugar!!!");
	}
}
return ret;
}


int print(Abonado* persona,int size,int value)
{
	int ret=-1;
	int i;

	if(persona!= NULL && size > 0 )
	{
		printf("\n");

		for(i=0;i<size;i++)
		{
			if(persona[i].isEmpty==value)
			{
		    printf("\n___|ID___|Nombre____|Apellido___|Edad__|");
			printf("\n%d %s %s %d",persona[i].idAbonado,persona[i].nombre,persona[i].apellido,persona[i].edad);
			}
        }
		ret=0;
	}
return ret;
}

int buscarID(Abonado* persona,int size,int value, int id,int* posicion)
{
    int ret=-1;
    int i;

    if(persona!= NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(persona[i].isEmpty==0)
                continue;
            else if(persona[i].idAbonado==id)
            {
                ret=0;
                *posicion=i;
                break;
            }
        }
    }
    return ret;
}

int baja(Abonado* persona, int size)
{
    int ret=-1;
    int posicion;
    int id;
    if(persona!=NULL && size>0)
    {
    	print(persona,CANT,1);
    	getInt(&id,"\n\nIngrese el ID del asociado a dar de baja: ","\nERROR.",1,size,2);

        if(buscarID(persona,size,0,id,&posicion)==0)
        {
            persona[posicion].edad=0;
            persona[posicion].idAbonado=0;
            persona[posicion].edad=0;
            strcpy(persona[posicion].apellido,"");
            strcpy(persona[posicion].nombre,"");
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

int buscarString(Abonado* persona, int size, char* value,int* indice)
{
    int ret=-1;
    int i;
    if(persona!=NULL && size>=0)
    {
        for(i=0;i<size;i++)
        {
            if(persona[i].isEmpty==1)
                continue;
            else if(strcmp(persona[i].DNI,value)==0)
            {
                *indice=i;
                ret=0;
                break;
            }
        }
    }
    return ret;
}
int modificar(Abonado* persona, int size)
{
    int ret=-1;
    int posicion;
    int id;
    if(persona!=NULL && size>0)
    {
    	print(persona,CANT,1);
    	getInt(&id,"\n\nIngrese el DNI del asociado a modificar: ","\nERROR.",1,size,2);

        if(buscarID(persona,size,0,id,&posicion)==0)
        {
        	getString(,"Ingrese el nombre de la pantalla: \n","\nError!!",3,20,2);
            pantallas[posicion].isEmpty=0;
            pantallas[posicion].idPantalla=0;
            persona[posicion].tipo=0;
            persona[posicion].precioDia=0;
            strcpy(persona[posicion].direccion,"");
            strcpy(persona[posicion].nombre,"");
            ret=0;
            printf("\tEl cambio fue exitoso!!");
        }
        else
        {
        	printf("\nNo existe el ID ingresado");
        }
    }
    return ret;
}


