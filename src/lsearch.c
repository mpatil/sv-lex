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
 * Copyright 2004 Sun Microsystems, Inc.  All rights reserved.
 * Use is subject to license terms.
 */

/*
 * from OpenSolaris "lsearch.c 1.15 05/06/08 SMI" 
 */

/*
 * Portions Copyright (c) 2005 Gunnar Ritter, Freiburg i. Br., Germany
 *
 * Sccsid @(#)lsearch.c 1.4 (gritter) 11/26/05
 */

/*
 * Copyright (c) 1988 AT&T 
 */
/*
 * All Rights Reserved 
 */


/*
 * Linear search algorithm, generalized from Knuth (6.1) Algorithm Q.
 *
 * This version no longer has anything to do with Knuth's Algorithm Q,
 * which first copies the new element into the table, then looks for it.
 * The assumption there was that the cost of checking for the end of the
 * table before each comparison outweighed the cost of the comparison, which
 * isn't true when an arbitrary comparison function must be called and when the
 * copy itself takes a significant number of cycles.
 * Actually, it has now reverted to Algorithm S, which is "simpler."
 */

#include <sys/types.h>
#include <stddef.h>
#include <string.h>
#include "search.h"

void           *
xlsearch(const void *ky, void *bs, unsigned *nelp, unsigned width,
	 int (*compar) (const void *, const void *))
{
  char           *key = (char *) ky;
  char           *base = (char *) bs;
  char           *next = base + *nelp * width;	/* End of table */
  void           *res;

  for (; base < next; base += width)
    if ((*compar) (key, base) == 0)
      return (base);		/* Key found */
  ++*nelp;			/* Not found, add to table */
  res = memcpy(base, key, width);	/* base now == next */
  return (res);
}
