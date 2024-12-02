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
/*
 * Copyright 2005 Sun Microsystems, Inc.
 * All rights reserved.
 * Use is subject to license terms.
 */

/*
 * Copyright (c) 1988 AT&T 
 */
/*
 * All Rights Reserved 
 */

/*
 * from OpenSolaris "header.c 6.22 05/06/08 SMI" 
 */

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)header.c  1.12 (gritter) 9/23/06
 */

#include "ldefs.c"

static void     chd1(void);
static void     chd2(void);
static void     ctail(void);

void
phead1(void)
{
  chd1();
}

static void
chd1(void)
{
  fprintf(fout, "`ifdef MAIN\n");
  fprintf(fout, "module lex;\n");
  fprintf(fout, "`endif\n\n");
  fprintf(fout, "//`define LEXDEBUG\n\n");

  fprintf(fout, "`define NLSTATE yyprevious = `YYNEWLINE\n");
  fprintf(fout, "`define BEGIN yybgin_ptr = 1 +\n");
  fprintf(fout, "`define INITIAL 0\n");
  fprintf(fout, "`define YYLERR 0\n");
  fprintf(fout, "`define YYSTATE (yyestate_ptr - 1)\n");
  fprintf(fout, "`define YYTYPE byte unsigned\n");
#ifdef DEBUG
  fprintf(fout, "`define LEXDEBUG 1\n");
#endif
  fprintf(fout, "`define BUFSIZ 4096 \n");
  fprintf(fout, "`ifndef YYLMAX \n");
  fprintf(fout, "`define YYLMAX `BUFSIZ\n");
  fprintf(fout, "`endif \n\n");
  fprintf(fout, "`define lex_output(c) $write(c)\n");

  fprintf(fout,
	  "`define unput(c)"
	  " begin yytchar = (c); if(yytchar == \"\\n\") yylineno--; end\n");
  fprintf(fout, "`define yymore() (yymorfg=1)\n");
  {
    {
      fprintf(fout, "int yyleng;\nint yybgin_ptr = 1;\n\n");

      fprintf(fout, "`define YYISARRAY\n\n");
      fprintf(fout, "typedef byte unsigned Bus[$];\nBus yytext;\n\n");
    }
  }
  fprintf(fout, "int yymorfg;\n");
  fprintf(fout, "byte yytchar;\n");
  fprintf(fout, "int yyin = -1, yyout = -1;\n\n");
  fprintf(fout, "int yylineno = 1;\n");
  fprintf(fout, "\nfunction int lex_input();");
  fprintf(fout, "\n  yytchar = b.Bgetc();");
  fprintf(fout, "\n  if (yytchar == 10) yylineno++;");
  fprintf(fout, "\n  if (yytchar == `Beof) return 0;");
  fprintf(fout, "\n  lex_input = yytchar;");
  fprintf(fout, "\nendfunction\n");
  fprintf(fout, "\ntask _yyioinit();\n");
  fprintf(fout, "    yyin = 0; yyout = 1;\nendtask\n");
  fprintf(fout, "\ntypedef struct {\n");
  fprintf(fout, "    `YYTYPE verify, advance;\n");
  fprintf(fout, "} YYWork;\n\n");

  fprintf(fout, "typedef struct {\n");
  fprintf(fout, "  int yystoff_ptr;\n");
  fprintf(fout, "  int yyother_ptr;\n");
  fprintf(fout, "  int yystops_ptr;\n} YYSvf;\n\n");
}

void
phead2(void)
{
  chd2();
}

static void
chd2(void)
{
  fprintf(fout, "  if (yyin == -1) yyin = 0;\n");
  fprintf(fout, "  if (yyout == -1) yyout = 1;\n");

  fprintf(fout, "  while ((nstr = yylook()) >= 0) begin\n");
  fprintf(fout, "    case(nstr)\n");
  fprintf(fout, "      0: if(yywrap()) return(0);\n");
}

void
ptail(void)
{
  if (!pflag)
    ctail();
  pflag = 1;
}

static void
ctail(void)
{
  fprintf(fout, "      -1: ;\n");	/* for reject */
  fprintf(fout,
	  "      default: $display($psprintf(\"bad switch yylook %%d\",nstr));\n");
  fprintf(fout, "    endcase\n  end\n  return(0);\n");
  fprintf(fout, "endfunction /* end of yylex */\n");
}

void
statistics(void)
{
  fprintf(errorf,
	  "%d/%d nodes(%%e), %d/%d positions(%%p), %d/%d (%%n), %ld transitions,\n",
	  tptr, treesize, nxtpos - positions, maxpos, stnum + 1, nstates,
	  rcount);
  fprintf(errorf, "%d/%d packed char classes(%%k), ", pcptr - pchar,
	  pchlen);
  if (optim)
    fprintf(errorf, " %d/%d packed transitions(%%a), ", nptr, ntrans);
  fprintf(errorf, " %d/%d output slots(%%o)", yytop, outsize);
  putc('\n', errorf);
}
