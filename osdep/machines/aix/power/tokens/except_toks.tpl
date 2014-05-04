/* $Id$ */

/*
 * Copyright 2011, The TenDRA Project.
 * Copyright 1997, United Kingdom Secretary of State for Defence.
 *
 * See doc/copyright/ for the full copyright terms.
 */

/* Spec Token Definitions for the PowerPC/RS6000 ANDF translator */

Tokdec c89.stdlib.abort : [] EXP;

/* ~Throw will be provided by producer */
Tokdec ~Throw : [NAT] EXP;

Common __TDFstacklim : pointer (locals_alignment) 
                     = make_null_ptr (locals_alignment);

Common __TDFhandler : proc;

/* Set_signal_handler Must be called before any possible exceptions */
Tokdef ~Set_signal_handler = [] EXP
Let handler = Proc bottom (err : Int)
{	
?{
	? ( * err == + error_val(overflow)(Int) );
		~Throw[error_val(overflow)];
		c89.stdlib.abort
	|  ? { ? ( * err == + error_val(stack_overflow)(Int) );
			~Throw[error_val(stack_overflow)];
			c89.stdlib.abort
		|
			~Throw[error_val(nil_access)];
			c89.stdlib.abort
		} 
	}
}
{
    __TDFhandler = handler;
    env_size(handler)
};      

Tokdef ~Sync_handler = [] EXP make_top;

Keep(~Set_signal_handler ,__TDFhandler,~Sync_handler,__TDFstacklim)
