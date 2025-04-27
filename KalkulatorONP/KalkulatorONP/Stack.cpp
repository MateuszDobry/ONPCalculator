#include "Stack.h"
#include <cstring>
Stack::Stack() : top(nullptr) {}

Stack::~Stack() {
    char znak[20];
    while (!isEmpty())
        pop(znak);
}

bool Stack::isEmpty() {
    return top == nullptr;
}

void Stack::push(char c[MAX_OPERAND_LENGHT]) {
    Node* newNode = new Node(c);
    if (isEmpty()) {
        top = newNode;
    }
    else {
      /*  top->next = newNode;
        newNode->prev = top;
        top = newNode;*/
        newNode->next = top;
        top = newNode;
    }
}

char* Stack::pop(char* val) {
    if (isEmpty()) {
        std::cerr << "Stack is empty.\n";
        exit(EXIT_FAILURE);
    }

    std::strcpy(val,top->data);
    Node* temp = top->next;
    delete top;
    top = temp;
    return val;
}

char* Stack::peek() {
    if (isEmpty()) {
        std::cerr << "Stack is empty.\n";
        exit(EXIT_FAILURE);
    }
    return top->data;
}

void Stack::print()
{
    /*if (isEmpty()) {
        std::cerr << "Stack is empty.\n";
        exit(EXIT_FAILURE);
    }*/
    Node* currentNode = top;
    while (currentNode != nullptr) {
        printf("%s ", currentNode->data);
        currentNode = currentNode->next;
    }
}

void Stack::Delete() {
    if (isEmpty()) {
        std::cerr << "Stack is empty.\n";
        exit(EXIT_FAILURE);
    }
    Node* temp = top;
    top = temp->next;
    delete temp;
}