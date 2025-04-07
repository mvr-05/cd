%{
    /* Header Section */
%}

%%

[ \t\n]+    ;          /* Ignore spaces, tabs, and newlines */
.           { printf("%s", yytext); }  /* Print other characters */

%%

int main() {
    yylex();  /* Calls lexical analyzer */
    return 0;
}

int yywrap() {
    return 1;
}
