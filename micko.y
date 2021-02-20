%{
  #include <stdio.h>
  #include <stdlib.h>
  #include "defs.h"
  #include "symtab.h"
  #include "codegen.h"

  int yyparse(void);
  int yylex(void);
  int yyerror(char *s);
  void warning(char *s);

  extern int yylineno;
  int out_lin = 0;
  char char_buffer[CHAR_BUFFER_LENGTH];
  int error_count = 0;
  int warning_count = 0;
  int var_num = 0;
  int fun_idx = -1;
  int fcall_idx = -1;
  int var_type = NO_TYPE; // cuva tip kod vise istih varijabli
  int ret_val = 0; // da li postoji return u funkciji
  int pars = 0; // broj parametara u funkciji
  int args = 0; // broj argumenata u pozivu
  unsigned lvl = 1;
  int last_idx;
  int lab_num = -1;
  FILE *output;
  int reg;
%}

%union {
  int i;
  char *s;
}

%token <i> _TYPE
%token _IF
%token _ELSE
%token _RETURN
%token <s> _ID
%token <s> _INT_NUMBER
%token <s> _UINT_NUMBER
%token _LPAREN
%token _RPAREN
%token _LBRACKET
%token _RBRACKET
%token _ASSIGN
%token _SEMICOLON
%token <i> _AROP
%token <i> _RELOP
%token _COMMA 
%token _INCR 
%token _DECR
%token _BRANCH
%token _FIRST
%token _SECOND 
%token _THIRD 
%token _OTHERW 
%token _ARROW 
%token _FOR 
%token _COLON 
%token _QMARK

%type <i> num_exp exp literal function_call arguments rel_exp if_part

%nonassoc ONLY_IF
%nonassoc _ELSE

%%

program
  : global_list function_list
      {  
        if(lookup_symbol("main", FUN) == NO_INDEX)
          err("undefined reference to 'main'");
       }
  ;
global_list
  : /*empty*/
  | global_list global_var
;

global_var
  : _TYPE _ID _SEMICOLON
  { 
	
     if( lookup_symbol($2, GVAR) == NO_INDEX)
	insert_symbol($2, GVAR, $1, NO_ATR, NO_ATR);
     else 
           err("redefinition of '%s'", $2);

    code("\n%s:\n\t\tWORD\t1", $2);	
}
  ;
function_list
  : function
  | function_list function
  ;

function
  : _TYPE _ID
      {
        fun_idx = lookup_symbol($2, FUN);
        if(fun_idx == NO_INDEX)
          fun_idx = insert_symbol($2, FUN, $1, NO_ATR, NO_ATR);
        else 
          err("redefinition of function '%s'", $2);

 	code("\n%s:", $2);
        code("\n\t\tPUSH\t%%14");
        code("\n\t\tMOV \t%%15,%%14");
      }
    _LPAREN parameters _RPAREN body
      {
        clear_symbols(fun_idx + pars + 1);
        var_num = 0;
	pars = 0;

 	code("\n@%s_exit:", $2);
        code("\n\t\tMOV \t%%14,%%15");
        code("\n\t\tPOP \t%%14");
        code("\n\t\tRET");
      }
  ;

parameters
  : /* empty */
	{ set_atr1(fun_idx, pars); } // prvi atribut funkcije cuva broj parametara
  | parameter
	{ set_atr1(fun_idx, pars); }
  ;

parameter
  : _TYPE _ID
      {
	if($1 == VOID) err("parameter type can not be void"); 

	if(lookup_symbol($2, PAR|VAR) == NO_INDEX || lookup_symbol($2, PAR|VAR) < fun_idx){
           insert_symbol($2, PAR, $1, ++pars, fun_idx); // drugi atribut parametra cuva kojoj funkciji pripada
    	}
	else
	 err("redefinition of function '%s'", $2);
      }
  | parameter _COMMA _TYPE _ID
    {
	if($3 == VOID) err("parameter type can not be void");
 
	if(lookup_symbol($4, PAR|VAR) == NO_INDEX || lookup_symbol($4, PAR|VAR) < fun_idx){
          insert_symbol($4, PAR, $3, ++pars, fun_idx);
	}
	else
	 err("redefinition of function '%s'", $4);
	}
  ;


body
  : _LBRACKET variable_list 
  { 
	if(var_num)
        code("\n\t\tSUBS\t%%15,$%d,%%15", 4*var_num);
        code("\n@%s_body:", get_name(fun_idx));
  }
  statement_list _RBRACKET
  {
	if (ret_val == 0 && get_type(fun_idx) != VOID)
	  warn("non void function must have a return");
  }
  ;

variable_list
  : /* empty */
  | variable_list variable
  ;

variable
  : _TYPE { if($1 == VOID) err("variable type can not be void"); var_type = $1; } vars _SEMICOLON 
  ;

vars 
  : _ID
   {
	int idx = lookup_symbol($1, VAR|PAR);
        if( idx == NO_INDEX || idx < fun_idx || get_atr2(idx) != lvl)
           insert_symbol($1, VAR, var_type, ++var_num, lvl);
        else 
           err("redefinition of '%s'", $1);
      }
  | vars _COMMA _ID
   {
       int idx = lookup_symbol($3, VAR|PAR);
        if( idx == NO_INDEX || idx < fun_idx || get_atr2(idx) != lvl)
           insert_symbol($3, VAR, var_type, ++var_num, lvl);
        else 
           err("redefinition of '%s'", $3);
      }
  | _ID _ASSIGN num_exp
  {
	int idx = lookup_symbol($1, VAR|PAR);
	int reg;
        if( idx == NO_INDEX || idx < fun_idx || get_atr2(idx) != lvl)
           reg = insert_symbol($1, VAR, var_type, ++var_num, lvl);
        else 
           err("redefinition of '%s'", $1);

	gen_mov($3, reg);
  }
  ;

statement_list
  : /* empty */
  | statement_list statement
  ;

statement
  : compound_statement
  | assignment_statement
  | if_statement
  | return_statement
  | incr_statement 
  | decr_statement
  | branch_statement 
  | for_statement 
  | voidf_call 
  ;


for_statement
  : _FOR _LPAREN _ID 
  {
	int index = lookup_symbol($3, VAR|PAR|GVAR);
	if( index == NO_INDEX)
	  err("variable %s not defined", $3);
	if(get_kind(index) == PAR){
		if(index < fun_idx)
		  err("not defined for this f");
	}
 	$<i>$ = ++lab_num;
        code("\n@for%d:", $<i>$);
   
  }
  _ASSIGN literal 
  {
	int index = lookup_symbol($3, VAR|PAR|GVAR);
	if(get_type(index) != get_type($6))
	  err("incompatible types in assignment");

	gen_mov($6, index);
  }
  _COLON literal
  {
	int index = lookup_symbol($3, VAR|PAR|GVAR);
 	if(get_type(index) != get_type($9))
	  err("incompatible types in assignment");
	if(atoi(get_name($6)) > atoi(get_name($9)))
	  err("first literal must be smaller");

	code("\n@check%d:", $<i>4);
	gen_cmp(index, $9);
	if(get_type($9) == UINT)
	  code("\n\t\tJLTU\t@true%d", $<i>4);
	else
	  code("\n\t\tJLTS\t@true%d", $<i>4);

 	code("\n@false%d:", $<i>4);
	code("\n\t\tJMP\t@exit%d", $<i>4);
 	code("\n@true%d:", $<i>4);

  }
   _RPAREN statement
  {
	int index = lookup_symbol($3, VAR|PAR|GVAR);
	if(get_type($9) == UINT)
	  code("\n\t\tADDU\t");
	else
	  code("\n\t\tADDS\t");
	  gen_sym_name(index);
          code(", $1, ");
          gen_sym_name(index);

	code("\n\t\tJMP\t@check%d", $<i>4);
 	code("\n@exit%d:", $<i>4);
  }
  ;

branch_statement
  : _BRANCH _LPAREN _ID
  {
	int index = lookup_symbol($3, VAR|PAR|GVAR); 
	if(index == -1)
	  err("variable %s not defined", $3);
	if(get_kind(index) == PAR){
		if(index < fun_idx)
		  err("not defined for this f");
	}

	$<i>$ = ++lab_num;
        code("\n@branch%d:", $<i>$);
  }
   _SEMICOLON literal
  {
	int index = lookup_symbol($3, VAR|PAR|GVAR); 
	if(get_type(index) != get_type($6))
            err("incompatible types in assignment");

	gen_cmp(index, $6);
	code("\n\t\tJEQ\t@first%d", $<i>4);
  }
   _COMMA literal
  {
	int index = lookup_symbol($3, VAR|PAR|GVAR); 
	if(get_type(index) != get_type($9))
            err("incompatible types in assignment");

	gen_cmp(index, $9);
	code("\n\t\tJEQ\t@second%d", $<i>4);
  }
   _COMMA literal
  {
	int index = lookup_symbol($3, VAR|PAR|GVAR); 
	if(get_type(index) != get_type($12))
            err("incompatible types in assignment");

	gen_cmp(index, $12);
	code("\n\t\tJEQ\t@third%d", $<i>4);
	code("\n\t\tJMP\t@otherwise%d", $<i>4);
  }
   _RPAREN _FIRST _ARROW
  {
        code("\n@first%d:", $<i>4);
  }
  statement
  { code("\n\t\tJMP\t@exit%d", $<i>4);}
  _SECOND _ARROW
  {
        code("\n@second%d:", $<i>4);
  }
  statement
  { code("\n\t\tJMP\t@exit%d", $<i>4); }
 _THIRD _ARROW
  {
        code("\n@third%d:", $<i>4);
  }
  statement
  { code("\n\t\tJMP\t@exit%d", $<i>4); }
  _OTHERW _ARROW
  {
        code("\n@otherwise%d:", $<i>4);
  }
 statement
  {
	code("\n@exit%d:", $<i>4);
  }
  ;

incr_statement
  : _ID _INCR _SEMICOLON
    {
	if(lookup_symbol($1, FUN) != -1)
	  err("function cannot be incremented");

	int idx = lookup_symbol($1, VAR|PAR|GVAR); 
	if(idx == NO_INDEX || idx < fun_idx)
	  {
	  idx = lookup_symbol($1, GVAR); 
	  if(idx == NO_INDEX)	
	    err("variable %s not defined", $1);
         }

	if(get_type(idx) == INT)
	  code("\n\t\tADDS\t");
	else
	  code("\n\t\tADDU\t");
	gen_sym_name(idx);
 	code(", $1, ");
        gen_sym_name(idx);
    }
  ;

decr_statement
  : _ID _DECR _SEMICOLON
    {
	if(lookup_symbol($1, FUN) != -1)
	  err("function cannot be decremented");

	int idx = lookup_symbol($1, VAR|PAR|GVAR); 
	if(idx == NO_INDEX || idx < fun_idx)
	  {
	  idx = lookup_symbol($1, GVAR); 
	  if(idx == NO_INDEX)	
	    err("variable %s not defined", $1);
         }

	if(get_type(idx) == INT)
	  code("\n\t\tSUBS\t");
	else
	  code("\n\t\tSUBU\t");
	gen_sym_name(idx);
 	code(", $1, ");
        gen_sym_name(idx);
    }
  ;


compound_statement
  : _LBRACKET 
  { $<i>$ = get_last_element(); lvl++; }
   variable_list statement_list _RBRACKET
  { lvl--; clear_symbols( $<i>2 + 1); }
  ;

assignment_statement
  : _ID _ASSIGN num_exp _SEMICOLON
      {
        int idx = lookup_symbol($1, VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("invalid lvalue '%s' in assignment", $1);
       
        if(get_type(idx) != get_type($3))
            err("incompatible types in assignment");
        gen_mov($3, idx);
      }
  ;

num_exp
  : exp
  | num_exp _AROP exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: arithmetic operation");
	else{
	int t1 = get_type($1);    
        code("\n\t\t%s\t", ar_instructions[$2 + (t1 - 1) * AROP_NUMBER]);
        gen_sym_name($1);
        code(",");
        gen_sym_name($3);
        code(",");
        free_if_reg($3);
        free_if_reg($1);
        $$ = take_reg();
        gen_sym_name($$);
        set_type($$, t1);
	}
      }
  ;

exp
  : literal
  | _ID
      {
        $$ = lookup_symbol($1, VAR|PAR|GVAR);
        if($$ == NO_INDEX)
          err("'%s' undeclared", $1);
      }
  | function_call
  {
        $$ = take_reg();
        gen_mov(FUN_REG, $$);
  }
  | _LPAREN num_exp _RPAREN
      { $$ = $2; }
  | _ID _INCR 
    {
	 int idx = lookup_symbol($1, VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("'%s' undeclared", $1);

	if(lookup_symbol($1, FUN) != NO_INDEX)
	  err("function cannot be incremented"); 
	$$ = take_reg();
	gen_mov(idx, $$);

	if(get_type(idx) == INT)
	  code("\n\t\tADDS\t");
	else
	  code("\n\t\tADDU\t");
	gen_sym_name(idx);
 	code(", $1, ");
        gen_sym_name(idx);
     }
  | _ID _DECR
    {
	 int idx = lookup_symbol($1, VAR|PAR|GVAR);
        if(idx == NO_INDEX)
          err("'%s' undeclared", $1);

	if(lookup_symbol($1, FUN) != NO_INDEX)
	  err("function cannot be incremented"); 
	$$ = take_reg();
	gen_mov(idx, $$);

	if(get_type(idx) == INT)
	  code("\n\t\tSUBS\t");
	else
	  code("\n\t\tSUBU\t");
	gen_sym_name(idx);
 	code(", $1, ");
        gen_sym_name(idx);
     }
  | _LPAREN rel_exp  _RPAREN _QMARK exp  _COLON exp 

  {
	if(get_type($5) != get_type($7))
	  err("Incompatible types");

	reg = take_reg();
	$<i>$ = ++lab_num;
	code("\n\t\t%s\t@false%d", opp_jumps[$2], $<i>$);
	code("\n@true%d:", $<i>$);
	gen_mov($5,reg);
	code("\n\t\tJMP\t@exit%d", $<i>$);
	code("\n@false%d:", $<i>$);
	gen_mov($7, reg);
	code("\n@exit%d:", $<i>$);
	$$ = reg;
	
  }	
  ;

literal
  : _INT_NUMBER
      { $$ = insert_literal($1, INT); }

  | _UINT_NUMBER
      { $$ = insert_literal($1, UINT); }
  ;

function_call
  : _ID 
      {
        fcall_idx = lookup_symbol($1, FUN);
        if(fcall_idx == NO_INDEX)
          err("'%s' is not a function", $1);
      }
    _LPAREN arguments _RPAREN
      {
        if(get_atr1(fcall_idx) != $4)
          err("wrong number of args to function '%s'", 
              get_name(fcall_idx));

 	code("\n\t\t\tCALL\t%s", get_name(fcall_idx));
        if($4 > 0)
          code("\n\t\t\tADDS\t%%15,$%d,%%15", $4 * 4);
        set_type(FUN_REG, get_type(fcall_idx));
	args = 0;
        $$ = FUN_REG;
      }
  ;

voidf_call
  : function_call _SEMICOLON
   {
	if(get_type(fcall_idx) != VOID)
           err("void function cannot be assigned");
   }
  ;

arguments
  : /* empty */
	{ $$ = args; }
  | argument
	{ $$ = args; }
  ;

argument
  : num_exp
    { 
      if(get_type(fcall_idx + args + 1) != get_type($1))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
      args++;
      free_if_reg($1);
      code("\n\t\t\tPUSH\t");
      gen_sym_name($1);
    }
  | argument _COMMA num_exp
    {
      if(get_type(fcall_idx + args + 1) != get_type($3))
        err("incompatible type for argument in '%s'",
            get_name(fcall_idx));
	args++;
      free_if_reg($3);
      code("\n\t\t\tPUSH\t");
      gen_sym_name($3);
     }
  ;

if_statement
  : if_part %prec ONLY_IF
     { code("\n@exit%d:", $1); }
  | if_part _ELSE statement
      { code("\n@exit%d:", $1); }
  ;

if_part
  : _IF _LPAREN
 {
        $<i>$ = ++lab_num;
        code("\n@if%d:", lab_num);
      }
  rel_exp
{
        code("\n\t\t%s\t@false%d", opp_jumps[$4], $<i>3);
        code("\n@true%d:", $<i>3);
      }
  _RPAREN statement
{
        code("\n\t\tJMP \t@exit%d", $<i>3);
        code("\n@false%d:", $<i>3);
        $$ = $<i>3;
      }
  ;

rel_exp
  : num_exp _RELOP num_exp
      {
        if(get_type($1) != get_type($3))
          err("invalid operands: relational operator");
 	$$ = $2 + ((get_type($1) - 1) * RELOP_NUMBER);
        gen_cmp($1, $3);
      }
  ;

return_statement
  : _RETURN num_exp _SEMICOLON
      {
	ret_val = 1;
	if(get_type(fun_idx) == VOID)
          err("void function cannot have return expression");

        if(get_type(fun_idx) != get_type($2))
          err("incompatible types in return");

 	gen_mov($2, FUN_REG);
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));   
      }

  | _RETURN _SEMICOLON
      {
	ret_val = 1;
        if(get_type(fun_idx) != VOID)
          warn("non void function must have return expression");
        code("\n\t\tJMP \t@%s_exit", get_name(fun_idx));   
  }
      
  ;


%%

int yyerror(char *s) {
  fprintf(stderr, "\nline %d: ERROR: %s", yylineno, s);
  error_count++;
  return 0;
}

void warning(char *s) {
  fprintf(stderr, "\nline %d: WARNING: %s", yylineno, s);
  warning_count++;
}

int main() {
  int synerr;
  init_symtab();
  output = fopen("output.asm", "w+");

  synerr = yyparse();

  clear_symtab();
  fclose(output);
  
  if(warning_count)
    printf("\n%d warning(s).\n", warning_count);

  if(error_count) {
    remove("output.asm");
    printf("\n%d error(s).\n", error_count);
  }

  if(synerr)
    return -1;  //syntax error
  else if(error_count)
    return error_count & 127; //semantic errors
  else if(warning_count)
    return (warning_count & 127) + 127; //warnings
  else
    return 0; //OK
}

