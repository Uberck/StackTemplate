//Christos Kokkalis 2020
//test.cpp file

#include <iostream>

#include "stack.h"

using namespace std;

int main()

{

    Stack < int > s;

    for (int i = 1; i <= 10; i++)

        s.push(i);

    cout << "Display the stack by calling display" << endl;

    s.display();

    cout << "Display the stack by calling top and pop." << endl;

    for (int i = 0; i < 10; i++) {

        cout << s.top() << endl;

        s.pop();

    }

    if (s.empty())

        cout << "Stack is empty\n";

    return 0;

}