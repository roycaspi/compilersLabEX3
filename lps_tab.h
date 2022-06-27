typedef union {
    _ID id;
    _NUM num;
    char op[6];
} YYSTYPE;
#define	DOT	258
#define	COMA	259
#define	LP	260
#define	RP	261
#define	COLON	262
#define	SEMICOL	263
#define	WS	264
#define	WHILE	265
#define	IF	266
#define	ELSE	267
#define	START	268
#define	DO	269
#define	INT	270
#define	ENDI	271
#define	ENDP	272
#define	PUT	273
#define	PROG	274
#define	GET	275
#define	REAL	276
#define	LOOP	277
#define	THEN	278
#define	VAR	279
#define	ENDL	280
#define	UNTIL	281
#define	NUMBER	282
#define	ID	283
#define	RELOP	284
#define	LT	285
#define	GT	286
#define	NE	287
#define	EQ	288
#define	ADDOP	289
#define	MULOP	290
#define	ASSIGNOP	291
#define	LOGOP	292


extern YYSTYPE yylval;
