#include "Helpers.h"

bool is_number(char c) {
    return (c >= '0' && c <= '9');
}

bool is_function(char znaki) { 
    return znaki == 'M' || znaki == 'N' || znaki == 'I';
}

bool is_operator(char* znak) {
    return znak[0] == '+' || znak[0] == '-' || znak[0] == '*' || znak[0] == '/';
}

int get_priority(char c[MAX_OPERAND_LENGHT]) {
    switch (c[0]) {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case 'IF':
    case 'N':
    case 'MIN':
    case 'MAX':
        return 3;
    case '(':
    case ')':
        return 4;
    default:
        return -100;
    }
}
