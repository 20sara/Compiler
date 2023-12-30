#include <stdio.h>
#include <ctype.h>
#include <string.h>

// Token structure to store token type and value
struct Token {
    char type[30];
    char value[30];
};

// Function to check if a character is an operator
int isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

// Function to check if a character is a parenthesis
int isSpecialChar(char c) {
    return c == '(' || c == ')'||c == '{' || c == '}' || c == '[' || c == ']' 
	        || c == '?' || c == ',;' || c == '!' || c == '$';
}

// Function to check if a character is whitespace
int isWhitespace(char c) {
    return c == ' ' || c == '\t' || c == '\n';
}


// Lexical analyzer function
struct Token getNextToken(char *sourceCode, int *currentPosition) {
    struct Token token;
    char currentChar = sourceCode[*currentPosition];

    // Skip whitespaces
    while (isWhitespace(currentChar)) {
        (*currentPosition)++;
        currentChar = sourceCode[*currentPosition];
    }

    // Check for the end of the source code
    if (currentChar == '\0') {
        sprintf(token.type, "EOF");
        sprintf(token.value, "");
        return token;
    }

    // Check for numbers
    if (isdigit(currentChar)) {
        int i = 0;
        while (isdigit(currentChar)) {
            token.value[i++] = currentChar;
            (*currentPosition)++;
            currentChar = sourceCode[*currentPosition];
        }
        token.value[i] = '\0';
        sprintf(token.type, "NUMBER");
        return token;
    }

    // Check for operators
    if (isOperator(currentChar)) {
        token.value[0] = currentChar;
        token.value[1] = '\0';
        sprintf(token.type, "OPERATOR");
        (*currentPosition)++;
        return token;
    }
   

    // Check for specialChar
    if (isSpecialChar(currentChar)) {
        token.value[0] = currentChar;
        token.value[1] = '\0';
        sprintf(token.type,"SpecialChar");
	
        (*currentPosition)++;
        return token;
    }

    // If no token is matched, raise an error or handle accordingly
    fprintf(stderr, "Error: Invalid token at position %d\n", *currentPosition);
    return token;
}

int main() {

    char sourceCode[] = "3 + 5 * } 2 - 8 ! ? / 4";
    int currentPosition = 0;

    while (1) {
        struct Token token = getNextToken(sourceCode, &currentPosition);

        // Display the token
        printf("[%s: %s]\n", token.type, token.value);

        // Check for the end of the source code
        if (strcmp(token.type, "EOF") == 0) {
            break;
        }
    }

    return 0;
}

