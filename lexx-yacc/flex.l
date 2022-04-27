%option noyywrap
%{
	#include<stdio.h>
	#include "y.tab.h"
%}

%%
start		{return START;}
end		{return END;}
entrada		{return ENTRADA;}
salida		{return SALIDA;}
[a-z]+		{return IDENTIFICADOR;}
[0-9]+		{return CONSTANTE;}
[+-;=]		{return yytext[0];}
.|"\n"		;
%%
