#pragma once
#include "Stack.h"
#include "IntStack.h"
#include "Queue.h"
#include "Helpers.h"
#include "Constants.h"
#include <cstdlib>

class ONPConv
{
private:
	Queue output;
	Stack stos;
	IntStack argCounter;
public:

	void addChar(char* znak);
	Queue* getOutput();
	void endParse();
	void print();
	void addToChar(int args);
	void destroy();

};

