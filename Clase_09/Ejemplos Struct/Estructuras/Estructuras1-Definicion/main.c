/*Estructuras - Definicion y Declaracion
*/
#include <stdio.h>
#include <stdlib.h>
//Definici�n de Estructura
//struct datosPersonales
typedef struct {
    char nombre[20];
    char apellido[20];
    char calle[20];
    int numero;
}datosPersonales;
//};
int main()
{   //Declaracion de variable agenda de tipo datosPersonales
    datosPersonales agenda;
//struct datosPersoanles agenda;

    return 0;
}