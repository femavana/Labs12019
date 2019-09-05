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
#include <stdlib.h>
#define CANT_EDADES 5


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



/*
 * Imprimir el array
 *
 *
 *
 */

