#pragma once
#include "Constants.h"

struct Node {
    char data[MAX_OPERAND_LENGHT];
    Node* next;

    Node(char* val) : next(nullptr) {
        std::strcpy(data, val);
    }


};


struct IntNode {
    int data;
    IntNode* next;

    IntNode(int args) : data(args), next(nullptr){}
};