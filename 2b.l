%{
    #include <stdio.h>
%}

%%

[ \t\n]+      ;  /* Ignore spaces, tabs, and newlines */
"int"|"float"|"if"|"else"|"while" { printf("KEYWORD: %s\n", yytext); } /* Keywords */
[0-9]+        { printf("NUMBER: %s\n", yytext); }  /* Numbers */
[a-zA-Z_][a-zA-Z0-9_]* { printf("IDENTIFIER: %s\n", yytext); } /* Identifiers */
"=="|"!="|"<="|">="|"<"|">" { printf("RELATIONAL OPERATOR: %s\n", yytext); } /* Relational operators */
"+"|"-"|"*"|"/" { printf("ARITHMETIC OPERATOR: %s\n", yytext); } /* Arithmetic operators */
"="            { printf("ASSIGNMENT OPERATOR: %s\n", yytext); } /* Assignment */
"(" | ")" | "{" | "}" { printf("BRACKET: %s\n", yytext); } /* Brackets */
";"            { printf("SEMICOLON: %s\n", yytext); } /* Semicolon */
.              { printf("UNKNOWN: %s\n", yytext); } /* Unknown characters */

%%

int main() {
    yylex();  /* Calls lexical analyzer */
    return 0;
}

int yywrap() {
    return 1;
}
