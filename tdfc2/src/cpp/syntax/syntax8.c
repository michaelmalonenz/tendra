/*
 * Automatically generated from the files:
 *	syntax.sid
 * and
 *	syntax.act
 * by:
 *	sid
 */

/* BEGINNING OF HEADER */

#define __SID_SPLIT
#line 190 "syntax.act"


/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997-1998, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

#include <shared/check.h>

#include "config.h"
#include "c_types.h"
#include "ctype_ops.h"
#include "exp_ops.h"
#include "hashid_ops.h"
#include "id_ops.h"
#include "nspace_ops.h"
#include "type_ops.h"
#include "error.h"
#include "catalog.h"
#include "option.h"
#include "access.h"
#include "allocate.h"
#include "assign.h"
#include "basetype.h"
#include "cast.h"
#include "chktype.h"
#include "class.h"
#include "constant.h"
#include "construct.h"
#include "convert.h"
#include "declare.h"
#include "derive.h"
#include "dump.h"
#include "exception.h"
#include "expression.h"
#include "function.h"
#include "hash.h"
#include "identifier.h"
#include "initialise.h"
#include "inttype.h"
#include "label.h"
#include "lex.h"
#include "literal.h"
#include "member.h"
#include "namespace.h"
#include "parse.h"
#include "pragma.h"
#include "predict.h"
#include "preproc.h"
#include "redeclare.h"
#include "rewrite.h"
#include "statement.h"
#include "symbols.h"
#include "template.h"
#include "tokdef.h"
#include "token.h"
#include "typeid.h"
#include "variable.h"


/*
    These are the aliases for the compound types used in the parser.
*/

typedef LIST ( EXP ) SID_LIST_EXP ;
typedef LIST ( TYPE ) SID_LIST_TYPE ;


/*
    The function declarations are included at this point so that the
    type definitions are in scope.
*/

#include "syntax.h"


/*
    The output of sid is automatically generated.  Hence it is not
    necessarily appropriate to apply the same level of checking to this
    as to the rest of the program.  These pragmas describe the relaxations
    allowed for the sid output.
*/

#if FS_TENDRA
#pragma TenDRA begin
#pragma TenDRA const conditional allow
#pragma TenDRA unreachable code allow
#pragma TenDRA variable analysis off
#endif


#line 110 "syntax8.c"

void
ZRany_Hclass_Hname(IDENTIFIER *ZOid)
{
	IDENTIFIER ZIid;

	switch (CURRENT_TERMINAL) {
	case 7:
		{
			/* BEGINNING OF EXTRACT: template-type */
			{
#line 249 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZIid = parse_type_template ( id, args, 0 ) ;
    crt_templ_qualifier = 1 ;
    RESCAN_LEXER ;
#line 129 "syntax8.c"
			}
			/* END OF EXTRACT: template-type */
			ADVANCE_LEXER;
		}
		break;
	case 1: case 2: case 3: case 4:
		{
			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 219 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 147 "syntax8.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 227 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 160 "syntax8.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 231 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 173 "syntax8.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 223 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 186 "syntax8.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto ZL1;
				}
			}
			/* END OF INLINE: any-identifier */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOid = ZIid;
}

void
ZRhandler(EXP ZIa)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIc;
		int ZIn;
		IDENTIFIER ZId;
		EXP ZIb;
		EXP ZIe0;
		EXP ZIe1;
		EXP ZIc1;
		EXP ZIe2;
		EXP ZIc2;
		EXP ZIc3;
		EXP ZIc4;

		switch (CURRENT_TERMINAL) {
		case 128:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF ACTION: stmt_compound_begin */
		{
#line 907 "syntax.act"

    (ZIc) = begin_compound_stmt ( 1 ) ;
#line 243 "syntax8.c"
		}
		/* END OF ACTION: stmt_compound_begin */
		/* BEGINNING OF ACTION: stmt_try_inject */
		{
#line 1047 "syntax.act"

    inject_try_stmt ( (ZIa) ) ;
#line 251 "syntax8.c"
		}
		/* END OF ACTION: stmt_try_inject */
		/* BEGINNING OF ACTION: no_type_defns */
		{
#line 2016 "syntax.act"

    (ZIn) = no_type_defns ;
#line 259 "syntax8.c"
		}
		/* END OF ACTION: no_type_defns */
		switch (CURRENT_TERMINAL) {
		case 65:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		ZRexception_Hdeclaration (ZIn, &ZId);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: stmt_catch_begin */
		{
#line 895 "syntax.act"

    (ZIb) = begin_catch_stmt ( (ZIa), (ZId) ) ;
#line 279 "syntax8.c"
		}
		/* END OF ACTION: stmt_catch_begin */
		switch (CURRENT_TERMINAL) {
		case 39:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF INLINE: open-brace */
		{
			{
				switch (CURRENT_TERMINAL) {
				case 64:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: open-brace */
		/* BEGINNING OF ACTION: stmt_compound_block */
		{
#line 911 "syntax.act"

    COPY_int ( exp_sequence_block ( (ZIc) ), 2 ) ;
#line 307 "syntax8.c"
		}
		/* END OF ACTION: stmt_compound_block */
		/* BEGINNING OF ACTION: exp_none */
		{
#line 581 "syntax.act"

    (ZIe0) = NULL_exp ;
#line 315 "syntax8.c"
		}
		/* END OF ACTION: exp_none */
		/* BEGINNING OF ACTION: stmt_decl */
		{
#line 931 "syntax.act"

    (ZIe1) = (ZIe0) ;
    in_declaration-- ;
#line 324 "syntax8.c"
		}
		/* END OF ACTION: stmt_decl */
		/* BEGINNING OF ACTION: stmt_compound_add */
		{
#line 919 "syntax.act"

    (ZIc1) = add_compound_stmt ( (ZIc), (ZIe1) ) ;
#line 332 "syntax8.c"
		}
		/* END OF ACTION: stmt_compound_add */
		/* BEGINNING OF ACTION: stmt_caught */
		{
#line 903 "syntax.act"

    MAKE_exp_thrown ( type_void, 1, (ZIe2) ) ;
#line 340 "syntax8.c"
		}
		/* END OF ACTION: stmt_caught */
		/* BEGINNING OF ACTION: stmt_compound_add */
		{
#line 919 "syntax.act"

    (ZIc2) = add_compound_stmt ( (ZIc1), (ZIe2) ) ;
#line 348 "syntax8.c"
		}
		/* END OF ACTION: stmt_compound_add */
		ZRstatement_Hseq_Hopt (ZIc2, &ZIc3);
		/* BEGINNING OF INLINE: close-brace */
		{
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			{
				switch (CURRENT_TERMINAL) {
				case 38:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: close-brace */
		/* BEGINNING OF ACTION: stmt_compound_end */
		{
#line 923 "syntax.act"

    (ZIc4) = end_compound_stmt ( (ZIc3) ) ;
#line 374 "syntax8.c"
		}
		/* END OF ACTION: stmt_compound_end */
		/* BEGINNING OF ACTION: stmt_catch_end */
		{
#line 899 "syntax.act"

    IGNORE end_catch_stmt ( (ZIb), (ZIc4) ) ;
#line 382 "syntax8.c"
		}
		/* END OF ACTION: stmt_catch_end */
		/* BEGINNING OF ACTION: rescan_token */
		{
#line 2149 "syntax.act"

    RESCAN_LEXER ;
#line 390 "syntax8.c"
		}
		/* END OF ACTION: rescan_token */
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZRdeclaration_Hcond(void)
{
	switch (CURRENT_TERMINAL) {
	case 30:
		{
			ADVANCE_LEXER;
		}
		break;
	case 26:
		{
			EXP ZIp;

			ZRdeclaration_Hcond_Hhead (&ZIp);
			/* BEGINNING OF INLINE: 1033 */
			{
				switch (CURRENT_TERMINAL) {
				case 28:
					{
						ADVANCE_LEXER;
						/* BEGINNING OF ACTION: cond_hash_else */
						{
#line 1930 "syntax.act"

    crt_hash_cond = make_else_cond ( crt_hash_cond ) ;
#line 425 "syntax8.c"
						}
						/* END OF ACTION: cond_hash_else */
						/* BEGINNING OF ACTION: decl_hash_else */
						{
#line 1911 "syntax.act"

    target_decl ( lex_else, NULL_exp ) ;
#line 433 "syntax8.c"
						}
						/* END OF ACTION: decl_hash_else */
						ZRdeclaration_Hcond_Hbody ();
						if ((CURRENT_TERMINAL) == 355) {
							RESTORE_LEXER;
							goto ZL1;
						}
					}
					break;
				case 355:
					RESTORE_LEXER;
					goto ZL1;
				default:
					break;
				}
			}
			/* END OF INLINE: 1033 */
			/* BEGINNING OF ACTION: cond_hash_endif */
			{
#line 1933 "syntax.act"

    crt_hash_cond = (ZIp) ;
#line 456 "syntax8.c"
			}
			/* END OF ACTION: cond_hash_endif */
			switch (CURRENT_TERMINAL) {
			case 29:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: decl_hash_endif */
			{
#line 1915 "syntax.act"

    target_decl ( lex_endif, NULL_exp ) ;
#line 471 "syntax8.c"
			}
			/* END OF ACTION: decl_hash_endif */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZR1370(DECL_SPEC *ZIds, TYPE *ZIp, BASE_TYPE *ZIq, ACCESS_LIST *ZIr, int *ZIf, IDENTIFIER *ZI1369, IDENTIFIER *ZOd)
{
	IDENTIFIER ZId;

	switch (CURRENT_TERMINAL) {
	default:
		{
			IDENTIFIER ZI1355;
			TYPE ZI1356;
			int ZI1357;
			TYPE ZI1349;
			IDENTIFIER ZIid;
			int ZIc;
			TYPE ZIt;
			int ZIfr;
			EXP ZIe;

			/* BEGINNING OF ACTION: declarator_type */
			{
#line 1734 "syntax.act"

    (ZI1355) = constr_name ( last_namespace, (*ZI1369) ) ;
#line 510 "syntax8.c"
			}
			/* END OF ACTION: declarator_type */
			/* BEGINNING OF ACTION: type_none */
			{
#line 1278 "syntax.act"

    (ZI1356) = NULL_type ;
#line 518 "syntax8.c"
			}
			/* END OF ACTION: type_none */
			/* BEGINNING OF ACTION: bool_false */
			{
#line 2051 "syntax.act"
 (ZI1357) = 0 ; 
#line 525 "syntax8.c"
			}
			/* END OF ACTION: bool_false */
			/* BEGINNING OF ACTION: declarator_begin */
			{
#line 1709 "syntax.act"

    begin_declarator ( (ZI1355), crt_id_qualifier, qual_namespace, 1 ) ;
#line 533 "syntax8.c"
			}
			/* END OF ACTION: declarator_begin */
			ZR1179 (ZI1356, ZI1355, ZI1357, &ZI1349, &ZIid, &ZIc);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: template_decl */
			{
#line 1866 "syntax.act"

    if ( !IS_NULL_type ( (*ZIp) ) ) template_decl ( (*ZIp) ) ;
#line 546 "syntax8.c"
			}
			/* END OF ACTION: template_decl */
			/* BEGINNING OF ACTION: type_inject */
			{
#line 1395 "syntax.act"

    (ZIt) = ( IS_NULL_type ( (ZI1349) ) ? (*ZIp) : inject_pre_type ( (ZI1349), (*ZIp), 1 ) ) ;
#line 554 "syntax8.c"
			}
			/* END OF ACTION: type_inject */
			/* BEGINNING OF ACTION: initialiser_bad */
			{
#line 1776 "syntax.act"

    if ( (ZIc) ) report ( crt_loc, ERR_dcl_init_bad () ) ;
#line 562 "syntax8.c"
			}
			/* END OF ACTION: initialiser_bad */
			/* BEGINNING OF ACTION: declare_member */
			{
#line 1644 "syntax.act"

    DECL_SPEC ds = (*ZIds) ;
    if ( type_tag ( (ZIt) ) == type_func_tag ) {
	/* Look ahead for function definitions */
	int def = predict_func_defn () ;
	if ( def & !have_func_declarator ) adjust_param ( (ZIt) ) ;
	if ( ds & dspec_friend ) {
	    (ZId) = make_friend_decl ( ds, (ZIt), (ZIid), def, 1 ) ;
	    (ZIfr) = 1 ;
	} else {
	    (ZId) = make_func_mem_decl ( ds, (ZIt), (ZIid), def ) ;
	    (ZIfr) = 0 ;
	}
	is_function_next = def ;
    } else {
	int f = ( (*ZIf) && ( crt_lex_token == lex_semicolon ) ) ;
	(ZId) = make_member_decl ( ds, (ZIt), (ZIid), f ) ;
	(ZIfr) = 0 ;
	is_function_next = 0 ;
    }
    if ( IS_id_type_alias ( (ZId) ) ) {
	BASE_TYPE bs = DEREF_btype ( id_type_alias_rep ( (ZId) ) ) ;
	bs |= (*ZIq) ;
	COPY_btype ( id_type_alias_rep ( (ZId) ), bs ) ;
    }
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
#line 595 "syntax8.c"
			}
			/* END OF ACTION: declare_member */
			/* BEGINNING OF ACTION: access_check_ret */
			{
#line 1478 "syntax.act"

    IGNORE clear_access ( (ZId), &(*ZIr) ) ;
#line 603 "syntax8.c"
			}
			/* END OF ACTION: access_check_ret */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1473 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (ZId) ) ;
    }
#line 613 "syntax8.c"
			}
			/* END OF ACTION: access_check_decl */
			ZRmember_Hspecifier_Hopt (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: initialise_member */
			{
#line 1771 "syntax.act"

    int def = ( (ZIfr) ? init_object ( (ZId), (ZIe) ) : init_member ( (ZId), (ZIe) ) ) ;
    if ( do_dump ) dump_declare ( (ZId), &decl_loc, def ) ;
#line 627 "syntax8.c"
			}
			/* END OF ACTION: initialise_member */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1473 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (ZId) ) ;
    }
#line 637 "syntax8.c"
			}
			/* END OF ACTION: access_check_decl */
		}
		break;
	case 41:
		{
			QUALIFIER ZIi;
			int ZIb;
			EXP ZIc;
			TYPE ZIt;

			/* BEGINNING OF ACTION: template_decl */
			{
#line 1866 "syntax.act"

    if ( !IS_NULL_type ( (*ZIp) ) ) template_decl ( (*ZIp) ) ;
#line 654 "syntax8.c"
			}
			/* END OF ACTION: template_decl */
			/* BEGINNING OF ACTION: declarator_begin */
			{
#line 1709 "syntax.act"

    begin_declarator ( (*ZI1369), crt_id_qualifier, qual_namespace, 1 ) ;
#line 662 "syntax8.c"
			}
			/* END OF ACTION: declarator_begin */
			/* BEGINNING OF ACTION: qual_get */
			{
#line 538 "syntax.act"

    (ZIi) = crt_id_qualifier ;
    (ZIb) = crt_templ_qualifier ;
#line 671 "syntax8.c"
			}
			/* END OF ACTION: qual_get */
			ADVANCE_LEXER;
			ZRconstant_Hexpression (&ZIc);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: qual_set */
			{
#line 543 "syntax.act"

    crt_id_qualifier = (ZIi) ;
    crt_templ_qualifier = (ZIb) ;
#line 686 "syntax8.c"
			}
			/* END OF ACTION: qual_set */
			/* BEGINNING OF ACTION: type_bitfield_mem */
			{
#line 1389 "syntax.act"

    /* Check for anonymous bitfields */
    HASHID nm = DEREF_hashid ( id_name ( (*ZI1369) ) ) ;
    int z = IS_hashid_anon ( nm ) ;
    (ZIt) = make_bitfield_type ( (*ZIp), (*ZIq), (ZIc), z ) ;
#line 697 "syntax8.c"
			}
			/* END OF ACTION: type_bitfield_mem */
			/* BEGINNING OF ACTION: declare_bitfield */
			{
#line 1680 "syntax.act"

    IDENTIFIER id = make_member_decl ( (*ZIds), (ZIt), (*ZI1369), 0 ) ;
    int def = init_member ( id, NULL_exp ) ;
    if ( do_dump ) dump_declare ( id, &decl_loc, def ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
    is_function_next = 0 ;
    (ZId) = id ;
#line 711 "syntax8.c"
			}
			/* END OF ACTION: declare_bitfield */
			/* BEGINNING OF ACTION: access_check_ret */
			{
#line 1478 "syntax.act"

    IGNORE clear_access ( (ZId), &(*ZIr) ) ;
#line 719 "syntax8.c"
			}
			/* END OF ACTION: access_check_ret */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1473 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (ZId) ) ;
    }
#line 729 "syntax8.c"
			}
			/* END OF ACTION: access_check_decl */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOd = ZId;
}

void
ZRpm_Hexpression(EXP *ZO1237)
{
	EXP ZI1237;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIe;

		ZRcast_Hexpression (&ZIe);
		ZR1238 (ZIe, &ZI1237);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1237 = ZI1237;
}

void
ZRtemplate_Hopt(NAMESPACE ZIns, int *ZOt)
{
	int ZIt;

	switch (CURRENT_TERMINAL) {
	default:
		{
			/* BEGINNING OF ACTION: bool_false */
			{
#line 2051 "syntax.act"
 (ZIt) = 0 ; 
#line 783 "syntax8.c"
			}
			/* END OF ACTION: bool_false */
		}
		break;
	case 147:
		{
			/* BEGINNING OF ACTION: rescan_template */
			{
#line 2152 "syntax.act"

    rescan_template ( (ZIns) ) ;
#line 795 "syntax8.c"
			}
			/* END OF ACTION: rescan_template */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: bool_true */
			{
#line 2052 "syntax.act"
 (ZIt) = 1 ; 
#line 803 "syntax8.c"
			}
			/* END OF ACTION: bool_true */
		}
		break;
	case 355:
		return;
	}
	*ZOt = ZIt;
}

void
ZRaccess_Hspecifier(DECL_SPEC *ZOa)
{
	DECL_SPEC ZIa;

	switch (CURRENT_TERMINAL) {
	case 142:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: access_private */
			{
#line 1451 "syntax.act"
 (ZIa) = dspec_private ; 
#line 827 "syntax8.c"
			}
			/* END OF ACTION: access_private */
		}
		break;
	case 143:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: access_protected */
			{
#line 1452 "syntax.act"
 (ZIa) = dspec_protected ; 
#line 839 "syntax8.c"
			}
			/* END OF ACTION: access_protected */
		}
		break;
	case 144:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: access_public */
			{
#line 1453 "syntax.act"
 (ZIa) = dspec_public ; 
#line 851 "syntax8.c"
			}
			/* END OF ACTION: access_public */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOa = ZIa;
}

void
ZRusing_Hdeclaration(void)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		switch (CURRENT_TERMINAL) {
		case 154:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		ZR1259 ();
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZR1373(TYPE *ZO1161, IDENTIFIER *ZO1162)
{
	TYPE ZI1161;
	IDENTIFIER ZI1162;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		IDENTIFIER ZI1374;
		TYPE ZI1375;
		TYPE ZIt;
		IDENTIFIER ZIid;

		/* BEGINNING OF ACTION: is_parameter */
		{
#line 2131 "syntax.act"

    /* Resolve parameter declarators from type names */
    (ZI0) = predict_param () ;
#line 916 "syntax8.c"
		}
		/* END OF ACTION: is_parameter */
		if (!ZI0)
			goto ZL2;
		ZRdeclarator_Hid (&ZI1374);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: type_none */
		{
#line 1278 "syntax.act"

    (ZI1375) = NULL_type ;
#line 931 "syntax8.c"
		}
		/* END OF ACTION: type_none */
		/* BEGINNING OF ACTION: declarator_posn */
		{
#line 1717 "syntax.act"

    IDENTIFIER pid = underlying_id ( (ZI1374) ) ;
    DEREF_loc ( id_loc ( pid ), decl_loc ) ;
#line 940 "syntax8.c"
		}
		/* END OF ACTION: declarator_posn */
		ZR1163 (ZI1375, ZI1374, &ZIt, &ZIid);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: declarator_bad */
		{
#line 1738 "syntax.act"

    if ( IS_NULL_type ( (ZIt) ) ) {
	report ( crt_loc, ERR_dcl_meaning_paren () ) ;
    }
#line 955 "syntax8.c"
		}
		/* END OF ACTION: declarator_bad */
		switch (CURRENT_TERMINAL) {
		case 39:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		ZR1163 (ZIt, ZIid, &ZI1161, &ZI1162);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	case 65:
		{
			TYPE ZIt;
			IDENTIFIER ZIid;

			ADVANCE_LEXER;
			ZR1373 (&ZIt, &ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declarator_bad */
			{
#line 1738 "syntax.act"

    if ( IS_NULL_type ( (ZIt) ) ) {
	report ( crt_loc, ERR_dcl_meaning_paren () ) ;
    }
#line 993 "syntax8.c"
			}
			/* END OF ACTION: declarator_bad */
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZR1163 (ZIt, ZIid, &ZI1161, &ZI1162);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 332:
		{
			IDENTIFIER ZI1372;
			int ZIw;
			TYPE ZI1378;
			IDENTIFIER ZI1379;
			TYPE ZIt;
			IDENTIFIER ZIid;

			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: id_none */
			{
#line 461 "syntax.act"

    (ZI1372) = NULL_id ;
    crt_id_qualifier = qual_none ;
    qual_namespace = NULL_nspace ;
#line 1034 "syntax8.c"
			}
			/* END OF ACTION: id_none */
			/* BEGINNING OF ACTION: bool_true */
			{
#line 2052 "syntax.act"
 (ZIw) = 1 ; 
#line 1041 "syntax8.c"
			}
			/* END OF ACTION: bool_true */
			/* BEGINNING OF ACTION: param_begin */
			{
#line 1201 "syntax.act"

    func_type_defn ( 0 ) ;
    begin_param ( (ZI1372) ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
#line 1052 "syntax8.c"
			}
			/* END OF ACTION: param_begin */
			ZRparameter_Htail (ZIw, &ZI1378);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: param_end */
			{
#line 1210 "syntax.act"

    end_param () ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 1 ;
#line 1067 "syntax8.c"
			}
			/* END OF ACTION: param_end */
			/* BEGINNING OF ACTION: id_anon */
			{
#line 468 "syntax.act"

    HASHID nm = lookup_anon () ;
    (ZI1379) = DEREF_id ( hashid_id ( nm ) ) ;
    crt_id_qualifier = qual_none ;
    qual_namespace = NULL_nspace ;
#line 1078 "syntax8.c"
			}
			/* END OF ACTION: id_anon */
			/* BEGINNING OF ACTION: declarator_posn */
			{
#line 1717 "syntax.act"

    IDENTIFIER pid = underlying_id ( (ZI1379) ) ;
    DEREF_loc ( id_loc ( pid ), decl_loc ) ;
#line 1087 "syntax8.c"
			}
			/* END OF ACTION: declarator_posn */
			ZR1163 (ZI1378, ZI1379, &ZIt, &ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declarator_bad */
			{
#line 1738 "syntax.act"

    if ( IS_NULL_type ( (ZIt) ) ) {
	report ( crt_loc, ERR_dcl_meaning_paren () ) ;
    }
#line 1102 "syntax8.c"
			}
			/* END OF ACTION: declarator_bad */
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZR1163 (ZIt, ZIid, &ZI1161, &ZI1162);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 66:
		{
			EXP ZIe;
			TYPE ZI1376;
			IDENTIFIER ZI1377;
			TYPE ZIt;
			IDENTIFIER ZIid;

			/* BEGINNING OF INLINE: open-square */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 66:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: open-square */
			ZR955 (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_array */
			{
#line 1373 "syntax.act"

    NAT n = make_array_dim ( (ZIe) ) ;
    MAKE_type_array ( cv_none, NULL_type, n, (ZI1376) ) ;
#line 1151 "syntax8.c"
			}
			/* END OF ACTION: type_array */
			/* BEGINNING OF INLINE: close-square */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 40:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: close-square */
			/* BEGINNING OF ACTION: id_anon */
			{
#line 468 "syntax.act"

    HASHID nm = lookup_anon () ;
    (ZI1377) = DEREF_id ( hashid_id ( nm ) ) ;
    crt_id_qualifier = qual_none ;
    qual_namespace = NULL_nspace ;
#line 1175 "syntax8.c"
			}
			/* END OF ACTION: id_anon */
			/* BEGINNING OF ACTION: declarator_posn */
			{
#line 1717 "syntax.act"

    IDENTIFIER pid = underlying_id ( (ZI1377) ) ;
    DEREF_loc ( id_loc ( pid ), decl_loc ) ;
#line 1184 "syntax8.c"
			}
			/* END OF ACTION: declarator_posn */
			ZR1163 (ZI1376, ZI1377, &ZIt, &ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declarator_bad */
			{
#line 1738 "syntax.act"

    if ( IS_NULL_type ( (ZIt) ) ) {
	report ( crt_loc, ERR_dcl_meaning_paren () ) ;
    }
#line 1199 "syntax8.c"
			}
			/* END OF ACTION: declarator_bad */
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZR1163 (ZIt, ZIid, &ZI1161, &ZI1162);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 10: case 11: case 33: case 78:
		{
			TYPE ZIp;
			TYPE ZIq;
			IDENTIFIER ZIid;
			TYPE ZIt;

			ZRptr_Hoperator (&ZIp);
			ZRparameter_Hdeclarator_Haux_Hopt (&ZIq, &ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_build */
			{
#line 1399 "syntax.act"

    (ZIt) = ( IS_NULL_type ( (ZIq) ) ? (ZIp) : inject_pre_type ( (ZIq), (ZIp), 0 ) ) ;
#line 1234 "syntax8.c"
			}
			/* END OF ACTION: type_build */
			/* BEGINNING OF ACTION: declarator_bad */
			{
#line 1738 "syntax.act"

    if ( IS_NULL_type ( (ZIt) ) ) {
	report ( crt_loc, ERR_dcl_meaning_paren () ) ;
    }
#line 1244 "syntax8.c"
			}
			/* END OF ACTION: declarator_bad */
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZR1163 (ZIt, ZIid, &ZI1161, &ZI1162);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 2: case 7: case 8: case 9:
	case 25: case 39: case 47: case 83:
	case 94: case 97: case 98: case 102:
	case 104: case 105: case 106: case 110:
	case 111: case 112: case 114: case 115:
	case 117: case 118: case 120: case 121:
	case 122: case 123: case 124: case 127:
	case 129: case 133: case 136: case 137:
	case 138: case 153: case 155: case 156:
	case 185: case 275: case 286: case 299:
		{
			IDENTIFIER ZI1371;
			int ZIw;
			TYPE ZIt;
			IDENTIFIER ZIid;

			/* BEGINNING OF ACTION: id_none */
			{
#line 461 "syntax.act"

    (ZI1371) = NULL_id ;
    crt_id_qualifier = qual_none ;
    qual_namespace = NULL_nspace ;
#line 1284 "syntax8.c"
			}
			/* END OF ACTION: id_none */
			/* BEGINNING OF ACTION: bool_false */
			{
#line 2051 "syntax.act"
 (ZIw) = 0 ; 
#line 1291 "syntax8.c"
			}
			/* END OF ACTION: bool_false */
			/* BEGINNING OF ACTION: param_begin */
			{
#line 1201 "syntax.act"

    func_type_defn ( 0 ) ;
    begin_param ( (ZI1371) ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
#line 1302 "syntax8.c"
			}
			/* END OF ACTION: param_begin */
			ZRparameter_Htail (ZIw, &ZIt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: param_end */
			{
#line 1210 "syntax.act"

    end_param () ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 1 ;
#line 1317 "syntax8.c"
			}
			/* END OF ACTION: param_end */
			/* BEGINNING OF ACTION: id_anon */
			{
#line 468 "syntax.act"

    HASHID nm = lookup_anon () ;
    (ZIid) = DEREF_id ( hashid_id ( nm ) ) ;
    crt_id_qualifier = qual_none ;
    qual_namespace = NULL_nspace ;
#line 1328 "syntax8.c"
			}
			/* END OF ACTION: id_anon */
			/* BEGINNING OF ACTION: declarator_posn */
			{
#line 1717 "syntax.act"

    IDENTIFIER pid = underlying_id ( (ZIid) ) ;
    DEREF_loc ( id_loc ( pid ), decl_loc ) ;
#line 1337 "syntax8.c"
			}
			/* END OF ACTION: declarator_posn */
			ZR1163 (ZIt, ZIid, &ZI1161, &ZI1162);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1161 = ZI1161;
	*ZO1162 = ZI1162;
}

void
parse_mem_type(TYPE *ZOt)
{
	TYPE ZIt;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		BASE_TYPE ZIbt;
		TYPE ZIp;
		CV_SPEC ZIcv;
		TYPE ZIq;

		ZRtype_Hspecifier_Hseq (&ZIbt, &ZIp, &ZIcv);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: type_complete */
		{
#line 1323 "syntax.act"

    (ZIq) = complete_pre_type ( (ZIbt), (ZIp), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 1384 "syntax8.c"
		}
		/* END OF ACTION: type_complete */
		/* BEGINNING OF INLINE: 986 */
		{
			switch (CURRENT_TERMINAL) {
			case 73:
				{
					QUALIFIER ZIi;
					int ZIb;
					EXP ZIc;

					ADVANCE_LEXER;
					/* BEGINNING OF ACTION: qual_get */
					{
#line 538 "syntax.act"

    (ZIi) = crt_id_qualifier ;
    (ZIb) = crt_templ_qualifier ;
#line 1403 "syntax8.c"
					}
					/* END OF ACTION: qual_get */
					ZRconstant_Hexpression (&ZIc);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
					/* BEGINNING OF ACTION: type_bitfield */
					{
#line 1384 "syntax.act"

    (ZIt) = make_bitfield_type ( (ZIq), (ZIbt), (ZIc), 0 ) ;
#line 1416 "syntax8.c"
					}
					/* END OF ACTION: type_bitfield */
					/* BEGINNING OF ACTION: qual_set */
					{
#line 543 "syntax.act"

    crt_id_qualifier = (ZIi) ;
    crt_templ_qualifier = (ZIb) ;
#line 1425 "syntax8.c"
					}
					/* END OF ACTION: qual_set */
				}
				break;
			default:
				{
					ZRabstract_Hdeclarator_Hopt (ZIq, &ZIt);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
				}
				break;
			}
		}
		/* END OF INLINE: 986 */
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOt = ZIt;
}

void
ZR871(IDENTIFIER *ZOid)
{
	IDENTIFIER ZIid;

	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
	case 7: case 8: case 9: case 83:
		{
			NAMESPACE ZIns;
			IDENTIFIER ZIaid;

			ZRany_Hnested_Hname_Hopt (&ZIns);
			ZRany_Hclass_Hname (&ZIaid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: namespace_id */
			{
#line 504 "syntax.act"

    (ZIid) = check_id ( (ZIns), (ZIaid), 0 ) ;
    last_namespace = (ZIns) ;
#line 1475 "syntax8.c"
			}
			/* END OF ACTION: namespace_id */
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: id_anon */
			{
#line 468 "syntax.act"

    HASHID nm = lookup_anon () ;
    (ZIid) = DEREF_id ( hashid_id ( nm ) ) ;
    crt_id_qualifier = qual_none ;
    qual_namespace = NULL_nspace ;
#line 1490 "syntax8.c"
			}
			/* END OF ACTION: id_anon */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOid = ZIid;
}

void
parse_operator(IDENTIFIER *ZOid)
{
	IDENTIFIER ZIid;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		QUALIFIER ZIi;
		int ZIb;
		int ZItd;
		IDENTIFIER ZItid;

		switch (CURRENT_TERMINAL) {
		case 141:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF ACTION: qual_get */
		{
#line 538 "syntax.act"

    (ZIi) = crt_id_qualifier ;
    (ZIb) = crt_templ_qualifier ;
#line 1533 "syntax8.c"
		}
		/* END OF ACTION: qual_get */
		/* BEGINNING OF ACTION: type_decl_begin */
		{
#line 420 "syntax.act"

    (ZItd) = have_type_declaration ;
    have_type_declaration = TYPE_DECL_NONE ;
#line 1542 "syntax8.c"
		}
		/* END OF ACTION: type_decl_begin */
		/* BEGINNING OF INLINE: 459 */
		{
			{
				TYPE ZI1320;
				BASE_TYPE ZIb1;
				TYPE ZIt1;
				CV_SPEC ZIcv1;
				BASE_TYPE ZIbt;
				TYPE ZIp;
				CV_SPEC ZIcv;
				TYPE ZIs;
				TYPE ZIq;
				TYPE ZIt;
				int ZId;

				/* BEGINNING OF ACTION: is_type_specifier */
				{
#line 2126 "syntax.act"

    /* Resolve type-specifiers from other declarators */
    (ZI0) = predict_tspec ( 0 ) ;
#line 1566 "syntax8.c"
				}
				/* END OF ACTION: is_type_specifier */
				if (!ZI0)
					goto ZL3;
				/* BEGINNING OF ACTION: type_none */
				{
#line 1278 "syntax.act"

    (ZI1320) = NULL_type ;
#line 1576 "syntax8.c"
				}
				/* END OF ACTION: type_none */
				ZRtype_Hspecifier (ZI1320, &ZIb1, &ZIt1, &ZIcv1);
				ZR887 (&ZIb1, &ZIt1, &ZIcv1, &ZIbt, &ZIp, &ZIcv);
				if ((CURRENT_TERMINAL) == 355) {
					RESTORE_LEXER;
					goto ZL1;
				}
				/* BEGINNING OF ACTION: type_complete */
				{
#line 1323 "syntax.act"

    (ZIs) = complete_pre_type ( (ZIbt), (ZIp), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 1591 "syntax8.c"
				}
				/* END OF ACTION: type_complete */
				ZRconversion_Hdeclarator_Hopt (&ZIq);
				if ((CURRENT_TERMINAL) == 355) {
					RESTORE_LEXER;
					goto ZL1;
				}
				/* BEGINNING OF ACTION: type_inject */
				{
#line 1395 "syntax.act"

    (ZIt) = ( IS_NULL_type ( (ZIq) ) ? (ZIs) : inject_pre_type ( (ZIq), (ZIs), 1 ) ) ;
#line 1604 "syntax8.c"
				}
				/* END OF ACTION: type_inject */
				/* BEGINNING OF ACTION: type_decl_end */
				{
#line 426 "syntax.act"

    int td = have_type_declaration ;
    (ZId) = 0 ;
    if ( td != TYPE_DECL_NONE ) {
	if ( td == TYPE_DECL_ELABORATE && found_elaborate_type ) {
	    /* This is allowed */
	    /* EMPTY */
	} else {
	    (ZId) = 1 ;
	}
    }
    have_type_declaration = (ZItd) ;
#line 1622 "syntax8.c"
				}
				/* END OF ACTION: type_decl_end */
				/* BEGINNING OF ACTION: conversion_func */
				{
#line 450 "syntax.act"

    HASHID nm = lookup_conv ( (ZIt) ) ;
    if ( (ZId) ) report ( crt_loc, ERR_class_conv_fct_typedef ( nm ) ) ;
    (ZItid) = DEREF_id ( hashid_id ( nm ) ) ;
    set_hashid_loc ( (ZItid), underlying_op ) ;
#line 1633 "syntax8.c"
				}
				/* END OF ACTION: conversion_func */
				goto ZL2;
			}
			/*UNREACHED*/
		ZL3:;
			switch (CURRENT_TERMINAL) {
			case 33: case 34: case 35: case 36:
			case 41: case 42: case 43: case 44:
			case 45: case 46: case 48: case 49:
			case 50: case 53: case 54: case 55:
			case 56: case 57: case 58: case 59:
			case 60: case 61: case 62: case 63:
			case 65: case 66: case 67: case 68:
			case 69: case 70: case 71: case 72:
			case 73: case 74: case 75: case 76:
			case 78: case 79: case 80: case 81:
			case 82: case 83: case 84: case 85:
			case 86: case 87: case 116: case 131:
			case 140: case 152: case 170: case 330:
				{
					int ZIop;

					ZRoperator_Hname (&ZIop);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
					/* BEGINNING OF ACTION: type_decl_quit */
					{
#line 439 "syntax.act"

    have_type_declaration = (ZItd) ;
#line 1667 "syntax8.c"
					}
					/* END OF ACTION: type_decl_quit */
					/* BEGINNING OF ACTION: operator_func */
					{
#line 444 "syntax.act"

    /* op will be in its primary form */
    HASHID nm = lookup_op ( (ZIop) ) ;
    (ZItid) = DEREF_id ( hashid_id ( nm ) ) ;
    set_hashid_loc ( (ZItid), underlying_op ) ;
#line 1678 "syntax8.c"
					}
					/* END OF ACTION: operator_func */
				}
				break;
			default:
				goto ZL1;
			}
		ZL2:;
		}
		/* END OF INLINE: 459 */
		/* BEGINNING OF ACTION: qual_set */
		{
#line 543 "syntax.act"

    crt_id_qualifier = (ZIi) ;
    crt_templ_qualifier = (ZIb) ;
#line 1695 "syntax8.c"
		}
		/* END OF ACTION: qual_set */
		ZIid = ZItid;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOid = ZIid;
}

void
ZRmember_Hspecifier_Hopt(EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 36:
		{
			ADVANCE_LEXER;
			ZRconstant_Hexpression (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: exp_none */
			{
#line 581 "syntax.act"

    (ZIe) = NULL_exp ;
#line 1731 "syntax8.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZR1254(TYPE *ZIt, BASE_TYPE *ZIbt, TYPE *ZIt1, CV_SPEC *ZIcv1, DECL_SPEC *ZIds2)
{
	switch (CURRENT_TERMINAL) {
	case 77:
		{
			/* BEGINNING OF ACTION: declare_id_empty */
			{
#line 1631 "syntax.act"

    IGNORE empty_decl ( (*ZIds2), (*ZIt), (*ZIbt), (*ZIt1), (*ZIcv1), last_lex_token, 0 ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
    have_type_specifier = 0 ;
#line 1761 "syntax8.c"
			}
			/* END OF ACTION: declare_id_empty */
			/* BEGINNING OF ACTION: access_check */
			{
#line 1462 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( crt_func_id ) ;
    }
#line 1771 "syntax8.c"
			}
			/* END OF ACTION: access_check */
			ADVANCE_LEXER;
		}
		break;
	case 1: case 2: case 3: case 4:
	case 5: case 6: case 7: case 8:
	case 9: case 10: case 11: case 33:
	case 65: case 78: case 83: case 141:
		{
			TYPE ZIt2;
			DECL_SPEC ZIds3;
			TYPE ZIt3;
			ACCESS_LIST ZIr;
			TYPE ZIs;
			IDENTIFIER ZIid;
			int ZIc;
			IDENTIFIER ZId;

			/* BEGINNING OF ACTION: dspec_complete */
			{
#line 1573 "syntax.act"

    /* Complete a declaration specifier and a type */
    (ZIds3) = complete_dspec ( (*ZIds2), (*ZIbt), (*ZIt1), (*ZIcv1) ) ;
    (ZIt2) = complete_pre_type ( (*ZIbt), (*ZIt1), (*ZIcv1), 0 ) ;
    have_type_specifier = 0 ;
#line 1799 "syntax8.c"
			}
			/* END OF ACTION: dspec_complete */
			/* BEGINNING OF ACTION: type_inject */
			{
#line 1395 "syntax.act"

    (ZIt3) = ( IS_NULL_type ( (*ZIt) ) ? (ZIt2) : inject_pre_type ( (*ZIt), (ZIt2), 1 ) ) ;
#line 1807 "syntax8.c"
			}
			/* END OF ACTION: type_inject */
			/* BEGINNING OF ACTION: access_return */
			{
#line 1482 "syntax.act"

    save_access ( &(ZIr) ) ;
#line 1815 "syntax8.c"
			}
			/* END OF ACTION: access_return */
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1706 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 1823 "syntax8.c"
			}
			/* END OF ACTION: declarator_start */
			ZRdeclarator (ZIt3, &ZIs, &ZIid, &ZIc);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declare_id */
			{
#line 1610 "syntax.act"

    if ( type_tag ( (ZIs) ) == type_func_tag ) {
	/* Look ahead for function definitions */
	int def = predict_func_defn () ;
	if ( def & !have_func_declarator ) adjust_param ( (ZIs) ) ;
	(ZId) = make_func_decl ( (ZIds3), (ZIs), (ZIid), def ) ;
	is_function_next = def ;
    } else {
	int def = predict_obj_defn () ;
	(ZId) = make_object_decl ( (ZIds3), (ZIs), (ZIid), def ) ;
	is_function_next = 0 ;
    }
    if ( IS_id_type_alias ( (ZId) ) ) {
	BASE_TYPE bs = DEREF_btype ( id_type_alias_rep ( (ZId) ) ) ;
	bs |= (*ZIbt) ;
	COPY_btype ( id_type_alias_rep ( (ZId) ), bs ) ;
    }
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
#line 1853 "syntax8.c"
			}
			/* END OF ACTION: declare_id */
			/* BEGINNING OF ACTION: access_check_ret */
			{
#line 1478 "syntax.act"

    IGNORE clear_access ( (ZId), &(ZIr) ) ;
#line 1861 "syntax8.c"
			}
			/* END OF ACTION: access_check_ret */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1473 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (ZId) ) ;
    }
#line 1871 "syntax8.c"
			}
			/* END OF ACTION: access_check_decl */
			ZR1077 (ZIbt, &ZIds3, &ZIt3, &ZIr, &ZIc, &ZId);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZRinclusive_Hor_Hexpression(EXP *ZO1201)
{
	EXP ZI1201;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIe;

		ZRexclusive_Hor_Hexpression (&ZIe);
		ZR1202 (ZIe, &ZI1201);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1201 = ZI1201;
}

void
ZRjump_Hlabel(EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 96:
		{
			EXP ZIc;

			ADVANCE_LEXER;
			ZRconstant_Hexpression (&ZIc);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: stmt_goto_case */
			{
#line 977 "syntax.act"

    report ( crt_loc, ERR_stmt_goto_case ( lex_case ) ) ;
    (ZIe) = begin_case_stmt ( (ZIc), 1 ) ;
#line 1940 "syntax8.c"
			}
			/* END OF ACTION: stmt_goto_case */
		}
		break;
	case 100:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: stmt_goto_default */
			{
#line 982 "syntax.act"

    report ( crt_loc, ERR_stmt_goto_case ( lex_default ) ) ;
    (ZIe) = begin_default_stmt ( 1 ) ;
#line 1954 "syntax8.c"
			}
			/* END OF ACTION: stmt_goto_default */
		}
		break;
	case 1: case 2: case 3: case 4:
		{
			IDENTIFIER ZIid;

			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 219 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 1973 "syntax8.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 227 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 1986 "syntax8.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 231 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 1999 "syntax8.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 223 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 2012 "syntax8.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto ZL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: qual_none */
			{
#line 551 "syntax.act"

    crt_id_qualifier = qual_none ;
    crt_templ_qualifier = 0 ;
    qual_namespace = NULL_nspace ;
#line 2030 "syntax8.c"
			}
			/* END OF ACTION: qual_none */
			/* BEGINNING OF ACTION: stmt_goto */
			{
#line 972 "syntax.act"

    (ZIe) = make_goto_stmt ( (ZIid) ) ;
#line 2038 "syntax8.c"
			}
			/* END OF ACTION: stmt_goto */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRsimple_Htype_Hspecifier(BASE_TYPE *ZObt, TYPE *ZOt)
{
	BASE_TYPE ZIbt;
	TYPE ZIt;

	switch (CURRENT_TERMINAL) {
	case 25:
		{
			/* BEGINNING OF EXTRACT: complex-type */
			{
#line 371 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZIt = parse_type_token ( id, args ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_type_specifier = 1 ;
    RESCAN_LEXER ;
#line 2075 "syntax8.c"
			}
			/* END OF EXTRACT: complex-type */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1254 "syntax.act"
 (ZIbt) = btype_none ; 
#line 2083 "syntax8.c"
			}
			/* END OF ACTION: btype_none */
		}
		break;
	case 8: case 9: case 83:
		{
			IDENTIFIER ZIid;

			ZRany_Hqualified_Htype (&ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_name */
			{
#line 1287 "syntax.act"

    MAKE_type_pre ( cv_none, btype_alias, crt_id_qualifier, (ZIt) ) ;
    COPY_id ( type_name ( (ZIt) ), (ZIid) ) ;
    have_type_specifier = 1 ;
#line 2104 "syntax8.c"
			}
			/* END OF ACTION: type_name */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1254 "syntax.act"
 (ZIbt) = btype_none ; 
#line 2111 "syntax8.c"
			}
			/* END OF ACTION: btype_none */
		}
		break;
	case 97: case 102: case 106: case 110:
	case 111: case 114: case 115: case 122:
	case 123: case 127: case 156: case 185:
	case 286: case 299:
		{
			ZRbase_Htype_Hspecifier (&ZIbt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_pre */
			{
#line 1282 "syntax.act"

    (ZIt) = NULL_type ;
    have_type_specifier = 1 ;
#line 2132 "syntax8.c"
			}
			/* END OF ACTION: type_pre */
		}
		break;
	case 2: case 7:
		{
			IDENTIFIER ZIid;

			ZRunqualified_Htype (&ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_name */
			{
#line 1287 "syntax.act"

    MAKE_type_pre ( cv_none, btype_alias, crt_id_qualifier, (ZIt) ) ;
    COPY_id ( type_name ( (ZIt) ), (ZIid) ) ;
    have_type_specifier = 1 ;
#line 2153 "syntax8.c"
			}
			/* END OF ACTION: type_name */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1254 "syntax.act"
 (ZIbt) = btype_none ; 
#line 2160 "syntax8.c"
			}
			/* END OF ACTION: btype_none */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZObt = ZIbt;
	*ZOt = ZIt;
}

void
ZR1256(TYPE *ZIt, DECL_SPEC *ZIds, BASE_TYPE *ZIbt, TYPE *ZIt1, CV_SPEC *ZI1255, EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 77:
		{
			/* BEGINNING OF ACTION: declare_id_empty */
			{
#line 1631 "syntax.act"

    IGNORE empty_decl ( (*ZIds), (*ZIt), (*ZIbt), (*ZIt1), (*ZI1255), last_lex_token, 0 ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
    have_type_specifier = 0 ;
#line 2195 "syntax8.c"
			}
			/* END OF ACTION: declare_id_empty */
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_none */
			{
#line 581 "syntax.act"

    (ZIe) = NULL_exp ;
#line 2204 "syntax8.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 1: case 2: case 3: case 4:
	case 5: case 6: case 7: case 8:
	case 9: case 10: case 11: case 33:
	case 65: case 78: case 83: case 141:
		{
			DECL_SPEC ZIds1;
			DECL_SPEC ZIds2;
			TYPE ZIt2;
			DECL_SPEC ZIds3;
			TYPE ZIt3;
			ACCESS_LIST ZIr;
			TYPE ZIs;
			IDENTIFIER ZIid;
			int ZIc;
			IDENTIFIER ZId;

			/* BEGINNING OF ACTION: dspec_none */
			{
#line 1546 "syntax.act"
 (ZIds1) = dspec_none ; 
#line 2229 "syntax8.c"
			}
			/* END OF ACTION: dspec_none */
			/* BEGINNING OF ACTION: dspec_join */
			{
#line 1562 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (*ZIds) & (ZIds1) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds2) = ( (*ZIds) | (ZIds1) ) ;
#line 2240 "syntax8.c"
			}
			/* END OF ACTION: dspec_join */
			/* BEGINNING OF ACTION: dspec_complete */
			{
#line 1573 "syntax.act"

    /* Complete a declaration specifier and a type */
    (ZIds3) = complete_dspec ( (ZIds2), (*ZIbt), (*ZIt1), (*ZI1255) ) ;
    (ZIt2) = complete_pre_type ( (*ZIbt), (*ZIt1), (*ZI1255), 0 ) ;
    have_type_specifier = 0 ;
#line 2251 "syntax8.c"
			}
			/* END OF ACTION: dspec_complete */
			/* BEGINNING OF ACTION: type_inject */
			{
#line 1395 "syntax.act"

    (ZIt3) = ( IS_NULL_type ( (*ZIt) ) ? (ZIt2) : inject_pre_type ( (*ZIt), (ZIt2), 1 ) ) ;
#line 2259 "syntax8.c"
			}
			/* END OF ACTION: type_inject */
			/* BEGINNING OF ACTION: access_return */
			{
#line 1482 "syntax.act"

    save_access ( &(ZIr) ) ;
#line 2267 "syntax8.c"
			}
			/* END OF ACTION: access_return */
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1706 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 2275 "syntax8.c"
			}
			/* END OF ACTION: declarator_start */
			ZRdeclarator (ZIt3, &ZIs, &ZIid, &ZIc);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declare_id */
			{
#line 1610 "syntax.act"

    if ( type_tag ( (ZIs) ) == type_func_tag ) {
	/* Look ahead for function definitions */
	int def = predict_func_defn () ;
	if ( def & !have_func_declarator ) adjust_param ( (ZIs) ) ;
	(ZId) = make_func_decl ( (ZIds3), (ZIs), (ZIid), def ) ;
	is_function_next = def ;
    } else {
	int def = predict_obj_defn () ;
	(ZId) = make_object_decl ( (ZIds3), (ZIs), (ZIid), def ) ;
	is_function_next = 0 ;
    }
    if ( IS_id_type_alias ( (ZId) ) ) {
	BASE_TYPE bs = DEREF_btype ( id_type_alias_rep ( (ZId) ) ) ;
	bs |= (*ZIbt) ;
	COPY_btype ( id_type_alias_rep ( (ZId) ), bs ) ;
    }
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
#line 2305 "syntax8.c"
			}
			/* END OF ACTION: declare_id */
			/* BEGINNING OF ACTION: access_check_ret */
			{
#line 1478 "syntax.act"

    IGNORE clear_access ( (ZId), &(ZIr) ) ;
#line 2313 "syntax8.c"
			}
			/* END OF ACTION: access_check_ret */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1473 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (ZId) ) ;
    }
#line 2323 "syntax8.c"
			}
			/* END OF ACTION: access_check_decl */
			ZR1077 (ZIbt, &ZIds3, &ZIt3, &ZIr, &ZIc, &ZId);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_none */
			{
#line 581 "syntax.act"

    (ZIe) = NULL_exp ;
#line 2336 "syntax8.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRcomma_Hexpression_Htail(SID_LIST_EXP *ZOp)
{
	SID_LIST_EXP ZIp;

	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 5:
	case 6: case 7: case 8: case 9:
	case 17: case 18: case 19: case 20:
	case 21: case 22: case 23: case 25:
	case 33: case 43: case 59: case 61:
	case 62: case 65: case 69: case 71:
	case 78: case 83: case 85: case 97:
	case 102: case 106: case 110: case 111:
	case 114: case 115: case 116: case 122:
	case 123: case 127: case 130: case 131:
	case 132: case 135: case 140: case 141:
	case 145: case 146: case 148: case 149:
	case 150: case 152: case 156: case 170:
	case 185: case 206: case 210: case 255:
	case 286: case 299: case 330:
		{
			EXP ZIa;

			ZRassignment_Hexpression (&ZIa);
			ZR1292 (&ZIa, &ZIp);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 298: case 324:
		{
			EXP ZIa;
			SID_LIST_EXP ZIq;

			ZRflow_Hexpression (&ZIa);
			ZRcomma_Hexpression_Htail (&ZIq);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: list_exp_cons */
			{
#line 566 "syntax.act"

    CONS_exp ( (ZIa), (ZIq), (ZIp) ) ;
#line 2402 "syntax8.c"
			}
			/* END OF ACTION: list_exp_cons */
		}
		break;
	case 346:
		{
			EXP ZIa;
			SID_LIST_EXP ZIq;

			ZRinset_Hflow_Hexpression (&ZIa);
			ZRcomma_Hexpression_Htail (&ZIq);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: list_exp_cons */
			{
#line 566 "syntax.act"

    CONS_exp ( (ZIa), (ZIq), (ZIp) ) ;
#line 2423 "syntax8.c"
			}
			/* END OF ACTION: list_exp_cons */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOp = ZIp;
}

void
ZRparameter_Hdeclaration_Hlist(int *ZOell)
{
	int ZIell;

ZL2_parameter_Hdeclaration_Hlist:;
	switch (CURRENT_TERMINAL) {
	case 47:
		{
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: bool_true */
			{
#line 2052 "syntax.act"
 (ZIell) = 1 ; 
#line 2455 "syntax8.c"
			}
			/* END OF ACTION: bool_true */
		}
		break;
	case 2: case 7: case 8: case 9:
	case 25: case 83: case 94: case 97:
	case 98: case 102: case 104: case 105:
	case 106: case 110: case 111: case 112:
	case 114: case 115: case 117: case 118:
	case 120: case 121: case 122: case 123:
	case 124: case 127: case 129: case 133:
	case 136: case 137: case 138: case 153:
	case 155: case 156: case 185: case 275:
	case 286: case 299:
		{
			TYPE ZIs;
			int ZIp;
			IDENTIFIER ZId;

			/* BEGINNING OF ACTION: type_none */
			{
#line 1278 "syntax.act"

    (ZIs) = NULL_type ;
#line 2480 "syntax8.c"
			}
			/* END OF ACTION: type_none */
			/* BEGINNING OF ACTION: param_func */
			{
#line 1748 "syntax.act"

    (ZIp) = CONTEXT_PARAMETER ;
#line 2488 "syntax8.c"
			}
			/* END OF ACTION: param_func */
			ZRparameter_Hdeclaration (ZIs, ZIp, &ZId);
			/* BEGINNING OF INLINE: 978 */
			{
				switch (CURRENT_TERMINAL) {
				case 42:
					{
						ADVANCE_LEXER;
						/* BEGINNING OF INLINE: parameter-declaration-list */
						goto ZL2_parameter_Hdeclaration_Hlist;
						/* END OF INLINE: parameter-declaration-list */
					}
					/*UNREACHED*/
				case 47:
					{
						ADVANCE_LEXER;
						/* BEGINNING OF ACTION: bool_true */
						{
#line 2052 "syntax.act"
 (ZIell) = 1 ; 
#line 2510 "syntax8.c"
						}
						/* END OF ACTION: bool_true */
					}
					break;
				default:
					{
						/* BEGINNING OF ACTION: bool_false */
						{
#line 2051 "syntax.act"
 (ZIell) = 0 ; 
#line 2521 "syntax8.c"
						}
						/* END OF ACTION: bool_false */
					}
					break;
				case 355:
					RESTORE_LEXER;
					goto ZL1;
				}
			}
			/* END OF INLINE: 978 */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOell = ZIell;
}

void
ZR1384(TYPE *ZI1382, TYPE *ZOt)
{
	TYPE ZIt;

	switch (CURRENT_TERMINAL) {
	case 10: case 11: case 33: case 65:
	case 66: case 78: case 332:
		{
			TYPE ZIq;

			ZRabstract_Hdeclarator_Haux (&ZIq);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_build */
			{
#line 1399 "syntax.act"

    (ZIt) = ( IS_NULL_type ( (ZIq) ) ? (*ZI1382) : inject_pre_type ( (ZIq), (*ZI1382), 0 ) ) ;
#line 2568 "syntax8.c"
			}
			/* END OF ACTION: type_build */
		}
		break;
	default:
		{
			ZIt = *ZI1382;
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOt = ZIt;
}

void
ZR1257(void)
{
	switch (CURRENT_TERMINAL) {
	case 26: case 30:
		{
			ZRdeclaration_Hcond ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: access_check */
			{
#line 1462 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( crt_func_id ) ;
    }
#line 2607 "syntax8.c"
			}
			/* END OF ACTION: access_check */
		}
		break;
	case 126: case 139: case 154:
		{
			EXP ZIe;

			ZRdeclaration_Hother (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declare_extern */
			{
#line 1744 "syntax.act"

    external_declaration ( (ZIe), 1 ) ;
#line 2626 "syntax8.c"
			}
			/* END OF ACTION: declare_extern */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZR1003(IDENTIFIER *ZId, SID_LIST_EXP *ZOp)
{
	SID_LIST_EXP ZIp;

	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 5:
	case 6: case 7: case 8: case 9:
	case 17: case 18: case 19: case 20:
	case 21: case 22: case 23: case 25:
	case 33: case 43: case 59: case 61:
	case 62: case 64: case 65: case 69:
	case 71: case 78: case 83: case 85:
	case 97: case 102: case 106: case 110:
	case 111: case 114: case 115: case 116:
	case 122: case 123: case 127: case 130:
	case 131: case 132: case 135: case 140:
	case 141: case 145: case 146: case 148:
	case 149: case 150: case 152: case 156:
	case 170: case 185: case 206: case 210:
	case 255: case 286: case 299: case 330:
		{
			ZRinitialiser_Hlist (*ZId, &ZIp);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: list_exp_null */
			{
#line 562 "syntax.act"

    (ZIp) = NULL_list ( EXP ) ;
#line 2678 "syntax8.c"
			}
			/* END OF ACTION: list_exp_null */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOp = ZIp;
}

void
ZRliteral(EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 135: case 150:
		{
			ZRboolean_Hliteral (&ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 17: case 18:
		{
			/* BEGINNING OF INLINE: character-literal */
			{
				switch (CURRENT_TERMINAL) {
				case 17:
					{
						/* BEGINNING OF EXTRACT: char-exp */
						{
#line 315 "syntax.act"

    ZIe = crt_token->pp_data.exp ;
#line 2721 "syntax8.c"
						}
						/* END OF EXTRACT: char-exp */
						ADVANCE_LEXER;
					}
					break;
				case 18:
					{
						/* BEGINNING OF EXTRACT: wchar-exp */
						{
#line 319 "syntax.act"

    ZIe = crt_token->pp_data.exp ;
#line 2734 "syntax8.c"
						}
						/* END OF EXTRACT: wchar-exp */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto ZL1;
				}
			}
			/* END OF INLINE: character-literal */
		}
		break;
	case 22:
		{
			/* BEGINNING OF INLINE: floating-literal */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 22:
						/* BEGINNING OF EXTRACT: floating-exp */
						{
#line 302 "syntax.act"

    ZIe = crt_token->pp_data.exp ;
#line 2759 "syntax8.c"
						}
						/* END OF EXTRACT: floating-exp */
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: floating-literal */
		}
		break;
	case 21:
		{
			/* BEGINNING OF INLINE: integer-literal */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 21:
						/* BEGINNING OF EXTRACT: integer-exp */
						{
#line 298 "syntax.act"

    ZIe = crt_token->pp_data.exp ;
#line 2784 "syntax8.c"
						}
						/* END OF EXTRACT: integer-exp */
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: integer-literal */
		}
		break;
	case 19: case 20:
		{
			/* BEGINNING OF INLINE: string-literal */
			{
				switch (CURRENT_TERMINAL) {
				case 19:
					{
						/* BEGINNING OF EXTRACT: string-exp */
						{
#line 323 "syntax.act"

    ZIe = crt_token->pp_data.exp ;
#line 2809 "syntax8.c"
						}
						/* END OF EXTRACT: string-exp */
						ADVANCE_LEXER;
					}
					break;
				case 20:
					{
						/* BEGINNING OF EXTRACT: wstring-exp */
						{
#line 327 "syntax.act"

    ZIe = crt_token->pp_data.exp ;
#line 2822 "syntax8.c"
						}
						/* END OF EXTRACT: wstring-exp */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto ZL1;
				}
			}
			/* END OF INLINE: string-literal */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRexception_Hspecification_Hopt(SID_LIST_TYPE *ZOp)
{
	SID_LIST_TYPE ZIp;

	switch (CURRENT_TERMINAL) {
	case 149:
		{
			ADVANCE_LEXER;
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF INLINE: 1108 */
			{
				switch (CURRENT_TERMINAL) {
				case 47:
					{
						ADVANCE_LEXER;
						/* BEGINNING OF ACTION: list_type_ellipsis */
						{
#line 1424 "syntax.act"

    report ( crt_loc, ERR_except_spec_ellipsis () ) ;
    (ZIp) = univ_type_set ;
#line 2876 "syntax8.c"
						}
						/* END OF ACTION: list_type_ellipsis */
					}
					break;
				case 2: case 7: case 8: case 9:
				case 25: case 83: case 97: case 98:
				case 102: case 104: case 106: case 110:
				case 111: case 114: case 115: case 118:
				case 121: case 122: case 123: case 124:
				case 127: case 129: case 153: case 156:
				case 185: case 286: case 299:
					{
						ZRtype_Hid_Hlist (&ZIp);
						if ((CURRENT_TERMINAL) == 355) {
							RESTORE_LEXER;
							goto ZL1;
						}
					}
					break;
				default:
					{
						/* BEGINNING OF ACTION: list_type_null */
						{
#line 1411 "syntax.act"

    (ZIp) = NULL_list ( TYPE ) ;
#line 2903 "syntax8.c"
						}
						/* END OF ACTION: list_type_null */
					}
					break;
				}
			}
			/* END OF INLINE: 1108 */
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: list_type_all */
			{
#line 1419 "syntax.act"

    (ZIp) = empty_type_set ;
#line 2927 "syntax8.c"
			}
			/* END OF ACTION: list_type_all */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOp = ZIp;
}

void
parse_decl(TYPE ZIt, DECL_SPEC ZIds)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		BASE_TYPE ZI1250;
		TYPE ZI1251;
		CV_SPEC ZI1252;
		DECL_SPEC ZI1253;
		BASE_TYPE ZIbt;
		TYPE ZIt1;
		CV_SPEC ZIcv1;
		DECL_SPEC ZIds1;
		DECL_SPEC ZIds2;

		/* BEGINNING OF ACTION: is_decl_specifier */
		{
#line 2079 "syntax.act"

    /* Resolve declaration-specifiers from other declarators */
    (ZI0) = predict_dspec ( 0 ) ;
#line 2966 "syntax8.c"
		}
		/* END OF ACTION: is_decl_specifier */
		if (!ZI0)
			goto ZL2;
		ZRdecl_Hspecifier (ZIt, &ZI1250, &ZI1251, &ZI1252, &ZI1253);
		ZR919 (&ZIt, &ZI1250, &ZI1251, &ZI1252, &ZI1253, &ZIbt, &ZIt1, &ZIcv1, &ZIds1);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: dspec_join */
		{
#line 1562 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (ZIds) & (ZIds1) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds2) = ( (ZIds) | (ZIds1) ) ;
#line 2985 "syntax8.c"
		}
		/* END OF ACTION: dspec_join */
		ZR1254 (&ZIt, &ZIbt, &ZIt1, &ZIcv1, &ZIds2);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		goto ZL0;
	}
	/*UNREACHED*/
ZL2:;
	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
	case 5: case 6: case 7: case 8:
	case 9: case 10: case 11: case 33:
	case 65: case 78: case 83: case 141:
		{
			BASE_TYPE ZIbt;
			TYPE ZIt1;
			CV_SPEC ZIcv1;
			DECL_SPEC ZIds1;
			DECL_SPEC ZIds2;
			TYPE ZIt2;
			DECL_SPEC ZIds3;
			TYPE ZIt3;
			ACCESS_LIST ZIr;
			TYPE ZIs;
			IDENTIFIER ZIid;
			int ZIc;
			IDENTIFIER ZId;

			/* BEGINNING OF ACTION: btype_none */
			{
#line 1254 "syntax.act"
 (ZIbt) = btype_none ; 
#line 3021 "syntax8.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: type_none */
			{
#line 1278 "syntax.act"

    (ZIt1) = NULL_type ;
#line 3029 "syntax8.c"
			}
			/* END OF ACTION: type_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1222 "syntax.act"
 (ZIcv1) = cv_none ; 
#line 3036 "syntax8.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: dspec_none */
			{
#line 1546 "syntax.act"
 (ZIds1) = dspec_none ; 
#line 3043 "syntax8.c"
			}
			/* END OF ACTION: dspec_none */
			/* BEGINNING OF ACTION: dspec_join */
			{
#line 1562 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (ZIds) & (ZIds1) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds2) = ( (ZIds) | (ZIds1) ) ;
#line 3054 "syntax8.c"
			}
			/* END OF ACTION: dspec_join */
			/* BEGINNING OF ACTION: dspec_complete */
			{
#line 1573 "syntax.act"

    /* Complete a declaration specifier and a type */
    (ZIds3) = complete_dspec ( (ZIds2), (ZIbt), (ZIt1), (ZIcv1) ) ;
    (ZIt2) = complete_pre_type ( (ZIbt), (ZIt1), (ZIcv1), 0 ) ;
    have_type_specifier = 0 ;
#line 3065 "syntax8.c"
			}
			/* END OF ACTION: dspec_complete */
			/* BEGINNING OF ACTION: type_inject */
			{
#line 1395 "syntax.act"

    (ZIt3) = ( IS_NULL_type ( (ZIt) ) ? (ZIt2) : inject_pre_type ( (ZIt), (ZIt2), 1 ) ) ;
#line 3073 "syntax8.c"
			}
			/* END OF ACTION: type_inject */
			/* BEGINNING OF ACTION: access_return */
			{
#line 1482 "syntax.act"

    save_access ( &(ZIr) ) ;
#line 3081 "syntax8.c"
			}
			/* END OF ACTION: access_return */
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1706 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 3089 "syntax8.c"
			}
			/* END OF ACTION: declarator_start */
			ZRdeclarator (ZIt3, &ZIs, &ZIid, &ZIc);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declare_id */
			{
#line 1610 "syntax.act"

    if ( type_tag ( (ZIs) ) == type_func_tag ) {
	/* Look ahead for function definitions */
	int def = predict_func_defn () ;
	if ( def & !have_func_declarator ) adjust_param ( (ZIs) ) ;
	(ZId) = make_func_decl ( (ZIds3), (ZIs), (ZIid), def ) ;
	is_function_next = def ;
    } else {
	int def = predict_obj_defn () ;
	(ZId) = make_object_decl ( (ZIds3), (ZIs), (ZIid), def ) ;
	is_function_next = 0 ;
    }
    if ( IS_id_type_alias ( (ZId) ) ) {
	BASE_TYPE bs = DEREF_btype ( id_type_alias_rep ( (ZId) ) ) ;
	bs |= (ZIbt) ;
	COPY_btype ( id_type_alias_rep ( (ZId) ), bs ) ;
    }
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
#line 3119 "syntax8.c"
			}
			/* END OF ACTION: declare_id */
			/* BEGINNING OF ACTION: access_check_ret */
			{
#line 1478 "syntax.act"

    IGNORE clear_access ( (ZId), &(ZIr) ) ;
#line 3127 "syntax8.c"
			}
			/* END OF ACTION: access_check_ret */
			/* BEGINNING OF ACTION: access_check_decl */
			{
#line 1473 "syntax.act"

    if ( crt_access_list.pending ) {
	IGNORE report_access ( (ZId) ) ;
    }
#line 3137 "syntax8.c"
			}
			/* END OF ACTION: access_check_decl */
			ZR1077 (&ZIbt, &ZIds3, &ZIt3, &ZIr, &ZIc, &ZId);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		goto ZL1;
	}
	return;
ZL1:;
	{
		/* BEGINNING OF ACTION: error_syntax */
		{
#line 1982 "syntax.act"

    /* Syntax errors */
    ERROR err = ERR_lex_parse ( crt_token ) ;
    report ( crt_loc, err ) ;
    have_syntax_error = 1 ;
#line 3161 "syntax8.c"
		}
		/* END OF ACTION: error_syntax */
	}
ZL0:;
}

void
ZR1385(TYPE *ZO1140)
{
	TYPE ZI1140;

	switch (CURRENT_TERMINAL) {
	case 10: case 11: case 33: case 65:
	case 66: case 78: case 332:
		{
			TYPE ZIt;

			ZRabstract_Hdeclarator_Haux (&ZIt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: declarator_bad */
			{
#line 1738 "syntax.act"

    if ( IS_NULL_type ( (ZIt) ) ) {
	report ( crt_loc, ERR_dcl_meaning_paren () ) ;
    }
#line 3191 "syntax8.c"
			}
			/* END OF ACTION: declarator_bad */
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZR1141 (ZIt, &ZI1140);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 2: case 7: case 8: case 9:
	case 25: case 39: case 47: case 83:
	case 94: case 97: case 98: case 102:
	case 104: case 105: case 106: case 110:
	case 111: case 112: case 114: case 115:
	case 117: case 118: case 120: case 121:
	case 122: case 123: case 124: case 127:
	case 129: case 133: case 136: case 137:
	case 138: case 153: case 155: case 156:
	case 185: case 275: case 286: case 299:
		{
			IDENTIFIER ZIid;
			int ZIw;
			TYPE ZIt;

			/* BEGINNING OF ACTION: id_none */
			{
#line 461 "syntax.act"

    (ZIid) = NULL_id ;
    crt_id_qualifier = qual_none ;
    qual_namespace = NULL_nspace ;
#line 3230 "syntax8.c"
			}
			/* END OF ACTION: id_none */
			/* BEGINNING OF ACTION: bool_false */
			{
#line 2051 "syntax.act"
 (ZIw) = 0 ; 
#line 3237 "syntax8.c"
			}
			/* END OF ACTION: bool_false */
			/* BEGINNING OF ACTION: param_begin */
			{
#line 1201 "syntax.act"

    func_type_defn ( 0 ) ;
    begin_param ( (ZIid) ) ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 0 ;
#line 3248 "syntax8.c"
			}
			/* END OF ACTION: param_begin */
			ZRparameter_Htail (ZIw, &ZIt);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: param_end */
			{
#line 1210 "syntax.act"

    end_param () ;
    have_type_declaration = TYPE_DECL_NONE ;
    have_func_declarator = 1 ;
#line 3263 "syntax8.c"
			}
			/* END OF ACTION: param_end */
			ZR1141 (ZIt, &ZI1140);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1140 = ZI1140;
}

void
ZR1386(SID_LIST_TYPE *ZOq)
{
	SID_LIST_TYPE ZIq;

	switch (CURRENT_TERMINAL) {
	case 2: case 7: case 8: case 9:
	case 25: case 83: case 97: case 98:
	case 102: case 104: case 106: case 110:
	case 111: case 114: case 115: case 118:
	case 121: case 122: case 123: case 124:
	case 127: case 129: case 153: case 156:
	case 185: case 286: case 299:
		{
			ZRtype_Hid_Hlist (&ZIq);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: error_comma */
			{
#line 1987 "syntax.act"

    /* Extra comma at the end of a list */
    report ( crt_loc, ERR_lex_extra_comma () ) ;
#line 3315 "syntax8.c"
			}
			/* END OF ACTION: error_comma */
			/* BEGINNING OF ACTION: list_type_null */
			{
#line 1411 "syntax.act"

    (ZIq) = NULL_list ( TYPE ) ;
#line 3323 "syntax8.c"
			}
			/* END OF ACTION: list_type_null */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOq = ZIq;
}

void
ZR1259(void)
{
	switch (CURRENT_TERMINAL) {
	case 153:
		{
			NAMESPACE ZIns;
			IDENTIFIER ZIid;
			TYPE ZIt;

			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: declarator_start */
			{
#line 1706 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 3355 "syntax8.c"
			}
			/* END OF ACTION: declarator_start */
			ZRany_Hnested_Hname_Hopt (&ZIns);
			ZRany_Hclass_Hname (&ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_typename */
			{
#line 1302 "syntax.act"

    (ZIt) = make_typename ( (ZIns), (ZIid) ) ;
    if ( have_type_declaration == TYPE_DECL_NONE ) {
	have_type_declaration = TYPE_DECL_ELABORATE ;
	found_elaborate_type = 1 ;
    }
    have_type_specifier = 1 ;
#line 3374 "syntax8.c"
			}
			/* END OF ACTION: type_typename */
			/* BEGINNING OF ACTION: using_typename */
			{
#line 1816 "syntax.act"

    using_typename ( (ZIt) ) ;
#line 3382 "syntax8.c"
			}
			/* END OF ACTION: using_typename */
			ZRsemicolon_Hx ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 1: case 2: case 3: case 4:
	case 5: case 6: case 7: case 8:
	case 9: case 83: case 141:
		{
			IDENTIFIER ZIid;

			ZRdeclarator_Hid (&ZIid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: using_identifier */
			{
#line 1812 "syntax.act"

    IGNORE using_identifier ( (ZIid) ) ;
#line 3408 "syntax8.c"
			}
			/* END OF ACTION: using_identifier */
			ZRsemicolon_Hx ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZR1260(EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
		{
			IDENTIFIER ZInid;
			IDENTIFIER ZIid;

			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 219 "syntax.act"

    ZInid = crt_token->pp_data.id.use ;
#line 3450 "syntax8.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 227 "syntax.act"

    ZInid = crt_token->pp_data.id.use ;
#line 3463 "syntax8.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 231 "syntax.act"

    ZInid = crt_token->pp_data.id.use ;
#line 3476 "syntax8.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 223 "syntax.act"

    ZInid = crt_token->pp_data.id.use ;
#line 3489 "syntax8.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto ZL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: namespace_simple */
			{
#line 509 "syntax.act"

    (ZIid) = (ZInid) ;
    crt_id_qualifier = qual_none ;
    last_namespace = crt_namespace ;
#line 3507 "syntax8.c"
			}
			/* END OF ACTION: namespace_simple */
			/* BEGINNING OF ACTION: declarator_posn */
			{
#line 1717 "syntax.act"

    IDENTIFIER pid = underlying_id ( (ZIid) ) ;
    DEREF_loc ( id_loc ( pid ), decl_loc ) ;
#line 3516 "syntax8.c"
			}
			/* END OF ACTION: declarator_posn */
			ZR1435 (&ZIid, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 64:
		{
			DECL_SPEC ZIds;
			TYPE ZIt;

			/* BEGINNING OF ACTION: namespace_begin_anon */
			{
#line 1797 "syntax.act"

    decl_loc = crt_loc ;
    begin_namespace ( NULL_id, 1 ) ;
#line 3537 "syntax8.c"
			}
			/* END OF ACTION: namespace_begin_anon */
			/* BEGINNING OF ACTION: dspec_none */
			{
#line 1546 "syntax.act"
 (ZIds) = dspec_none ; 
#line 3544 "syntax8.c"
			}
			/* END OF ACTION: dspec_none */
			/* BEGINNING OF ACTION: type_none */
			{
#line 1278 "syntax.act"

    (ZIt) = NULL_type ;
#line 3552 "syntax8.c"
			}
			/* END OF ACTION: type_none */
			/* BEGINNING OF INLINE: open-brace */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 64:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: open-brace */
			ZRdeclaration_Hseq_Hopt (ZIt, ZIds);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: namespace_end_anon */
			{
#line 1801 "syntax.act"

    end_namespace ( 1 ) ;
#line 3578 "syntax8.c"
			}
			/* END OF ACTION: namespace_end_anon */
			/* BEGINNING OF INLINE: close-brace */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 38:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: close-brace */
			/* BEGINNING OF ACTION: rescan_token */
			{
#line 2149 "syntax.act"

    RESCAN_LEXER ;
#line 3599 "syntax8.c"
			}
			/* END OF ACTION: rescan_token */
			/* BEGINNING OF ACTION: exp_none */
			{
#line 581 "syntax.act"

    (ZIe) = NULL_exp ;
#line 3607 "syntax8.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRexclusive_Hor_Hexpression(EXP *ZO1205)
{
	EXP ZI1205;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIe;

		ZRand_Hexpression (&ZIe);
		ZR1206 (ZIe, &ZI1205);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1205 = ZI1205;
}

void
ZRcompound_Hstatement(EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIc;
		EXP ZIa;

		/* BEGINNING OF ACTION: stmt_compound_begin */
		{
#line 907 "syntax.act"

    (ZIc) = begin_compound_stmt ( 1 ) ;
#line 3668 "syntax8.c"
		}
		/* END OF ACTION: stmt_compound_begin */
		/* BEGINNING OF INLINE: open-brace */
		{
			{
				switch (CURRENT_TERMINAL) {
				case 64:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: open-brace */
		/* BEGINNING OF ACTION: stmt_compound_block */
		{
#line 911 "syntax.act"

    COPY_int ( exp_sequence_block ( (ZIc) ), 2 ) ;
#line 3689 "syntax8.c"
		}
		/* END OF ACTION: stmt_compound_block */
		ZRstatement_Hseq_Hopt (ZIc, &ZIa);
		/* BEGINNING OF INLINE: close-brace */
		{
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			{
				switch (CURRENT_TERMINAL) {
				case 38:
					break;
				default:
					goto ZL1;
				}
				ADVANCE_LEXER;
			}
		}
		/* END OF INLINE: close-brace */
		/* BEGINNING OF ACTION: stmt_compound_end */
		{
#line 923 "syntax.act"

    (ZIe) = end_compound_stmt ( (ZIa) ) ;
#line 3715 "syntax8.c"
		}
		/* END OF ACTION: stmt_compound_end */
		/* BEGINNING OF ACTION: rescan_token */
		{
#line 2149 "syntax.act"

    RESCAN_LEXER ;
#line 3723 "syntax8.c"
		}
		/* END OF ACTION: rescan_token */
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZR1261(EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 139:
		{
			NAMESPACE ZIpns;
			IDENTIFIER ZIpid;
			IDENTIFIER ZIid;
			NAMESPACE ZIns;

			ADVANCE_LEXER;
			ZRany_Hnested_Hname_Hopt (&ZIpns);
			ZRany_Hclass_Hname (&ZIpid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: namespace_id */
			{
#line 504 "syntax.act"

    (ZIid) = check_id ( (ZIpns), (ZIpid), 0 ) ;
    last_namespace = (ZIpns) ;
#line 3761 "syntax8.c"
			}
			/* END OF ACTION: namespace_id */
			/* BEGINNING OF ACTION: namespace_name */
			{
#line 1804 "syntax.act"

    (ZIns) = find_nspace_id ( (ZIid) ) ;
#line 3769 "syntax8.c"
			}
			/* END OF ACTION: namespace_name */
			/* BEGINNING OF ACTION: using_namespace */
			{
#line 1820 "syntax.act"

    using_namespace ( (ZIns) ) ;
#line 3777 "syntax8.c"
			}
			/* END OF ACTION: using_namespace */
			ZRsemicolon_Hx ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_none */
			{
#line 581 "syntax.act"

    (ZIe) = NULL_exp ;
#line 3790 "syntax8.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 1: case 2: case 3: case 4:
	case 5: case 6: case 7: case 8:
	case 9: case 83: case 141: case 153:
		{
			ZR1259 ();
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_none */
			{
#line 581 "syntax.act"

    (ZIe) = NULL_exp ;
#line 3809 "syntax8.c"
			}
			/* END OF ACTION: exp_none */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRsemicolon_Hx(void)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		switch (CURRENT_TERMINAL) {
		case 77:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
	}
	return;
ZL1:;
	{
		int ZIt;

		/* BEGINNING OF ACTION: lex_semicolon */
		{
#line 397 "syntax.act"
 (ZIt) = lex_semicolon ; 
#line 3851 "syntax8.c"
		}
		/* END OF ACTION: lex_semicolon */
		/* BEGINNING OF ACTION: expected */
		{
#line 1997 "syntax.act"

    /* Expected symbol */
    int p = primary_form ( crt_lex_token ) ;
    if ( p != (ZIt) ) report ( crt_loc, ERR_lex_expect ( (ZIt) ) ) ;
#line 3861 "syntax8.c"
		}
		/* END OF ACTION: expected */
	}
}

void
ZRlogical_Hor_Hexpression(EXP *ZO1193)
{
	EXP ZI1193;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIe;

		ZRlogical_Hand_Hexpression (&ZIe);
		ZR1194 (ZIe, &ZI1193);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1193 = ZI1193;
}

void
ZRconstant_Hexpression(EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIa;

		ZRconditional_Hexpression (&ZIa);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
		/* BEGINNING OF ACTION: exp_eval */
		{
#line 669 "syntax.act"

    (ZIe) = convert_reference ( (ZIa), REF_NORMAL ) ;
    (ZIe) = convert_lvalue ( (ZIe) ) ;
#line 3915 "syntax8.c"
		}
		/* END OF ACTION: exp_eval */
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRtemplate_Hparam_Hname(IDENTIFIER *ZOid)
{
	IDENTIFIER ZIid;

	switch (CURRENT_TERMINAL) {
	case 1: case 2: case 3: case 4:
		{
			IDENTIFIER ZItid;

			/* BEGINNING OF INLINE: any-identifier */
			{
				switch (CURRENT_TERMINAL) {
				case 1:
					{
						/* BEGINNING OF EXTRACT: identifier */
						{
#line 219 "syntax.act"

    ZItid = crt_token->pp_data.id.use ;
#line 3947 "syntax8.c"
						}
						/* END OF EXTRACT: identifier */
						ADVANCE_LEXER;
					}
					break;
				case 3:
					{
						/* BEGINNING OF EXTRACT: namespace-name */
						{
#line 227 "syntax.act"

    ZItid = crt_token->pp_data.id.use ;
#line 3960 "syntax8.c"
						}
						/* END OF EXTRACT: namespace-name */
						ADVANCE_LEXER;
					}
					break;
				case 4:
					{
						/* BEGINNING OF EXTRACT: statement-name */
						{
#line 231 "syntax.act"

    ZItid = crt_token->pp_data.id.use ;
#line 3973 "syntax8.c"
						}
						/* END OF EXTRACT: statement-name */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 223 "syntax.act"

    ZItid = crt_token->pp_data.id.use ;
#line 3986 "syntax8.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto ZL1;
				}
			}
			/* END OF INLINE: any-identifier */
			/* BEGINNING OF ACTION: namespace_simple */
			{
#line 509 "syntax.act"

    (ZIid) = (ZItid) ;
    crt_id_qualifier = qual_none ;
    last_namespace = crt_namespace ;
#line 4004 "syntax8.c"
			}
			/* END OF ACTION: namespace_simple */
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: id_anon */
			{
#line 468 "syntax.act"

    HASHID nm = lookup_anon () ;
    (ZIid) = DEREF_id ( hashid_id ( nm ) ) ;
    crt_id_qualifier = qual_none ;
    qual_namespace = NULL_nspace ;
#line 4019 "syntax8.c"
			}
			/* END OF ACTION: id_anon */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOid = ZIid;
}

void
ZR500(SID_LIST_EXP *ZOq)
{
	SID_LIST_EXP ZIq;

	switch (CURRENT_TERMINAL) {
	case 42:
		{
			ADVANCE_LEXER;
			ZRexpression_Hlist (&ZIq);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	default:
		{
			/* BEGINNING OF ACTION: list_exp_null */
			{
#line 562 "syntax.act"

    (ZIq) = NULL_list ( EXP ) ;
#line 4058 "syntax8.c"
			}
			/* END OF ACTION: list_exp_null */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOq = ZIq;
}

void
ZRptr_Hoperator(TYPE *ZOp)
{
	TYPE ZIp;

	switch (CURRENT_TERMINAL) {
	case 11:
		{
			IDENTIFIER ZIid;
			CV_SPEC ZIcv;

			/* BEGINNING OF EXTRACT: full-name-star */
			{
#line 285 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 4090 "syntax8.c"
			}
			/* END OF EXTRACT: full-name-star */
			ADVANCE_LEXER;
			ZRcv_Hqualifier_Hseq_Hopt (&ZIcv);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_ptr_mem */
			{
#line 1357 "syntax.act"

    CLASS_TYPE ct = find_class ( (ZIid) ) ;
    if ( IS_NULL_ctype ( ct ) ) {
	report ( crt_loc, ERR_dcl_mptr_type ( (ZIid) ) ) ;
	MAKE_type_ptr ( (ZIcv), NULL_type, (ZIp) ) ;
    } else {
	MAKE_type_ptr_mem ( (ZIcv), ct, NULL_type, (ZIp) ) ;
    }
#line 4110 "syntax8.c"
			}
			/* END OF ACTION: type_ptr_mem */
		}
		break;
	case 10:
		{
			IDENTIFIER ZIid;
			CV_SPEC ZIcv;

			/* BEGINNING OF EXTRACT: nested-name-star */
			{
#line 281 "syntax.act"

    ZIid = crt_token->pp_data.id.use ;
#line 4125 "syntax8.c"
			}
			/* END OF EXTRACT: nested-name-star */
			ADVANCE_LEXER;
			ZRcv_Hqualifier_Hseq_Hopt (&ZIcv);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_ptr_mem */
			{
#line 1357 "syntax.act"

    CLASS_TYPE ct = find_class ( (ZIid) ) ;
    if ( IS_NULL_ctype ( ct ) ) {
	report ( crt_loc, ERR_dcl_mptr_type ( (ZIid) ) ) ;
	MAKE_type_ptr ( (ZIcv), NULL_type, (ZIp) ) ;
    } else {
	MAKE_type_ptr_mem ( (ZIcv), ct, NULL_type, (ZIp) ) ;
    }
#line 4145 "syntax8.c"
			}
			/* END OF ACTION: type_ptr_mem */
		}
		break;
	case 78:
		{
			CV_SPEC ZIcv;

			ADVANCE_LEXER;
			ZRcv_Hqualifier_Hseq_Hopt (&ZIcv);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_ptr */
			{
#line 1347 "syntax.act"

    MAKE_type_ptr ( (ZIcv), NULL_type, (ZIp) ) ;
#line 4165 "syntax8.c"
			}
			/* END OF ACTION: type_ptr */
		}
		break;
	case 33:
		{
			CV_SPEC ZIcv;

			/* BEGINNING OF INLINE: and */
			{
				{
					switch (CURRENT_TERMINAL) {
					case 33:
						break;
					default:
						goto ZL1;
					}
					ADVANCE_LEXER;
				}
			}
			/* END OF INLINE: and */
			ZRcv_Hqualifier_Hseq_Hopt (&ZIcv);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: type_ref */
			{
#line 1352 "syntax.act"

    /* Can't have const-volatile qualified references */
    if ( (ZIcv) ) report ( crt_loc, ERR_dcl_ref_cv ( (ZIcv) ) ) ;
    MAKE_type_ref ( cv_none, NULL_type, (ZIp) ) ;
#line 4199 "syntax8.c"
			}
			/* END OF ACTION: type_ref */
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOp = ZIp;
}

void
ZR1264(EXP *ZI1262, EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 72:
		{
			EXP ZIa;
			EXP ZIb;

			ADVANCE_LEXER;
			ZRexpression (&ZIa);
			switch (CURRENT_TERMINAL) {
			case 41:
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZRassignment_Hexpression (&ZIb);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_cond */
			{
#line 625 "syntax.act"

    (ZIe) = make_cond_exp ( (*ZI1262), (ZIa), (ZIb) ) ;
#line 4250 "syntax8.c"
			}
			/* END OF ACTION: exp_cond */
		}
		break;
	default:
		{
			ZIe = *ZI1262;
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRbase_Hspecifier_Hlist(void)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
ZL2_base_Hspecifier_Hlist:;
	{
		ZRbase_Hspecifier ();
		/* BEGINNING OF INLINE: 848 */
		{
			switch (CURRENT_TERMINAL) {
			case 42:
				{
					ADVANCE_LEXER;
					/* BEGINNING OF INLINE: base-specifier-list */
					goto ZL2_base_Hspecifier_Hlist;
					/* END OF INLINE: base-specifier-list */
				}
				/*UNREACHED*/
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				break;
			}
		}
		/* END OF INLINE: 848 */
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZRlinkage_Hspecification(TYPE ZIt, DECL_SPEC ZIds, EXP *ZOe)
{
	EXP ZIe;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIc;
		DECL_SPEC ZIa;
		DECL_SPEC ZIb;
		DECL_SPEC ZIds0;
		DECL_SPEC ZIds1;
		EXP ZIe1;

		switch (CURRENT_TERMINAL) {
		case 105:
			break;
		default:
			goto ZL1;
		}
		ADVANCE_LEXER;
		/* BEGINNING OF INLINE: string-literal */
		{
			switch (CURRENT_TERMINAL) {
			case 19:
				{
					/* BEGINNING OF EXTRACT: string-exp */
					{
#line 323 "syntax.act"

    ZIc = crt_token->pp_data.exp ;
#line 4339 "syntax8.c"
					}
					/* END OF EXTRACT: string-exp */
					ADVANCE_LEXER;
				}
				break;
			case 20:
				{
					/* BEGINNING OF EXTRACT: wstring-exp */
					{
#line 327 "syntax.act"

    ZIc = crt_token->pp_data.exp ;
#line 4352 "syntax8.c"
					}
					/* END OF EXTRACT: wstring-exp */
					ADVANCE_LEXER;
				}
				break;
			default:
				goto ZL1;
			}
		}
		/* END OF INLINE: string-literal */
		/* BEGINNING OF ACTION: linkage_string */
		{
#line 1588 "syntax.act"

    (ZIa) = find_linkage ( (ZIc) ) ;
#line 4368 "syntax8.c"
		}
		/* END OF ACTION: linkage_string */
		/* BEGINNING OF ACTION: linkage_begin */
		{
#line 1592 "syntax.act"

    (ZIb) = crt_linkage ;
    crt_linkage = (ZIa) ;
    IGNORE incr_value ( OPT_VAL_external_specs ) ;
#line 4378 "syntax8.c"
		}
		/* END OF ACTION: linkage_begin */
		/* BEGINNING OF ACTION: dspec_linkage */
		{
#line 1558 "syntax.act"
 (ZIds0) = ( dspec_extern | dspec_c ) ; 
#line 4385 "syntax8.c"
		}
		/* END OF ACTION: dspec_linkage */
		/* BEGINNING OF ACTION: dspec_join */
		{
#line 1562 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (ZIds) & (ZIds0) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds1) = ( (ZIds) | (ZIds0) ) ;
#line 4396 "syntax8.c"
		}
		/* END OF ACTION: dspec_join */
		/* BEGINNING OF INLINE: 1066 */
		{
			{
				BASE_TYPE ZI1250;
				TYPE ZI1251;
				CV_SPEC ZI1252;
				DECL_SPEC ZI1253;
				BASE_TYPE ZIbt;
				TYPE ZIt1;
				CV_SPEC ZIcv1;
				DECL_SPEC ZI1606;
				DECL_SPEC ZIds2;

				/* BEGINNING OF ACTION: is_decl_specifier */
				{
#line 2079 "syntax.act"

    /* Resolve declaration-specifiers from other declarators */
    (ZI0) = predict_dspec ( 0 ) ;
#line 4418 "syntax8.c"
				}
				/* END OF ACTION: is_decl_specifier */
				if (!ZI0)
					goto ZL4;
				ZRdecl_Hspecifier (ZIt, &ZI1250, &ZI1251, &ZI1252, &ZI1253);
				ZR919 (&ZIt, &ZI1250, &ZI1251, &ZI1252, &ZI1253, &ZIbt, &ZIt1, &ZIcv1, &ZI1606);
				if ((CURRENT_TERMINAL) == 355) {
					RESTORE_LEXER;
					goto ZL1;
				}
				/* BEGINNING OF ACTION: dspec_join */
				{
#line 1562 "syntax.act"

    /* Combine two declaration specifiers */
    DECL_SPEC d = ( ( (ZIds1) & (ZI1606) ) & dspec_duplicate ) ;
    if ( d ) report ( crt_loc, ERR_dcl_spec_dup ( d ) ) ;
    (ZIds2) = ( (ZIds1) | (ZI1606) ) ;
#line 4437 "syntax8.c"
				}
				/* END OF ACTION: dspec_join */
				ZR1254 (&ZIt, &ZIbt, &ZIt1, &ZIcv1, &ZIds2);
				if ((CURRENT_TERMINAL) == 355) {
					RESTORE_LEXER;
					goto ZL1;
				}
				/* BEGINNING OF ACTION: exp_none */
				{
#line 581 "syntax.act"

    (ZIe1) = NULL_exp ;
#line 4450 "syntax8.c"
				}
				/* END OF ACTION: exp_none */
				/* BEGINNING OF ACTION: linkage_end */
				{
#line 1599 "syntax.act"

    decr_value ( OPT_VAL_external_specs ) ;
    crt_linkage = (ZIb) ;
#line 4459 "syntax8.c"
				}
				/* END OF ACTION: linkage_end */
				goto ZL3;
			}
			/*UNREACHED*/
		ZL4:;
			switch (CURRENT_TERMINAL) {
			case 105:
				{
					ZRlinkage_Hspecification (ZIt, ZIds1, &ZIe1);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
					/* BEGINNING OF ACTION: linkage_end */
					{
#line 1599 "syntax.act"

    decr_value ( OPT_VAL_external_specs ) ;
    crt_linkage = (ZIb) ;
#line 4480 "syntax8.c"
					}
					/* END OF ACTION: linkage_end */
				}
				break;
			case 64:
				{
					TYPE ZIt2;
					DECL_SPEC ZIds2;

					/* BEGINNING OF INLINE: open-brace */
					{
						{
							switch (CURRENT_TERMINAL) {
							case 64:
								break;
							default:
								goto ZL1;
							}
							ADVANCE_LEXER;
						}
					}
					/* END OF INLINE: open-brace */
					/* BEGINNING OF ACTION: template_check */
					{
#line 1861 "syntax.act"

    if ( !IS_NULL_type ( (ZIt) ) ) report ( crt_loc, ERR_temp_decl_bad () ) ;
    UNUSED ( (ZIds1) ) ;
#line 4509 "syntax8.c"
					}
					/* END OF ACTION: template_check */
					/* BEGINNING OF ACTION: type_none */
					{
#line 1278 "syntax.act"

    (ZIt2) = NULL_type ;
#line 4517 "syntax8.c"
					}
					/* END OF ACTION: type_none */
					/* BEGINNING OF ACTION: dspec_none */
					{
#line 1546 "syntax.act"
 (ZIds2) = dspec_none ; 
#line 4524 "syntax8.c"
					}
					/* END OF ACTION: dspec_none */
					ZRdeclaration_Hseq_Hopt (ZIt2, ZIds2);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
					/* BEGINNING OF ACTION: linkage_end */
					{
#line 1599 "syntax.act"

    decr_value ( OPT_VAL_external_specs ) ;
    crt_linkage = (ZIb) ;
#line 4538 "syntax8.c"
					}
					/* END OF ACTION: linkage_end */
					/* BEGINNING OF INLINE: close-brace */
					{
						{
							switch (CURRENT_TERMINAL) {
							case 38:
								break;
							default:
								goto ZL1;
							}
							ADVANCE_LEXER;
						}
					}
					/* END OF INLINE: close-brace */
					/* BEGINNING OF ACTION: exp_none */
					{
#line 581 "syntax.act"

    (ZIe1) = NULL_exp ;
#line 4559 "syntax8.c"
					}
					/* END OF ACTION: exp_none */
				}
				break;
			case 134: case 147:
				{
					ZRtemplate_Hdeclaration (ZIt, ZIds1, &ZIe1);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
					/* BEGINNING OF ACTION: linkage_end */
					{
#line 1599 "syntax.act"

    decr_value ( OPT_VAL_external_specs ) ;
    crt_linkage = (ZIb) ;
#line 4577 "syntax8.c"
					}
					/* END OF ACTION: linkage_end */
				}
				break;
			case 1: case 2: case 3: case 4:
			case 5: case 6: case 7: case 8:
			case 9: case 10: case 11: case 33:
			case 65: case 77: case 78: case 83:
			case 141:
				{
					BASE_TYPE ZIbt;
					TYPE ZIt1;
					CV_SPEC ZI1255;

					/* BEGINNING OF ACTION: btype_none */
					{
#line 1254 "syntax.act"
 (ZIbt) = btype_none ; 
#line 4596 "syntax8.c"
					}
					/* END OF ACTION: btype_none */
					/* BEGINNING OF ACTION: type_none */
					{
#line 1278 "syntax.act"

    (ZIt1) = NULL_type ;
#line 4604 "syntax8.c"
					}
					/* END OF ACTION: type_none */
					/* BEGINNING OF ACTION: cv_none */
					{
#line 1222 "syntax.act"
 (ZI1255) = cv_none ; 
#line 4611 "syntax8.c"
					}
					/* END OF ACTION: cv_none */
					ZR1256 (&ZIt, &ZIds1, &ZIbt, &ZIt1, &ZI1255, &ZIe1);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
					/* BEGINNING OF ACTION: linkage_end */
					{
#line 1599 "syntax.act"

    decr_value ( OPT_VAL_external_specs ) ;
    crt_linkage = (ZIb) ;
#line 4625 "syntax8.c"
					}
					/* END OF ACTION: linkage_end */
				}
				break;
			case 126: case 139: case 154:
				{
					/* BEGINNING OF ACTION: template_check */
					{
#line 1861 "syntax.act"

    if ( !IS_NULL_type ( (ZIt) ) ) report ( crt_loc, ERR_temp_decl_bad () ) ;
    UNUSED ( (ZIds1) ) ;
#line 4638 "syntax8.c"
					}
					/* END OF ACTION: template_check */
					ZRdeclaration_Hother (&ZIe1);
					if ((CURRENT_TERMINAL) == 355) {
						RESTORE_LEXER;
						goto ZL1;
					}
					/* BEGINNING OF ACTION: linkage_end */
					{
#line 1599 "syntax.act"

    decr_value ( OPT_VAL_external_specs ) ;
    crt_linkage = (ZIb) ;
#line 4652 "syntax8.c"
					}
					/* END OF ACTION: linkage_end */
				}
				break;
			default:
				goto ZL1;
			}
		ZL3:;
		}
		/* END OF INLINE: 1066 */
		ZIe = ZIe1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZRequality_Hexpression(EXP *ZO1217)
{
	EXP ZI1217;

	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
	{
		EXP ZIe;

		ZRrelational_Hexpression (&ZIe);
		ZR1218 (ZIe, &ZI1217);
		if ((CURRENT_TERMINAL) == 355) {
			RESTORE_LEXER;
			goto ZL1;
		}
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1217 = ZI1217;
}

void
ZRinit_Hdeclarator_Hlist(DECL_SPEC ZIds, BASE_TYPE ZIbt, TYPE ZIt, ACCESS_LIST ZIr)
{
	if ((CURRENT_TERMINAL) == 355) {
		return;
	}
ZL2_init_Hdeclarator_Hlist:;
	{
		ZRinit_Hdeclarator (ZIds, ZIbt, ZIt, ZIr);
		/* BEGINNING OF INLINE: 1012 */
		{
			switch (CURRENT_TERMINAL) {
			case 42:
				{
					ADVANCE_LEXER;
					/* BEGINNING OF ACTION: declarator_start */
					{
#line 1706 "syntax.act"

    crt_templ_qualifier = 0 ;
#line 4719 "syntax8.c"
					}
					/* END OF ACTION: declarator_start */
					/* BEGINNING OF INLINE: init-declarator-list */
					goto ZL2_init_Hdeclarator_Hlist;
					/* END OF INLINE: init-declarator-list */
				}
				/*UNREACHED*/
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				break;
			}
		}
		/* END OF INLINE: 1012 */
	}
	return;
ZL1:;
	SAVE_LEXER (355);
	return;
}

void
ZR1266(EXP *ZI1265, EXP *ZOe)
{
	EXP ZIe;

	switch (CURRENT_TERMINAL) {
	case 36:
		{
			EXP ZIb;

			ADVANCE_LEXER;
			ZRassignment_Hexpression (&ZIb);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_assign */
			{
#line 607 "syntax.act"

    (ZIe) = make_assign_exp ( (*ZI1265), (ZIb), 0 ) ;
#line 4763 "syntax8.c"
			}
			/* END OF ACTION: exp_assign */
		}
		break;
	default:
		{
			ZR1264 (ZI1265, &ZIe);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 34: case 45: case 58: case 60:
	case 68: case 70: case 74: case 76:
	case 79: case 81:
		{
			int ZIop;
			EXP ZIb;

			/* BEGINNING OF ACTION: lex_crt */
			{
#line 391 "syntax.act"
 (ZIop) = crt_lex_token ; 
#line 4788 "syntax8.c"
			}
			/* END OF ACTION: lex_crt */
			ZRassignment_Hoperator ();
			ZRassignment_Hexpression (&ZIb);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: exp_assign_op */
			{
#line 612 "syntax.act"

    /* op will be in its primary form */
    (ZIe) = make_become_exp ( (ZIop), (*ZI1265), (ZIb) ) ;
#line 4803 "syntax8.c"
			}
			/* END OF ACTION: exp_assign_op */
		}
		break;
	case 355:
		return;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZOe = ZIe;
}

void
ZR1268(NAMESPACE *ZIns, EXP *ZO1241)
{
	EXP ZI1241;

	switch (CURRENT_TERMINAL) {
	case 2: case 7:
		{
			IDENTIFIER ZItid;
			IDENTIFIER ZIid;
			TYPE ZI1267;
			BASE_TYPE ZIbt;
			CV_SPEC ZIcv;
			TYPE ZIt;
			SID_LIST_EXP ZIp;
			EXP ZIe;

			/* BEGINNING OF INLINE: any-type-name */
			{
				switch (CURRENT_TERMINAL) {
				case 7:
					{
						/* BEGINNING OF EXTRACT: template-type */
						{
#line 249 "syntax.act"

    IDENTIFIER id = crt_token->pp_data.tok.id ;
    PPTOKEN *args = crt_token->pp_data.tok.args ;
    ZItid = parse_type_template ( id, args, 0 ) ;
    crt_templ_qualifier = 1 ;
    RESCAN_LEXER ;
#line 4850 "syntax8.c"
						}
						/* END OF EXTRACT: template-type */
						ADVANCE_LEXER;
					}
					break;
				case 2:
					{
						/* BEGINNING OF EXTRACT: type-name */
						{
#line 223 "syntax.act"

    ZItid = crt_token->pp_data.id.use ;
#line 4863 "syntax8.c"
						}
						/* END OF EXTRACT: type-name */
						ADVANCE_LEXER;
					}
					break;
				default:
					goto ZL1;
				}
			}
			/* END OF INLINE: any-type-name */
			/* BEGINNING OF ACTION: namespace_nested */
			{
#line 495 "syntax.act"

    crt_id_qualifier = qual_nested ;
    qual_namespace = (*ZIns) ;
#line 4880 "syntax8.c"
			}
			/* END OF ACTION: namespace_nested */
			/* BEGINNING OF ACTION: namespace_id */
			{
#line 504 "syntax.act"

    (ZIid) = check_id ( (*ZIns), (ZItid), 0 ) ;
    last_namespace = (*ZIns) ;
#line 4889 "syntax8.c"
			}
			/* END OF ACTION: namespace_id */
			/* BEGINNING OF ACTION: type_name */
			{
#line 1287 "syntax.act"

    MAKE_type_pre ( cv_none, btype_alias, crt_id_qualifier, (ZI1267) ) ;
    COPY_id ( type_name ( (ZI1267) ), (ZIid) ) ;
    have_type_specifier = 1 ;
#line 4899 "syntax8.c"
			}
			/* END OF ACTION: type_name */
			/* BEGINNING OF ACTION: btype_none */
			{
#line 1254 "syntax.act"
 (ZIbt) = btype_none ; 
#line 4906 "syntax8.c"
			}
			/* END OF ACTION: btype_none */
			/* BEGINNING OF ACTION: cv_none */
			{
#line 1222 "syntax.act"
 (ZIcv) = cv_none ; 
#line 4913 "syntax8.c"
			}
			/* END OF ACTION: cv_none */
			/* BEGINNING OF ACTION: type_complete */
			{
#line 1323 "syntax.act"

    (ZIt) = complete_pre_type ( (ZIbt), (ZI1267), (ZIcv), 1 ) ;
    have_type_specifier = 0 ;
#line 4922 "syntax8.c"
			}
			/* END OF ACTION: type_complete */
			switch (CURRENT_TERMINAL) {
			case 65:
				break;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			ZRexpression_Hlist_Hopt (&ZIp);
			switch (CURRENT_TERMINAL) {
			case 39:
				break;
			case 355:
				RESTORE_LEXER;
				goto ZL1;
			default:
				goto ZL1;
			}
			ADVANCE_LEXER;
			/* BEGINNING OF ACTION: exp_func_cast */
			{
#line 682 "syntax.act"

    (ZIe) = make_func_cast_exp ( (ZIt), (ZIp) ) ;
#line 4948 "syntax8.c"
			}
			/* END OF ACTION: exp_func_cast */
			ZR1242 (ZIe, &ZI1241);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 1: case 3: case 5: case 6:
	case 141: case 147:
		{
			int ZIq;
			IDENTIFIER ZIuid;
			IDENTIFIER ZIid;
			EXP ZIe;

			ZRtemplate_Hopt (*ZIns, &ZIq);
			ZRnested_Hid (*ZIns, &ZIuid);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
			/* BEGINNING OF ACTION: namespace_nested */
			{
#line 495 "syntax.act"

    crt_id_qualifier = qual_nested ;
    qual_namespace = (*ZIns) ;
#line 4978 "syntax8.c"
			}
			/* END OF ACTION: namespace_nested */
			/* BEGINNING OF ACTION: namespace_templ */
			{
#line 521 "syntax.act"

    (ZIid) = check_id ( (*ZIns), (ZIuid), (ZIq) ) ;
    last_namespace = (*ZIns) ;
#line 4987 "syntax8.c"
			}
			/* END OF ACTION: namespace_templ */
			/* BEGINNING OF ACTION: exp_identifier */
			{
#line 686 "syntax.act"

    (ZIe) = make_id_exp ( (ZIid) ) ;
#line 4995 "syntax8.c"
			}
			/* END OF ACTION: exp_identifier */
			ZR1242 (ZIe, &ZI1241);
			if ((CURRENT_TERMINAL) == 355) {
				RESTORE_LEXER;
				goto ZL1;
			}
		}
		break;
	case 355:
		return;
	default:
		goto ZL1;
	}
	goto ZL0;
ZL1:;
	SAVE_LEXER (355);
	return;
ZL0:;
	*ZO1241 = ZI1241;
}

/* END OF FILE */
