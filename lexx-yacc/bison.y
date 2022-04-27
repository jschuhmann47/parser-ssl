%{
	#include<stdio.h>
	#include<conio.h>
	void yyerror(const char *);
%}

%token START 
%token END
%token ENTRADA
%token SALIDA
%token IDENTIFICADOR
%token CONSTANTE
%token ASIGNACION

%%

programa: START listaSentencias END
;
listaSentencias: 
		sentencia 
		| listaSentencias sentencia 
;
sentencia: 
		IDENTIFICADOR '=' expresion ';'
		| ENTRADA expresion ';'
		| SALIDA expresion ';'
;
expresion: 
		termino  
		| expresion operadorAditivo termino
;
termino: 
		IDENTIFICADOR
		| CONSTANTE
;
operadorAditivo: 
		'+'
		| '-'
;

%%

int main(void)
{
	
	if(yyparse()==0)
		printf("La compilacion fue exitosa\n");
    else
        printf("Error de compilacion o memoria RAM insuficiente\n");
	int d=0;
	scanf("%d",d);
	return 0;
}

void yyerror(const char * s)
{
	puts(s);
	return ;
}
