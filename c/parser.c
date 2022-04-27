#include <stdio.h>


void objetivo();
void match(TOKEN t);
void programa();
void listaSentencias();
void sentencia(TOKEN t);
void identificador();
void listaExpresiones();
void expresion();
void errorSintactico();
TOKEN siguienteToken();
extern TOKEN scanner();


void match(TOKEN t){
    if(!(t==siguienteToken())){
        errorSintactico();
    }
};



void objetivo(){
    programa();
    match(EOT); //EOT es END OF FILE
}

void programa(){
    
    match(START);
    listaSentencias();;
}
void listaSentencias(void)
{   
    TOKEN t=siguienteToken();
    sentencia(t);
    while (1)
    {
        TOKEN t=siguienteToken();
        switch (t)
        {
        case IDENTIFICADOR : case ENTRADA : case SALIDA :
            sentencia(t);
            break;
        case(END) : return;
        default: errorSintactico();
        }
        
    }
}

void sentencia(TOKEN t){
    switch(t){
        case(IDENTIFICADOR):{ 
            match(ASIGNACION);
            listaExpresiones();
            break;
        }
        case(ENTRADA):{
            listaExpresiones();       
            break;
        }
        case(SALIDA):{
            listaExpresiones();
            break;
        }
        default:{
            errorSintactico();
        }
    }
}


void listaExpresiones(){
   expresion(); 
   TOKEN t=siguienteToken();
   switch(t){
       case (SUMA):{
           listaExpresiones();
           break;
       }
       case (RESTA):{
           listaExpresiones();
           break;
       }
       case (PUNTOYCOMA): return;
       default: errorSintactico();
   }

}

void expresion(){
   TOKEN t=siguienteToken();
   switch(t){
       case (IDENTIFICADOR):{
           break;
       }
       case (CONSTANTE):{
           break;
       }
       default:{
           errorSintactico();
       }
   }
   
}



void errorSintactico(){
    flagError=1;
}

TOKEN siguienteToken()
{   
    TOKEN tokenActual = scanner();
    return tokenActual;
}

