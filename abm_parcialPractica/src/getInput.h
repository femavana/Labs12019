/*
 * getInput.h
 *
 *  Created on: 21 sep. 2019
 *      Author: femavana
 */

#ifndef GETINPUT_H_
#define GETINPUT_H_

int getFloat(float *input,
			 char* mensaje,
			 char* msjError,
			 int minSize,
			 int maxSize,
			 int retries);
int getInt(	int *input,
			char* mensaje,
			char* mensajeError,
			int minSize,
			int maxSize,
			int retries);
int getChar( char *input,
			 char* mensaje,
			 char* msjError,
			 char minSize,
			 char maxSize,
			 int retries);
int getString(char* input,
		      char* message,
			  char* msgError,
			  int   minSize,
			  int   maxSize,
			  int   retries);
int getStrChar(char* input,
		      char* message,
		      char* msgError,
		      int minSize,
		      int maxSize,
		      int retries);

int onlyLetter(char aux);
int onlyNumbersStr(char* aux);
int onlyTextStr(char* aux);


#endif /* GETINPUT_H_ */
