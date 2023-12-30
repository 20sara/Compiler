//#include <stdio.h>
//#include <stdbool.h>
//#include <ctype.h>
//
//
////// parsing 
//
//const char* current;
//char lookahead;
//
//bool expression();
//bool term();
//bool factor();
//bool match(char expected);
//
//bool analyzeSyntax(const char* input) {
//    current = input;
//    lookahead = *current;
//    return expression() && match('\0');
//}
//
//bool expression() {
//    if (term()) {
//        while (lookahead == '+' || lookahead == '-') {
//            char op = lookahead;
//            match(lookahead);
//            if (!term()) {
//                printf("Syntax error: Expected term after '%c'\n", op);
//                return false;
//            }
//        }
//        return true;
//    }
//    return false;
//}
//
//bool term() {
//    if (factor()) {
//        while (lookahead == '*' || lookahead == '/') {
//            char op = lookahead;
//            match(lookahead);
//            if (!factor()) {
//                printf("Syntax error: Expected factor after '%c'\n", op);
//                return false;
//            }
//        }
//        return true;
//    }
//    return false;
//}
//
//bool factor() {
//    if (isdigit(lookahead)) {
//        match(lookahead);
//        return true;
//    } else if (lookahead == '(') {
//        match('(');
//        if (!expression()) {
//            printf("Syntax error: Expected expression inside parentheses\n");
//            return false;
//        }
//        match(')');
//        return true;
//    } else {
//        printf("Syntax error: Unexpected character '%c'\n", lookahead);
//        return false;
//    }
//}
//
//bool match(char expected) {
//    if (lookahead == expected) {
//        current++;
//        lookahead = *current;
//        return true;
//    }
//    printf("Syntax error: Expected '%c' but found '%c'\n", expected, lookahead);
//    return false;
//}
//
//int main() {
//    const char* input = "5 + 3 * 2)";
//    if (analyzeSyntax(input)) {
//        printf("Syntax analysis successful\n");
//    } else {
//        printf("Syntax analysis failed\n");
//    }
//
//    return 0;
//}

