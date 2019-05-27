%{
	#include<stdio.h>
	#include<stdlib.h>
	extern FILE* yyin;
	extern FILE* yyout;
	extern int yylex();
	extern int yyerror();	
%}
%token ID OP NUM KEY
%%
input: ID input
|OP input
|NUM input
|KEY input
|ID
|OP
|NUM
|KEY
%%
int main()
{
	yyin = fopen("in.c", "r");
	yyout = fopen("junk.c", "w");
	yyparse();
}
int yyerror()
{
	printf("Error\n");
	exit(0);
}