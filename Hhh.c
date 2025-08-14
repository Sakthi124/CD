%{
#include<stdio.h>
%}

keyword    int|float|char|double|while|for|if|else|return|void
identifier [a-zA-Z_][a-zA-Z0-9_]*
number     [0-9]+(\.[0-9]+)?
operator   \+|\-|\*|\/|=|==|<|>|<=|>=|!=

%%

{keyword}      { printf("%s is a keyword\n", yytext); }
{identifier}   { printf("%s is an identifier\n", yytext); }
{number}       { printf("%s is a number\n", yytext); }
{operator}     { printf("%s is an operator\n", yytext); }
[ \t\n]        ; // Ignore whitespace
.              { printf("%s is an unrecognized symbol\n", yytext); }

%%

int main() {
    yylex();
    return 0;
}

int yywrap() {
    return 1;
}
