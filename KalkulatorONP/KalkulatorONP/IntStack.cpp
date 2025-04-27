#include "IntStack.h"

IntStack::IntStack() : top(nullptr) {}


IntStack::~IntStack()
{
	while (!isEmpty())
		pop();
}

bool IntStack::isEmpty()
{
    return top == nullptr;
}

void IntStack::push(int liczba)
{
    IntNode* newNode = new IntNode(liczba);
    if (isEmpty()) {
        top = newNode;
    }
    else {
        newNode->next = top;
        top = newNode;
    }
}

void IntStack::incrementTop()
{
    top->data++;
}

int IntStack::pop()
{
    if (isEmpty()) {
        std::cerr << "Int Stack is empty.\n";
        exit(EXIT_FAILURE);
    }
    int val = top->data;
    IntNode* temp = top->next;
    delete top;
    top = temp;
    return val;
}

int IntStack::peek()
{
    if (isEmpty()) {
        std::cerr << "Stack is empty.\n";
        exit(EXIT_FAILURE);
    }
    return top->data;
}

void IntStack::print()
{
    IntNode* currentNode = top;
    while (currentNode != nullptr) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
}
