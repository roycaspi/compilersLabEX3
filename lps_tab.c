
/*  A Bison parser, made from lps.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

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

#line 1 "lps.y"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>

typedef struct {
	int length;
	char val[20];
} _ID;
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
logop(char* val1, char* op, char* val2);
relop(char* val1, char* op, char* val2);
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


#line 47 "lps.y"
typedef union {
    _ID id;
    _NUM num;
    char op[6];
    bool boolean;
} YYSTYPE;

#ifndef YYLTYPE
typedef
  struct yyltype
    {
      int timestamp;
      int first_line;
      int first_column;
      int last_line;
      int last_column;
      char *text;
   }
  yyltype;

#define YYLTYPE yyltype
#endif

#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		93
#define	YYFLAG		-32768
#define	YYNTBASE	40

#define YYTRANSLATE(x) ((unsigned)(x) <= 292 ? yytranslate[x] : 50)

static const char yytranslate[] = {     0,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,    38,
    39,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     9,    18,    26,    32,    36,    39,    41,    45,    49,
    51,    57,    62,    66,    70,    73,    75,    77,    79,    81,
    85,    88,    89,    93,    96,    99,   102,   105,   113,   121,
   127,   133,   137,   143,   149,   153,   159,   165,   169,   173,
   177,   180,   184,   186,   190,   192,   194,   196,   200,   204
};

static const short yyrhs[] = {    19,
    28,     8,    41,    13,    44,    17,     3,     0,    19,    28,
     8,    41,    13,    44,    17,     1,     0,    19,    28,     8,
    41,    13,    44,     1,     0,    19,    28,     8,    41,     1,
     0,    19,    28,     1,     0,    19,     1,     0,     1,     0,
    24,    42,     8,     0,    24,    42,     1,     0,     1,     0,
    42,     4,    28,     7,    43,     0,    42,     4,    28,     1,
     0,    42,     4,     1,     0,    28,     7,    43,     0,    28,
     1,     0,     1,     0,    15,     0,    21,     0,     1,     0,
    45,     8,    44,     0,    45,     1,     0,     0,    28,    36,
    47,     0,    28,     1,     0,    18,    47,     0,    20,    28,
     0,    20,     1,     0,    11,    46,    23,    44,    12,    44,
    16,     0,    11,    46,    23,    44,    12,    44,     1,     0,
    11,    46,    23,    44,    16,     0,    11,    46,    23,    44,
     1,     0,    11,    46,     1,     0,    22,    46,    14,    44,
    25,     0,    22,    46,    14,    44,     1,     0,    22,    46,
     1,     0,    14,    44,    26,    46,    25,     0,    14,    44,
    26,    46,     1,     0,    14,    44,     1,     0,    47,    29,
    47,     0,    47,    37,    47,     0,    47,     1,     0,    47,
    34,    48,     0,    48,     0,    48,    35,    49,     0,    49,
     0,    28,     0,    27,     0,    38,    47,    39,     0,    38,
    47,     1,     0,     1,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    67,    68,    69,    70,    71,    72,    73,    83,    84,    85,
    87,    88,    89,    91,    92,    93,    95,    96,    97,    99,
   100,   101,   103,   104,   105,   106,   107,   108,   109,   110,
   111,   112,   113,   114,   115,   116,   117,   118,   120,   121,
   122,   125,   126,   128,   129,   131,   132,   133,   134,   135
};

static const char * const yytname[] = {   "$","error","$undefined.","DOT","COMA",
"LP","RP","COLON","SEMICOL","WS","WHILE","IF","ELSE","START","DO","INT","ENDI",
"ENDP","PUT","PROG","GET","REAL","LOOP","THEN","VAR","ENDL","UNTIL","NUMBER",
"ID","RELOP","LT","GT","NE","EQ","ADDOP","MULOP","ASSIGNOP","LOGOP","'('","')'",
"program","declarations","declList","type","stmtList","statement","boolExp",
"expression","term","factor",""
};
#endif

static const short yyr1[] = {     0,
    40,    40,    40,    40,    40,    40,    40,    41,    41,    41,
    42,    42,    42,    42,    42,    42,    43,    43,    43,    44,
    44,    44,    45,    45,    45,    45,    45,    45,    45,    45,
    45,    45,    45,    45,    45,    45,    45,    45,    46,    46,
    46,    47,    47,    48,    48,    49,    49,    49,    49,    49
};

static const short yyr2[] = {     0,
     8,     8,     7,     5,     3,     2,     1,     3,     3,     1,
     5,     4,     3,     3,     2,     1,     1,     1,     1,     3,
     2,     0,     3,     2,     2,     2,     2,     7,     7,     5,
     5,     3,     5,     5,     3,     5,     5,     3,     3,     3,
     2,     3,     1,     3,     1,     1,     1,     3,     3,     1
};

static const short yydefact[] = {     0,
     7,     0,     6,     0,     5,     0,    10,     0,     0,    16,
     0,     0,     4,    22,    15,     0,     9,     0,     8,     0,
    22,     0,     0,     0,     0,     0,     0,    19,    17,    18,
    14,    13,     0,    50,    47,    46,     0,     0,     0,    43,
    45,     0,    25,    27,    26,     0,    24,     0,     3,     0,
    21,    22,    12,     0,     0,    32,    22,    41,     0,     0,
     0,     0,    38,     0,    35,    22,    23,     2,     1,    20,
    11,    49,    48,     0,    39,    42,    40,    44,     0,     0,
    31,    22,    30,    37,    36,    34,    33,     0,    29,    28,
     0,     0,     0
};

static const short yydefgoto[] = {    91,
     9,    12,    31,    26,    27,    38,    39,    40,    41
};

static const short yypact[] = {    53,
-32768,     7,-32768,    67,-32768,     8,-32768,    11,    10,-32768,
    56,    12,-32768,    42,-32768,    50,-32768,    20,-32768,     6,
    42,     6,    21,     6,     1,     9,    75,-32768,-32768,-32768,
-32768,-32768,    77,-32768,-32768,-32768,     6,    23,    18,    31,
-32768,    24,    33,-32768,-32768,    13,-32768,     6,-32768,    14,
-32768,    42,-32768,    50,     4,-32768,    42,-32768,     6,     6,
     6,     6,-32768,     6,-32768,    42,    33,-32768,-32768,-32768,
-32768,-32768,-32768,    57,    33,    31,    33,-32768,     3,     5,
-32768,    42,-32768,-32768,-32768,-32768,-32768,    58,-32768,-32768,
    79,    80,-32768
};

static const short yypgoto[] = {-32768,
-32768,-32768,    27,   -21,-32768,   -23,   -19,    17,    25
};


#define	YYLAST		87


static const short yytable[] = {    42,
    46,    47,    43,    84,    72,    86,    34,     3,     7,    49,
    13,    10,    17,    65,    68,    18,    69,    55,    58,    19,
    32,    44,    14,    56,    63,    50,    66,    85,    67,    87,
    70,     8,    35,    36,     4,    74,    48,    60,    11,    75,
    79,    77,    73,    37,    80,    57,    59,    33,    45,    64,
    28,    60,    20,     1,    61,    21,    15,    81,    89,    22,
    88,    23,    16,    24,    29,    62,    60,     5,    82,    25,
    30,     2,    83,    90,     6,    51,    76,    53,    92,    93,
    71,     0,    52,    54,     0,     0,    78
};

static const short yycheck[] = {    21,
    24,     1,    22,     1,     1,     1,     1,     1,     1,     1,
     1,     1,     1,     1,     1,     4,     3,    37,     1,     8,
     1,     1,    13,     1,     1,    17,    14,    25,    48,    25,
    52,    24,    27,    28,    28,    57,    36,    34,    28,    59,
    64,    61,    39,    38,    66,    23,    29,    28,    28,    26,
     1,    34,    11,     1,    37,    14,     1,     1,     1,    18,
    82,    20,     7,    22,    15,    35,    34,     1,    12,    28,
    21,    19,    16,    16,     8,     1,    60,     1,     0,     0,
    54,    -1,     8,     7,    -1,    -1,    62
};
/* -*-C-*-  Note some compilers choke on comments on `#line' lines.  */
#line 3 "bison.simple"

/* Skeleton output parser for bison,
   Copyright (C) 1984, 1989, 1990 Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */

/* As a special exception, when this file is copied by Bison into a
   Bison output file, you may use that output file without restriction.
   This special exception was added by the Free Software Foundation
   in version 1.24 of Bison.  */

#ifndef alloca
#ifdef __GNUC__
#define alloca __builtin_alloca
#else /* not GNU C.  */
#if (!defined (__STDC__) && defined (sparc)) || defined (__sparc__) || defined (__sparc) || defined (__sgi)
#include <alloca.h>
#else /* not sparc */
#if defined (MSDOS) && !defined (__TURBOC__)
#include <malloc.h>
#else /* not MSDOS, or __TURBOC__ */
#if defined(_AIX)
#include <malloc.h>
 #pragma alloca
#else /* not MSDOS, __TURBOC__, or _AIX */
#ifdef __hpux
#ifdef __cplusplus
extern "C" {
void *alloca (unsigned int);
};
#else /* not __cplusplus */
void *alloca ();
#endif /* not __cplusplus */
#endif /* __hpux */
#endif /* not _AIX */
#endif /* not MSDOS, or __TURBOC__ */
#endif /* not sparc.  */
#endif /* not GNU C.  */
#endif /* alloca not defined.  */

/* This is the parser code that is written into each bison parser
  when the %semantic_parser declaration is not specified in the grammar.
  It was written by Richard Stallman by simplifying the hairy parser
  used when %semantic_parser is specified.  */

/* Note: there must be only one dollar sign in this file.
   It is replaced by the list of actions, each action
   as one case of the switch.  */

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		-2
#define YYEOF		0
#define YYACCEPT	return(0)
#define YYABORT 	return(1)
#define YYERROR		goto yyerrlab1
/* Like YYERROR except do call yyerror.
   This remains here temporarily to ease the
   transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */
#define YYFAIL		goto yyerrlab
#define YYRECOVERING()  (!!yyerrstatus)
#define YYBACKUP(token, value) \
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    { yychar = (token), yylval = (value);			\
      yychar1 = YYTRANSLATE (yychar);				\
      YYPOPSTACK;						\
      goto yybackup;						\
    }								\
  else								\
    { yyerror ("syntax error: cannot back up"); YYERROR; }	\
while (0)

#define YYTERROR	1
#define YYERRCODE	256

#ifndef YYPURE
#define YYLEX		yylex()
#endif

#ifdef YYPURE
#ifdef YYLSP_NEEDED
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, &yylloc, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval, &yylloc)
#endif
#else /* not YYLSP_NEEDED */
#ifdef YYLEX_PARAM
#define YYLEX		yylex(&yylval, YYLEX_PARAM)
#else
#define YYLEX		yylex(&yylval)
#endif
#endif /* not YYLSP_NEEDED */
#endif

/* If nonreentrant, generate the variables here */

#ifndef YYPURE

int	yychar;			/*  the lookahead symbol		*/
YYSTYPE	yylval;			/*  the semantic value of the		*/
				/*  lookahead symbol			*/

#ifdef YYLSP_NEEDED
YYLTYPE yylloc;			/*  location data for the lookahead	*/
				/*  symbol				*/
#endif

int yynerrs;			/*  number of parse errors so far       */
#endif  /* not YYPURE */

#if YYDEBUG != 0
int yydebug;			/*  nonzero means print parse trace	*/
/* Since this is uninitialized, it does not stop multiple parsers
   from coexisting.  */
#endif

/*  YYINITDEPTH indicates the initial size of the parser's stacks	*/

#ifndef	YYINITDEPTH
#define YYINITDEPTH 200
#endif

/*  YYMAXDEPTH is the maximum size the stacks can grow to
    (effective only if the built-in stack extension method is used).  */

#if YYMAXDEPTH == 0
#undef YYMAXDEPTH
#endif

#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif

/* Prevent warning if -Wstrict-prototypes.  */
#ifdef __GNUC__
int yyparse (void);
#endif

#if __GNUC__ > 1		/* GNU C and GNU C++ define this.  */
#define __yy_memcpy(FROM,TO,COUNT)	__builtin_memcpy(TO,FROM,COUNT)
#else				/* not GNU C or C++ */
#ifndef __cplusplus

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (from, to, count)
     char *from;
     char *to;
     int count;
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#else /* __cplusplus */

/* This is the most reliable way to avoid incompatibilities
   in available built-in functions on various systems.  */
static void
__yy_memcpy (char *from, char *to, int count)
{
  register char *f = from;
  register char *t = to;
  register int i = count;

  while (i-- > 0)
    *t++ = *f++;
}

#endif
#endif

#line 192 "bison.simple"

/* The user can define YYPARSE_PARAM as the name of an argument to be passed
   into yyparse.  The argument should have type void *.
   It should actually point to an object.
   Grammar actions can access the variable by casting it
   to the proper pointer type.  */

#ifdef YYPARSE_PARAM
#define YYPARSE_PARAM_DECL void *YYPARSE_PARAM;
#else
#define YYPARSE_PARAM
#define YYPARSE_PARAM_DECL
#endif

int
yyparse(YYPARSE_PARAM)
     YYPARSE_PARAM_DECL
{
  register int yystate;
  register int yyn;
  register short *yyssp;
  register YYSTYPE *yyvsp;
  int yyerrstatus;	/*  number of tokens to shift before error messages enabled */
  int yychar1 = 0;		/*  lookahead token as an internal (translated) token number */

  short	yyssa[YYINITDEPTH];	/*  the state stack			*/
  YYSTYPE yyvsa[YYINITDEPTH];	/*  the semantic value stack		*/

  short *yyss = yyssa;		/*  refer to the stacks thru separate pointers */
  YYSTYPE *yyvs = yyvsa;	/*  to allow yyoverflow to reallocate them elsewhere */

#ifdef YYLSP_NEEDED
  YYLTYPE yylsa[YYINITDEPTH];	/*  the location stack			*/
  YYLTYPE *yyls = yylsa;
  YYLTYPE *yylsp;

#define YYPOPSTACK   (yyvsp--, yyssp--, yylsp--)
#else
#define YYPOPSTACK   (yyvsp--, yyssp--)
#endif

  int yystacksize = YYINITDEPTH;

#ifdef YYPURE
  int yychar;
  YYSTYPE yylval;
  int yynerrs;
#ifdef YYLSP_NEEDED
  YYLTYPE yylloc;
#endif
#endif

  YYSTYPE yyval;		/*  the variable used to return		*/
				/*  semantic values from the action	*/
				/*  routines				*/

  int yylen;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Starting parse\n");
#endif

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss - 1;
  yyvsp = yyvs;
#ifdef YYLSP_NEEDED
  yylsp = yyls;
#endif

/* Push a new state, which is found in  yystate  .  */
/* In all cases, when you get here, the value and location stacks
   have just been pushed. so pushing a state here evens the stacks.  */
yynewstate:

  *++yyssp = yystate;

  if (yyssp >= yyss + yystacksize - 1)
    {
      /* Give user a chance to reallocate the stack */
      /* Use copies of these so that the &'s don't force the real ones into memory. */
      YYSTYPE *yyvs1 = yyvs;
      short *yyss1 = yyss;
#ifdef YYLSP_NEEDED
      YYLTYPE *yyls1 = yyls;
#endif

      /* Get the current used size of the three stacks, in elements.  */
      int size = yyssp - yyss + 1;

#ifdef yyoverflow
      /* Each stack pointer address is followed by the size of
	 the data in use in that stack, in bytes.  */
#ifdef YYLSP_NEEDED
      /* This used to be a conditional around just the two extra args,
	 but that might be undefined if yyoverflow is a macro.  */
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yyls1, size * sizeof (*yylsp),
		 &yystacksize);
#else
      yyoverflow("parser stack overflow",
		 &yyss1, size * sizeof (*yyssp),
		 &yyvs1, size * sizeof (*yyvsp),
		 &yystacksize);
#endif

      yyss = yyss1; yyvs = yyvs1;
#ifdef YYLSP_NEEDED
      yyls = yyls1;
#endif
#else /* no yyoverflow */
      /* Extend the stack our own way.  */
      if (yystacksize >= YYMAXDEPTH)
	{
	  yyerror("parser stack overflow");
	  return 2;
	}
      yystacksize *= 2;
      if (yystacksize > YYMAXDEPTH)
	yystacksize = YYMAXDEPTH;
      yyss = (short *) alloca (yystacksize * sizeof (*yyssp));
      __yy_memcpy ((char *)yyss1, (char *)yyss, size * sizeof (*yyssp));
      yyvs = (YYSTYPE *) alloca (yystacksize * sizeof (*yyvsp));
      __yy_memcpy ((char *)yyvs1, (char *)yyvs, size * sizeof (*yyvsp));
#ifdef YYLSP_NEEDED
      yyls = (YYLTYPE *) alloca (yystacksize * sizeof (*yylsp));
      __yy_memcpy ((char *)yyls1, (char *)yyls, size * sizeof (*yylsp));
#endif
#endif /* no yyoverflow */

      yyssp = yyss + size - 1;
      yyvsp = yyvs + size - 1;
#ifdef YYLSP_NEEDED
      yylsp = yyls + size - 1;
#endif

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Stack size increased to %d\n", yystacksize);
#endif

      if (yyssp >= yyss + yystacksize - 1)
	YYABORT;
    }

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Entering state %d\n", yystate);
#endif

  goto yybackup;
 yybackup:

/* Do appropriate processing given the current state.  */
/* Read a lookahead token if we need one and don't already have one.  */
/* yyresume: */

  /* First try to decide what to do without reference to lookahead token.  */

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* yychar is either YYEMPTY or YYEOF
     or a valid token in external form.  */

  if (yychar == YYEMPTY)
    {
#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Reading a token: ");
#endif
      yychar = YYLEX;
    }

  /* Convert token to internal form (in yychar1) for indexing tables with */

  if (yychar <= 0)		/* This means end of input. */
    {
      yychar1 = 0;
      yychar = YYEOF;		/* Don't call YYLEX any more */

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Now at end of input.\n");
#endif
    }
  else
    {
      yychar1 = YYTRANSLATE(yychar);

#if YYDEBUG != 0
      if (yydebug)
	{
	  fprintf (stderr, "Next token is %d (%s", yychar, yytname[yychar1]);
	  /* Give the individual parser a way to print the precise meaning
	     of a token, for further debugging info.  */
#ifdef YYPRINT
	  YYPRINT (stderr, yychar, yylval);
#endif
	  fprintf (stderr, ")\n");
	}
#endif
    }

  yyn += yychar1;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != yychar1)
    goto yydefault;

  yyn = yytable[yyn];

  /* yyn is what to do for this token type in this state.
     Negative => reduce, -yyn is rule number.
     Positive => shift, yyn is new state.
       New state is final state => don't bother to shift,
       just return success.
     0, or most negative number => error.  */

  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrlab;

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Shift the lookahead token.  */

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting token %d (%s), ", yychar, yytname[yychar1]);
#endif

  /* Discard the token being shifted unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  /* count tokens shifted since error; after three, turn off error status.  */
  if (yyerrstatus) yyerrstatus--;

  yystate = yyn;
  goto yynewstate;

/* Do the default action for the current state.  */
yydefault:

  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;

/* Do a reduction.  yyn is the number of a rule to reduce with.  */
yyreduce:
  yylen = yyr2[yyn];
  if (yylen > 0)
    yyval = yyvsp[1-yylen]; /* implement default value of the action */

#if YYDEBUG != 0
  if (yydebug)
    {
      int i;

      fprintf (stderr, "Reducing via rule %d (line %d), ",
	       yyn, yyrline[yyn]);

      /* Print the symbols being reduced, and their result.  */
      for (i = yyprhs[yyn]; yyrhs[i] > 0; i++)
	fprintf (stderr, "%s ", yytname[yyrhs[i]]);
      fprintf (stderr, " -> %s\n", yytname[yyr1[yyn]]);
    }
#endif


  switch (yyn) {

case 1:
#line 67 "lps.y"
{return 0;;
    break;}
case 2:
#line 68 "lps.y"
{ourError(". is missing after ENDP");;
    break;}
case 3:
#line 69 "lps.y"
{ourError("'Endp' is missing after statements ");;
    break;}
case 4:
#line 70 "lps.y"
{ourError("'Start' is missing after variable declarations ");;
    break;}
case 5:
#line 71 "lps.y"
{ourError("Program should end with ';'");;
    break;}
case 6:
#line 72 "lps.y"
{ourError("invalid program ID name");;
    break;}
case 7:
#line 73 "lps.y"
{ourError("Program should start with prog");;
    break;}
case 9:
#line 84 "lps.y"
{ourError("declerations list should end with ';'");;
    break;}
case 10:
#line 85 "lps.y"
{ourError("declerations list should start with 'var' ");;
    break;}
case 11:
#line 87 "lps.y"
{addToList(yyvsp[-2].id);;
    break;}
case 12:
#line 88 "lps.y"
{ourError("between variable ID name and type should come ':'");;
    break;}
case 13:
#line 89 "lps.y"
{ourError("invalid variable id name");;
    break;}
case 14:
#line 91 "lps.y"
{addToList(yyvsp[-2].id);;
    break;}
case 15:
#line 92 "lps.y"
{ourError("between variable ID name and type should come ':'");;
    break;}
case 16:
#line 93 "lps.y"
{ourError("invalid variable id name");;
    break;}
case 17:
#line 95 "lps.y"
{yyval.op = yyvsp[0].op;;
    break;}
case 18:
#line 96 "lps.y"
{yyval.op = yyvsp[0].op;;
    break;}
case 19:
#line 97 "lps.y"
{ourError("Type should be 'int' or 'real'");;
    break;}
case 21:
#line 100 "lps.y"
{ourError("';' is missing");;
    break;}
case 23:
#line 103 "lps.y"
{assign(yyvsp[-2].id, yyvsp[0].num);;
    break;}
case 24:
#line 104 "lps.y"
{ourError("invalid assign operator");;
    break;}
case 25:
#line 105 "lps.y"
{put(yyvsp[0].num);;
    break;}
case 26:
#line 106 "lps.y"
{get(yyvsp[0].id);;
    break;}
case 27:
#line 107 "lps.y"
{ourError("invalid ID name");;
    break;}
case 29:
#line 109 "lps.y"
{ourError("invalid if statement, should end with 'ENDI'");;
    break;}
case 31:
#line 111 "lps.y"
{ourError("invalid if statement, should end with 'ENDI'");;
    break;}
case 32:
#line 112 "lps.y"
{ourError("invalid if statement, bolean expression should end with 'THEN'");;
    break;}
case 34:
#line 114 "lps.y"
{ourError("invalid loop statement, should end with 'ENDL'");;
    break;}
case 35:
#line 115 "lps.y"
{ourError("invalid loop statement, bolean expression should end with 'DO'");;
    break;}
case 37:
#line 117 "lps.y"
{ourError("invalid do statement, should end with 'ENDL'");;
    break;}
case 38:
#line 118 "lps.y"
{ourError("invalid do statement, missing 'UNTIL'");;
    break;}
case 39:
#line 120 "lps.y"
{yyval.boolean = relop(yyvsp[-2].num,yyvsp[-1].op,yyvsp[0].num);;
    break;}
case 40:
#line 121 "lps.y"
{yyval.boolean = logop(yyvsp[-2].num,yyvsp[-1].op,yyvsp[0].num);;
    break;}
case 41:
#line 122 "lps.y"
{ourError("invalid boolExp");;
    break;}
case 42:
#line 125 "lps.y"
{yyval.num = addop(yyvsp[-2].num,yyvsp[-1].op,yyvsp[0].num);;
    break;}
case 43:
#line 126 "lps.y"
{yyval.num = yyvsp[0].num;;
    break;}
case 44:
#line 128 "lps.y"
{yyval.num = mulop(yyvsp[-2].num,yyvsp[-1].op,yyvsp[0].num);;
    break;}
case 45:
#line 129 "lps.y"
{yyval.num = yyvsp[0].num;;
    break;}
case 46:
#line 131 "lps.y"
{Node* temp = find(getId(yyvsp[0].id)); yyval.num = temp? temp.val:ourError("invalid ID name"); ;
    break;}
case 47:
#line 132 "lps.y"
{ yyval.num = getNumber(yyvsp[0].num); ;
    break;}
case 48:
#line 133 "lps.y"
{yyval.num = yyvsp[-1].num;;
    break;}
case 49:
#line 134 "lps.y"
{ ourError("missing ')'");;
    break;}
case 50:
#line 135 "lps.y"
{ ourError("invalid factor");;
    break;}
}
   /* the action file gets copied in in place of this dollarsign */
#line 487 "bison.simple"

  yyvsp -= yylen;
  yyssp -= yylen;
#ifdef YYLSP_NEEDED
  yylsp -= yylen;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

  *++yyvsp = yyval;

#ifdef YYLSP_NEEDED
  yylsp++;
  if (yylen == 0)
    {
      yylsp->first_line = yylloc.first_line;
      yylsp->first_column = yylloc.first_column;
      yylsp->last_line = (yylsp-1)->last_line;
      yylsp->last_column = (yylsp-1)->last_column;
      yylsp->text = 0;
    }
  else
    {
      yylsp->last_line = (yylsp+yylen-1)->last_line;
      yylsp->last_column = (yylsp+yylen-1)->last_column;
    }
#endif

  /* Now "shift" the result of the reduction.
     Determine what state that goes to,
     based on the state we popped back to
     and the rule number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTBASE] + *yyssp;
  if (yystate >= 0 && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTBASE];

  goto yynewstate;

yyerrlab:   /* here on detecting error */

  if (! yyerrstatus)
    /* If not already recovering from an error, report this error.  */
    {
      ++yynerrs;

#ifdef YYERROR_VERBOSE
      yyn = yypact[yystate];

      if (yyn > YYFLAG && yyn < YYLAST)
	{
	  int size = 0;
	  char *msg;
	  int x, count;

	  count = 0;
	  /* Start X at -yyn if nec to avoid negative indexes in yycheck.  */
	  for (x = (yyn < 0 ? -yyn : 0);
	       x < (sizeof(yytname) / sizeof(char *)); x++)
	    if (yycheck[x + yyn] == x)
	      size += strlen(yytname[x]) + 15, count++;
	  msg = (char *) malloc(size + 15);
	  if (msg != 0)
	    {
	      strcpy(msg, "parse error");

	      if (count < 5)
		{
		  count = 0;
		  for (x = (yyn < 0 ? -yyn : 0);
		       x < (sizeof(yytname) / sizeof(char *)); x++)
		    if (yycheck[x + yyn] == x)
		      {
			strcat(msg, count == 0 ? ", expecting `" : " or `");
			strcat(msg, yytname[x]);
			strcat(msg, "'");
			count++;
		      }
		}
	      yyerror(msg);
	      free(msg);
	    }
	  else
	    yyerror ("parse error; also virtual memory exceeded");
	}
      else
#endif /* YYERROR_VERBOSE */
	yyerror("parse error");
    }

  goto yyerrlab1;
yyerrlab1:   /* here on error raised explicitly by an action */

  if (yyerrstatus == 3)
    {
      /* if just tried and failed to reuse lookahead token after an error, discard it.  */

      /* return failure if at end of input */
      if (yychar == YYEOF)
	YYABORT;

#if YYDEBUG != 0
      if (yydebug)
	fprintf(stderr, "Discarding token %d (%s).\n", yychar, yytname[yychar1]);
#endif

      yychar = YYEMPTY;
    }

  /* Else will try to reuse lookahead token
     after shifting the error token.  */

  yyerrstatus = 3;		/* Each real token shifted decrements this */

  goto yyerrhandle;

yyerrdefault:  /* current state does not do anything special for the error token. */

#if 0
  /* This is wrong; only states that explicitly want error tokens
     should shift them.  */
  yyn = yydefact[yystate];  /* If its default is to accept any token, ok.  Otherwise pop it.*/
  if (yyn) goto yydefault;
#endif

yyerrpop:   /* pop the current state because it cannot handle the error token */

  if (yyssp == yyss) YYABORT;
  yyvsp--;
  yystate = *--yyssp;
#ifdef YYLSP_NEEDED
  yylsp--;
#endif

#if YYDEBUG != 0
  if (yydebug)
    {
      short *ssp1 = yyss - 1;
      fprintf (stderr, "Error: state stack now");
      while (ssp1 != yyssp)
	fprintf (stderr, " %d", *++ssp1);
      fprintf (stderr, "\n");
    }
#endif

yyerrhandle:

  yyn = yypact[yystate];
  if (yyn == YYFLAG)
    goto yyerrdefault;

  yyn += YYTERROR;
  if (yyn < 0 || yyn > YYLAST || yycheck[yyn] != YYTERROR)
    goto yyerrdefault;

  yyn = yytable[yyn];
  if (yyn < 0)
    {
      if (yyn == YYFLAG)
	goto yyerrpop;
      yyn = -yyn;
      goto yyreduce;
    }
  else if (yyn == 0)
    goto yyerrpop;

  if (yyn == YYFINAL)
    YYACCEPT;

#if YYDEBUG != 0
  if (yydebug)
    fprintf(stderr, "Shifting error token, ");
#endif

  *++yyvsp = yylval;
#ifdef YYLSP_NEEDED
  *++yylsp = yylloc;
#endif

  yystate = yyn;
  goto yynewstate;
}

#line 138 "lps.y"

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
	if(!strcmp(op, '=')){
		return (num1 == num2);
	}
	else if(!strcmp(op, "<>")){
		return (num1 != num2);
	}
	else if(!strcmp(op, '>')){
		return (num1 > num2);
	}
	else if(!strcmp(op, '<')){
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




