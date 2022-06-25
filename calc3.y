%{
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdarg.h>

#define LISTLEN 30
#define ERRCODE 0x8fffffff

void yyerror(char *s);
int insertToVar(char* id, int num);
int getVar(char* id);
void printVars();
typedef struct
{
  int val;
  char id[20];
}st;
extern int linenum;
st stList[LISTLEN];
int stPos = 0;
int ifCond = 0;
%}

typedef %union {
    int  num;                 /* integer value */
    char id[20];              /* symbol table id */
}STYPE;
#define YYSTYPE STYPE

%token <num> INTEGER
%token <id> VARIABLE
%token PRINT IF


%left GE LE EQ NE '>' '<'
%left '+' '-'
%left '*' '/'
%right UMINUS

%type <num> stmt expr stmt_list

%%

program:
        function                { exit(0); }
        ;

function:
          function stmt
        | /* NULL */
        ;

stmt:     expr ';'
        | PRINT expr ';'                 { if(!ifCond){ printf("%d\n",$2);} }
        | '{' stmt_list '}'              { if(!ifCond){ $$ = $2;}}   
        | VARIABLE '=' expr ';'          { if(!ifCond){ insertToVar($1, $3);} 
		| IF '(' expr ')' {ifCond++} stmt  {ifCond--; $$ = 0; }
        ;

stmt_list:
          stmt                  { $$ = $1; }
        | stmt_list stmt        
        ;

expr:
          INTEGER               { $$ = $1; }
        | VARIABLE              { $$ = getVar($1); }
        | '-' expr %prec UMINUS { $$ = -$2; }
        | expr '+' expr         { $$ = $1 +  $3; }
        | expr '-' expr         { $$ = $1 -  $3; }
        | expr '*' expr         { $$ = $1 *  $3; }
        | expr '/' expr         { $$ = $1 /  $3; }
        | expr '<' expr         { $$ = $1 <  $3; }
        | expr '>' expr         { $$ = $1 >  $3; }
        | expr GE expr          { $$ = $1 >= $3; }
        | expr LE expr          { $$ = $1 <= $3; }
        | expr NE expr          { $$ = $1 != $3; }
        | expr EQ expr          { $$ = $1 == $3; }
        | '(' expr ')'          { $$ = $2; }
		| error                 { yyerror("ilegal expretion statment");} 
        ;

%%



void yyerror(char *s) {
    fprintf(stdout, "error in line: %d : %s\n", linenum, s);
}

int insertToVar(char* id, int num)
{
  int i;
  for( i = 0; i < stPos; i++)
    if(!strcmp( id, stList[i].id)){
      stList[i].val = num;
      return 0;
    }
  if(stPos < LISTLEN){
    strcpy(stList[stPos].id, id);
    stList[stPos++].val = num;
    return 0;
  }
  return ERRCODE;
}

int getVar(char* id)
{
  int i;
  for( i = 0; i < stPos; i++){
    if(!strcmp(stList[i].id, id))
      return stList[i].val ;
  }
  return ERRCODE;
} 

void printVars()
{
  int i;
  for(i=0; i<stPos ; i++){
    printf("%s:  %d\n",stList[i].id,stList[i].val);
  }
}

int main(void) {
    yyparse();
    return 0;
}
