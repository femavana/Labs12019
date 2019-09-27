/*
 ============================================================================
 Name        : NavarroMariaFernanda.c
 Author      : Navarro
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"
#include "getInput.h"
#define   ESTADO_PEDIENTE 0
#define   ESTADO_CUMPLIDO 1
#define   MOTIVOS_INFARTO 2
#define   MOTIVOS_ACV     1
#define   MOTIVOS_GRIPE   3
#define   CANT 10

int main(void)
{
	Abonado persona[CANT];
    int opcion;
    int idAbonado=0;

    iniciarlizar(persona,CANT,0);

    do
    {
    printf("\n");
    printf("\n");
	menu();
	getInt(&opcion,"\n\nIngrese una opcion: ","\nERROR",1,7,2);


	switch(opcion)
	{
	case 1:
		printf("\n\t...Alta del asociado...\n");
		alta(persona,CANT,0,&idAbonado);
		break;
	case 2:
		printf("\n\t...Modificar datos del asociado...\n");
		//modificar(persona,CANT);
		break;
	case 3:
		    printf("\n\t...Baja del asociado...");
		    baja(persona,CANT);
			break;
	case 4:
			printf("\n\t...Nueva llamada...");//modificar llamado
			print(persona,CANT,1);
			break;
	case 5:
		printf("\n\t...Asignar ambulancia:...");
		/*5-publicacion
          se lista las pantallas contratadas por cuit
          id pantalla
          */
		break;
	case 6:
	      printf("\n\t...Informar:..");
		    /*listarPublicaciones
		  validar que solo cargue los ids de pantalla q tiene.
		    alta publicaciones*/
		    break;
	   }
}while(opcion!=7);

return EXIT_SUCCESS;
}
