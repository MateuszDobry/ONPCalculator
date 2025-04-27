#pragma once
#include "Constants.h"

bool is_number(char c);
bool is_function(char znaki);
bool is_operator(char* znak);
int get_priority(char c[MAX_OPERAND_LENGHT]);

