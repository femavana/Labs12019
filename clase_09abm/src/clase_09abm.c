/*
 ============================================================================
 Name        : clase_09abm.c
 Author      : Navarro Maria Fernanda
 Version     :
 Copyright   : Your copyright notice
 Description : ABM usuarios
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
#define   CANT 10

int main(void)
{
	Persona arrayPersona[CANT];
    int opcion;
    int lugarLibre;

    initArrayStruct(arrayPersona,CANT,0);

    do
    {
    printf("\n");
    printf("\n");
	menu();
	getInt(&opcion,"\n\nIngrese una opcion: ","\nERROR",1,6,3);

	switch(opcion)
	{
	case 1:
		printf("\n\t...Alta...");
		lugarLibre=searchFreeSpace(arrayPersona,CANT,0);
		alta(arrayPersona,lugarLibre);
		break;
	case 2:
		printf("\n\t...Baja...");
		break;
	case 3:
		printf("\n\t...Modificacion...");
		break;
	case 4:
		    printf("\n\t...Listar...");
		    printArrayStruct(arrayPersona,CANT);
		    break;
	case 5:
		printf("\n\t...Ordenar...");
		break;
	   }
}while(opcion!=6);

return EXIT_SUCCESS;
}
