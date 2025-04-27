#pragma once
#include <iostream>
#include "Node.h"





class Stack {
private:
	Node* top;
public:
	Stack();

	~Stack();

	bool isEmpty();

	void push(char c[MAX_OPERAND_LENGHT]);

	char* pop(char* val);

	char* peek();

	void print();

	void Delete();
};

