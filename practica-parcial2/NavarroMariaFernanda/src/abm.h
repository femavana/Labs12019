/*
 * funciones.h
 *
 *  Created on: 19 sep. 2019
 *      Author: femavana
 */

#ifndef ABM_H_
#define ABM_H_

typedef struct{
	int  idAbonado;
	char nombre[50];
	char apellido[50];
	char DNI[10];
	int edad;
	int isEmpty;
}Abonado;


typedef struct{
	char motivo[50];
	int tiempo;
	int estado;//Pendiente,cumplido
	int isEmpty;
	int idAmbulancia;
	Abonado idAbonado;
}Llamada;


void menu();
int iniciarlizar(Abonado* persona, int size, int valor);
int freeSpace(Abonado* persona, int size,int valor,int* freePosition);
int alta(Abonado* persona,int size,int value,int* idPantalla);
int print(Abonado* persona,int size,int value);
int buscarID(Abonado* persona,int size,int value, int id,int* posicion);
int baja(Abonado* persona, int size);
#endif /* ABM_H_ */
