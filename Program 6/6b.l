%{
	#include "y.tab.h"
%}
%%
"int"|"float"|"void"|"double"|"long"|"printf"|"scanf"|"char"|"main" { printf("%s is a keyword\n", yytext); return  KEY; }
[_a-zA-Z][_a-zA-Z0-9]* { printf("%s is an identifier\n", yytext); return ID; }
[0-9]+ { printf("%s is a Number\n", yytext); return NUM; }
[+|*|-|/] { printf("%s is an operator\n", yytext); return OP; }
[\t];
[\n];
[{|}];
"#include".*
%%