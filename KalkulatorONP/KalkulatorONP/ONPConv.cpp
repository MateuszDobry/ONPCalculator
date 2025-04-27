#include "ONPConv.h"
#include <iostream>
#include <cstdio>

void ONPConv::addChar(char* znak) {
    char element[20];
    // Jeœli token jest operandem
    if (is_number(znak[0])) {
        output.enqueue(znak);
    }
    else if (is_function(znak[0])) {
        stos.push(znak);  
    }
    // Jeœli token to nawias otwieraj¹cy '('
    else if (znak[0] == '(') { 
        argCounter.push(1);
        stos.push(znak);
    }
    // Jeœli token to nawias zamykaj¹cy ')'
    else if (znak[0] == ')') {
        while (!stos.isEmpty() && stos.peek()[0] != '(') {
            output.enqueue(stos.pop(element));
        }
        if (!stos.isEmpty()) {
            stos.Delete(); // Wynika z '('
        }
        if (!stos.isEmpty() && is_function(stos.peek()[0])) {
            if (stos.peek()[0] == 'M') {
                addToChar(argCounter.peek());
            } 
            output.enqueue(stos.pop(element));
        }
        argCounter.pop();
    }

    else if (znak[0] == ',') {       
            argCounter.incrementTop();
        while (stos.peek()[0] != '(') {
            output.enqueue(stos.pop(element));
        }

    }
    // Jeœli token jest operatorem
    else {
        while (!stos.isEmpty() && get_priority(znak) <= get_priority(stos.peek()) && stos.peek()[0] != '(') {
            output.enqueue(stos.pop(element));
        }
        stos.push(znak);
    }
}

Queue* ONPConv::getOutput() {
    return &(this->output);
}

void ONPConv::endParse()
{
    char element[20];
    while (!stos.isEmpty()) {
        char* temp = stos.pop(element);
        output.enqueue(temp);
    }
}

void ONPConv::print()
{
    output.print();
    stos.print();
}

void ONPConv::addToChar(int args)
{
    sprintf(stos.peek() + 3 * sizeof(char), "%d", args);
}

void ONPConv::destroy() {
    output.~Queue();
}
