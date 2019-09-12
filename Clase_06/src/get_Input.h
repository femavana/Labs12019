/*
 * get_Input.h
 *
 *  Created on: 12 sep. 2019
 *      Author: femavana
 */

#ifndef GET_INPUT_H_
#define GET_INPUT_H_

/**1  \brief  Solicita un numero al usuario y lo valida
     * \param pResultado Puntero del numero ingresado
     * \param mensaje  Puntero del mensaje a ser mostrado
     * \param msjError Puntero del mensaje a ser mostrado en caso de error
     * \param minimo Limite minimo a validar
     * \param maximo Limite maximo a validar
     * \param reintentos Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el numero y sino -1
     */
int getInt(	int *pResultado,
		    char* mensaje,
	        char* msjError,
			int minimo,
			int maximo,
			int reintentos);

/**2   \brief Solicita un numero al usuario y lo valida
     * \param pResultado Puntero del numero ingresado
     * \param mensaje  Puntero del mensaje a ser mostrado
     * \param msjError Puntero del mensaje a ser mostrado en caso de error
     * \param minimo Limite minimo a validar
     * \param maximo Limite maximo a validar
     * \param reintentos Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el numero y sino -1
     */
int getFloat(float *pResultado,
		     char* mensaje,
		     char* msjError,
			 int minimo,
			 int maximo,
			 int reintentos);

/**3   \brief Solicita un caracter al usuario y lo valida
     * \param pResultado Puntero del caracter ingresado
     * \param mensaje  Puntero del mensaje a ser mostrado
     * \param msjError Puntero del mensaje a ser mostrado en caso de error
     * \param minimo Limite minimo a validar
     * \param maximo Limite maximo a validar
     * \param reintentos Cantidad de intentos en caso de error
     * \return Devuelve 0 si carga el numero y sino -1
     */
int getChar( char *pResultado,
		     char* mensaje,
		     char* msjError,
			 int minimo,
			 int maximo,
			 int reintentos);


#endif /* GET_INPUT_H_ */
