%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>

_ID getId(char* id);
_NUM getNumber(char* num);
void addToList(char *newID);
bool updateListInt(char *existingID, float val);
bool updateListFloat(char *existingID, float val);
bool isInteger(char* num);
Node* find(char* id);
void put(char* id);
void get(char* id);
void assign(char* id, char* exp);
char* getOutputFileName(char* fileName, char* extension);
int yyerror(char* s);
void ourError(char* s);
int yylex();
extern FILE *yyin;
extern FILE *yyout;
extern int lines;
extern char *yytext;
typedef struct {
	int length;
	char val[20];
} _ID
typedef struct {
	char* type = "INT";
	int val;
} _INT;
typedef struct {
	char* type = "REAL";
	float val;
} _REAL;
union {
	char type[4];
	_INT integerVal;
	_REAL floatVal;
}_NUM;
typedef struct {
    _ID id;
    _NUM val;
    struct Node* next;
}Node;

Node* head = NULL;
%}

%union {
    _ID id;
    _NUM num;
    char op[6];
}

%token 		DOT COMA LP RP COLON SEMICOL WS WHILE IF ELSE START DO INT ENDI ENDP PUT PROG GET REAL LOOP THEN VAR ENDL UNTIL
%token <num>	NUMBER 			// all tokens with num value
%token <id> 	ID			// id values
%token <op> 	RELOP LT GT NE EQ	// operations

%left ADDOP MULOP
%right ASSIGNOP LOGOP

%type <op> boolExp statement expression term factor type

%%
program: programStart declarations START error {ourError("'Start' is missing after variable declarations ");} stmtList ENDP error {ourError("Endp is missing after after statements ");} fixDotIssue {return 0;}
	| error {ourError("Error in program");}
;
fixDotIssue:  DOT
             | error {ourError(". is missing after ENDP");}
;
programStart: PROG ID SEMICOL
	| error  {ourError("Program should start with prog ID ;");}
;
declarations: VAR declList SEMICOL
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
stmtList: statement SEMICOL | error {ourError("';' is missing");} stmtList
			| /* empty string */
			| error {ourError("stmtList is invalid, each statment must end with ';' ");}
;
statement: ID ASSIGNOP expression {assign($1, $3)}
			| PUT expression {put($2)}
			| GET ID {get($2)}
			| IF boolExp THEN stmtList ELSE stmtList ENDI
			| IF boolExp THEN stmtList  ENDI
			| LOOP boolExp DO stmtList ENDL
			| DO stmtList UNTIL boolExp ENDL
			| error {ourError("invalid statement\n");}
;
boolExp: expression case expression
	| expression '<' expression {$$ = $1 < $3;}
	| expression '>' expression {$$ = $1 < $3;}
	| expression '<>' expression {$$ = $1 != $3;}
	| expression '&' expression {$$ = $1 && $3;}
	| expression '~' expression {$$ = $1 == $3;} //don't understand what ~ means
	| expression '!' expression {$$ = $1 || $3;}
;
case: RELOP 
	| LOGOP
;
expression: 	expression '+' term {$$ = $1 + $3;}
		|  expression '-' term {$$ = $1 - $3;}
		|  term
;
term: 	term '*' factor {$$ = $1 * $3;}
 	| term '/' factor {$$ = $1 / $3}
 	| term 'mod' factor {$$ = $1 % $3}
	| factor {$$ = $2;}
;
factor: ID {$$ = getId($1); }
		|  NUMBER { $$ = getNumber($1); }
	|  '('expression')' {$$ = $2;}
	| error                 { ourError("");}
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

_NUM getNumber(char* num) {
	_NUM n;
	if(!isInteger(num)) {
	    n.type = "REAL"
	    n.floatVal = atof($1);
	    return n;
	}
	n.type = "INT"
	n.intVal = atoi($1);
	return n;
}

_ID getId(char* id) {
	_ID newId;
	id.length = strlen(id);
	newId.val = id;
	return newId;
}

void addToList(char *newID) {
    Node* curr = head;
    while (curr != NULL) {
        curr = curr->next
    }
    curr = (struct Node*)malloc(sizeof(struct Node));
    curr->id->val = newID;
    curr->id->length = strlen(newID);
}

bool updateListInt(char *existingID, int val) { //returns false if id doesn't exist in list
    Node* curr = head;
    while (curr != NULL) {
    	if(strcmp(curr->id.val, existingID) {
    		curr->val.integerVal = val;
    	}
        curr = curr->next
        return true;
    }
    return false;
}

bool updateListFloat(char *existingID, float val) {
    Node* curr = head;
    while (curr != NULL) {
    	if(strcmp(curr->id.val, existingID) {
    		curr->val.floatVal = val;
    	}
        curr = curr->next
        return true;
    }
    return false;
}
bool isInteger(char* num) {
	for(int i = 0; i < strlen(num); i++) { //check if integer or float
		if(num[i] == '.'){
		    return false;
		}
        }
        return true;
}
Node* find(char* id){
	Node* curr = head;
	while (curr != NULL) {
		if(strcmp(curr->id.val, id) {
			return curr;
		}
		curr = curr->next
    	}
    	return NULL;
}
void put(char* id){
	Node* temp = find(id);
	if(temp==NULL){
		ourError("%s does not exist", id)};
	}
	else{
		(strcmp(temp->val.type, "INT"))?print("%d", temp->integerVal.val): print("%d", temp->floatVal.val);
	}
}
void get(char* id){
	Node* temp = find(id);
	if(temp==NULL){
		ourError("%s does not exist", id)};
	}
	else{
		strcmp(temp->type == "INT")? temp->val.integerVal = 1: temp->val.floatVal = 1.0;
	}
}
void assign(char* id, char* exp){
	if(isInteger(exp)){
		if(!updateListInt(id,exp)){
			ourError("%s already exists, id")
		}
	}else
	{
		if(!updateListFloat(id,exp))
		{
			ourError("%s already exists, id")
		}
	}
}




