#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef enum {
    IDENTIFICADOR,CONSTANTE,SUMA,RESTA,PARENIZQUIERDO,PARENDERECHO,PUNTOYCOMA,ASIGNACION,EOT,ERRORLEXICO,START,END,ENTRADA,SALIDA
    }TOKEN;

FILE *entrada;
int flagError=0;
char *palabrasReservadas[4]={"start","end","entrada%","salida%"};