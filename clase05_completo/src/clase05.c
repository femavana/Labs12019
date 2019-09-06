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
#include "funciones.h"
#define QTY_EDADES 5

int main(void)
{
	int edades[QTY_EDADES];
	int cantidadUsuario;
	int max;
	int min;
	int promedio;
	int suma;

	initArrayInt(edades,QTY_EDADES,1);
	cantidadUsuario = getArrayInt(edades,QTY_EDADES,"Ingrese una Edad?\n","Error\n",0,200,2);
	printArrayInt(edades,cantidadUsuario);
	minimoArrayInt(edades,QTY_EDADES,&min);
	maximoArrayInt(edades,QTY_EDADES,&max);
	promedioArrayInt(edades,QTY_EDADES,&promedio);
	sumaArrayInt(edades,QTY_EDADES,&suma);
	printf("\nEl maximo es:%d y el minimo:%d",max,min);
	printf("\nLa suma total es:%d y el promedio:%d",suma,promedio);
	return EXIT_SUCCESS;
}

