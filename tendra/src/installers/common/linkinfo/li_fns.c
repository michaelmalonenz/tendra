/*
 * Copyright (c) 2002-2004, The Tendra Project <http://www.ten15.org/>
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice unmodified, this list of conditions, and the following
 *    disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
 * IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
 * OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
 * IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
 * NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 * DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 * THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 *
 *    		 Crown Copyright (c) 1997
 *
 *    This TenDRA(r) Computer Program is subject to Copyright
 *    owned by the United Kingdom Secretary of State for Defence
 *    acting through the Defence Evaluation and Research Agency
 *    (DERA).  It is made available to Recipients with a
 *    royalty-free licence for its use, reproduction, transfer
 *    to other parties and amendment for any purpose not excluding
 *    product development provided that any such use et cetera
 *    shall be deemed to be acceptance of the following conditions:-
 *
 *        (1) Its Recipients shall ensure that this Notice is
 *        reproduced upon any copies or amended versions of it;
 *
 *        (2) Any amended version of it shall be clearly marked to
 *        show both the nature of and the organisation responsible
 *        for the relevant amendment or amendments;
 *
 *        (3) Its onward transfer from a recipient to another
 *        party shall be deemed to be that party's acceptance of
 *        these conditions;
 *
 *        (4) DERA gives no warranty or assurance as to its
 *        quality or suitability for any purpose and DERA accepts
 *        no liability whatsoever in relation to any use to which
 *        it may be put.
 *
 * $TenDRA$
 */


#include "config.h"
#include "fmm.h"

#include "common_types.h"
#include "flags.h"
#include "messages_li.h"
#include "natmacs.h"
#include "main_reads.h"
#include "externs.h"

#if is80x86
#include "assembler.h"
#include "localflags.h"
#define use_link_stuff 1
#endif

#if use_link_stuff
extern weak_cell *weak_list;
#include "out.h"
#endif

#include "readglob.h"
#include "read_fns.h"
#include "basicread.h"
#include "exp.h"
#include "expmacs.h"
#include "tags.h"
#include "machine.h"


/* PROCEDURES */

extern void out_rename(char *, char *);

static char *
id_prefix(char *s)
{
	char * r;
	int l1, l2;
	l1 = (int)strlen(name_prefix);
	if (l1==0)
		return s;
	l2 = (int)strlen(s);
	r = (char *)xcalloc(l1+l2+1, sizeof(char));
	IGNORE strcpy(r, name_prefix);
	IGNORE strcpy(&r[l1], s);
	return r;
}

linkinfo
f_make_weak_defn(exp e1, exp e2)
{
#if use_link_stuff
	weak_cell * wc = (weak_cell *)xmalloc(sizeof(weak_cell));

	wc -> weak_id = brog(son(e1))-> dec_u.dec_val.dec_id;
	wc -> val_id = brog(son(e2))-> dec_u.dec_val.dec_id;
	brog(son(e2))-> dec_u.dec_val.isweak = 1;
	wc -> next = weak_list;
	weak_list = wc;

#endif
	kill_exp(e1, e1);
	kill_exp(e2, e2);
	return 0;
}


linkinfo
f_make_weak_symbol(tdfstring id, exp e)
{
#if use_link_stuff
	char * * lid = &brog(son(e))-> dec_u.dec_val.dec_id;
	char * nid = id_prefix(id.ints.chars);
	brog(son(e))-> dec_u.dec_val.isweak = 1;
	brog(son(e))-> dec_u.dec_val.extnamed = 1;
	outs(".weak ");
	outs(nid);
	outnl();
	out_rename(*lid, nid);
	*lid = nid;
#endif
	kill_exp(e, e);
	return 0;
}

linkinfo
f_make_comment(tdfstring id)
{
#if use_link_stuff
	outs(".ident \"");
	outs(id_prefix(id.ints.chars));
	outs("\"");
	outnl();
#endif
	return 0;
}

linkinfo
f_static_name_def(exp e, tdfstring id)
{
	char * * oldid = &brog(son(e))-> dec_u.dec_val.dec_id;
	char * newid = id_prefix(id.ints.chars);

	if (name(e) != name_tag || !isglob(son(e)))
    {
		failer(ILLEGAL_STATIC);
		kill_exp(e, e);
		return 0;
    }

	if (separate_units)
		failer(INCOMPATIBLE_U);
	else
		out_rename(*oldid, newid);

	*oldid = newid;
	kill_exp(e, e);
	return 0;
}

void
init_linkinfo(void)
{
	return;
}

linkinfo_list
new_linkinfo_list(int n)
{
	UNUSED(n);
	return 0;
}

linkinfo_list
add_linkinfo_list(linkinfo_list list, linkinfo elem,
				  int index)
{
	UNUSED(list); UNUSED(elem); UNUSED(index);
	return 0;
}


void
start_make_linkinfo_unit(int ntokens, int ntags, int naltags, int ndiagtags)
{
	UNUSED(ndiagtags);

	allocate_unit(ntokens, ntags, naltags, 0, 0);
	return;
}

int
f_make_linkinfo_unit(void)
{

	setup_ind_tokens();
	setup_ind_tags();
	setup_ind_altags();
	start_bytestream();
	unit_alloc_labels(small_dtdfint());
	IGNORE d_linkinfo_list();
	end_bytestream();
	unit_destroy();
	return 0;
}

linkinfo_props
f_make_linkinfos(tdfint nl, linkinfo_list tds)
{
	UNUSED(nl); UNUSED(tds);
	return 0;
}
