#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_KEYWORDS 32
#define MAX_IDENTIFIERS 100
#define MAX_NUMBERS 100
#define MAX_OPERATORS 100
#define MAX_STRINGS 100
#define MAX_SPECIAL_SYMBOLS 100

int isKeyword(char w[]) {
    char keyword[32][10] = {
        "auto", "break", "case", "char", "const", "continue", "default",
        "do", "double", "else", "enum", "extern", "float", "for", "goto",
        "if", "int", "long", "register", "return", "short", "signed", "sizeof",
        "static", "struct", "switch", "typedef", "union", "unsigned", "void",
        "volatile", "while"
    };
    for (int i = 0; i < 32; i++) {
        if (strcmp(w, keyword[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int isIdentifier(char w[]) {
    if (!isalpha(w[0]) && w[0] != '_') {
        return 0;
    }
    for (int i = 1; w[i] != '\0'; i++) {
        if (!isalnum(w[i]) && w[i] != '_') {
            return 0;
        }
    }
    return 1;
}

int isNumber(char w[]) {
    for (int i = 0; w[i] != '\0'; i++) {
        if (!isdigit(w[i])) {
            return 0;
        }
    }
    return 1;
}

int isOperator(char w[]) {
    char operators[10][3] = {
        "+", "-", "*", "/", "%", "++", "--", "==", "!=", "="
    };
    for (int i = 0; i < 10; i++) {
        if (strcmp(w, operators[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    FILE *file,*fp;
    char ch;
    printf("Enter your code to Analyze: \n");
    fp=fopen("lab3.txt","w");
    ch=getchar();
     while(ch!=EOF){
        fputc(ch,fp);
        ch=getchar();
    }
    fclose(fp);

    file = fopen("lab3.txt", "r");
    char c;
    char word[100];
    int wordIndex = 0;

    char keywords[MAX_KEYWORDS][10];
    int keywordIndex = 0;

    char identifiers[MAX_IDENTIFIERS][100];
    int identifierIndex = 0;

    char numbers[MAX_NUMBERS][100];
    int numberIndex = 0;

    char operators[MAX_OPERATORS][3];
    int operatorIndex = 0;

    char strings[MAX_STRINGS][100];
    int stringIndex = 0;

    char specialSymbols[MAX_SPECIAL_SYMBOLS][3]; // Increase size to accommodate ""
    int specialSymbolIndex = 0;

    int inString = 0;

    while ((c = fgetc(file)) != EOF) {
        if (c == '"') {
            if (!inString) {
                inString = 1;
                specialSymbols[specialSymbolIndex][0] = '"';
            } else {
                inString = 0;
                specialSymbols[specialSymbolIndex][1] = '"';
                specialSymbols[specialSymbolIndex][2] = '\0';
                specialSymbolIndex++;
            }
        } else if (inString) {
            word[wordIndex++] = c;
        } else if (isalnum(c) || c == '_') {
            word[wordIndex++] = c;
        } else {
            word[wordIndex] = '\0';
            if (wordIndex > 0) {
                if (isKeyword(word)) {
                    strcpy(keywords[keywordIndex++], word);
                } else if (isIdentifier(word)) {
                    strcpy(identifiers[identifierIndex++], word);
                } else if (isNumber(word)) {
                    strcpy(numbers[numberIndex++], word);
                } else {
                    strcpy(strings[stringIndex++], word); // Store as a string
                }
                wordIndex = 0;
            }
            if (ispunct(c)) {
                word[0] = c;
                word[1] = '\0';
                if (isOperator(word)) {
                    strcpy(operators[operatorIndex++], word);
                } else {
                    strcpy(specialSymbols[specialSymbolIndex++], word);
                }
            }
        }
    }

    fclose(file);

    printf("Keywords: ");
    for (int i = 0; i < keywordIndex; i++) {
        printf("%s ", keywords[i]);
    }
    printf("\n");

    printf("Identifiers: ");
    for (int i = 0; i < identifierIndex; i++) {
        printf("%s ", identifiers[i]);
    }
    printf("\n");

    printf("Numbers: ");
    for (int i = 0; i < numberIndex; i++) {
        printf("%s ", numbers[i]);
    }
    printf("\n");

    printf("Operators: ");
    for (int i = 0; i < operatorIndex; i++) {
        printf("%s ", operators[i]);
    }
    printf("\n");

    printf("Strings: ");
    for (int i = 0; i < stringIndex; i++) {
        printf("%s ", strings[i]);
    }
    printf("\n");

    printf("Special Symbols: ");
    for (int i = 0; i < specialSymbolIndex; i++) {
        printf("%s ", specialSymbols[i]);
    }
    printf("\n");

    return 0;
}
