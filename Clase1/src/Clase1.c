/*
 ============================================================================
 Name        : Suma.c
 Author      : Leonardo Blanco
 Version     :
 Copyright   : 
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int pideSuma(int* resultado);

int main(void)
{
	int resultado;
	if(pideSuma(&resultado)== 0)
	{
		printf("El resultado es:%d",resultado);
	}else
	{
		printf("Error.Ingrese solo numeros enteros");
	}
	return 0;
}
int pideSuma(int* resultado)
{
	int num1;
	int num2;
	printf("Ingrese el primero numero: ");
	scanf("%d",&num1);
	printf("Ingrese el segundo numero: ");
	scanf("%d",&num2);
	*resultado = num1+num2;
	return 0;
}

