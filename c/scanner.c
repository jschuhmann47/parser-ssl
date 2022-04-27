#include <stdio.h>



TOKEN scanner();
int estadoFinal(int e);
int comprobarCaracterActual(char c);
TOKEN analizarPalabraReservada(char b[]);
int esPalabraReservada(char palabra[]);

/*
TT	Id	Cte	+   - 	;   =  EOT	espacio
0	1	3	5	6	7	8	9	0
1	1	2	2	2	2	2	2	2
2+	10	10	10	10	10	10	10	10
3	4	3	4	4	4	4	4	4
4+	10	10	10	10	10	10	10	10
5+	10	10	10	10	10	10	10	10
6+	10	10	10	10	10	10	10	10
7+	10	10	10	10	10	10	10	10
8+	10	10	10	10	10	10	10	10
9+	10	10	10	10	10	10	10	10
10	10	10	10	10	10	10	10	10
*/



TOKEN scanner(){
    int matriz[11][8]=
        {
        {1,3,5,6,7,8,9,0},
        {1,2,2,2,2,2,2,2},
        {10,10,10,10,10,10,10,10},
        {4,3,4,4,4,4,4,4},
        {10,10,10,10,10,10,10,10},
        {10,10,10,10,10,10,10,10},
        {10,10,10,10,10,10,10,10},
        {10,10,10,10,10,10,10,10},
        {10,10,10,10,10,10,10,10},
        {10,10,10,10,10,10,10,10},
        {10,10,10,10,10,10,10,10}
        };
    char regBuffer[33];
    int estadoActual=0;
    int columna;
    int caracterActual;
    int caracter;
    int i=0;
    do{
        caracter = fgetc(entrada);
        columna=comprobarCaracterActual(caracter);
        estadoActual=matriz[estadoActual][columna];
        if(columna!=7){
            regBuffer[i] = caracter;
            i++;
        }
    }while(!estadoFinal(estadoActual) && !(estadoActual == 9) );
    regBuffer[i] = '\0';
    switch(estadoActual){
        case(2):{
            if(columna!=7){
                ungetc(caracter,entrada);
                regBuffer[i-1] = '\0';
            }
            if(esPalabraReservada(regBuffer)){
                TOKEN tt=analizarPalabraReservada(regBuffer);
                return tt;
            }else
                return IDENTIFICADOR;
            };
        case(4):{
            if(columna!=7){
                ungetc(caracter,entrada);
                regBuffer[i-1] = '\0';
            }
            return CONSTANTE;
            };
        case(5):{return SUMA;};
        case(6):{return RESTA;};
        case(7):{return PUNTOYCOMA;};
        case(8):{return ASIGNACION;};
        case(9):{return EOT;}; //fin de archivo
    };
}

int estadoFinal(int e){ 
    if (e==2 ||e==4 ||e==5 ||e==6 ||e==7 ||e==8 || e==9) 
        return 1;
    else return 0;
}

int comprobarCaracterActual(char c){
    if (isalpha(c)){return 0;} 
    if ( isdigit(c) ){return 1;} 
    if ( c == '+' ) return 2;
    if ( c == '-' ) return 3;
    if ( c == ';' ) return 4;
    if ( c == '=' ) return 5;
    if ( c == EOF ) return 6;
    if ( isspace(c) || c=='\n') return 7;
   
}


TOKEN analizarPalabraReservada(char b[]){
    if(strcmp(b,"start")==0){return START;};
    if(strcmp(b,"end")==0){return END;};
    if(strcmp(b,"entrada")==0){return ENTRADA;};
    if(strcmp(b,"salida")==0){return SALIDA;};
}

int esPalabraReservada(char palabra[]){
    if (strcmp(palabra,"start")==0||strcmp(palabra,"end")==0||strcmp(palabra,"entrada")==0||strcmp(palabra,"salida")==0){
        return 1;
    }
    return 0;
}

