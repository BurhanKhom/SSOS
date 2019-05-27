%{
	#include<stdio.h>
%}
%X SCOMMENT MCOMMENT
%%
"//" { BEGIN SCOMMENT; }
<SCOMMENT>. ;
<SCOMMENT>\n {BEGIN 0;}
"/*" { BEGIN MCOMMENT; }
<MCOMMENT>. ;
<MCOMMENT>\n ;
<MCOMMENT>"*/" { BEGIN 0; }
%%
int main()
{
	yyin = fopen("in.c", "r");
	yyout = fopen("out.c", "w");
	yylex();
}