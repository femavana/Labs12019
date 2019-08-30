# Labs12019
Functions :

fflush()
/**
** Fuerza una escritura en el búfer para el flujo de salida o actualización dado a través de función de escritura subyacente.
**En flujos de busqueda descarta cualquier información almacenada que se ha obtenido del archivo subyacente, pero no se ha consumido por la aplicación.
**Si se completa correctamente devuelve 0 sino EOF o errno.
*/
#include <stdio.h>
int fflush(FILE *stream);

fpurge() 
/**
**Borra los bufers de la secuencia.
**De los flujos de salida descarta cualquier salida no escrita.
**De los flujos de entrada descarta cualquiera leída pero no obtenida mediante get.
**Si se completa correctamente devuelve 0 sino -1 o errno.
*/
#include <stdio.h>
int fpurge (ARCHIVO * flujo);

__fpurge ()
/**
borra los bufers de la secuencia.
De los flujos de salida descarta cualquier salida no escrita.
De los flujos de entrada descarta cualquier leída pero no obtenida mediante get.
No devuelve un valor.
*/
#include <stdio.h>
#include <stdio_ext.h>
void  __fpurge(FILE *stream);



Fuentes:
http://man7.org/linux/man-pages/man3/fpurge.3.html






























































































