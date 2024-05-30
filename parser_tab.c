
/*  A Bison parser, made from parser.y with Bison version GNU Bison version 1.24
  */

#define YYBISON 1  /* Identify Bison output.  */

#define	TIDENT	258
#define	TNUMBER	259
#define	TRNUMBER	260
#define	TCONST	261
#define	TELSE	262
#define	TIF	263
#define	TINT	264
#define	TFLOAT	265
#define	TRETURN	266
#define	TVOID	267
#define	TWHILE	268
#define	TADD	269
#define	TSUB	270
#define	TMUL	271
#define	TDIV	272
#define	TMOD	273
#define	TASSIGN	274
#define	TADDASSIGN	275
#define	TSUBASSIGN	276
#define	TMULASSIGN	277
#define	TDIVASSIGN	278
#define	TMODASSIGN	279
#define	TNOT	280
#define	TOR	281
#define	TAND	282
#define	TEQUAL	283
#define	TNOTEQU	284
#define	TGREAT	285
#define	TLESS	286
#define	TGREATE	287
#define	TLESSE	288
#define	TINC	289
#define	TDEC	290
#define	TCOMMA	291
#define	TSEMICOLON	292
#define	TLPAREN	293
#define	TRPAREN	294
#define	TLBRACE	295
#define	TRBRACE	296
#define	TLSQUARE	297
#define	TRSQUARE	298
#define	TTOOLONG	299
#define	TSTARTWD	300
#define	TILLCH	301
#define	TLOWERTHANELSE	302

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

int returntp = 0; // 0:void, 1:int
int type = 0; // 0:scalar, 1:array, 2:function
int paramidx = 0; // index of parameter array

extern printError(ERRORtypes err);
extern yylex();
extern yyerror(char* s);

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



#define	YYFINAL		188
#define	YYFLAG		-32768
#define	YYNTBASE	48

#define YYTRANSLATE(x) ((unsigned)(x) <= 302 ? yytranslate[x] : 94)

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
    36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
    46,    47
};

#if YYDEBUG != 0
static const short yyprhs[] = {     0,
     0,     2,     4,     7,     9,    11,    13,    16,    18,    21,
    24,    27,    31,    33,    35,    38,    40,    42,    44,    46,
    48,    50,    52,    56,    60,    62,    63,    65,    69,    72,
    77,    82,    84,    85,    87,    90,    94,    98,   101,   103,
   107,   109,   113,   117,   119,   124,   129,   131,   132,   134,
   135,   137,   140,   142,   144,   146,   148,   150,   153,   156,
   158,   159,   165,   173,   179,   183,   187,   189,   191,   195,
   199,   203,   207,   211,   215,   219,   223,   227,   231,   235,
   239,   241,   245,   249,   251,   255,   259,   261,   265,   269,
   273,   277,   279,   283,   287,   291,   295,   297,   301,   305,
   309,   313,   315,   319,   323,   327,   331,   335,   339,   341,
   344,   347,   350,   353,   355,   360,   365,   368,   371,   373,
   374,   376,   378,   382,   384,   386,   388,   392,   394,   396
};

static const short yyrhs[] = {    49,
     0,    50,     0,    49,    50,     0,    46,     0,    51,     0,
    66,     0,     3,     1,     0,    41,     0,    52,    63,     0,
    52,    37,     0,    52,     1,     0,    53,    58,    59,     0,
    54,     0,    55,     0,    54,    55,     0,    56,     0,    57,
     0,     6,     0,     9,     0,    10,     0,    12,     0,    93,
     0,    38,    60,    39,     0,    38,    60,     1,     0,    61,
     0,     0,    62,     0,    61,    36,    62,     0,    53,    69,
     0,    40,    64,    71,    41,     0,    40,    64,    71,     1,
     0,    65,     0,     0,    66,     0,    65,    66,     0,    53,
    67,    37,     0,    53,    67,     1,     0,    53,     1,     0,
    68,     0,    67,    36,    68,     0,    69,     0,    69,    19,
     4,     0,    69,    19,     5,     0,    93,     0,    93,    42,
    70,    43,     0,    93,    42,    70,     1,     0,     4,     0,
     0,    72,     0,     0,    73,     0,    72,    73,     0,    63,
     0,    74,     0,    76,     0,    77,     0,    78,     0,    75,
    37,     0,    79,     1,     0,    79,     0,     0,     8,    38,
    79,    39,    73,     0,     8,    38,    79,    39,    73,     7,
    73,     0,    13,    38,    79,    39,    73,     0,    11,    75,
    37,     0,    11,    75,     1,     0,    80,     0,    81,     0,
    87,    19,    80,     0,    87,    19,     1,     0,    87,    20,
    80,     0,    87,    20,     1,     0,    87,    21,    80,     0,
    87,    21,     1,     0,    87,    22,    80,     0,    87,    22,
     1,     0,    87,    23,    80,     0,    87,    23,     1,     0,
    87,    24,    80,     0,    87,    24,     1,     0,    82,     0,
    81,    26,    82,     0,    81,    26,     1,     0,    83,     0,
    82,    27,    83,     0,    82,    27,     1,     0,    84,     0,
    83,    28,    84,     0,    83,    28,     1,     0,    83,    29,
    84,     0,    83,    29,     1,     0,    85,     0,    84,    30,
    85,     0,    84,    31,    85,     0,    84,    32,    85,     0,
    84,    33,    85,     0,    86,     0,    85,    14,    86,     0,
    85,    14,     1,     0,    85,    15,    86,     0,    85,    15,
     1,     0,    87,     0,    86,    16,    87,     0,    86,    16,
     1,     0,    86,    17,    87,     0,    86,    17,     1,     0,
    86,    18,    87,     0,    86,    18,     1,     0,    88,     0,
    15,    87,     0,    25,    87,     0,    34,    87,     0,    35,
    87,     0,    92,     0,    88,    42,    79,    43,     0,    88,
    38,    89,    39,     0,    88,    34,     0,    88,    35,     0,
    90,     0,     0,    91,     0,    80,     0,    91,    36,    80,
     0,    93,     0,     4,     0,     5,     0,    38,    79,    39,
     0,     3,     0,    44,     0,    45,     0
};

#endif

#if YYDEBUG != 0
static const short yyrline[] = { 0,
    37,    39,    40,    41,    47,    48,    49,    54,    60,    61,
    62,    68,    70,    72,    73,    75,    76,    78,    80,    81,
    82,    84,    92,    93,    99,   100,   102,   103,   105,   112,
   113,   119,   120,   122,   123,   125,   126,   131,   137,   138,
   140,   141,   142,   144,   149,   154,   160,   161,   163,   164,
   166,   167,   169,   170,   171,   172,   173,   175,   176,   182,
   183,   185,   186,   188,   190,   191,   197,   199,   200,   201,
   206,   207,   212,   213,   218,   219,   224,   225,   230,   231,
   237,   238,   239,   245,   246,   247,   253,   254,   255,   260,
   261,   267,   268,   269,   270,   271,   273,   274,   275,   280,
   281,   287,   288,   289,   294,   295,   300,   301,   307,   308,
   309,   310,   311,   313,   314,   315,   316,   317,   319,   320,
   322,   324,   325,   327,   328,   329,   330,   332,   333,   338
};

static const char * const yytname[] = {   "$","error","$undefined.","TIDENT",
"TNUMBER","TRNUMBER","TCONST","TELSE","TIF","TINT","TFLOAT","TRETURN","TVOID",
"TWHILE","TADD","TSUB","TMUL","TDIV","TMOD","TASSIGN","TADDASSIGN","TSUBASSIGN",
"TMULASSIGN","TDIVASSIGN","TMODASSIGN","TNOT","TOR","TAND","TEQUAL","TNOTEQU",
"TGREAT","TLESS","TGREATE","TLESSE","TINC","TDEC","TCOMMA","TSEMICOLON","TLPAREN",
"TRPAREN","TLBRACE","TRBRACE","TLSQUARE","TRSQUARE","TTOOLONG","TSTARTWD","TILLCH",
"TLOWERTHANELSE","mini_c","translation_unit","external_dcl","function_def","function_header",
"dcl_spec","dcl_specifiers","dcl_specifier","type_qualifier","type_specifier",
"function_name","formal_param","opt_formal_param","formal_param_list","param_dcl",
"compound_st","opt_dcl_list","declaration_list","declaration","init_dcl_list",
"init_declarator","declarator","opt_number","opt_stat_list","statement_list",
"statement","expression_st","opt_expression","if_st","while_st","return_st",
"expression","assignment_exp","logical_or_exp","logical_and_exp","equality_exp",
"relational_exp","additive_exp","multiplicative_exp","unary_exp","postfix_exp",
"opt_actual_param","actual_param","actual_param_list","primary_exp","identifier",
""
};
#endif

static const short yyr1[] = {     0,
    48,    49,    49,    49,    50,    50,    50,    50,    51,    51,
    51,    52,    53,    54,    54,    55,    55,    56,    57,    57,
    57,    58,    59,    59,    60,    60,    61,    61,    62,    63,
    63,    64,    64,    65,    65,    66,    66,    66,    67,    67,
    68,    68,    68,    69,    69,    69,    70,    70,    71,    71,
    72,    72,    73,    73,    73,    73,    73,    74,    74,    75,
    75,    76,    76,    77,    78,    78,    79,    80,    80,    80,
    80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
    81,    81,    81,    82,    82,    82,    83,    83,    83,    83,
    83,    84,    84,    84,    84,    84,    85,    85,    85,    85,
    85,    86,    86,    86,    86,    86,    86,    86,    87,    87,
    87,    87,    87,    88,    88,    88,    88,    88,    89,    89,
    90,    91,    91,    92,    92,    92,    92,    93,    93,    93
};

static const short yyr2[] = {     0,
     1,     1,     2,     1,     1,     1,     2,     1,     2,     2,
     2,     3,     1,     1,     2,     1,     1,     1,     1,     1,
     1,     1,     3,     3,     1,     0,     1,     3,     2,     4,
     4,     1,     0,     1,     2,     3,     3,     2,     1,     3,
     1,     3,     3,     1,     4,     4,     1,     0,     1,     0,
     1,     2,     1,     1,     1,     1,     1,     2,     2,     1,
     0,     5,     7,     5,     3,     3,     1,     1,     3,     3,
     3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
     1,     3,     3,     1,     3,     3,     1,     3,     3,     3,
     3,     1,     3,     3,     3,     3,     1,     3,     3,     3,
     3,     1,     3,     3,     3,     3,     3,     3,     1,     2,
     2,     2,     2,     1,     4,     4,     2,     2,     1,     0,
     1,     1,     3,     1,     1,     1,     3,     1,     1,     1
};

static const short yydefact[] = {     0,
     0,    18,    19,    20,    21,     8,     4,     1,     2,     5,
     0,     0,    13,    14,    16,    17,     6,     7,     3,    11,
    10,    33,     9,    38,   128,   129,   130,     0,     0,    39,
    41,    44,    15,     0,    50,    32,    34,    26,    12,    37,
     0,    36,     0,    48,    44,   125,   126,     0,    61,     0,
     0,     0,     0,     0,     0,    53,     0,    49,    51,    54,
     0,    55,    56,    57,     0,    67,    68,    81,    84,    87,
    92,    97,   102,   109,   114,   124,    35,     0,     0,    25,
    27,    40,    42,    43,    47,     0,     0,     0,    60,     0,
   110,   111,   112,   113,     0,    31,    30,    52,    58,    59,
     0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     0,     0,     0,     0,     0,     0,     0,     0,     0,   117,
   118,   120,     0,    29,    24,    23,     0,    46,    45,     0,
    66,    65,     0,   127,    83,    82,   102,    86,    85,    89,
    88,    91,    90,    93,    94,    95,    96,    99,    98,   101,
   100,   104,   103,   106,   105,   108,   107,    70,    69,    72,
    71,    74,    73,    76,    75,    78,    77,    80,    79,   122,
     0,   119,   121,     0,    28,    61,    61,   116,     0,   115,
    62,    64,   123,    61,    63,     0,     0,     0
};

static const short yydefgoto[] = {   186,
     8,     9,    10,    11,    12,    13,    14,    15,    16,    28,
    39,    79,    80,    81,    56,    35,    36,    17,    29,    30,
    31,    86,    57,    58,    59,    60,    61,    62,    63,    64,
    65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
   171,   172,   173,    75,    76
};

static const short yypact[] = {     4,
    32,-32768,-32768,-32768,-32768,-32768,-32768,    69,-32768,-32768,
    37,     3,   123,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,   123,-32768,-32768,-32768,-32768,-32768,     1,    66,-32768,
    30,   -33,-32768,     3,   446,   123,-32768,   123,-32768,-32768,
     8,-32768,    61,    59,    13,-32768,-32768,    60,   489,    71,
   489,   489,   489,   489,   489,-32768,    27,   446,-32768,-32768,
    36,-32768,-32768,-32768,    43,-32768,    81,    87,   110,    92,
   128,    41,   496,    70,-32768,-32768,-32768,     8,    23,    84,
-32768,-32768,-32768,-32768,-32768,    11,   489,    45,-32768,   489,
-32768,-32768,-32768,-32768,    89,-32768,-32768,-32768,-32768,-32768,
    26,    96,   112,   148,   489,   489,   489,   489,   163,   199,
   214,   250,   265,   301,   316,   352,   367,   403,   418,-32768,
-32768,   489,   489,-32768,-32768,-32768,   123,-32768,-32768,    97,
-32768,-32768,   109,-32768,-32768,    87,-32768,-32768,   110,-32768,
    92,-32768,    92,   128,   128,   128,   128,-32768,    41,-32768,
    41,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,-32768,
   126,-32768,   133,   119,-32768,   462,   462,-32768,   489,-32768,
   164,-32768,-32768,   462,-32768,   170,   172,-32768
};

static const short yypgoto[] = {-32768,
-32768,   166,-32768,-32768,   -21,-32768,   162,-32768,-32768,-32768,
-32768,-32768,-32768,    49,   168,-32768,-32768,    20,-32768,   136,
   102,-32768,-32768,-32768,   -58,-32768,   132,-32768,-32768,-32768,
   -47,   -96,-32768,    83,    85,    51,    53,    35,   -17,-32768,
-32768,-32768,-32768,-32768,    -9
};


#define	YYLAST		534


static const short yytable[] = {    98,
    34,    89,    32,    24,   -22,    25,     1,    95,    44,     2,
    25,   128,     3,     4,    34,     5,    78,   159,   161,   163,
   165,   167,   169,   125,    45,   170,   135,    96,    25,    46,
    47,    45,    18,    91,    92,    93,    94,    20,    38,   130,
    51,    37,   133,   100,     6,   131,    26,    27,    43,     7,
    52,    26,    27,   129,    44,    77,   111,   112,   113,    53,
    54,   126,    85,    55,    83,    84,    40,    97,    45,    26,
    27,     1,    99,    21,     2,   174,    22,     3,     4,   -60,
     5,   132,   183,   137,   137,   137,   137,   137,   137,   137,
   137,   137,   137,   153,   155,   157,   138,    87,    25,    46,
    47,    41,    42,   120,   121,    78,   101,   122,    90,     6,
    51,   123,   140,   102,    25,    46,    47,   181,   182,   127,
    52,   105,   106,   107,   108,   185,    51,   134,     2,    53,
    54,     3,     4,    55,     5,   176,    52,   103,   104,    26,
    27,   109,   110,   149,   151,    53,    54,   177,   142,    55,
    25,    46,    47,   141,   143,    26,    27,   144,   145,   146,
   147,   180,    51,   148,   178,    25,    46,    47,   179,   187,
   184,   188,    52,    19,    33,   175,    82,    51,    23,   124,
    88,    53,    54,   136,     0,    55,   139,    52,     0,     0,
     0,    26,    27,     0,     0,     0,    53,    54,     0,   150,
    55,    25,    46,    47,     0,     0,    26,    27,     0,     0,
     0,     0,     0,    51,   152,     0,    25,    46,    47,     0,
     0,     0,     0,    52,     0,     0,     0,     0,    51,     0,
     0,     0,    53,    54,     0,     0,    55,     0,    52,     0,
     0,     0,    26,    27,     0,     0,     0,    53,    54,     0,
   154,    55,    25,    46,    47,     0,     0,    26,    27,     0,
     0,     0,     0,     0,    51,   156,     0,    25,    46,    47,
     0,     0,     0,     0,    52,     0,     0,     0,     0,    51,
     0,     0,     0,    53,    54,     0,     0,    55,     0,    52,
     0,     0,     0,    26,    27,     0,     0,     0,    53,    54,
     0,   158,    55,    25,    46,    47,     0,     0,    26,    27,
     0,     0,     0,     0,     0,    51,   160,     0,    25,    46,
    47,     0,     0,     0,     0,    52,     0,     0,     0,     0,
    51,     0,     0,     0,    53,    54,     0,     0,    55,     0,
    52,     0,     0,     0,    26,    27,     0,     0,     0,    53,
    54,     0,   162,    55,    25,    46,    47,     0,     0,    26,
    27,     0,     0,     0,     0,     0,    51,   164,     0,    25,
    46,    47,     0,     0,     0,     0,    52,     0,     0,     0,
     0,    51,     0,     0,     0,    53,    54,     0,     0,    55,
     0,    52,     0,     0,     0,    26,    27,     0,     0,     0,
    53,    54,     0,   166,    55,    25,    46,    47,     0,     0,
    26,    27,     0,     0,     0,     0,     0,    51,   168,     0,
    25,    46,    47,     0,     0,     0,     0,    52,     0,     0,
     0,     0,    51,     0,     0,     0,    53,    54,     0,     0,
    55,     0,    52,     0,     0,     0,    26,    27,    25,    46,
    47,    53,    54,    48,     0,    55,    49,     0,    50,     0,
    51,    26,    27,     0,    25,    46,    47,     0,     0,    48,
    52,     0,    49,     0,    50,     0,    51,     0,     0,    53,
    54,     0,   -61,    55,     0,    22,    52,     0,     0,    26,
    27,    25,    46,    47,     0,    53,    54,     0,     0,    55,
     0,    22,     0,    51,     0,    26,    27,     0,     0,     0,
     0,     0,     0,    52,   114,   115,   116,   117,   118,   119,
     0,     0,    53,    54,     0,     0,    55,     0,     0,     0,
     0,     0,    26,    27
};

static const short yycheck[] = {    58,
    22,    49,    12,     1,    38,     3,     3,    55,    42,     6,
     3,     1,     9,    10,    36,    12,    38,   114,   115,   116,
   117,   118,   119,     1,    34,   122,     1,     1,     3,     4,
     5,    41,     1,    51,    52,    53,    54,     1,    38,    87,
    15,    22,    90,     1,    41,     1,    44,    45,    19,    46,
    25,    44,    45,    43,    42,    36,    16,    17,    18,    34,
    35,    39,     4,    38,     4,     5,     1,    41,    78,    44,
    45,     3,    37,    37,     6,   123,    40,     9,    10,    37,
    12,    37,   179,   101,   102,   103,   104,   105,   106,   107,
   108,   109,   110,   111,   112,   113,     1,    38,     3,     4,
     5,    36,    37,    34,    35,   127,    26,    38,    38,    41,
    15,    42,     1,    27,     3,     4,     5,   176,   177,    36,
    25,    30,    31,    32,    33,   184,    15,    39,     6,    34,
    35,     9,    10,    38,    12,    39,    25,    28,    29,    44,
    45,    14,    15,   109,   110,    34,    35,    39,     1,    38,
     3,     4,     5,   103,   104,    44,    45,   105,   106,   107,
   108,    43,    15,     1,    39,     3,     4,     5,    36,     0,
     7,     0,    25,     8,    13,   127,    41,    15,    11,    78,
    49,    34,    35,   101,    -1,    38,   102,    25,    -1,    -1,
    -1,    44,    45,    -1,    -1,    -1,    34,    35,    -1,     1,
    38,     3,     4,     5,    -1,    -1,    44,    45,    -1,    -1,
    -1,    -1,    -1,    15,     1,    -1,     3,     4,     5,    -1,
    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    15,    -1,
    -1,    -1,    34,    35,    -1,    -1,    38,    -1,    25,    -1,
    -1,    -1,    44,    45,    -1,    -1,    -1,    34,    35,    -1,
     1,    38,     3,     4,     5,    -1,    -1,    44,    45,    -1,
    -1,    -1,    -1,    -1,    15,     1,    -1,     3,     4,     5,
    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,    15,
    -1,    -1,    -1,    34,    35,    -1,    -1,    38,    -1,    25,
    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    34,    35,
    -1,     1,    38,     3,     4,     5,    -1,    -1,    44,    45,
    -1,    -1,    -1,    -1,    -1,    15,     1,    -1,     3,     4,
     5,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,    -1,
    15,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,    -1,
    25,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,    34,
    35,    -1,     1,    38,     3,     4,     5,    -1,    -1,    44,
    45,    -1,    -1,    -1,    -1,    -1,    15,     1,    -1,     3,
     4,     5,    -1,    -1,    -1,    -1,    25,    -1,    -1,    -1,
    -1,    15,    -1,    -1,    -1,    34,    35,    -1,    -1,    38,
    -1,    25,    -1,    -1,    -1,    44,    45,    -1,    -1,    -1,
    34,    35,    -1,     1,    38,     3,     4,     5,    -1,    -1,
    44,    45,    -1,    -1,    -1,    -1,    -1,    15,     1,    -1,
     3,     4,     5,    -1,    -1,    -1,    -1,    25,    -1,    -1,
    -1,    -1,    15,    -1,    -1,    -1,    34,    35,    -1,    -1,
    38,    -1,    25,    -1,    -1,    -1,    44,    45,     3,     4,
     5,    34,    35,     8,    -1,    38,    11,    -1,    13,    -1,
    15,    44,    45,    -1,     3,     4,     5,    -1,    -1,     8,
    25,    -1,    11,    -1,    13,    -1,    15,    -1,    -1,    34,
    35,    -1,    37,    38,    -1,    40,    25,    -1,    -1,    44,
    45,     3,     4,     5,    -1,    34,    35,    -1,    -1,    38,
    -1,    40,    -1,    15,    -1,    44,    45,    -1,    -1,    -1,
    -1,    -1,    -1,    25,    19,    20,    21,    22,    23,    24,
    -1,    -1,    34,    35,    -1,    -1,    38,    -1,    -1,    -1,
    -1,    -1,    44,    45
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

case 4:
#line 42 "parser.y"
{
						yyerrok;
						printError(illch);	/* error - Lillegal character */
					;
    break;}
case 7:
#line 50 "parser.y"
{
						yyerrok;
						printError(wrong_st);	/* error - Wrong Statement */
					;
    break;}
case 8:
#line 55 "parser.y"
{
						yyerrok;
						printError(nobrace);	/* error - Missing brace */
					;
    break;}
case 11:
#line 63 "parser.y"
{
						yyerrok;
						printError(wrong_funcdef);	/* error - Wrong function definition */
					;
    break;}
case 19:
#line 80 "parser.y"
{returntp = 1;;
    break;}
case 20:
#line 81 "parser.y"
{returntp = 2;;
    break;}
case 21:
#line 82 "parser.y"
{returntp = 0;;
    break;}
case 22:
#line 85 "parser.y"
{
						curid->tp = 4;
						curid->rtp = returntp;
						preid = curid;
						paramidx = 0;
					;
    break;}
case 24:
#line 94 "parser.y"
{
						yyerrok;
						printError(noparen);	/* error - Missing paren */
					;
    break;}
case 29:
#line 106 "parser.y"
{
						curid->tp = type;
						preid->param[paramidx++] = curid->index;
						preid->paramnum++;
					;
    break;}
case 31:
#line 114 "parser.y"
{
						yyerrok;
						printError(nobrace);	/* error - Missing brace */
					;
    break;}
case 37:
#line 127 "parser.y"
{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					;
    break;}
case 38:
#line 132 "parser.y"
{
						yyerrok;
						printError(wrong_dcl);	/* error - wrong declaration */
					;
    break;}
case 44:
#line 145 "parser.y"
{
						if (returntp == 1) {type = 0; curid->tp = 0;}
						else if (returntp == 2) {type = 2; curid->tp = 2;}
					;
    break;}
case 45:
#line 150 "parser.y"
{
						if (returntp == 1) {type = 1; curid->tp = 1; returntp = type = -1;}
						else if (returntp == 2) {type = 3; curid->tp = 3; returntp = type = -1;}
					;
    break;}
case 46:
#line 155 "parser.y"
{
						yyerrok;
						printError(nosquare);	/* error - Missing square */
					;
    break;}
case 59:
#line 177 "parser.y"
{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					;
    break;}
case 66:
#line 192 "parser.y"
{
						yyerrok;
						printError(nosemi);	/* error - Missing semicolon */
					;
    break;}
case 70:
#line 202 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 72:
#line 208 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 74:
#line 214 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 76:
#line 220 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 78:
#line 226 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 80:
#line 232 "parser.y"
{
						yyerrok;
						printError(wrong_asgn);	/* error - Wrong assignment */
					;
    break;}
case 83:
#line 240 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 86:
#line 248 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 89:
#line 256 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 91:
#line 262 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 99:
#line 276 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 101:
#line 282 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 104:
#line 290 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 106:
#line 296 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 108:
#line 302 "parser.y"
{
						yyerrok;
						printError(wrong_op);	/* error - Wrong operation */
					;
    break;}
case 129:
#line 334 "parser.y"
{
						yyerrok;
						printError(toolong);	/* error - too long identifier */
					;
    break;}
case 130:
#line 339 "parser.y"
{
						yyerrok;
						printError(startwd);		/* error - Start with digit identifier */
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
#line 344 "parser.y"


