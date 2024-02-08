%option noyywrap
 
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "symtab.c"
    
    extern FILE *yyin;
    extern FILE *yyout;
    
    int lineno = 1; // initialize to 1
    void ret_print(char *token_type);
    void yyerror();
%}
 
%x ML_COMMENT
 
alpha       [a-zA-Z]
digit       [0-9]
alnum       {alpha}|{digit}
print       [ -!#-~]
 
ID          {alpha}{alnum}*
ICONST      "0"|[0-9]{digit}*
FCONST      "0"|{digit}*"."{digit}+
CCONST      (\'{print}\')|(\'\\[nftrbv]\')
STRING      \"{print}*\"
 
%%
 
"#".*                   { printf("Comment begins from line %d\n", lineno); } 
 
"'''"                   { printf("Comment begins from line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT><<EOF>>     { yy_fatal_error("No Closing Comment"); }
<ML_COMMENT>"'''"       { printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+     
<ML_COMMENT>"*"         
<ML_COMMENT>"\n"        { lineno += 1; }
 
{FCONST}"."{digit}*     { yy_fatal_error("Incorrect Float Declaration");}
{ICONST}+{alpha}        {yy_fatal_error("Incorrect Variable name");}

"and"			{ ret_print("KEYWORD_AND"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"as"              	{ ret_print("KEYWORD_AS"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"assert"		{ ret_print("KEYWORD_ASSERT"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"async"			{ ret_print("KEYWORD_ASYNC"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"await"         	{ ret_print("KEYWORD_AWAIT"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"break"        		{ ret_print("KEYWORD_BREAK"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"class"         	{ ret_print("KEYWORD_CLASS"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"continue"   		{ ret_print("KEYWORD_CONTINUE"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"def"			{ ret_print("KEYWORD_DEF"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"del"			{ ret_print("KEYWORD_DEL"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"elif"			{ ret_print("KEYWORD_ELIF"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"else"            	{ ret_print("KEYWORD_ELSE"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"except"		{ ret_print("KEYWORD_EXCEPT"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"False"			{ ret_print("KEYWORD_FALSE"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"finally"		{ ret_print("KEYWORD_FINALLY"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"for"             	{ ret_print("KEYWORD_FOR"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"from"			{ ret_print("KEYWORD_FROM"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"global"		{ ret_print("KEYWORD_GLOBAL"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"if"              	{ ret_print("KEYWORD_IF"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"import"		{ ret_print("KEYWORD_IMPORT"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"in"			{ ret_print("KEYWORD_IN"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"is"			{ ret_print("KEYWORD_IS"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"lambda"		{ ret_print("KEYWORD_LAMBDA"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"None"			{ ret_print("KEYWORD_NONE"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"nonlocal"		{ ret_print("KEYWORD_NONLOCAL"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"not"			{ ret_print("KEYWORD_NOT"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"or"			{ ret_print("KEYWORD_OR"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"pass"			{ ret_print("KEYWORD_PASS"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"print"			{ ret_print("KEYWORD_PRINT"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"raise"			{ ret_print("KEYWORD_RAISE"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"return"   		{ ret_print("KEYWORD_RETURN"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"True"			{ ret_print("KEYWORD_TRUE"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"try"			{ ret_print("KEYWORD_TRY"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"while"  		{ ret_print("KEYWORD_WHILE"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"with"			{ ret_print("KEYWORD_WITH"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}
"yield"			{ ret_print("KEYWORD_YIELD"); insert(yytext, strlen(yytext), UNDEF, lineno, "KEYWORD");}


 
 
"+"                 	{ ret_print("ADDOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"-"                     { ret_print("SUBOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"**"			{ ret_print("EXPOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"&&"			{ ret_print("ANDOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"||"			{ ret_print("OROP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"&"			{ ret_print("BITANDOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"|"			{ ret_print("BITOROP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"*"                     { ret_print("MULOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"/"                     { ret_print("DIVOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"%"			{ ret_print("MODOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"//"			{ ret_print("FLOORDIVOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"+="         		{ ret_print("INCR"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"-="                    { ret_print("DECR"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"!"                     { ret_print("NOTOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"=="|"!="               { ret_print("EQUOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
">"|"<"|">="|"<="       { ret_print("RELOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
">>"|"<<"               { ret_print("SHIFTOP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}
"^"                     { ret_print("XOROP"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}

 
 
"("             { ret_print("LPAREN"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
")"             { ret_print("RPAREN"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
"]"             { ret_print("LBRACK"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
"["             { ret_print("RBRACK"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
"{"             { ret_print("LBRACE"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
"}"             { ret_print("RBRACE"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
";"             {}
":"             { ret_print("COLON"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
"."             { ret_print("DOT"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
","             { ret_print("COMMA"); insert(yytext, strlen(yytext), UNDEF, lineno, "PUNCTUATORS");}
"="             { ret_print("ASSIGN"); insert(yytext, strlen(yytext), UNDEF, lineno, "OP");}

 
{ID}            {
                    // insert identifier into symbol table
                    insert(yytext, strlen(yytext), UNDEF, lineno, "ID");
                    ret_print("ID");
                }
{ICONST}        { ret_print("ICONST"); insert(yytext, strlen(yytext), UNDEF, lineno, "CONST");}
{FCONST}        { ret_print("FCONST"); insert(yytext, strlen(yytext), UNDEF, lineno, "CONST");}
{CCONST}        { ret_print("CCONST"); insert(yytext, strlen(yytext), UNDEF, lineno, "CONST");}
{STRING}        { ret_print("STRING"); insert(yytext, strlen(yytext), UNDEF, lineno, "CONST");}
 
 
"\n"            { lineno += 1; }
[ \t\r\f]+      
 
.               { yyerror("Unrecognized character"); }
 
%%
 
void ret_print(char *token_type){
    printf("Text: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}
 
void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
    exit(1);
}
 
int main(){
    init_hash_table();
    yyin = fopen("input.py", "r");
    yylex();
    fclose(yyin);

    yyout = fopen("symtable.out", "w");
    symtab_dump(yyout);
    fclose(yyout);  
    
    return 0;
}

