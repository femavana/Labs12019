/*
 * funciones.h
 *
 *  Created on: 19 sep. 2019
 *      Author: femavana
 */

#ifndef ABM_H_
#define ABM_H_

typedef struct{
	int idPantalla;
	char nombre[20];
	char direccion[20];
	float precioDia;
	int tipo;
	int isEmpty;
}ePantalla;

/*
typedef struct{
	int idPublicacion;
	char nombre[20];
	int cuit;
	int cantDias;
	int archivo;
	int isEmpty;
	ePantalla idPantalla;
}ePublicidad;
*/

int getInt(	int *pResultado,
			char* mensaje,
			char* mensajeError,
			int minimo,
			int maximo,
			int reintentos);
int getString(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int   retries);
int getFloat(float *pResultado,
			 char* mensaje,
			 char* msjError,
			 int minimo,
			 int maximo,
			 int reintentos);
int getStrChar(char* input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries);
int onlyLetters(char* aux);
int onlyNumbers(char* aux);
void menu();
int iniciarPantallas(ePantalla* pantallas, int size, int valor);
int freeSpacePantalla(ePantalla* pantallas, int size,int valor,int* freePosition);
int altaPantalla(ePantalla* pantallas,int size,int value,int* idPantalla);
int printPantallas(ePantalla* pantallas,int size,int value);
int buscarIDPantalla(ePantalla* pantallas,int size,int value, int id,int* posicion);;
int bajaPantalla(ePantalla* pantallas, int size);

/*
int alta(ePublicidad publicacion,int lugarLibre);
void printArrayStruct(ePublicidad publicacion, ,int size);
int searchPantalla(ePublicidad publicacion, int size,int valor);
int searchPublicidad(ePantalla pantallas, int size,int valor);
int initPublicacion(ePublicidad publicacion, int size, int valor);
*/
#endif /* ABM_H_ */
