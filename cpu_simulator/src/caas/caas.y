
%define parse.error verbose

%locations


%{
	#include "caas.h"
	#include <stdio.h>
	int yylex(void);
	void yyerror(const char*);
%}


/* This union defines the possible return types of both lexer and
 * parser rules. We'll refer to these later on by the field name */
%union {
	int         num;
//	char       *text;
}

%token data_directive
%token code_directive
%token comma
%token int_mnemonic
%token <num>   	number
%token <num>   	cpu_register
%token <num> 	data_size
%token <num> 	binary_alu_mnemonic
%token <num> 	unary_alu_mnemonic
%token <num> 	ls_mnemonic
%token li_mnemonic
%token jmp_mnemonic
%token <num> 	br_mnemonic

%type <num> optional_size
%%

/* A program is defined recursively as either empty or an instruction
 * followed by another program. In this case, there's nothing meaningful
 * for us to do or return as an action, so we omit any action after the
 * rules. */
prog
  :
  { encode_header();} data_directive data code_directive instr_list { update_number_of_globals(); }
  |
  { encode_header();} code_directive instr_list
  ;

data
  :
  | data_size number { encode_global($1, $2); } data
  ;
instr_list
  :
  | instr instr_list
  ;

instr
  :
  binary_alu_mnemonic optional_size cpu_register comma cpu_register comma cpu_register
        { encode_binary_alu_instruction($1, $2, $5, $7, $3); }
  |
  unary_alu_mnemonic optional_size cpu_register comma cpu_register
    	{ encode_unary_alu_instruction($1, $2, $5, $3); }
  |
  ls_mnemonic cpu_register comma number
    	{ encode_load_store($1, $4, $2); }
  |
  li_mnemonic cpu_register comma number
	    { encode_load_immediate(WORD, $4, $2); }
  |
  br_mnemonic number
  	    { encode_branch_instruction($1, $2); }
  |
  jmp_mnemonic number
    	{ encode_jump($2); }
  |
  int_mnemonic number
  	    { encode_interrupt($2); }
  ;

optional_size
  :
    { $$ = WORD; }
  | data_size
    { $$ = $1; }
  ;
%%