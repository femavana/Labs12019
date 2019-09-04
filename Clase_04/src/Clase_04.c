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
#include <stdio_ext.h>

int calculoMaxYMin(int* pFlag,int numero,int* pMax,int* pMin);
int getInt(int* pNumero, int rangoMax, int rangoMin,int reintentos,char* mensaje, char* msjError);

int main(void)
{
	int numero;
	char respuesta;
	int max = 0;
	int min = 0;
	int flag = 0;

	do
	{
		getInt(&numero,105,1,2,"\nIngrese un número: ","\n\t<>ERROR.Solo debe ingresar numeros<>");
		calculoMaxYMin(&flag,numero,&max,&min);
		printf("\nDesea continuar? s/n\n");
		__fpurge(stdin);
		scanf("%c",&respuesta);
	} while(respuesta != 'n');
	printf("\nEl Maximo es: %d ",max);
	printf("\nEl Minimo es: %d ",min);
	return 0;
}

int getInt(int* pNumero, int rangoMax, int rangoMin,int reintentos,char* mensaje, char* msjError)
{
int numero;
int i;
	for(i=0;i<=reintentos;i++)
	{
	printf(mensaje);
	if(scanf("%d",&numero)==1) // valida que el dato ingresado sea numero
	 {
		if(numero > rangoMin && numero < rangoMax)
	 {
		 *pNumero=numero;
		 break;
	}
	 }
	else
		{
			 printf(msjError);
			 break;
		 }
	}
return 0;
}


int calculoMaxYMin(int* pFlag,int numero,int* pMax,int* pMin)
{
	int max = *pMax;
	int min = *pMin;
	int flag = *pFlag;


	//pregunto si es la primera vez que entro
	if(flag==0)
	{
		max = numero;
		min = numero;
		*pFlag=1; // paso el flag externo a 1
	}

	if(numero > max)
	{
		max = numero;
	}
	*pMax = max;

	if(numero < min)
	{
		min = numero;
	}
	*pMin = min;

	return 0;
}

