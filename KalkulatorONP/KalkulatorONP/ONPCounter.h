#pragma once
#include "Helpers.h"
#include "Stack.h"
#include "Queue.h"
#include "IntStack.h"
#include <cstdlib>

class ONPCounter
{
private:
	IntStack stos;
	Queue kolejka;
	bool flag = true;
public:
	
	void fillQueue(Queue* kolejka);
	void print();
	bool is_flag();
	bool isInputEmpty();
	int count();

};

