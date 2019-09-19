/*
 * funciones.h
 *
 *  Created on: 19 sep. 2019
 *      Author: femavana
 */

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
int getString( char message[],
	       char input[]);
int getStringNumbers( char message[],
		             char msgError[],
		             char  input[]);
int getStringLetters(char message[],
		     char msgError[],
		     char input[]);
int onlyLetters(char aux[]);
int onlyNumbers(char aux[]);
void menu();
void initArrayStruct(Persona arrayPersona[], int limite, int valor);
int searchFreeSpace(Persona arrayPersona[], int limite,int valor);
void alta(Persona arrayPersona[],int lugarLibre);
void printArrayStruct(Persona arrayPersona[] ,int limite);
int searchOccurrence(Persona arrayPersona[], int limite,int valor);
