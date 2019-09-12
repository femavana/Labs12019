/*
 ============================================================================
 Name        : Clase_06.c
 Author      : NavarroMaria
 Version     :
 Copyright   : Nadie
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include "get_Input.h"
#include "arrays.h"
#define  CANT 4


int main(void)
{
	int legajo[CANT];
	char sexo[CANT];
	int edad[CANT];
	int nota1P[CANT];
	int nota2P[CANT];
	float promedio[CANT];

	    cargarSetDatos(legajo, sexo, edad, nota1P, nota2P, promedio, CANT);
	    //Mostrar ordenar y mostrar
	    mostrarEstudiantes(legajo, sexo, edad, nota1P, nota2P, promedio, CANT);
	    ordenarString(legajo, sexo, edad, nota1P, nota2P, promedio, CANT);
	    mostrarEstudiantes(legajo, sexo, edad, nota1P, nota2P, promedio, CANT);
	return 0;
}
