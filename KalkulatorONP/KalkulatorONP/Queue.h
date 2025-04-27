#pragma once
#include <iostream>
#include "Node.h"
#include "Constants.h"


class Queue {
private:
	Node* front;
	Node* rear;

public:
	Queue();

	~Queue();
	
	bool isEmpty();
	
	void enqueue(char* val);

	char* dequeue(char* destination);
	
	char* peek();

	void print();

	Queue& operator=(const Queue* other);

};

