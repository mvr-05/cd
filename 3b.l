%{
#include <stdio.h>
int tokenCount = 0, idCount = 0;
%}

%%

[ \t\n]+                          ;   // Ignore spaces, tabs, newlines
"#".*                            ;   // Ignore preprocessor lines
"//".*                           ;   // Ignore single-line comments
"/*"([^*]|\*+[^*/])*\*+"/"       ;   // Ignore multi-line comments

// Keywords
auto|break|case|char|const|continue|default|do|double|else|enum|
extern|float|for|goto|if|int|long|register|return|short|signed|
sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {
    printf("token: %d < keyword, %s >\n", ++tokenCount, yytext);
}

// Operators
[+\-*/%<>=]=?|==|!=              { printf("token: %d < operator, %s >\n", ++tokenCount, yytext); }

// Special symbols
[();{}]                          { printf("token: %d < special char, %s >\n", ++tokenCount, yytext); }

// Constants
[0-9]+                           { printf("token: %d < constant, %s >\n", ++tokenCount, yytext); }

// Identifiers
[a-zA-Z_][a-zA-Z0-9_]*           { printf("token: %d < ID %d, %s >\n", ++tokenCount, ++idCount, yytext); }

// Anything else = invalid
.                                { printf("ERROR: INVALID TOKEN %s\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
