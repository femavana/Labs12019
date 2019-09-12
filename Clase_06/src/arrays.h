/*
 * funciones.h
 *
 *  Created on: 11 sep. 2019
 *      Author: alumno
 */

#ifndef ARRAYS_H_
#define ARRAYS_H_

int initArray(int* pArray, int limite,int valor);
int initArrayInt(int *pArray , int limite, int valor);
int printArrayInt(int *pArray , int limite);
int getArrayInt(	int *pArray,
					int limite,
					char *pMensaje,
					char *pMensajeError,
					int minimo,
					int maximo,
					int reintentos);

int maximoArrayInt(int *pArray,int limite,int *pMax);
int minimoArrayInt(int *pArray,int limite,int *pMin);
int promedioArrayInt(int *pArray,int limite,int *promedio);
int sumaArrayInt(int *pArray,int limite,int *suma);
int cargarSetDatos(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite);
void printString(int aLegajo, char aSexo, int aEdad, int aNota1P,int aNota2P, float aPromedio);
void mostrarEstudiantes(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite);
void ordenarString(int* aLegajo, char* aSexo,int* aEdad,int* aNota1P,int* aNota2P, float* aPromedio,int limite);

#endif /* ARRAYS_H_ */
