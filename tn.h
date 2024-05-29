/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

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
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     TIDENT = 258,
     TNUMBER = 259,
     TCONST = 260,
     TELSE = 261,
     TIF = 262,
     TINT = 263,
     TRETURN = 264,
     TVOID = 265,
     TWHILE = 266,
     TADD = 267,
     TSUB = 268,
     TMUL = 269,
     TDIV = 270,
     TMOD = 271,
     TASSIGN = 272,
     TADDASSIGN = 273,
     TSUBASSIGN = 274,
     TMULASSIGN = 275,
     TDIVASSIGN = 276,
     TMODASSIGN = 277,
     TNOT = 278,
     TOR = 279,
     TAND = 280,
     TEQUAL = 281,
     TNOTEQU = 282,
     TGREAT = 283,
     TLESS = 284,
     TGREATE = 285,
     TLESSE = 286,
     TINC = 287,
     TDEC = 288,
     TCOMMA = 289,
     TSEMICOLON = 290,
     TLPAREN = 291,
     TRPAREN = 292,
     TLBRACE = 293,
     TRBRACE = 294,
     TLSQUARE = 295,
     TRSQUARE = 296,
     TTOOLONG = 297,
     TILLIDENT = 298,
     TILLCH = 299,
     TLOWERTHANELSE = 300
   };
#endif
/* Tokens.  */
#define TIDENT 258
#define TNUMBER 259
#define TCONST 260
#define TELSE 261
#define TIF 262
#define TINT 263
#define TRETURN 264
#define TVOID 265
#define TWHILE 266
#define TADD 267
#define TSUB 268
#define TMUL 269
#define TDIV 270
#define TMOD 271
#define TASSIGN 272
#define TADDASSIGN 273
#define TSUBASSIGN 274
#define TMULASSIGN 275
#define TDIVASSIGN 276
#define TMODASSIGN 277
#define TNOT 278
#define TOR 279
#define TAND 280
#define TEQUAL 281
#define TNOTEQU 282
#define TGREAT 283
#define TLESS 284
#define TGREATE 285
#define TLESSE 286
#define TINC 287
#define TDEC 288
#define TCOMMA 289
#define TSEMICOLON 290
#define TLPAREN 291
#define TRPAREN 292
#define TLBRACE 293
#define TRBRACE 294
#define TLSQUARE 295
#define TRSQUARE 296
#define TTOOLONG 297
#define TILLIDENT 298
#define TILLCH 299
#define TLOWERTHANELSE 300




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

