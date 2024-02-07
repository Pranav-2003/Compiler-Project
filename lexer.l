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
print       [ -~]
 
ID          {alpha}+{alnum}*
ICONST      "0"|[0-9]{digit}*
FCONST      "0"|{digit}*"."{digit}+
CCONST      (\'{print}\')|(\'\\[nftrbv]\')
STRING      \"{print}*\"
 
%%
 
"#".*                  { printf("Eat up comment at line %d\n", lineno); } 
 
"/*"                    { printf("Eat up comment from line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/"        { printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+     
<ML_COMMENT>"*"         
<ML_COMMENT>"\n"        { lineno += 1; }
 

"and"							{ ret_print("KEYWORD_AND"); }
"as"              { ret_print("KEYWORD_AS"); }
"assert"			 		{ ret_print("KEYWORD_ASSERT"); }
"async"						{ ret_print("KEYWORD_ASYNC"); }
"await"         	{ ret_print("KEYWORD_AWAIT"); }
"break"        		{ ret_print("KEYWORD_BREAK"); }
"class"         	{ ret_print("KEYWORD_CLASS"); }
"continue"   			{ ret_print("KEYWORD_CONTINUE"); }
"def"							{ ret_print("KEYWORD_DEF"); }
"del"							{ ret_print("KEYWORD_DEL"); }
"elif"						{ ret_print("KEYWORD_ELIF"); }
"else"            { ret_print("KEYWORD_ELSE"); }
"except"					{ ret_print("KEYWORD_EXCEPT"); }
"False"						{ ret_print("KEYWORD_FALSE"); }
"finally"					{ ret_print("KEYWORD_FINALLY"); }
"for"             { ret_print("KEYWORD_FOR"); }
"from"						{ ret_print("KEYWORD_FROM"); }
"global"					{ ret_print("KEYWORD_GLOBAL"); }
"if"              { ret_print("KEYWORD_IF"); }
"import"					{ ret_print("KEYWORD_IMPORT"); }
"in"							{ ret_print("KEYWORD_IN"); }
"is"							{ ret_print("KEYWORD_IS"); }
"lambda"					{ ret_print("KEYWORD_LAMBDA"); }
"None"						{ ret_print("KEYWORD_NONE"); }
"nonlocal"				{ ret_print("KEYWORD_NONLOCAL"); }
"not"							{ ret_print("KEYWORD_NOT"); }
"or"							{ ret_print("KEYWORD_OR"); }
"pass"						{ ret_print("KEYWORD_PASS"); }
"raise"						{ ret_print("KEYWORD_RAISE"); }
"return"   		    { ret_print("KEYWORD_RETURN"); }
"True"						{ ret_print("KEYWORD_TRUE"); }
"try"							{ ret_print("KEYWORD_TRY"); }
"while"  		      { ret_print("KEYWORD_WHILE"); }
"with"						{ ret_print("KEYWORD_WITH"); }
"yield"						{ ret_print("KEYWORD_YIELD"); }


 
 
"+"                 		{ ret_print("ADDOP"); }
"-"                     { ret_print("SUBOP"); }
"*"                     { ret_print("MULOP"); }
"/"                     { ret_print("DIVOP"); }
"%"											{ ret_print("MODOP");}
"//"										{ ret_print("FLOORDIVOP");}
"++"         			      { ret_print("INCR"); }
"--"                    { ret_print("DECR");}
"!"                     { ret_print("NOTOP"); }
"=="|"!="               { ret_print("EQUOP"); }
">"|"<"|">="|"<="       { ret_print("RELOP"); }
 
 
"("             { ret_print("LPAREN"); }
")"             { ret_print("RPAREN"); }
"]"             { ret_print("LBRACK"); }
"["             { ret_print("RBRACK"); }
"{"             { ret_print("LBRACE"); }
"}"             { ret_print("RBRACE"); }
";"             {}
":"             { ret_print("COLON");}
"."             { ret_print("DOT"); }
","             { ret_print("COMMA"); }
"="             { ret_print("ASSIGN"); }
"&"             { ret_print("REFER"); }
 
 
{ID}            {
                    // insert identifier into symbol table
                    insert(yytext, strlen(yytext), UNDEF, lineno);
                    ret_print("ID");
                }
{ICONST}        { ret_print("ICONST"); }
{FCONST}        { ret_print("FCONST"); }
{CCONST}        { ret_print("CCONST"); }
{STRING}        { ret_print("STRING"); }
 
 
"\n"            { lineno += 1; }
[ \t\r\f]+      
 
.               { yyerror("Unrecognized character"); }
 
%%
 
void ret_print(char *token_type){
    printf("yytext: %s\ttoken: %s\tlineno: %d\n", yytext, token_type, lineno);
}
 
void yyerror(char *message){
    printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
    exit(1);
}
 
int main(){
    init_hash_table();
    yyin = fopen("Valid_Input.txt", "r");
    yylex();
    fclose(yyin);

    yyout = fopen("symtable.out", "w");
    symtab_dump(yyout);
    fclose(yyout);  
    
    return 0;
}

