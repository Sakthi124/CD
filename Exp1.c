#include <stdio.h>
#include <ctype.h>
#include <string.h>

int isKeyword(char *word) {
    char *keywords[] = {"int", "float", "return", "if", "else"};
    for (int i = 0; i < 5; i++) {
        if (strcmp(word, keywords[i]) == 0)
            return 1;
    }
    return 0;
}

int main() {
    char input[] =
        "int main() {\n"
        "  int a = 10;\n"
        "  float b = 3.5;\n"
        "  // comment line\n"
        "  a = a + b;\n"
        "  return 0;\n"
        "}\n";
    char word[100];
    int i = 0, j = 0;

    printf("Lexical Tokens:\n");

    while (input[i] != '\0') {
        // Identifiers / Keywords
        if (isalpha(input[i])) {
            j = 0;
            while (isalnum(input[i])) {
                word[j++] = input[i++];
            }
            word[j] = '\0';
            if (isKeyword(word))
                printf("[Keyword: %s]\n", word);
            else
                printf("[Identifier: %s]\n", word);
        }
        // Constants
        else if (isdigit(input[i])) {
            j = 0;
            while (isdigit(input[i]) || input[i] == '.') {
                word[j++] = input[i++];
            }
            word[j] = '\0';
            printf("[Constant: %s]\n", word);
        }
        // Single-line comments
        else if (input[i] == '/' && input[i + 1] == '/') {
            i += 2;
            while (input[i] != '\n' && input[i] != '\0') i++;
            printf("[Single Line Comment]\n");
        }
        // Operators
        else if (strchr("=+-*/<>", input[i])) {
            printf("[Operator: %c]\n", input[i]);
            i++;
        }
        // Separators
        else if (strchr("();{}", input[i])) {
            printf("[Separator: %c]\n", input[i]);
            i++;
        }
        // Skip other characters (spaces, newline, etc.)
        else {
            i++;
        }
    }
    return 0;
}
