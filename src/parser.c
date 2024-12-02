#ifndef lint
static const char yysccsid[] = "@(#)yaccpar	1.9 (Berkeley) 02/21/93";
#endif

#define YYBYACC 1
#define YYMAJOR 1
#define YYMINOR 9
#define YYPATCH 20130304

#define YYEMPTY        (-1)
#define yyclearin      (yychar = YYEMPTY)
#define yyerrok        (yyerrflag = 0)
#define YYRECOVERING() (yyerrflag != 0)

#define YYPREFIX "yy"

#define YYPURE 0

#line 2 "parser.y"
/*
 * CDDL HEADER START
 *
 * The contents of this file are subject to the terms of the
 * Common Development and Distribution License, Version 1.0 only
 * (the "License").  You may not use this file except in compliance
 * with the License.
 *
 * You can obtain a copy of the license at usr/src/OPENSOLARIS.LICENSE
 * or http://www.opensolaris.org/os/licensing.
 * See the License for the specific language governing permissions
 * and limitations under the License.
 *
 * When distributing Covered Code, include this CDDL HEADER in each
 * file and include the License file at usr/src/OPENSOLARIS.LICENSE.
 * If applicable, add the following below this CDDL HEADER, with the
 * fields enclosed by brackets "[]" replaced with your own identifying
 * information: Portions Copyright [yyyy] [name of copyright owner]
 *
 * CDDL HEADER END
 */
#line 35 "parser.y"
/*	from OpenSolaris "parser.y	6.15	05/06/10 SMI"	*/

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)parser.y	1.8 (gritter) 11/26/05
 */

void yyerror(char *);

#include <ctype.h>
#include <wchar.h>
#include <inttypes.h>
#ifndef	__sun
#define	wcsetno(c)	0
#endif

#line 75 "parser.y"
#include "ldefs.c"

#define YYSTYPE union _yystype_
union _yystype_
{
	int	i;
	CHR	*cp;
};
int	peekon = 0; /* need this to check if "^" came in a definition section */

#line 88 "parser.y"
int i;
int j,k;
int g;
CHR *p;
static wchar_t  L_PctUpT[]= {'%', 'T', 0};
static wchar_t  L_PctLoT[]= {'%', 't', 0};
static wchar_t  L_PctCbr[]= {'%', '}', 0};
#line 78 "y.tab.c"

#ifndef YYSTYPE
typedef int YYSTYPE;
#endif

/* compatibility with bison */
#ifdef YYPARSE_PARAM
/* compatibility with FreeBSD */
# ifdef YYPARSE_PARAM_TYPE
#  define YYPARSE_DECL() yyparse(YYPARSE_PARAM_TYPE YYPARSE_PARAM)
# else
#  define YYPARSE_DECL() yyparse(void *YYPARSE_PARAM)
# endif
#else
# define YYPARSE_DECL() yyparse(void)
#endif

/* Parameters sent to lex. */
#ifdef YYLEX_PARAM
# define YYLEX_DECL() yylex(void *YYLEX_PARAM)
# define YYLEX yylex(YYLEX_PARAM)
#else
# define YYLEX_DECL() yylex(void)
# define YYLEX yylex()
#endif

/* Parameters sent to yyerror. */
#ifndef YYERROR_DECL
#define YYERROR_DECL() yyerror(const char *s)
#endif
#ifndef YYERROR_CALL
#define YYERROR_CALL(msg) yyerror(msg)
#endif

extern int YYPARSE_DECL();

#define CHAR 257
#define CCL 258
#define NCCL 259
#define STR 260
#define DELIM 261
#define SCON 262
#define ITER 263
#define NEWE 264
#define NULLS 265
#define XSCON 266
#define ARRAY 267
#define POINTER 268
#define CAT 269
#define YYERRCODE 256
static const short yylhs[] = {                           -1,
    0,    1,    1,    1,    5,    5,    2,    2,    3,    4,
    4,    6,    6,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,    7,    7,    7,    7,    7,
    7,    7,    7,    7,    7,
};
static const short yylen[] = {                            2,
    1,    4,    3,    1,    1,    0,    3,    0,    1,    2,
    1,    2,    2,    1,    1,    1,    1,    1,    2,    2,
    2,    3,    2,    3,    5,    3,    4,    2,    2,    2,
    2,    3,    1,    1,    1,
};
static const short yydefred[] = {                         0,
    4,    0,    1,    0,    0,    9,    0,    7,    0,   14,
   17,   18,   15,    0,   33,    0,   34,   35,    0,    0,
   16,    5,    0,    3,   11,    0,   13,    0,    0,    0,
    0,    2,   10,    0,   12,    0,   31,    0,   19,   20,
   21,    0,   32,    0,   26,    0,    0,    0,   27,   25,
};
static const short yydgoto[] = {                          2,
    3,    4,   22,   23,   24,   25,   42,
};
static const short yysindex[] = {                      -255,
    0,    0,    0, -252, -245,    0,   33,    0, -259,    0,
    0,    0,    0,   45,    0,   45,    0,    0,   45,   45,
    0,    0,   33,    0,    0,  -36,    0,   14,   14,   80,
  -24,    0,    0,  -41,    0,   45,    0,   45,    0,    0,
    0,  -22,    0, -123,    0,   23,   89, -100,    0,    0,
};
static const short yyrindex[] = {                      -247,
    0,    0,    0,    0,    0,    0,   26,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   26,    0,    0,    0,    0,   60,   68,    2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  -12,    0,    0,    0,   52,   -5,    0,    0,    0,
};
static const short yygindex[] = {                         0,
    0,    0,   28,    0,    7,   10,  130,
};
#define YYTABLESIZE 354
static const short yytable[] = {                         37,
    1,   49,   44,   20,   27,   39,   40,    5,    6,   21,
   36,   37,    8,    8,    8,   20,   43,   39,   40,   39,
   40,   21,   36,   23,   50,    6,   41,   23,   23,   32,
   22,    7,   33,   23,   23,   22,    0,   30,   41,    0,
   41,   22,   30,    0,    0,    0,    0,    0,   30,   37,
    0,    0,    0,   20,    0,   39,   40,   19,   37,   21,
   36,    0,   20,    0,   39,   40,    0,    0,   21,   19,
    0,    0,   20,    0,    0,    0,   41,    0,   21,    0,
    0,   23,    0,   45,   20,   41,    0,   38,   22,    0,
   21,    0,   24,    0,    0,   30,    0,    0,   24,   38,
   28,    0,    0,    0,    0,    0,    0,   19,   29,    0,
    0,   23,    0,    0,    0,    0,   19,    0,   22,   20,
    0,   39,   40,    0,    0,   21,   19,    0,   20,    0,
   39,   40,    0,    0,   21,    0,   26,   38,   19,   48,
    0,    0,   41,   28,    0,   29,   38,    0,   30,   31,
    0,   41,   26,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   46,    0,   47,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   38,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   10,   11,   12,   13,    0,   14,   34,   35,   15,   16,
   17,   18,   10,   11,   12,   13,    0,   14,   34,    0,
   15,   16,   17,   18,   23,   23,   23,   23,    0,   23,
   23,   23,   23,   23,   23,   23,   22,    0,   22,    0,
   22,   22,   22,   30,    0,   30,    0,   30,   30,   30,
   10,   11,   12,   13,    0,    0,   34,    0,   15,   10,
   11,   12,   13,    0,    0,   34,    0,   15,    9,   10,
   11,   12,   13,    6,   14,    0,    0,   15,   16,   17,
   18,   10,   11,   12,   13,    0,   14,    0,    0,   15,
   16,   17,   18,   24,    0,   24,    0,   24,   24,   24,
    0,   28,    0,   28,    0,   28,   28,   28,    0,   29,
    0,   29,    0,   29,   29,   29,   10,   11,   12,   13,
    0,    0,   34,    0,   15,   10,   11,   12,   13,    0,
    0,   34,    0,   15,
};
static const short yycheck[] = {                         36,
  256,  125,   44,   40,  264,   42,   43,  260,  261,   46,
   47,   36,  260,  261,  260,   40,   41,   42,   43,   42,
   43,   46,   47,   36,  125,    0,   63,   40,   41,   23,
   36,    4,   23,   46,   47,   41,   -1,   36,   63,   -1,
   63,   47,   41,   -1,   -1,   -1,   -1,   -1,   47,   36,
   -1,   -1,   -1,   40,   -1,   42,   43,   94,   36,   46,
   47,   -1,   40,   -1,   42,   43,   -1,   -1,   46,   94,
   -1,   -1,   40,   -1,   -1,   -1,   63,   -1,   46,   -1,
   -1,   94,   -1,  125,   40,   63,   -1,  124,   94,   -1,
   46,   -1,   41,   -1,   -1,   94,   -1,   -1,   47,  124,
   41,   -1,   -1,   -1,   -1,   -1,   -1,   94,   41,   -1,
   -1,  124,   -1,   -1,   -1,   -1,   94,   -1,  124,   40,
   -1,   42,   43,   -1,   -1,   46,   94,   -1,   40,   -1,
   42,   43,   -1,   -1,   46,   -1,    7,  124,   94,  263,
   -1,   -1,   63,   14,   -1,   16,  124,   -1,   19,   20,
   -1,   63,   23,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   36,   -1,   38,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  124,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  257,  258,  259,  260,   -1,  262,  263,  264,  265,  266,
  267,  268,  257,  258,  259,  260,   -1,  262,  263,   -1,
  265,  266,  267,  268,  257,  258,  259,  260,   -1,  262,
  263,  264,  265,  266,  267,  268,  262,   -1,  264,   -1,
  266,  267,  268,  262,   -1,  264,   -1,  266,  267,  268,
  257,  258,  259,  260,   -1,   -1,  263,   -1,  265,  257,
  258,  259,  260,   -1,   -1,  263,   -1,  265,  256,  257,
  258,  259,  260,  261,  262,   -1,   -1,  265,  266,  267,
  268,  257,  258,  259,  260,   -1,  262,   -1,   -1,  265,
  266,  267,  268,  262,   -1,  264,   -1,  266,  267,  268,
   -1,  262,   -1,  264,   -1,  266,  267,  268,   -1,  262,
   -1,  264,   -1,  266,  267,  268,  257,  258,  259,  260,
   -1,   -1,  263,   -1,  265,  257,  258,  259,  260,   -1,
   -1,  263,   -1,  265,
};
#define YYFINAL 2
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 269
#if YYDEBUG
static const char *yyname[] = {

"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,"'$'",0,0,0,"'('","')'","'*'","'+'","','",0,"'.'","'/'",0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,"'?'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
"'^'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'|'","'}'",0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,"CHAR","CCL","NCCL","STR","DELIM","SCON","ITER","NEWE",
"NULLS","XSCON","ARRAY","POINTER","CAT",
};
static const char *yyrule[] = {
"$accept : acc",
"acc : lexinput",
"lexinput : defns delim prods end",
"lexinput : defns delim end",
"lexinput : error",
"end : delim",
"end :",
"defns : defns STR STR",
"defns :",
"delim : DELIM",
"prods : prods pr",
"prods : pr",
"pr : r NEWE",
"pr : error NEWE",
"r : CHAR",
"r : STR",
"r : '.'",
"r : CCL",
"r : NCCL",
"r : r '*'",
"r : r '+'",
"r : r '?'",
"r : r '|' r",
"r : r r",
"r : r '/' r",
"r : r ITER ',' ITER '}'",
"r : r ITER '}'",
"r : r ITER ',' '}'",
"r : SCON r",
"r : XSCON r",
"r : '^' r",
"r : r '$'",
"r : '(' r ')'",
"r : NULLS",
"r : ARRAY",
"r : POINTER",

};
#endif

int      yydebug;
int      yynerrs;

int      yyerrflag;
int      yychar;
YYSTYPE  yyval;
YYSTYPE  yylval;

/* define the initial stack-sizes */
#ifdef YYSTACKSIZE
#undef YYMAXDEPTH
#define YYMAXDEPTH  YYSTACKSIZE
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 10000
#define YYMAXDEPTH  500
#endif
#endif

#define YYINITSTACKSIZE 500

typedef struct {
    unsigned stacksize;
    short    *s_base;
    short    *s_mark;
    short    *s_last;
    YYSTYPE  *l_base;
    YYSTYPE  *l_mark;
} YYSTACKDATA;
/* variables for the parser stack */
static YYSTACKDATA yystack;
#line 292 "parser.y"
int
yylex(void)
{
	CHR *p;
	int  i;
	CHR *xp;
	int lex_startcond_lookupval;
	CHR  *t, c;
	int n, j = 0, k, x;
	CHR ch;
	static int sectbegin;
	static CHR token[TOKENSIZE];
	static int iter;
	int ccs; /* Current CodeSet. */
	CHR *ccp;
	int exclusive_flag;	/* XCU4: exclusive start flag */

# ifdef DEBUG
	yylval.i = 0;
# endif

	if(sect == DEFSECTION) {		/* definitions section */
		while(!eof) {
			if(prev == '\n'){    /* next char is at beginning of line */
				getl(p=buf);
				switch(*p){
				case '%':
					switch(c= *(p+1)){
					case '%':
						if(scomp(p, (CHR *)"%%")) {
							p++;
							while(*(++p))
								if(!space(*p)) {
									warning("invalid string following %%%% be ignored");
									break;
								}
						}
						lgate();
						if(!ratfor)fprintf(fout,"`");
						fprintf(fout,"define YYNEWLINE %d\n",ctable['\n']);
						if(!ratfor) {
							fprintf(fout,"function int yylex();\n\tautomatic int nstr = 0; //int yyprevious;\n");
						}
						sectbegin = TRUE;
						i = treesize*(sizeof(*name)+sizeof(*left)+
							sizeof(*right)+sizeof(*nullstr)+sizeof(*parent))+ALITTLEEXTRA;
						p = myalloc(i,1);
						if(p == NULL)
							error("Too little core for parse tree");
						free(p);
						name = myalloc(treesize,sizeof(*name));
						left = myalloc(treesize,sizeof(*left));
						right = myalloc(treesize,sizeof(*right));
						nullstr = myalloc(treesize,sizeof(*nullstr));
						parent = myalloc(treesize,sizeof(*parent));
						if(name == 0 || left == 0 || right == 0 || parent == 0 || nullstr == 0)
							error("Too little core for parse tree");
						return(freturn(DELIM));
					case 'p': case 'P':
					        /* %p or %pointer */
						if ((*(p+2) == 'o') ||
						    (*(p+2) == 'O')) {
						    if(lgatflg)
							error("Too late for %%pointer");
						    while(*p && !iswspace(*p))
							p++;
						    isArray = 0;
						    continue;
						}
						/* has overridden number of positions */
						p += 2;
						maxpos = siconv(p);
						if (maxpos<=0)error("illegal position number");
# ifdef DEBUG
						if (debug) printf("positions (%%p) now %d\n",maxpos);
# endif
						if(report == 2)report = 1;
						continue;
					case 'n': case 'N':	/* has overridden number of states */
						p += 2;
						nstates = siconv(p);
						if(nstates<=0)error("illegal state number");
# ifdef DEBUG
						if(debug)printf( " no. states (%%n) now %d\n",nstates);
# endif
						if(report == 2)report = 1;
						continue;
					case 'e': case 'E':		/* has overridden number of tree nodes */
						p += 2;
						treesize = siconv(p);
						if(treesize<=0)error("illegal number of parse tree nodes");
# ifdef DEBUG
						if (debug) printf("treesize (%%e) now %d\n",treesize);
# endif
						if(report == 2)report = 1;
						continue;
					case 'o': case 'O':
						p += 2;
						outsize = siconv(p);
						if(outsize<=0)error("illegal size of output array");
						if (report ==2) report=1;
						continue;
					case 'a': case 'A':
					        /* %a or %array */
						if ((*(p+2) == 'r') ||
						    (*(p+2) == 'R')) {
						    if(lgatflg)
							error("Too late for %%array");
						    while(*p && !iswspace(*p))
							p++;
						    isArray = 1;
						    continue;
						}
						/* has overridden number of transitions */
						p += 2;
						ntrans = siconv(p);
						if(ntrans<=0)error("illegal translation number");
# ifdef DEBUG
						if (debug)printf("N. trans (%%a) now %d\n",ntrans);
# endif
						if(report == 2)report = 1;
						continue;
					case 'k': case 'K': /* overriden packed char classes */
						p += 2;
						free(pchar);
						pchlen = siconv(p);
						if(pchlen<=0)error("illegal number of packed character class");
# ifdef DEBUG
						if (debug) printf( "Size classes (%%k) now %d\n",pchlen);
# endif
						pchar=pcptr=myalloc(pchlen, sizeof(*pchar));
						if (report==2) report=1;
						continue;
					case 't': case 'T': 	/* character set specifier */
						if(handleeuc)
							error("\
Character table (%t) is supported only in ASCII compatibility mode.\n");
						ZCH = wcstol(p+2, NULL, 10);
						if (ZCH < NCH) ZCH = NCH;
						if (ZCH > 2*NCH) error("ch table needs redeclaration");
						chset = TRUE;
						for(i = 0; i<ZCH; i++)
							ctable[i] = 0;
						while(getl(p) && scomp(p,L_PctUpT) != 0 && scomp(p,L_PctLoT) != 0){
							if((n = siconv(p)) <= 0 || n > ZCH){
								error("Character value %d out of range",n);
								continue;
								}
							while(digit(*p)) p++;
							if(!iswspace(*p)) error("bad translation format");
							while(iswspace(*p)) p++;
							t = p;
							while(*t){
								c = ctrans(&t);
								if(ctable[(unsigned)c]){
									if (iswprint(c))
										warning("Character '%lc' used twice",c);

									else
										error("Chararter %o used twice",c);
									}
								else ctable[(unsigned)c] = n;
								t++;
								}
							p = buf;
							}
						{
						char chused[2*NCH]; int kr;
						for(i=0; i<ZCH; i++)
							chused[i]=0;
						for(i=0; i<NCH; i++)
							chused[ctable[i]]=1;
						for(kr=i=1; i<NCH; i++)
							if (ctable[i]==0)
								{
								while (chused[kr] == 0)
									kr++;
								ctable[i]=kr;
								chused[kr]=1;
								}
						}
						lgate();
						continue;
					case 'r': case 'R':
						c = 'r';
						/* FALLTHRU */
					case 'c': case 'C':
						if(lgatflg)
							error("Too late for language specifier");
						ratfor = (c == 'r');
						continue;
					case '{':
						lgate();
						while(getl(p) && scomp(p, L_PctCbr) != 0)
							if(p[0]=='/' && p[1]=='*')
								cpycom(p);
							else
								fprintf(fout,"%ls\n",p);
						if(p[0] == '%') continue;
						if (*p) error("EOF before %%%%");
						else error("EOF before %%}");
						break;

					case 'x': case 'X':		/* XCU4: exclusive start conditions */
						exclusive_flag = 1;
						goto start;

					case 's': case 'S':		/* start conditions */
						exclusive_flag = 0;
start:
						lgate();

						while(*p && !iswspace(*p) && ((*p) != (wchar_t)',')) p++;
						n = TRUE;
						while(n){
							while(*p && (iswspace(*p) || ((*p) == (wchar_t)','))) p++;
							t = p;
							while(*p && !iswspace(*p) && ((*p) != (wchar_t)',')) {
							    if(!isascii(*p))
								error("None-ASCII characters in start condition.");
							    p++;
							}
							if(!*p) n = FALSE;
							*p++ = 0;
							if (*t == 0) continue;
							i = sptr*2;
							if(!ratfor)fprintf(fout,"`");
							fprintf(fout,"define %ls %d\n",t,i);
							scopy(t,sp);
							sname[sptr] = sp;
							/* XCU4: save exclusive flag with start name */
							exclusive[sptr++] = exclusive_flag;
							sname[sptr] = 0;	/* required by lookup */
							if(sptr >= STARTSIZE)
								error("Too many start conditions");
							sp += slength(sp) + 1;
							if(sp >= schar+STARTCHAR)
								error("Start conditions too long");
							}
						continue;
					default:
						error("Invalid request %s",p);
						continue;
						}	/* end of switch after seeing '%' */
					break;
				case ' ': case '\t':		/* must be code */
					lgate();
					if( p[1]=='/' && p[2]=='*' ) cpycom(p);
					else fprintf(fout, "%ls\n",p);
					continue;
				case '/':	/* look for comments */
					lgate();
					if((*(p+1))=='*') cpycom(p);
					/* FALLTHRU */
				default:		/* definition */
					while(*p && !iswspace(*p)) p++;
					if(*p == 0)
						continue;
					prev = *p;
					*p = 0;
					bptr = p+1;
					yylval.cp = (CHR *)buf;
					if(digit(buf[0]))
						warning("Substitution strings may not begin with digits");
					return(freturn(STR));
				}
			} else { /* still sect 1, but prev != '\n' */
				p = bptr;
				while(*p && iswspace(*p)) p++;
				if(*p == 0)
					warning("No translation given - null string assumed");
				scopy(p,token);
				yylval.cp = (CHR *)token;
				prev = '\n';
				return(freturn(STR));
				}
			}
		error("unexpected EOF before %%%%");
		/* end of section one processing */
	} else if(sect == RULESECTION){		/* rules and actions */
		lgate();
		while(!eof){
			static int first_test=TRUE, first_value;
			static int reverse=FALSE;
			switch(c=gch()){
			case '\0':
				if(n_error)error_tail();
				return(freturn(0));
			case '\n':
				if(prev == '\n') continue;
				x = NEWE;
				break;
			case ' ':
			case '\t':
				if(prev == '\n') copy_line = TRUE;
				if(sectbegin == TRUE){
					cpyact();
					copy_line = FALSE;
					while((c=gch()) && c != '\n');
					continue;
					}
				if(!funcflag)phead2();
				funcflag = TRUE;
				if(ratfor)fprintf(fout,"%d\n",30000+casecount);
				else fprintf(fout,"      %d: ",casecount);
				if(cpyact()){
					if(ratfor)fprintf(fout,"goto 30997\n");
					else fprintf(fout,"");
					}
				while((c=gch()) && c != '\n') {
					if (c=='/') {
						if((c=gch())=='*') {
							c=gch();
							while(c !=EOF) {
								while (c=='*')
									if ((c=gch()) == '/') goto w_loop;
								c = gch();
							}
							error("EOF inside comment");
						} else
							warning("undefined string");
					} else if (c=='}')
						error("illegal extra \"}\"");
				w_loop: ;
				}
				/* while ((c=gch())== ' ' || c == '\t') ; */
				/* if (!space(c)) error("undefined action string"); */
				if(peek == ' ' || peek == '\t' || sectbegin == TRUE){
					fatal = 0;
					n_error++;
					error("executable statements should occur right after %%%%");
					fatal = 1;
					continue;
					}
				x = NEWE;
				break;
			case '%':
				if(prev != '\n') goto character;
				if(peek == '{'){	/* included code */
					getl(buf);
					while(!eof&& getl(buf) && scomp(L_PctCbr,buf)!=0)
						if(buf[0]=='/' && buf[1]=='*')
							cpycom(buf);
						else
							fprintf(fout,"%ls\n",buf);
					continue;
					}
				if(peek == '%'){
					c = gch();
					c = gch();
					x = DELIM;
					break;
					}
				goto character;
			case '|':
				if(peek == ' ' || peek == '\t' || peek == '\n'){
					if(ratfor)fprintf(fout,"%d\n",30000+casecount++);
					else fprintf(fout,"case %d:\n",casecount++);
					continue;
					}
				x = '|';
				break;
			case '$':
				if(peek == '\n' || peek == ' ' || peek == '\t' || peek == '|' || peek == '/'){
					x = c;
					break;
					}
				goto character;
			case '^':
                                if(peekon && (prev == '}')){
                                        x = c;
                                        break;
                                }
				if(prev != '\n' && scon != TRUE) goto character;
				/* valid only at line begin */
				x = c;
				break;
			case '?':
			case '+':
			case '*':
				if(prev == '\n' ) {
					fatal = 0;
					n_error++;
					error("illegal operator -- %c",c);
					fatal = 1;
				}
				/* FALLTHRU */
			case '.':
			case '(':
			case ')':
			case ',':
			case '/':
				x = c;
				break;
			case '}':
				iter = FALSE;
				x = c;
				break;
			case '{':	/* either iteration or definition */
				if(digit(c=gch())){	/* iteration */
					iter = TRUE;
					if(prev=='{') first_test = TRUE;
				ieval:
					i = 0;
					while(digit(c)){
						token[i++] = c;
						c = gch();
						}
					token[i] = 0;
					yylval.i = siconv(token);
					if(first_test) {
						first_test = FALSE;
						first_value = yylval.i;
					} else
						if(first_value>yylval.i)warning("the values between braces are reversed");
					ch = c;
					munput('c',&ch);
					x = ITER;
					break;
					}
				else {		/* definition */
					i = 0;
					while(c && c!='}'){
						token[i++] = c;
						if(i >= TOKENSIZE)
							error("definition too long");
						c = gch();
						}
					token[i] = 0;
					i = lookup(token,def);
					if(i < 0)
						error("definition %ls not found",token);
					else
						munput('s',(CHR *)(subs[i]));
            				if (peek == '^')
                                                peekon = 1;
					continue;
					}
			case '<':		/* start condition ? */
				if(prev != '\n')  /* not at line begin, not start */
					goto character;
				t = slptr;
				do {
					i = 0;
					if(!isascii(c = gch()))
					    error("Non-ASCII characters in start condition.");
					while(c != ',' && c && c != '>'){
						token[i++] = c;
						if(i >= TOKENSIZE)
							error("string name too long");
						if(!isascii(c = gch()))
						    error("None-ASCII characters in start condition.");
						}
					token[i] = 0;
					if(i == 0)
						goto character;
					i = lookup(token,sname);
					lex_startcond_lookupval = i;
					if(i < 0) {
						fatal = 0;
						n_error++;
						error("undefined start condition %ls",token);
						fatal = 1;
						continue;
						}
					*slptr++ = i+1;
					} while(c && c != '>');
				*slptr++ = 0;
				/* check if previous value re-usable */
				for (xp=slist; xp<t; )
					{
					if (scomp(xp, t)==0)
						break;
					while (*xp++);
					}
				if (xp<t)
					{
					/* re-use previous pointer to string */
					slptr=t;
					t=xp;
					}
				if(slptr > slist+STARTSIZE)	/* note not packed */
					error("Too many start conditions used");
				yylval.cp = (CHR *)t;

				/* XCU4: add XSCON */

				if (exclusive[lex_startcond_lookupval])
					x = XSCON;
				else
					x = SCON;
				break;
			case '"':
				i = 0;
				while((c=gch()) && c != '"' && c != '\n'){
					if(c == '\\') c = usescape(c=gch());
					remch(c);
					token[i++] = c;
					if(i >= TOKENSIZE){
						warning("String too long");
						i = TOKENSIZE-1;
						break;
						}
					}
				if(c == '\n') {
					yyline--;
					warning("Non-terminated string");
					yyline++;
					}
				token[i] = 0;
				if(i == 0)x = NULLS;
				else if(i == 1){
					yylval.i = (unsigned)token[0];
					x = CHAR;
					}
				else {
					yylval.cp = (CHR *)token;
					x = STR;
					}
				break;
			case '[':
				reverse = FALSE;
				x = CCL;
				if((c = gch()) == '^'){
					x = NCCL;
					reverse = TRUE;
					c = gch();
					}
				i = 0;
				while(c != ']' && c){
					static int light=TRUE, ESCAPE=FALSE;
					if(c == '-' && prev == '^' && reverse){
						symbol[(unsigned)c] = 1;
						c = gch();
						continue;
					}
					if(c == '\\') {
						c = usescape(c=gch());
						ESCAPE = TRUE;
					}
					if(c=='-' && !ESCAPE && prev!='[' && peek!=']'){
					/* range specified */
						if (light) {
							c = gch();
							if(c == '\\') 
								c=usescape(c=gch());
							remch(c);
							k = c;
							ccs=wcsetno(k);
							if(wcsetno(j)!=ccs)
							    error("\
Character range specified between different codesets.");
							if((unsigned)j > (unsigned)k) {
								n = j;
								j = k;
								k = n;
								}
							if(!handleeuc)
							if(!(('A'<=j && k<='Z') ||
						     	     ('a'<=j && k<='z') ||
						     	     ('0'<=j && k<='9')))
								warning("Non-portable Character Class");
							token[i++] = RANGE;
							token[i++] = j;
							token[i++] = k;
							light = FALSE;
						} else {
							error("unmatched hyphen");
							if(symbol[(unsigned)c])warning("\"%c\" redefined inside brackets",c);
							else symbol[(unsigned)c] = 1;
						}
						ESCAPE = FALSE;
					} else {
						j = c;
						remch(c);
						token[i++] = c; /* Remember whatever.*/
						light = TRUE;
						ESCAPE = FALSE;
					}
					c = gch();
				}
				/* try to pack ccl's */

				token[i] = 0;
				ccp = ccl;
				while (ccp < ccptr && scomp(token, ccp) != 0) ccp++;
				if (ccp < ccptr) {  /* found in ccl */
				    yylval.cp = ccp;
				} else {            /* not in ccl, add it */
				    scopy(token,ccptr);
				    yylval.cp = ccptr;
				    ccptr += slength(token) + 1;
				    if(ccptr >= ccl+CCLSIZE)
				      error("Too many large character classes");
				}
				break;
			case '\\':
				c = usescape(c=gch());
			default:
			character:
				if(iter){	/* second part of an iteration */
					iter = FALSE;
					if('0' <= c && c <= '9')
						goto ieval;
					}
				remch(c);
				if(alpha(peek)){
					i = 0;
					yylval.cp = (CHR *)token;
					token[i++] = c;
					while(alpha(peek)) {
						remch(token[i++] = gch());
						if(i >= TOKENSIZE) {
							warning("string too long");
							i = TOKENSIZE - 1;
							break;
							}
						}
					if(peek == '?' || peek == '*' || peek == '+')
						munput('c',&token[--i]);
					token[i] = 0;
					if(i == 1){
						yylval.i = (unsigned)(token[0]);
						x = CHAR;
						}
					else x = STR;
					}
				else {
					yylval.i = (unsigned)c;
					x = CHAR;
					}
				}
			scon = FALSE;
			peekon = 0;
			if((x == SCON) || (x == XSCON))
				scon = TRUE;
			sectbegin = FALSE;
			return(freturn(x));
			/* NOTREACHED */
			}
		}
	/* section three */
	lgate();
	ptail();
# ifdef DEBUG
	if(debug)
		fprintf(fout,"\n/*this comes from section three - debug */\n");
# endif

	if(getl(buf) && !eof) {
  		if (sargv[optind] == NULL)
			fprintf(fout, "\n/*# line %d */\n", yyline-1);
		else	
			fprintf(fout,
				"\n/*# line %d \"%s\"*/\n", yyline-1, sargv[optind]);
		fprintf(fout,"%ls\n",buf);
		while(getl(buf) && !eof)
			fprintf(fout,"%ls\n",buf);
        }

	return(freturn(0));
	}
/* end of yylex */
# ifdef DEBUG
freturn(i)
  int i; {
	if(yydebug) {
		printf("now return ");
		if((unsigned)i < NCH) allprint(i);
		else printf("%d",i);
		printf("   yylval = ");
		switch(i){
			case STR: case CCL: case NCCL:
				strpt(yylval.cp);
				break;
			case CHAR:
				allprint(yylval.i);
				break;
			default:
				printf("%d",yylval.i);
				break;
			}
		putchar('\n');
		}
	return(i);
	}
# endif
#line 1025 "y.tab.c"

#if YYDEBUG
#include <stdio.h>		/* needed for printf */
#endif

#include <stdlib.h>	/* needed for malloc, etc */
#include <string.h>	/* needed for memset */

/* allocate initial stack or double stack size, up to YYMAXDEPTH */
static int yygrowstack(YYSTACKDATA *data)
{
    int i;
    unsigned newsize;
    short *newss;
    YYSTYPE *newvs;

    if ((newsize = data->stacksize) == 0)
        newsize = YYINITSTACKSIZE;
    else if (newsize >= YYMAXDEPTH)
        return -1;
    else if ((newsize *= 2) > YYMAXDEPTH)
        newsize = YYMAXDEPTH;

    i = (int) (data->s_mark - data->s_base);
    newss = (short *)realloc(data->s_base, newsize * sizeof(*newss));
    if (newss == 0)
        return -1;

    data->s_base = newss;
    data->s_mark = newss + i;

    newvs = (YYSTYPE *)realloc(data->l_base, newsize * sizeof(*newvs));
    if (newvs == 0)
        return -1;

    data->l_base = newvs;
    data->l_mark = newvs + i;

    data->stacksize = newsize;
    data->s_last = data->s_base + newsize - 1;
    return 0;
}

#if YYPURE || defined(YY_NO_LEAKS)
static void yyfreestack(YYSTACKDATA *data)
{
    free(data->s_base);
    free(data->l_base);
    memset(data, 0, sizeof(*data));
}
#else
#define yyfreestack(data) /* nothing */
#endif

#define YYABORT  goto yyabort
#define YYREJECT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR  goto yyerrlab

int
YYPARSE_DECL()
{
    int yym, yyn, yystate;
#if YYDEBUG
    const char *yys;

    if ((yys = getenv("YYDEBUG")) != 0)
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = YYEMPTY;
    yystate = 0;

#if YYPURE
    memset(&yystack, 0, sizeof(yystack));
#endif

    if (yystack.s_base == NULL && yygrowstack(&yystack)) goto yyoverflow;
    yystack.s_mark = yystack.s_base;
    yystack.l_mark = yystack.l_base;
    yystate = 0;
    *yystack.s_mark = 0;

yyloop:
    if ((yyn = yydefred[yystate]) != 0) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, reading %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: state %d, shifting to state %d\n",
                    YYPREFIX, yystate, yytable[yyn]);
#endif
        if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
        {
            goto yyoverflow;
        }
        yystate = yytable[yyn];
        *++yystack.s_mark = yytable[yyn];
        *++yystack.l_mark = yylval;
        yychar = YYEMPTY;
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;

    yyerror("syntax error");

    goto yyerrlab;

yyerrlab:
    ++yynerrs;

yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yystack.s_mark]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: state %d, error recovery shifting\
 to state %d\n", YYPREFIX, *yystack.s_mark, yytable[yyn]);
#endif
                if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
                {
                    goto yyoverflow;
                }
                yystate = yytable[yyn];
                *++yystack.s_mark = yytable[yyn];
                *++yystack.l_mark = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("%sdebug: error recovery discarding state %d\n",
                            YYPREFIX, *yystack.s_mark);
#endif
                if (yystack.s_mark <= yystack.s_base) goto yyabort;
                --yystack.s_mark;
                --yystack.l_mark;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("%sdebug: state %d, error recovery discards token %d (%s)\n",
                    YYPREFIX, yystate, yychar, yys);
        }
#endif
        yychar = YYEMPTY;
        goto yyloop;
    }

yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: state %d, reducing by rule %d (%s)\n",
                YYPREFIX, yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    if (yym)
        yyval = yystack.l_mark[1-yym];
    else
        memset(&yyval, 0, sizeof yyval);
    switch (yyn)
    {
case 1:
#line 97 "parser.y"
	{	
# ifdef DEBUG
		if(debug) sect2dump();
# endif
	}
break;
case 3:
#line 105 "parser.y"
	{
		if(!funcflag)phead2();
		funcflag = TRUE;
	}
break;
case 4:
#line 110 "parser.y"
	{
# ifdef DEBUG
		if(debug) {
			sect1dump();
			sect2dump();
			}
# endif
		fatal = 0;
		n_error++;
		error("Illegal definition");
		fatal = 1;
		}
break;
case 7:
#line 125 "parser.y"
	{	scopy(yystack.l_mark[-1].cp,dp);
		def[dptr] = dp;
		dp += slength(yystack.l_mark[-1].cp) + 1;
		scopy(yystack.l_mark[0].cp,dp);
		subs[dptr++] = dp;
		if(dptr >= DEFSIZE)
			error("Too many definitions");
		dp += slength(yystack.l_mark[0].cp) + 1;
		if(dp >= dchar+DEFCHAR)
			error("Definitions too long");
		subs[dptr]=def[dptr]=0;	/* for lookup - require ending null */
	}
break;
case 9:
#line 140 "parser.y"
	{
# ifdef DEBUG
		if(sect == DEFSECTION && debug) sect1dump();
# endif
		sect++;
		}
break;
case 10:
#line 148 "parser.y"
	{	yyval.i = mn2(RNEWE,yystack.l_mark[-1].i,yystack.l_mark[0].i);
		}
break;
case 11:
#line 151 "parser.y"
	{	yyval.i = yystack.l_mark[0].i;}
break;
case 12:
#line 154 "parser.y"
	{
		if(divflg == TRUE)
			i = mn1(S1FINAL,casecount);
		else i = mn1(FINAL,casecount);
		yyval.i = mn2(RCAT,yystack.l_mark[-1].i,i);
		divflg = FALSE;
		if((++casecount)>NACTIONS)
			error("Too many (>%d) pattern-action rules.", NACTIONS);
		}
break;
case 13:
#line 164 "parser.y"
	{
# ifdef DEBUG
		if(debug) sect2dump();
# endif
		fatal = 0;
		yyline--;
		n_error++;
		error("Illegal rule");
		fatal = 1;
		yyline++;
		}
break;
case 14:
#line 176 "parser.y"
	{	yyval.i = mn0(yystack.l_mark[0].i); }
break;
case 15:
#line 178 "parser.y"
	{
		p = (CHR *)yystack.l_mark[0].cp;
		i = mn0((unsigned)(*p++));
		while(*p)
			i = mn2(RSTR,i,(unsigned)(*p++));
		yyval.i = i;
		}
break;
case 16:
#line 186 "parser.y"
	{
		yyval.i = mn0(DOT);
		}
break;
case 17:
#line 190 "parser.y"
	{	yyval.i = mn1(RCCL,(intptr_t)yystack.l_mark[0].cp); }
break;
case 18:
#line 192 "parser.y"
	{	yyval.i = mn1(RNCCL,(intptr_t)yystack.l_mark[0].cp); }
break;
case 19:
#line 194 "parser.y"
	{	yyval.i = mn1(STAR,yystack.l_mark[-1].i); }
break;
case 20:
#line 196 "parser.y"
	{	yyval.i = mn1(PLUS,yystack.l_mark[-1].i); }
break;
case 21:
#line 198 "parser.y"
	{	yyval.i = mn1(QUEST,yystack.l_mark[-1].i); }
break;
case 22:
#line 200 "parser.y"
	{	yyval.i = mn2(BAR,yystack.l_mark[-2].i,yystack.l_mark[0].i); }
break;
case 23:
#line 202 "parser.y"
	{	yyval.i = mn2(RCAT,yystack.l_mark[-1].i,yystack.l_mark[0].i); }
break;
case 24:
#line 204 "parser.y"
	{	if(!divflg){
			j = mn1(S2FINAL,-casecount);
			i = mn2(RCAT,yystack.l_mark[-2].i,j);
			yyval.i = mn2(DIV,i,yystack.l_mark[0].i);
			}
		else {
			yyval.i = mn2(RCAT,yystack.l_mark[-2].i,yystack.l_mark[0].i);
			error("illegal extra slash");
			}
		divflg = TRUE;
		}
break;
case 25:
#line 216 "parser.y"
	{	if(yystack.l_mark[-3].i > yystack.l_mark[-1].i){
			i = yystack.l_mark[-3].i;
			yystack.l_mark[-3].i = yystack.l_mark[-1].i;
			yystack.l_mark[-1].i = i;
			}
		if(yystack.l_mark[-1].i <= 0)
			error("iteration range must be positive");
		else {
			j = yystack.l_mark[-4].i;
			for(k = 2; k<=yystack.l_mark[-3].i;k++)
				j = mn2(RCAT,j,dupl(yystack.l_mark[-4].i));
			for(i = yystack.l_mark[-3].i+1; i<=yystack.l_mark[-1].i; i++){
				g = dupl(yystack.l_mark[-4].i);
				for(k=2;k<=i;k++)
					g = mn2(RCAT,g,dupl(yystack.l_mark[-4].i));
				j = mn2(BAR,j,g);
				}
			yyval.i = j;
			}
	}
break;
case 26:
#line 237 "parser.y"
	{
		if(yystack.l_mark[-1].i < 0)error("can't have negative iteration");
		else if(yystack.l_mark[-1].i == 0) yyval.i = mn0(RNULLS);
		else {
			j = yystack.l_mark[-2].i;
			for(k=2;k<=yystack.l_mark[-1].i;k++)
				j = mn2(RCAT,j,dupl(yystack.l_mark[-2].i));
			yyval.i = j;
			}
		}
break;
case 27:
#line 248 "parser.y"
	{
				/* from n to infinity */
		if(yystack.l_mark[-2].i < 0)error("can't have negative iteration");
		else if(yystack.l_mark[-2].i == 0) yyval.i = mn1(STAR,yystack.l_mark[-3].i);
		else if(yystack.l_mark[-2].i == 1)yyval.i = mn1(PLUS,yystack.l_mark[-3].i);
		else {		/* >= 2 iterations minimum */
			j = yystack.l_mark[-3].i;
			for(k=2;k<yystack.l_mark[-2].i;k++)
				j = mn2(RCAT,j,dupl(yystack.l_mark[-3].i));
			k = mn1(PLUS,dupl(yystack.l_mark[-3].i));
			yyval.i = mn2(RCAT,j,k);
			}
		}
break;
case 28:
#line 262 "parser.y"
	{	yyval.i = mn2(RSCON,yystack.l_mark[0].i,(intptr_t)yystack.l_mark[-1].cp); }
break;
case 29:
#line 266 "parser.y"
	{	yyval.i = mn2(RXSCON,yystack.l_mark[0].i,(intptr_t)yystack.l_mark[-1].cp); }
break;
case 30:
#line 268 "parser.y"
	{	yyval.i = mn1(CARAT,yystack.l_mark[0].i); }
break;
case 31:
#line 270 "parser.y"
	{	i = mn0('\n');
		if(!divflg){
			j = mn1(S2FINAL,-casecount);
			k = mn2(RCAT,yystack.l_mark[-1].i,j);
			yyval.i = mn2(DIV,k,i);
			}
		else yyval.i = mn2(RCAT,yystack.l_mark[-1].i,i);
		divflg = TRUE;
		}
break;
case 32:
#line 280 "parser.y"
	{	yyval.i = yystack.l_mark[-1].i; }
break;
case 33:
#line 282 "parser.y"
	{	yyval.i = mn0(RNULLS); }
break;
case 34:
#line 286 "parser.y"
	{ isArray = 1; }
break;
case 35:
#line 288 "parser.y"
	{ isArray = 0; }
break;
#line 1474 "y.tab.c"
    }
    yystack.s_mark -= yym;
    yystate = *yystack.s_mark;
    yystack.l_mark -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("%sdebug: after reduction, shifting from state 0 to\
 state %d\n", YYPREFIX, YYFINAL);
#endif
        yystate = YYFINAL;
        *++yystack.s_mark = YYFINAL;
        *++yystack.l_mark = yyval;
        if (yychar < 0)
        {
            if ((yychar = YYLEX) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("%sdebug: state %d, reading %d (%s)\n",
                        YYPREFIX, YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("%sdebug: after reduction, shifting from state %d \
to state %d\n", YYPREFIX, *yystack.s_mark, yystate);
#endif
    if (yystack.s_mark >= yystack.s_last && yygrowstack(&yystack))
    {
        goto yyoverflow;
    }
    *++yystack.s_mark = (short) yystate;
    *++yystack.l_mark = yyval;
    goto yyloop;

yyoverflow:
    yyerror("yacc stack overflow");

yyabort:
    yyfreestack(&yystack);
    return (1);

yyaccept:
    yyfreestack(&yystack);
    return (0);
}
