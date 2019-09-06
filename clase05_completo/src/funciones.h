/*
 * funciones.h
 *
 *  Created on: 4 sep. 2019
 *      Author: alumno
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

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
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);
int maximoArrayInt(int *pArray,int limite,int *pMax);
int minimoArrayInt(int *pArray,int limite,int *pMin);
int promedioArrayInt(int *pArray,int limite,int *promedio);
int sumaArrayInt(int *pArray,int limite,int *suma);

#endif /* FUNCIONES_H_ */
