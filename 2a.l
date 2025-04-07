%{
    #include <stdio.h>
%}

%%

[0-9]+      { printf("NUMBER: %s\n", yytext); }       /* Identifies numbers */
[a-zA-Z_][a-zA-Z0-9_]*  { printf("IDENTIFIER: %s\n", yytext); }  /* Identifies identifiers */
"+"|"-"|"*"|"/"          { printf("OPERATOR: %s\n", yytext); }  /* Identifies operators */
"="                     { printf("ASSIGNMENT OPERATOR: %s\n", yytext); }  /* Identifies = */
"(" | ")" | "{" | "}"   { printf("BRACKET: %s\n", yytext); }  /* Identifies brackets */
";"                     { printf("SEMICOLON: %s\n", yytext); }  /* Identifies semicolons */
.          { printf("UNKNOWN: %s\n", yytext); }  /* Catches unknown characters */

%%

int main() {
    yylex();  /* Calls lexical analyzer */
    return 0;
}

int yywrap() {
    return 1;
}
