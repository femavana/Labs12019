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

#define   LCD 1
#define   LED 2
#define   FALSE 1
#define   TRUE  0
#define   CANT 10

int main(void)
{
	ePantalla pantallas[CANT];
    int opcion;

    iniciarPantallas(pantallas,CANT,0);

    do
    {
    printf("\n");
    printf("\n");
	menu();
	getInt(&opcion,"\n\nIngrese una opcion: ","\nERROR",1,6,3);

	switch(opcion)
	{
	case 1:
		//altaPantalla
		altaPantalla(pantallas,CANT,0);
		break;
	case 2:
		printf("\n\t...Baja...");
		break;
	case 3:
		printf("\n\t...Modificacion...");
		/*5-publicacion
          se lista las pantallas contratadas por cuit
          id pantalla
          */
		break;
	case 4:
		    /*listarPublicaciones
		  validar que solo cargue los ids de pantalla q tiene.
		    alta publicaciones*/
		    break;
	case 5:
		printf("\n\t....");
		//facturacion multiplica cant dias por precio x dia
		//nunca mostrar codigos si descripcion o nombre
		break;
	   }
}while(opcion!=6);

return EXIT_SUCCESS;
}
