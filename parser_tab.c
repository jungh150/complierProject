
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDENT	258
#define	TNUMBER	259
#define	TCONST	260
#define	TELSE	261
#define	TIF	262
#define	TINT	263
#define	TRETURN	264
#define	TVOID	265
#define	TWHILE	266
#define	TADD	267
#define	TSUB	268
#define	TMUL	269
#define	TDIV	270
#define	TMOD	271
#define	TASSIGN	272
#define	TADDASSIGN	273
#define	TSUBASSIGN	274
#define	TMULASSIGN	275
#define	TDIVASSIGN	276
#define	TMODASSIGN	277
#define	TNOT	278
#define	TOR	279
#define	TAND	280
#define	TEQUAL	281
#define	TNOTEQU	282
#define	TGREAT	283
#define	TLESS	284
#define	TGREATE	285
#define	TLESSE	286
#define	TINC	287
#define	TDEC	288
#define	TCOMMA	289
#define	TSEMICOLON	290
#define	TLPAREN	291
#define	TRPAREN	292
#define	TLBRACKET	293
#define	TRBRACKET	294
#define	TLBRACE	295
#define	TRBRACE	296
#define	LOWER_THAN_ELSE	297

#line 1 "parser.y"

/*
 * parser.y - yacc source for the MiniC
 * 
 * Programmer - 김예지(2176082), 송채원(2076216), 신정화(2271035), 윤하영(2071033)
 *
 * date - 2024/5/31
 *
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <malloc.h>
#include "glob.h"

int type_int = 0;
int type_void = 0;

void line(int);
extern void printError();
extern int yylex();
extern void yyerror(const char *s);

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

#ifndef YYSTYPE
#define YYSTYPE int
#endif
#include <stdio.h>

#ifndef __cplusplus
#ifndef __STDC__
#define const
#endif
#endif



#define	YYFINAL		158
#define	YYFLAG		-32768
#define	YYNTBASE	43

#define YYTRANSLATE(x) ((unsigned)(x) <= 297 ? yytranslate[x] : 88)

static const char yytranslate[] = {     0,
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
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     2,     2,     2,     2,     2,     1,     2,     3,     4,     5,
     6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
    16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
    26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
    36,    37,    38,    39,    40,    41,    42
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    14,    17,    20,    23,
    26,    30,    32,    34,    37,    39,    41,    43,    45,    47,
    49,    53,    55,    56,    58,    62,    65,    70,    72,    73,
    75,    78,    82,    84,    88,    90,    94,    96,   101,   103,
   104,   106,   107,   109,   112,   114,   116,   118,   120,   122,
   125,   127,   128,   134,   142,   148,   152,   154,   156,   160,
   164,   168,   172,   176,   180,   182,   186,   188,   192,   194,
   198,   202,   204,   208,   212,   216,   220,   222,   226,   230,
   232,   236,   240,   244,   246,   249,   252,   255,   258,   260,
   265,   270,   273,   276,   278,   279,   281,   283,   287,   289,
   291
};

static const short yyrhs[] = {    44,
     0,    45,     0,    44,    45,     0,    46,     0,    61,     0,
     3,    35,     0,     3,     1,     0,    47,    58,     0,    47,
    35,     0,    47,     1,     0,    48,    53,    54,     0,    49,
     0,    50,     0,    49,    50,     0,    51,     0,    52,     0,
     5,     0,     8,     0,    10,     0,     3,     0,    36,    55,
    37,     0,    56,     0,     0,    57,     0,    56,    34,    57,
     0,    48,    64,     0,    40,    59,    66,    41,     0,    60,
     0,     0,    61,     0,    60,    61,     0,    48,    62,    35,
     0,    63,     0,    62,    34,    63,     0,    64,     0,    64,
    17,     4,     0,     3,     0,     3,    38,    65,    39,     0,
     4,     0,     0,    67,     0,     0,    68,     0,    67,    68,
     0,    58,     0,    69,     0,    71,     0,    72,     0,    73,
     0,    70,    35,     0,    74,     0,     0,     7,    36,    74,
    37,    68,     0,     7,    36,    74,    37,    68,     6,    68,
     0,    11,    36,    74,    37,    68,     0,     9,    70,    35,
     0,    75,     0,    76,     0,    82,    17,    75,     0,    82,
    18,    75,     0,    82,    19,    75,     0,    82,    20,    75,
     0,    82,    21,    75,     0,    82,    22,    75,     0,    77,
     0,    76,    24,    77,     0,    78,     0,    77,    25,    78,
     0,    79,     0,    78,    26,    79,     0,    78,    27,    79,
     0,    80,     0,    79,    28,    80,     0,    79,    29,    80,
     0,    79,    30,    80,     0,    79,    31,    80,     0,    81,
     0,    80,    12,    81,     0,    80,    13,    81,     0,    82,
     0,    81,    14,    82,     0,    81,    15,    82,     0,    81,
    16,    82,     0,    83,     0,    13,    82,     0,    23,    82,
     0,    32,    82,     0,    33,    82,     0,    87,     0,    83,
    38,    74,    39,     0,    83,    36,    84,    37,     0,    83,
    32,     0,    83,    33,     0,    85,     0,     0,    86,     0,
    75,     0,    86,    34,    75,     0,     3,     0,     4,     0,
    36,    74,    37,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    36,    38,    39,    41,    42,    43,    44,    50,    51,    52,
    62,    64,    66,    67,    69,    70,    72,    74,    75,    76,
    88,    90,    91,    93,    94,    99,   100,   101,   102,   103,
   104,   105,   106,   107,   108,   109,   110,   111,   112,   113,
   114,   115,   116,   117,   118,   119,   120,   121,   122,   124,
   125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
   135,   136,   137,   138,   140,   141,   142,   143,   144,   145,
   146,   147,   148,   149,   150,   151,   152,   153,   154,   155,
   156,   157,   158,   159,   160,   161,   162,   163,   164,   165,
   166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
   176
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TCONST","TELSE","TIF","TINT","TRETURN","TVOID","TWHILE","TADD","TSUB",
"TMUL","TDIV","TMOD","TASSIGN","TADDASSIGN","TSUBASSIGN","TMULASSIGN","TDIVASSIGN",
"TMODASSIGN","TNOT","TOR","TAND","TEQUAL","TNOTEQU","TGREAT","TLESS","TGREATE",
"TLESSE","TINC","TDEC","TCOMMA","TSEMICOLON","TLPAREN","TRPAREN","TLBRACKET",
"TRBRACKET","TLBRACE","TRBRACE","LOWER_THAN_ELSE","mini_c","translation_unit",
"external_dcl","function_def","function_header","dcl_spec","dcl_specifiers",
"dcl_specifier","type_qualifier","type_specifier","function_name","formal_param",
"opt_formal_param","formal_param_list","param_dcl","compound_st","opt_dcl_list",
"declaration_list","declaration","init_dcl_list","init_declarator","declarator",
"opt_number","opt_stat_list","statement_list","statement","expression_st","opt_expression",
"if_st","while_st","return_st","expression","assignment_exp","logical_or_exp",
"logical_and_exp","equality_exp","relational_exp","additive_exp","multiplicative_exp",
"unary_exp","postfix_exp","opt_actual_param","actual_param","actual_param_list",
"primary_exp",""
};
#endif

static const short yyr1[] = {     0,
    43,    44,    44,    45,    45,    45,    45,    46,    46,    46,
    47,    48,    49,    49,    50,    50,    51,    52,    52,    53,
    54,    55,    55,    56,    56,    57,    58,    59,    59,    60,
    60,    61,    62,    62,    63,    63,    64,    64,    65,    65,
    66,    66,    67,    67,    68,    68,    68,    68,    68,    69,
    70,    70,    71,    71,    72,    73,    74,    75,    75,    75,
    75,    75,    75,    75,    76,    76,    77,    77,    78,    78,
    78,    79,    79,    79,    79,    79,    80,    80,    80,    81,
    81,    81,    81,    82,    82,    82,    82,    82,    83,    83,
    83,    83,    83,    84,    84,    85,    86,    86,    87,    87,
    87
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     2,     2,     2,     2,     2,
     3,     1,     1,     2,     1,     1,     1,     1,     1,     1,
     3,     1,     0,     1,     3,     2,     4,     1,     0,     1,
     2,     3,     1,     3,     1,     3,     1,     4,     1,     0,
     1,     0,     1,     2,     1,     1,     1,     1,     1,     2,
     1,     0,     5,     7,     5,     3,     1,     1,     3,     3,
     3,     3,     3,     3,     1,     3,     1,     3,     1,     3,
     3,     1,     3,     3,     3,     3,     1,     3,     3,     1,
     3,     3,     3,     1,     2,     2,     2,     2,     1,     4,
     4,     2,     2,     1,     0,     1,     1,     3,     1,     1,
     3
};

static const short yydefact[] = {     0,
     0,    17,    18,    19,     1,     2,     4,     0,     0,    12,
    13,    15,    16,     5,     7,     6,     3,    10,     9,    29,
     8,    37,     0,     0,    33,    35,    14,     0,    42,    28,
    30,    40,    23,    11,     0,    32,     0,    37,    99,   100,
     0,    52,     0,     0,     0,     0,     0,     0,    45,     0,
    41,    43,    46,     0,    47,    48,    49,    51,    57,    58,
    65,    67,    69,    72,    77,    80,    84,    89,    31,    39,
     0,     0,     0,    22,    24,    34,    36,     0,     0,     0,
    85,    86,    87,    88,     0,    27,    44,    50,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,    92,    93,    95,
     0,    38,    26,    21,     0,     0,    56,     0,   101,    66,
    80,    68,    70,    71,    73,    74,    75,    76,    78,    79,
    81,    82,    83,    59,    60,    61,    62,    63,    64,    97,
     0,    94,    96,     0,    25,    52,    52,    91,     0,    90,
    53,    55,    98,    52,    54,     0,     0,     0
};

static const short yydefgoto[] = {   156,
     5,     6,     7,     8,     9,    10,    11,    12,    13,    23,
    34,    73,    74,    75,    49,    29,    30,    14,    24,    25,
    26,    71,    50,    51,    52,    53,    54,    55,    56,    57,
    58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
   141,   142,   143,    68
};

static const short yypact[] = {    22,
     7,-32768,-32768,-32768,    22,-32768,-32768,     6,    11,   105,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,   105,
-32768,   -10,   -14,     9,-32768,    12,-32768,    36,    58,   105,
-32768,    41,   105,-32768,    36,-32768,    43,    30,-32768,-32768,
    34,   103,    53,   103,   103,   103,   103,   103,-32768,    25,
    58,-32768,-32768,    42,-32768,-32768,-32768,-32768,-32768,    55,
    79,    10,    89,    62,    -5,    66,     2,-32768,-32768,-32768,
    75,    36,    71,    91,-32768,-32768,-32768,   103,    92,   103,
-32768,-32768,-32768,-32768,    93,-32768,-32768,-32768,   103,   103,
   103,   103,   103,   103,   103,   103,   103,   103,   103,   103,
   103,   103,   103,   103,   103,   103,   103,-32768,-32768,   103,
   103,-32768,-32768,-32768,   105,    94,-32768,    95,-32768,    79,
-32768,    10,    89,    89,    62,    62,    62,    62,    -5,    -5,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
    96,-32768,   100,    90,-32768,    69,    69,-32768,   103,-32768,
   122,-32768,-32768,    69,-32768,   137,   138,-32768
};

static const short yypgoto[] = {-32768,
-32768,   135,-32768,-32768,   -18,-32768,   131,-32768,-32768,-32768,
-32768,-32768,-32768,    27,   136,-32768,-32768,    -7,-32768,   108,
    73,-32768,-32768,-32768,   -51,-32768,   104,-32768,-32768,-32768,
   -47,   -86,-32768,    59,    57,     8,    28,    14,   -41,-32768,
-32768,-32768,-32768,-32768
};


#define	YYLAST		148


static const short yytable[] = {    87,
    85,    28,    81,    82,    83,    84,    18,    15,    99,   100,
   101,    28,    31,    22,    72,   134,   135,   136,   137,   138,
   139,    33,    69,   140,     1,   -20,     2,    32,    37,     3,
   116,     4,   118,   108,   109,    91,    92,   110,    38,   111,
    19,    16,    35,    36,    70,    20,    77,   121,   121,   121,
   121,   121,   121,   121,   121,   121,   121,   131,   132,   133,
    39,    40,   153,   144,    41,    86,    42,    32,    43,    78,
    44,    39,    40,    97,    98,    41,    88,    42,    89,    43,
    45,    44,   102,   103,   104,   105,   106,   107,    80,    46,
    47,    45,   -52,    48,   151,   152,    72,    20,   123,   124,
    46,    47,   155,    90,    48,    39,    40,   114,    20,     2,
   129,   130,     3,   112,     4,    44,    93,    94,    95,    96,
   125,   126,   127,   128,   115,    45,   117,   154,   150,   119,
   146,   147,   148,   149,    46,    47,   157,   158,    48,    17,
    27,   145,    76,    21,   113,    79,   122,   120
};

static const short yycheck[] = {    51,
    48,    20,    44,    45,    46,    47,     1,     1,    14,    15,
    16,    30,    20,     3,    33,   102,   103,   104,   105,   106,
   107,    36,    30,   110,     3,    36,     5,    38,    17,     8,
    78,    10,    80,    32,    33,    26,    27,    36,     3,    38,
    35,    35,    34,    35,     4,    40,     4,    89,    90,    91,
    92,    93,    94,    95,    96,    97,    98,    99,   100,   101,
     3,     4,   149,   111,     7,    41,     9,    38,    11,    36,
    13,     3,     4,    12,    13,     7,    35,     9,    24,    11,
    23,    13,    17,    18,    19,    20,    21,    22,    36,    32,
    33,    23,    35,    36,   146,   147,   115,    40,    91,    92,
    32,    33,   154,    25,    36,     3,     4,    37,    40,     5,
    97,    98,     8,    39,    10,    13,    28,    29,    30,    31,
    93,    94,    95,    96,    34,    23,    35,     6,    39,    37,
    37,    37,    37,    34,    32,    33,     0,     0,    36,     5,
    10,   115,    35,     8,    72,    42,    90,    89
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

case 7:
#line 45 "parser.y"
{
                        yyerrok;
                        printError(wrong_st);    /* error - wrong statement */
                    ;
    break;}
case 10:
#line 53 "parser.y"
{
                        /* 에러 발생 시 type 수정을 위해 default값 0 세팅 */
                        /* identifier about parse error */
                        look_tmp->type = 0;
                        yyerrok;
                        /* error - wrong function definition */
                        printError(wrong_funcdef);
                    ;
    break;}
case 18:
#line 74 "parser.y"
{type_int=1;;
    break;}
case 19:
#line 75 "parser.y"
{type_void=1;;
    break;}
case 20:
#line 77 "parser.y"
{
                        /* identifier about parse error or not defined identifier/function */
                        if(look_id->type == 0 || look_id->type == 5)
                        {
                            look_id->type=4;        /* function name */
                            type_int=0;                /* not integer */
                            type_void=0;            /* not void */
                            look_tmp=look_id;        
                        }
                    ;
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
#line 177 "parser.y"


void semantic(int n)
{    
    printf("reduced rule number = %d\n",n);
}
