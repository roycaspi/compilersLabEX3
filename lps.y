%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

logop(YYSTYPE val1, char* op, YYSTYPE val2);
relop(YYSTYPE val1, char* op, YYSTYPE val2);
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
	char type[4];
	int integerVal;
	float floatVal;
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
    bool boolean;
}

%token 		DOT COMA LP RP COLON SEMICOL WS WHILE IF ELSE START DO INT ENDI ENDP PUT PROG GET REAL LOOP THEN VAR ENDL UNTIL
%token <num>	NUMBER 			// all tokens with num value
%token <id> 	ID			// id values
%token <op> 	RELOP LT GT NE EQ	// operations

%left ADDOP MULOP
%right ASSIGNOP LOGOP

%type <op> type
%type <boolean> boolExp
%type <num> factor expression term

%%
program: PROG ID SEMICOL declarations START stmtList ENDP DOT {return 0;}
	| PROG ID SEMICOL declarations START stmtList ENDP error {ourError(". is missing after ENDP");}
	| PROG ID SEMICOL declarations START stmtList error {ourError("'Endp' is missing after statements ");}
	| PROG ID SEMICOL declarations error {ourError("'Start' is missing after variable declarations ");}
	| PROG ID error  {ourError("Program should end with ';'");}
	| PROG error  {ourError("invalid program ID name");}
	| error  {ourError("Program should start with prog");}
;
//fixDotIssue:  DOT
//             | error {ourError(". is missing after ENDP");}
//;
//programStart: 	PROG ID SEMICOL
//		| PROG ID error  {ourError("Program should end with ';'");}
//		| PROG error  {ourError("invalid program ID name");}
//		| error  {ourError("Program should start with prog");}
//;
declarations: 	VAR declList SEMICOL
		| VAR declList error  {ourError("declerations list should end with ';'");}
		| error  {ourError("declerations list should start with 'var' ");}
;
declList: 	declList COMA ID COLON type {addToList($3);}
		| declList COMA ID error  {ourError("between variable ID name and type should come ':'");}
		| declList COMA error  {ourError("invalid variable id name");}
		| declList error  {ourError("variables should be split by ','");}
		| ID COLON type {addToList($1);}
		| ID error {ourError("between variable ID name and type should come ':'");}
		| error {ourError("invalid variable id name");}
;
type:	INT {$$ = $<op>1;}
	|  REAL {$$ = $<op>1;}
	| error  {ourError("Type should be 'int' or 'real'");}
;
stmtList: 	statement SEMICOL stmtList
		| statement error {ourError("';' is missing");}
		| /* empty string */
;
statement: 	ID ASSIGNOP expression {assign($1, $3);}
		| ID error {ourError("invalid assign operator");}
		| PUT expression {put($2);}
		| GET ID {get($2);}
		| GET error {ourError("invalid ID name");}
		| IF boolExp THEN stmtList ELSE stmtList ENDI
		| IF boolExp THEN stmtList ELSE stmtList error {ourError("invalid if statement, should end with 'ENDI'");}
		| IF boolExp THEN stmtList ENDI
		| IF boolExp THEN stmtList error {ourError("invalid if statement, should end with 'ENDI'");}
		| IF boolExp error {ourError("invalid if statement, bolean expression should end with 'THEN'");}
		| LOOP boolExp DO stmtList ENDL
		| LOOP boolExp DO stmtList error {ourError("invalid loop statement, should end with 'ENDL'");}
		| LOOP boolExp error {ourError("invalid loop statement, bolean expression should end with 'DO'");}
		| DO stmtList UNTIL boolExp ENDL
		| DO stmtList UNTIL boolExp error {ourError("invalid do statement, should end with 'ENDL'");}
		| DO stmtList error {ourError("invalid do statement, missing 'UNTIL'");}
;
boolExp: expression RELOP expression {$$ = relop($1,$<op>2,$3);}
	| expression LOGOP expression {$$ = logop($1,$<op>2,$3);}
	| expression error {ourError("invalid boolExp");}
;

expression: 	expression ADDOP term {$$ = addop($1,$<op>2,$3);}
		| term {$$ = $1;}
;
term: 	term MULOP factor {$$ = mulop($1,$<op>2,$3);}
	| factor {$$ = $1;}
;
factor: ID {Node* temp = find(getId($1)); $$ = temp? temp.val:ourError("invalid ID name"); }
	|  NUMBER { $$ = getNumber($1); }
	|  '('expression')' {$$ = $2;}
	| '('expression error { ourError("missing ')'");}
	| error { ourError("invalid factor");}
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
	newId.length = strlen(id);
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
    	if(!(strcmp(curr->id.val, existingID)) {
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
		(!strcmp(temp->val.type, "INT"))?print("%d", temp->integerVal.val): print("%d", temp->floatVal.val);
	}
}
void get(char* id){
	Node* temp = find(id);
	if(temp==NULL){
		ourError("%s does not exist", id)};
	}
	else{
		((!strcmp(temp->type, "INT")))? temp->val.integerVal = 1: temp->val.floatVal = 1.0;
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
bool relop(char* val1, char* op, char* val2) {
	float num1 = isInteger(val1)? (float)atoi(val1):atof(val1);
	float num2 = isInteger(val2)? (float)atoi(val2):atof(val2);
	if(!strcmp(op, '='){
		return (num1 == num2);
	}
	else if(!strcmp(op, "<>"){
		return (num1 != num2);
	}
	else if(!strcmp(op, '>'){
		return (num1 > num2);
	}
	else if(!strcmp(op, '<'){
		return (num1 < num2);
	}
}
bool logop(char* val1, char* op, char* val2) {
	float num1 = isInteger(val1)? (float)atoi(val1):atof(val1);
	float num2 = isInteger(val2)? (float)atoi(val2):atof(val2);
	if(!strcmp(op, '&'){
		return (num1 && num2);
	}
	else if(!strcmp(op, '~'){
		return !(num1 && num2);
	}
	else if(!strcmp(op, '!'){
		return (num1 || num2);
	}
}
_NUM addop(char* val1, char* op, char* val2) {
	_NUM result;
	float num1 = atof(val1);
	float num2 = atof(val2);
	result.type = "REAL";
	result.floatVal = (!strcmp(op, '+'))? num1 + num2: num1 - num2;
	return result;
}
_NUM mulop(char* val1, char* op, char* val2) {
	_NUM result;
	float num1 = atof(val1);
	float num2 = atof(val2);
	result.type = "REAL";
	result.floatVal = (!strcmp(op, '*'))? num1 * num2: (!strcmp(op, '/'))?num1 / num2: num1 % num2;
	return result;
}




