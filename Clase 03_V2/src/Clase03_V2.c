/*
 ============================================================================
 Name        : Get.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
int calculoMaxYMin(int *flagFun,int numeroFun,int *MaxFun, int *MinFun);
int getNumero(int* pNumero, int* rangoMax, int* rangoMin,int reintentos,char* mensaje, char* msjError);

int main(void)
{
	int numero;
	char respuesta;
	int max = 0;
	int min = 0;
	int flag = 0;

	do
	{
		printf("\nIngrese un numero");
		scanf("%d",&numero);
		getNumero(&numero,100,1,5,"Ingrese un numero","ERROR");
		calculoMaxYMin(&flag,numero,&max,&min);
		printf("\nDesea continuar? s/n");
		_fpurge(stdin);
		scanf("%c",&respuesta);

	} while(respuesta != 'n');

	printf("El Maximo es %d ",Max);
	printf("El Minimo es %d ",Min);
	return 0;
}
int getNumero(int* pNumero, int* rangoMax, int* rangoMin,int reintentos,char* mensaje, char* msjError)
{
int numero;
int ret=0;
	for(i=0;i>reintentos;i++)
	{
	printf(*mensaje);
	scanf("%d",&numero);
	 if(numero < *rangoMin && numero > *rangoMax)
	 {
		 *pNumero= numero;
		 ret=1;
	 }
	}
return ret;
}


int calculoMaxYMin(int* pFlag,int numeroFun,int* pMax,int* pMin)
{
	int max = *pMax;
	int min = *pMin;
	int flag = *pFlag;


	//pregunto si es la primera vez que entro
	if(flag==0)
	{
		max = numeroFun;
		min = numeroFun;
		*pFlag=1; // paso el flag externo a 1
	}


	if(numeroFun > max)
	{
		max = numeroFun;
	}
	*pMax = max;


	if(numeroFun < min)
	{
		min = numeroFun;
	}
	*pMin = min;


	return 0;
}

