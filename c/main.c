#include "headers.h"
#include "parser.c"
#include "scanner.c"



/*
EJEMPLO:
start
aa=4+5-1;
entrada% 90;
salida% aa-90;
end


*/

int main(){
    entrada=fopen("codigoEjemplo.txt","r");
    if(entrada!=NULL){
        objetivo();
        fclose(entrada);
        if(flagError){
            printf("Error Sintactico\n");
        }else{
        printf("Compilacion exitosa\n");
    }
    }
    else printf("No se pudo abrir el archivo");
    
    int d=0;
    scanf("%d",d);
    return 0;
}