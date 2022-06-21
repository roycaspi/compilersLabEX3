%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lps_tab.h"

int lines = 0;

//void printTok(int token);
//char* getOutputFileName(char* fileName, char* extension);
//void handleRELOP();
//void printCenterText(const char *text);
//const char* getTokName(Tok tok);
%}

digit		[0-9]
id    		[a-zA-Z]+
ws		    [ \t]+
num 		{digit}+|{digit}*\.{digit}+
relop       ["<"|">"|"<>"|"="]
addop       ["+"|"-"]
mulop       ["*"|"/"|"mod"]
logop       ["&"|"~"|"!"]
%x comment

%%

"/*"		BEGIN comment;
<comment>"*/"	BEGIN INITIAL;
<comment>.|\n	;
^start		{ECHO; return START;}
start		{ECHO; return START;}
^if			{ECHO; return IF;}
if			{ECHO; return IF;}
^else		{ECHO; return ELSE;}
else		{ECHO; return ELSE;}
^do			{ECHO; return DO;}
do			{ECHO; return DO;}
^int 		{ECHO; return INT;}
int 		{ECHO; return INT;}
^endi 		{ECHO; return ENDI;}
endi 		{ECHO; return ENDI;}
^put 		{ECHO; return PUT;}
put 		{ECHO; return PUT;}
^prog 		{ECHO; return PROG;}
prog 		{ECHO; return PROG;}
^get 		{ECHO; return GET;}
get 		{ECHO; return GET;}
^real 		{ECHO; return REAL;}
real 		{ECHO; return REAL;}
^then 		{ECHO; return THEN;}
then 		{ECHO; return THEN;}
^var 		{ECHO; return VAR;}
var 		{ECHO; return VAR;}
^loop 		{ECHO; return LOOP;}
loop 		{ECHO; return LOOP;}
^endl 		{ECHO; return ENDL;}
endl 		{ECHO; return ENDL;}
^until 		{ECHO; return UNTIL;}
until 		{ECHO; return UNTIL;}
^endp 		{ECHO; return ENDP;}
endp 		{ECHO; return ENDP;}
^{num}		{ECHO; return NUMBER;}
{num}		{ECHO; return NUMBER;}
^{id}		{ECHO; return ID;}
{id}		{ECHO; return ID;}
^{ws}		{ECHO; }
{ws}		{ECHO;}

^"<="       {ECHO; return ASSIGNOP;}
"<="       {ECHO; return ASSIGNOP;}
^{relop}     {ECHO; return RELOP;}
{relop}     {ECHO; return RELOP;}
^{addop}     {ECHO; return ADDOP;}
{addop}     {ECHO; return ADDOP;}
^{mulop}     {ECHO; return MULOP;}
{mulop}     {ECHO; return MULOP;}
^{logop}     {ECHO; return LOGOP;}
{logop}     {ECHO; return LOGOP;}

^";"			{ECHO; return SEMICOL;}
";"			{ECHO; return SEMICOL;}
^":"			{ECHO; return COLON;}
":"			{ECHO; return COLON;}
^","			{ECHO; return COMA;}
","			{ECHO; return COMA;}
^"("			{ECHO; return LP;}
"("			{ECHO; return LP;}
^")"			{ECHO; return RP;}
")"			{ECHO; return RP;}
^\n        	{ECHO; lines++;}
\n        	{ECHO; lines++;}
"."			{ECHO; return DOT;}
.			{fprintf(yyout,"\nUnexpected character at line %d: %s\n",lines, yytext); return 0;}
%%

int yywrap()
{
	return 1;
}
