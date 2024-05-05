%{
	#include <stdio.h>
	#include <stdarg.h>
	#include "symTab_new.h"
    #include "tac.h"

	int yylex();
	void yyerror(const char *msg);
    extern int yylineno; 

    int count = 0;

    //char val_temp[200];
    char func_name[100];

    char identifier[100];

    int op_count = 0;

    char func_call_name[100];

    int arg_count = 0;
    int param_count = 0;
    char param_count_str[10];
    
    int func_line_no;

	void finish()
	{
		printf("\n------------------->valid python syntax<--------------------\n\n\n\n");
        print_symbol_table();
        print_quads();
        dead_code_elim();
        loop_inv();
        const_prop();
        print_quads_opt();
		exit(0);
	}

%}

%union {char *data; int indent_depth;};

%token T_identifier T_False T_True T_number Indent Nodent Dedent T_string T_print T_colon T_newLine T_lesserThan T_greaterThanEqualTo T_lesserThanEqualTo T_or T_and T_not T_assignOP T_notEqualOP T_equalOP T_greaterThan T_in T_if T_elif T_while T_else T_import T_break T_pass T_minus T_plus T_division T_multiply T_openParanthesis T_closeParanthesis T_EOF T_return T_openBracket T_closeBracket T_def T_comma T_List T_range T_None T_continue T_len T_input

%left T_plus T_minus
%left T_multiply T_division
%right T_assignOP
%nonassoc T_if
%nonassoc T_elif
%nonassoc T_else
%start Start
%type<data> arith_exp term constant list_index

%%

Start : StartParse T_EOF {printf("Start => StartParse EOF\n\n"); finish();};

constant : T_number {printf("constant => number\n\n");
                    insert("Constant", $<data>1, @1.first_line, strlen($<data>1), "null");
                    }
         | T_string {printf("constant => string\n\n"); insert("Constant", $<data>1, @1.first_line, strlen($<data>1), "null");}
		 | T_None {printf("constant => none\n\n");insert("Constant", "None", @1.first_line, strlen($<data>1), "null");};

term : T_identifier {	printf("term => id\n\n");
                        push_0($<data>1);
                        check_scope($<data>1, @1.first_line);
                        if((strcmp(identifier, $<data>1) != 0) && (li_s)){ li_flag ++; }
                        else li_flag -- ;
                        insert("Identifier", $<data>1, @1.first_line, strlen($<data>1), "null");
                        //memset(lookup($<data>1)->value, 0, sizeof(lookup($<data>1)->value));
                        strncpy($$, lookup($<data>1)->value, strlen(lookup($<data>1)->value));
                    }
     | constant {printf("term => constant\n\n"); if((strcmp(identifier, $<data>1) != 0) && (li_s)) li_flag ++ ; $$ = $<data>1; push_0($<data>1);}
     | list_index {printf("term => list_index\n\n");}
     | T_len T_openParanthesis T_identifier T_closeParanthesis {printf("term => len ( array )\n\n");}
     | T_input T_openParanthesis T_string T_closeParanthesis {printf("term => input ( string )\n\n");}
     | T_input T_openParanthesis T_closeParanthesis {printf("term => input ( )\n\n");}


list_index : T_identifier T_openBracket arith_exp T_closeBracket { printf("list_index => id ( constant )\n\n"); check_scope($<data>1, @1.first_line); is_iter($<data>1, @1.first_line);};

StartParse : T_newLine StartParse {printf("StartParse => \\n StartParse\n\n");} | finalStatements T_newLine {reset_depth();} StartParse {printf("StartParse => finalStatements \\n StartParse\n\n");} | {printf("StartParse => epsilon\n\n");} ;

basic_stmt : pass_stmt {printf("basic_stmt => pass_stmt\n\n");}
           | break_stmt {printf("basic_stmt => break_stmt\n\n");}
		   | continue_stmt {printf("basic_stmt => continue_stmt\n\n");}
           | import_stmt {printf("basic_stmt => import_stmt\n\n");}
           | assign_stmt {printf("basic_stmt => assign_stmt\n\n");}
           | arith_exp {printf("basic_stmt => arith_exp\n\n");}
           | bool_exp {printf("basic_stmt => bool_exp\n\n");}
           | print_stmt {printf("basic_stmt => print_stmt\n\n");}
           | return_stmt {printf("basic_stmt => return_stmt\n\n");};

arith_exp : term {printf("arith_exp => term\n\n"); if(li_s) op_count++;$$=$<data>1;}
          | arith_exp T_plus {push_0("+");}  arith_exp {printf("arith_exp => arith_exp + arith_exp\n\n");
                                            int val = atoi($1) + atoi($4);
                                            sprintf($$, "%d", val);
                                            codegen2($$, @1.first_line);
                                          }
          | arith_exp T_minus {push_0("-");}  arith_exp { printf("arith_exp => arith_exp - arith_exp\n\n");
                                            int val = atoi($1) - atoi($4);
                                            sprintf($$, "%d", val);
                                            codegen2($$, @1.first_line);
                                        }
          | arith_exp T_multiply {push_0("*");}  arith_exp { printf("arith_exp => arith_exp * arith_exp\n\n");
                                            int val = atoi($1) * atoi($4);
                                            sprintf($$, "%d", val);
                                            codegen2($$, @1.first_line);
                                        }
          | arith_exp T_division {push_0("/");}  arith_exp{ printf("arith_exp => arith_exp / arith_exp\n\n");
                                            int val = atoi($1) / atoi($4);
                                            sprintf($$, "%d", val);
                                            codegen2($$, @1.first_line);
                                        }
          | T_openParanthesis arith_exp T_closeParanthesis{ printf("arith_exp => ( arith_exp )\n\n");
                                            $$ = $2;
                                        };


bool_exp : bool_term T_or bool_term {printf("bool_exp => bool_term or bool_term\n\n");}
         | arith_exp T_lesserThan { push_0("<");} arith_exp {printf("bool_exp => arith_exp < arith_exp\n\n");int val = atoi($1) < atoi($4); cond_code_gen(val, @1.first_line);}
         | bool_term T_and bool_term {printf("bool_exp => bool_term and bool_term\n\n");}
         | arith_exp T_greaterThan {push_0(">");} arith_exp {printf("bool_exp => arith_exp > arith_exp\n\n"); int val = atoi($1) > atoi($4); cond_code_gen(val, @1.first_line);}
         | arith_exp T_lesserThanEqualTo {push_0("<=");} arith_exp {printf("bool_exp => arith_exp <= arith_exp\n\n"); int val = atoi($1) <= atoi($4); cond_code_gen(val, @1.first_line);}
         | arith_exp T_greaterThanEqualTo {push_0(">=");} arith_exp {printf("bool_exp => arith_exp >= arith_exp\n\n"); int val = atoi($1) >= atoi($4); cond_code_gen(val, @1.first_line);}
         | arith_exp T_in {push_0("in"); printf("bool_exp => arith_exp in id\n\n");} T_identifier
         | bool_term {printf("bool_exp => bool_term\n\n");} ;

bool_term : bool_factor {printf("bool_term => bool_factor\n\n");}
          | arith_exp T_equalOP arith_exp {printf("bool_term => arith_exp == arith_exp\n\n");}
          | T_True {insert("Constant", "True", @1.first_line, strlen($<data>1), "null");printf("bool_term => True\n\n");}
          | T_False {insert("Constant", "False", @1.first_line, strlen($<data>1), "null");printf("bool_term => False\n\n");};

bool_factor : T_not bool_factor {printf("bool_factor => not bool_factor\n\n");}
            | T_openParanthesis bool_exp T_closeParanthesis {printf("bool_factor => ( bool_exp )\n\n");};

import_stmt : T_import T_identifier {insert("Package name", $<data>2, @2.first_line, strlen($<data>2), "null"); printf("import_stmt => import id\n\n");};
pass_stmt : T_pass {printf("pass_stmt => pass\n\n");}
continue_stmt : T_continue {printf("continue_stmt => continue\n\n");}
break_stmt : T_break {printf("break_stmt => break\n\n");}
return_stmt : T_return {dc_flag = 1; printf("return_stmt => return\n\n");}
			| T_return arith_exp {dc_flag = 1; printf("return_stmt => return arith_exp\n\n");}
	    	| T_return bool_exp {dc_flag = 1; printf("return_stmt => return bool_exp\n\n");} ;


assign_stmt : T_identifier {memset(identifier,0,sizeof(identifier));strncpy(identifier, $<data>1, strlen($<data>1));push_0($<data>1);} T_assignOP {push_0("=");} assign{printf("assign_stmt => id = assign\n\n");} 
			| list_index T_assignOP {push_0("=");} arith_exp;


assign: arith_exp{
					printf("assign => arith_exp\n\n");
                    insert("Identifier", identifier, @1.first_line, strlen(identifier), $1);
                    if(op_count==1) li_flag = 1;
                    codegen_assign();
                    li_flag = 0;
                    op_count = 0;
                }
      |T_minus arith_exp{
      						printf("assign => - arith_exp\n\n");
                            char temp[100] = "-";
                            strcat(temp, $2);
                            insert("Identifier", identifier, @1.first_line, strlen(identifier), temp);
                            if(op_count==1) li_flag = 1;
                            codegen_umin();
                            li_flag = 0;
                            op_count = 0;
                        }
      | bool_exp {printf("assign => bool_exp\n\n");insert("Identifier", $<data>1, @1.first_line, strlen($<data>1), "null");}
      | func_call {printf("assign => func_call\n\n");insert("Identifier", identifier, @1.first_line, strlen(identifier), "null");insert("Func call", $<data>1, @1.first_line, strlen($<data>1), "null");}
      | T_openBracket list_elements T_closeBracket {printf("assign => ( list_elements )\n\n");insert("List identifier", $<data>1, @1.first_line, strlen($<data>1), "null");};     

print_stmt : T_print T_openParanthesis print_values T_closeParanthesis {printf("print_stmt => print ( print_values )\n\n"); }
print_values: arith_exp T_comma print_values {printf("print_values => arith_exp , print_values\n\n"); }
			| arith_exp {printf("print_values => arith_exp\n\n"); }
			| bool_exp T_comma print_values {printf("print_values => bool_exp , print_values\n\n"); }
			| bool_exp {printf("print_values => bool_exp\n\n"); }
			| func_call T_comma print_values {printf("print_values => func_call , print_values\n\n"); }
			| func_call {printf("print_values => func_call\n\n"); };

finalStatements : basic_stmt {printf("finalStatements => basic_stmt\n\n"); }
                | cmpd_stmt {printf("finalStatements => cmpd_stmt\n\n"); }
                | func_def {printf("finalStatements => func_def\n\n"); }
                | func_call {printf("finalStatements => func_call\n\n"); }
                | error T_newLine {printf("finalStatements => error \\n\n\n"); yyerrok; yyclearin;} ;

cmpd_stmt : if_stmt {printf("cmpd_stmt => if_stmt\n\n"); }
          | while_stmt {printf("cmpd_stmt => while_stmt\n\n"); } ;

if_stmt : T_if bool_exp {if_code_1();} T_colon start_suite if_opt {printf("if_stmt => if bool_exp : start_suite if_opt\n\n"); };

if_opt: elif_stmts {printf("if_opt => elif_stmts");}
      | %prec T_if {printf("if_opt => T_if");}; 		

elif_stmts : else_stmt {printf("elif_stmts => else_stmt\n\n"); }
           | T_elif {elif1();count++;} bool_exp {if_code_1();} T_colon start_suite {if_code_2();} elif_stmts {printf("elif_stmts => elif bool_exp : start_suite elif_stmts\n\n"); };

else_stmt : T_else {if(count == 0){ count = 0; if_code_2();}} T_colon start_suite {printf("else_stmt => else : start_suite\n\n"); };

func_def : T_def T_identifier {memset(func_name,0,sizeof(func_name)); strncpy(func_name,$<data>2,strlen($<data>2)); func_begin($<data>2); func_line_no=@2.first_line;} T_openParanthesis{flag = 1; func_no++;} param T_closeParanthesis T_colon {sprintf(param_count_str, "%d", param_count); insert("Func_Name", func_name, func_line_no, strlen(func_name), param_count_str);} start_suite_func {printf("func_def => def id ( param ) : start_suite_func\n\n"); };

func_call : T_identifier {memset(func_call_name,0,sizeof(func_call_name)); strncpy(func_call_name,$<data>1,strlen($<data>1)); arg_count=0;} T_openParanthesis list_elements T_closeParanthesis {func_call(func_call_name, arg_count);arg_count=0;} {printf("func_call => id ( list_elements )\n\n"); };

while_stmt : T_while {while_code_1();} bool_exp {li_s = 1; while_code_2();} T_colon start_suite_while {printf("while_stmt => while bool_exp : start_suite\n\n");};

start_suite_while : basic_stmt {printf("start_suite_while => basic_stmt\n\n");}
            | T_newLine Indent finalStatements suite_while {printf("start_suite_while => \\n Indent finalStatements suite_while\n\n");};

suite_while : T_newLine Nodent finalStatements suite_while {printf("suite_while => \\n Nodent finalStatements suite_while\n\n");}
      | T_newLine end_suite_while {printf("suite_while => \\n end_suite_while\n\n");};

end_suite_while : Dedent finalStatements {printf("end_suite => Dedent finalStatements\n\n"); li_s = 0; while_code_3();}
          | Dedent {printf("end_suite => Dedent\n\n"); li_s = 0; while_code_3();}
          | {li_s = 0; while_code_3();reset_depth();} finalStatements {printf("end_suite => finalStatements\n\n");}
          | {printf("end_suite => epsilon\n\n"); li_s = 0; while_code_3(); reset_depth();};

start_suite_func : basic_stmt {printf("start_suite_func => basic_stmt\n\n");}
            | T_newLine Indent finalStatements suite_func {printf("start_suite_func => \\n Indent finalStatements suite_func\n\n");};

suite_func : T_newLine Nodent finalStatements suite_func {printf("suite_func => \\n Nodent finalStatements suite_func\n\n");}
      | T_newLine end_suite_func {printf("suite_func => \\n end_suite_func\n\n");};

end_suite_func : Dedent finalStatements {printf("end_suite_func => Dedent finalStatements\n\n");}
          | Dedent {printf("end_suite_func => Dedent\n\n");}
          | {dc_flag = 0;func_end(func_name); flag = 0; cur_scope = 0;reset_depth();param_count=0;} finalStatements {printf("end_suite_func => finalStatements\n\n");}
          | {dc_flag = 0;func_end(func_name); reset_depth();param_count=0; printf("end_suite_func => epsilon\n\n");};

start_suite : basic_stmt {printf("start_suite => basic_stmt\n\n");}
            | T_newLine Indent finalStatements suite{printf("start_suite => \\n Indent finalStatements\n\n");};

suite : T_newLine Nodent finalStatements suite {printf("suite => \\n Nodent finalStatements suite\n\n");}
      | T_newLine end_suite {printf("suite => \\n end_suite\n\n");}
      | {reset_depth();} elif_stmts {printf("suite => elif_stmts\n\n");};

end_suite : Dedent finalStatements {if_code_3(); printf("end_suite => Dedent finalStatements\n\n");}
          | Dedent {if_code_3(); printf("end_suite => Dedent\n\n");}
          | { if_code_3();reset_depth();} finalStatements {printf("end_suite => finalStatements\n\n");}
          | {if_code_3();reset_depth();} {printf("end_suite => epsilon\n\n");};

param : T_identifier {param_arg($<data>1, 0); insert("Identifier", $<data>1, @1.first_line, strlen($<data>1), "null");param_count++; } params {printf("params => id params\n\n");} | {printf("param => epsilon\n\n");}

params : T_comma T_identifier {param_arg($<data>2, 0); insert("Identifier", $<data>2, @1.first_line, strlen($<data>2), "null");param_count++;} params {printf("params => , id params\n\n");} | {printf("params => epsilon\n\n");};

list_element : T_comma arith_exp {param_arg($<data>2, 1);arg_count++;} list_element | ;

list_elements : T_identifier {param_arg($<data>1, 1);arg_count++ ;insert("Identifier", $<data>1, @1.first_line, strlen($<data>1), "null");} list_element {printf("list_elements => id list_element\n\n");} | T_number {param_arg($<data>1, 1); insert("Constant", $<data>1, @1.first_line, strlen($<data>1), "null");arg_count++;} list_element | T_string {param_arg($<data>1, 1); insert("Constant", $<data>1, @1.first_line, strlen($<data>1), "null");arg_count++;} list_element {printf("list_elements => string list_element\n\n");} | {printf("list_elements => epsilon\n\n");}


%%

void yyerror(const char *msg)
{
	printf("\nSyntax Error at Line %d, Column : %d\n",  yylineno, yylloc.last_column);
	print_symbol_table();
	exit(0);
}

int main()
{
    init_hash_table();
	yyparse();
	return 0;
}
