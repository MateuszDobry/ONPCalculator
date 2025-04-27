#include "ONPCounter.h"

void ONPCounter::fillQueue(Queue* Kolejka)
{
    this->kolejka = Kolejka;
}

int ONPCounter::count() 
{
    flag = true;
    char element[20];
    while (!kolejka.isEmpty() && flag) {
        if (is_number(kolejka.peek()[0])) {
            char element[20];
            int number = atoi(strcpy(element, kolejka.dequeue(element)));
            stos.push(number);
        }
        else if (is_operator(kolejka.peek())) {
            std::cout << kolejka.peek() << " ";
            stos.print();
            std::cout << std::endl;
            char* operand = kolejka.dequeue(element);
            int a = stos.pop();
            int b = stos.pop();
            if (operand[0] == '+') {
                stos.push(a + b);
            }
            else if (operand[0] == '-') {
                stos.push(b - a);
            }
            else if (operand[0] == '*') {
                stos.push(a * b);
            }
            else {
                if (a == 0)
                {
                    std::cout << "ERROR";
                    std::cout << '\n';
                    flag = false;
                    return 1; 
                }
                else {
                    stos.push(b / a);
                }
            }

        }
        else if (is_function(kolejka.peek()[0])) {
            if (kolejka.peek()[0] == 'M') {
                if (kolejka.peek()[1] == 'I') {
                    char* znak = kolejka.dequeue(element);
                    char element[20];
                    strcpy(element, znak);
                    int number = atoi(element + 3);
                    std::cout << znak << " ";
                    stos.print();
                    std::cout << '\n';
                    int min;
                    min = stos.pop();
                    for (int i = 0; i < number - 1; i++) {
                        if (stos.peek() < min) {
                            min = stos.pop();
                        }
                        else {
                            stos.pop();
                        }
                    }
                    stos.push(min);
                }
                else {
                    char* znak = kolejka.dequeue(element);
                    char element[20];
                    strcpy(element, znak);
                    int number = atoi(element + 3);
                    std::cout << znak << " ";
                    stos.print();
                    std::cout << '\n';
                    int max;
                    max = stos.pop();
                    for (int i = 0; i < number - 1; i++) {
                        if (stos.peek() > max) {
                            max = stos.pop();
                        }
                        else {
                            stos.pop();
                        }
                    }
                    stos.push(max);
                }

            }
            else if (kolejka.peek()[0] == 'N') {
                std::cout <<kolejka.dequeue(element) << " ";
                stos.print();
                std::cout << "\n";
                stos.push(stos.pop() * (-1));
            }
            else if (kolejka.peek()[0] == 'I') {
                std::cout << kolejka.dequeue(element) << " ";
                stos.print();
                std::cout << "\n";
                int a = stos.pop();
                int b = stos.pop();
                int c = stos.pop();
                if (c > 0) {
                    stos.push(b);
                }
                else {
                    stos.push(a);
                }
            }
        }
    }
 
    return stos.pop();
}

void ONPCounter::print()
{
    kolejka.print();
}

bool ONPCounter::is_flag()
{
        return flag;
}



bool ONPCounter::isInputEmpty()
{
    return kolejka.isEmpty();
}
