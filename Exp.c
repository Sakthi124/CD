%{
#include <stdio.h>
#include <stdlib.h>
int COMMENT = 0;
%}
%%
#include<.*>        printf("\n%s is a preprocessor directive.", yytext);

int|float|void|main|if|else|printf|scanf|for|char|getch|while
                    { if(!COMMENT) printf("\n%s is a keyword", yytext); }

"/*"                { COMMENT = 1; }

"*/"                { COMMENT = 0; }

"{"                 { if(!COMMENT) printf("\nBlock begins"); }
"}"                 { if(!COMMENT) printf("\nBlock ends"); }

[a-zA-Z_][a-zA-Z0-9_]* 
                    { if(!COMMENT) printf("\n%s is an identifier", yytext); }

\".*\"              { if(!COMMENT) printf("\n%s is a string", yytext); }

[0-9]+              { if(!COMMENT) printf("\n%s is a number", yytext); }

[ \t]               { /* Ignore white space */ }

"="                 { if(!COMMENT) printf("\n%s is an assignment operator", yytext); }

"<"|"<="|">"|">="|"=="|"!="
                    { if(!COMMENT) printf("\n%s is a relational operator", yytext); }

.                   { /* Ignore other characters */ }
%%

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("\nCould not open the file: %s", argv[1]);
        exit(0);
    }
    FILE *file = fopen(argv[1], "r");
    if(!file)
    {
        printf("\nCould not open the file: %s", argv[1]);
        exit(0);
    }
    yyin = file;
    yylex();
    printf("\n\n");
    return 0;
}

int yywrap()
{
    return 1;
}
