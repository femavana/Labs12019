/*
 ============================================================================
 Name        : clase_09abm.c
 Author      : Navarro Maria Fernanda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#define   CANT 2

typedef struct{
	char nombre[20];
	int edad;
	int dni;
	int isEmpty;
}Persona;


int getInt(	int *pResultado,
			char* mensaje,
			char* mensajeError,
			int minimo,
			int maximo,
			int reintentos);
void menu();
void inicializador(Persona arrayPersona[], int limite, int valor);
int buscarLibre(Persona arrayPersona[], int limite,int valor,int *pAux);
int alta(Persona arrayPersona[],int lugarLibre);
void listar(Persona arrayPersona[],int limite);

int main(void)
{
	Persona arrayPersona[CANT];
    int option;
    int lugarLibre;

    inicializador(arrayPersona,CANT,0);

    do
    {
    printf("\n");
    printf("\n");
	menu();
	getInt(&option,"\nIngrese una opcion: ","\nERROR",1,6,3);

	switch(option)
	{
	case 1:
		printf("\n\t<<Alta>>");
		buscarLibre(arrayPersona,CANT,0,&lugarLibre);
		alta(arrayPersona,lugarLibre);
		break;
	case 2:
		break;
	case 3:
		break;
	case 4:
		    printf("\n\t<<Listar>>");
		    listar(arrayPersona,CANT);
		    break;
	case 5:
		break;
	   }
}while(option!=6);

return EXIT_SUCCESS;
}

void menu()
{
	printf("<>>>>>>GuiaTelefonica<<<<<<>");
	printf("\n1-Alta");
	printf("\n2-Baja");
	printf("\n3-Modificar");
	printf("\n4-Listar");
	printf("\n5-Ordenar:");
	printf("\n6-Salir:");
}

void inicializador(Persona arrayPersona[], int limite, int valor)
{
 int i;
 for(i=0;i<limite;i++)
 {
	 arrayPersona[i].isEmpty=valor;
 }
}

int buscarLibre(Persona arrayPersona[], int limite,int valor,int *pAux)
{
 int i;

 for(i=0;i<limite;i++)
 {
 	if(arrayPersona[i].isEmpty == valor)
 	{
 	  *pAux=i;
 	}
 }
return 0;
}

int alta(Persona arrayPersona[],int lugarLibre)
{
	if(lugarLibre == 0)
	{
	printf("Ingrese el nombre:");
	fgets(arrayPersona[lugarLibre].nombre,sizeof(arrayPersona.nombre),stdin);
	printf("Ingrese la edad :");
	fgets(arrayPersona[lugarLibre].edad,sizeof(arrayPersona.edad),stdin);
	printf("Ingrese el dni:");
	fgets(arrayPersona[lugarLibre].dni,sizeof(arrayPersona.dni),stdin);
	arrayPersona[lugarLibre].isEmpty =1;
    }
	else
	{
	 printf("\n\tNo hay mas espacio libre");
	}
return 0;
}

void listar(Persona arrayPersona[],int limite)
{
	int i;

		for(i=0;i<limite;i++)
		{
			if(arrayPersona[i].isEmpty != 0)
		    {
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
		printf("%s",mensajeError);
		reintentos--;
	}while(reintentos >= 0);
	return ret;
}

