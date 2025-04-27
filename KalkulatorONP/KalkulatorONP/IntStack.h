#pragma once
#include <iostream>
#include "Node.h"


class IntStack
{
private:
	IntNode* top;
public:
	IntStack();

	~IntStack();

	bool isEmpty();

	void push(int liczba);

	void incrementTop();

	int pop();

	int peek();

	void print();

	
};

