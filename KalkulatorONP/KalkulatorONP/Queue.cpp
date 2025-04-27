#include "Queue.h"
#include <cstring>

Queue::Queue() : front(nullptr), rear(nullptr) {}

Queue::~Queue() {
	while (!isEmpty()) {
		Node* temp = front; // Tymczasowy wska�nik do pierwszego w�z�a
		front = front->next; 
		delete temp;
	}
	rear = nullptr; 
}

bool Queue::isEmpty() {
	return front == nullptr;
}

void Queue::enqueue(char* val) {
	Node* newNode = new Node(val);
	if (isEmpty()) {
		front = rear = newNode;
	}
	else {
		rear->next = newNode;
		rear = newNode;
	}
}

char* Queue::dequeue(char* destination) {
	if (isEmpty()) {
		std::cerr << "Queue is empty, cannot dequeue element\n";
		return nullptr;
	}

	std::strcpy(destination, front->data);
	Node* temp = front->next;
	delete front;
	front = temp;
	
	if (front == nullptr) {
		rear = nullptr;
	}
	return destination;
}

char* Queue::peek() {
	if (isEmpty()) {
		std::cerr << "Queue is empty.\n";
		exit(EXIT_FAILURE);
	}
	return front->data;
}

void Queue::print()
{
	//if (isEmpty()) {
	//	std::cerr << "Queue is empty.\n";
	//	exit(EXIT_FAILURE);
	//}
	Node* currentNode = front;
	while (currentNode != nullptr) {
		std::cout << currentNode->data << " ";
		currentNode = currentNode->next;
	}
}

Queue& Queue::operator=(const Queue* other) {
	char znak[20];
	if (this == other) { // sprawdzenie samo-przypisania
		return *this;
	}

	// Najpierw usuwamy zawarto�� bie��cej kolejki
	while (!isEmpty()) {
		dequeue(znak);
	}

	// Teraz kopiujemy zawarto�� z "other" do tej kolejki, zauwa� u�ycie wska�nika
	Node* current = other->front; // zaczynamy od pocz�tku "other"

	while (current != nullptr) { // iteracja przez kolejne elementy
		this->enqueue(current->data); // dodajemy elementy do bie��cej kolejki
		current = current->next; // przechodzimy do nast�pnego w�z�a
	}

	return *this; // zwracamy referencj� do bie��cej instancji
}

