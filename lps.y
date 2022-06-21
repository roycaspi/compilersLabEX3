%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

char* getOutputFileName(char* fileName, char* extension);
int yyerror(char* s);
void ourError(char* s);
int yylex();
extern FILE *yyin;
extern FILE *yyout;
extern int lines;
extern char *yytext;
%}

%token DOT COMA LP RP COLON SEMICOL NUMBER ID WS RELOP WHILE IF ELSE START DO INT ENDI ENDP PUT PROG GET REAL LOOP THEN VAR ENDL UNTIL LT GT NE EQ
%left ADDOP MULOP
%right ASSIGNOP LOGOP

%%
program: programStart declarations START stmtList ENDP fixDotIssue {return 0;}
| error {ourError("Error in program");}
;
fixDotIssue:  DOT
             | error {ourError("Could not find DOT after ENDP");}
;
programStart: PROG ID SEMICOL
| error  {ourError("Program should start with 'prog ID ;'");}
;
declarations: VAR declList SEMICOL  {}
| error  {ourError("Declerations list should start with 'var' and end with ';'");}
;
declList: declList COMA ID COLON type
			| ID COLON type
| error  {ourError("Each declaration should be in format ID:Type (seperated with ',')");}
;
type:  INT  
	|  REAL 
| error  {ourError("Type should be 'int' or 'real'");}
;
stmtList: statement SEMICOL stmtList
			| /* empty string */
			| error {ourError("stmtList is invalid, each statment must end with ';' ");}
;
statement: ID ASSIGNOP expression
			| PUT expression
			| GET ID
			| IF boolExp THEN stmtList ELSE stmtList ENDI
			| IF boolExp THEN stmtList  ENDI
			| LOOP boolExp DO stmtList ENDL
			| DO stmtList UNTIL boolExp ENDL
			| error {ourError("invalid statement\n");}
;
boolExp: expression case expression
;
case: RELOP 
	| LOGOP
;
expression: expression ADDOP term  
		|  term
;
term: term MULOP factor 
		| factor
;
factor: ID
	|  NUMBER
	|  '('expression')'
;

%%
int yyerror(char *errorMsg) {
	fprintf(yyout, "%s\n", errorMsg);
	fprintf(stderr, "%s\n", errorMsg);  /* Debug Mode. TODO: Remove*/
	return 0;
}

int main(int argc, char* argv[]){
	if(argc > 1){
        	yyin = fopen(argv[1],"r");
        	if(!yyin){
        		printf("Failed to open file %s", argv[1]);
        		return 1;
        	}
          }
          else{
        	  printf("Missing argument: input file name");
        	  return 1;
          }

        char* LSToutputFileName = getOutputFileName(argv[1], ".lst");
        yyout = fopen(LSToutputFileName, "w");
	char* outputFileName = getOutputFileName(argv[1], ".lst");
	yyparse()? printf("Failure"): printf("Success");
	return 0;
}

void ourError(char *errorMsg) {
	fprintf(yyout, "Line: %d\t", lines);
	fprintf(stderr, "Line: %d\t", lines);
	yyerror(errorMsg);
	exit(1);
}

char* getOutputFileName(char* fileName, char* extension){
    char* dotPos = strstr(fileName, ".sle");
	if(!dotPos || *(dotPos+4)!=0){
		printf("Wrong argument. file name must end with '.sle'");
		exit(1);
	}
	char* outputName = (char*)calloc(strlen(fileName), 1);
	char* outputNameRunner = outputName;
	char* runnerPointer = fileName;

    	// copy basename
	while(runnerPointer != dotPos) *outputNameRunner++ = *runnerPointer++;
	// add extension
	while(*extension != 0) *outputNameRunner++ = *extension++;
	*outputNameRunner = 0;
	return outputName;
}




