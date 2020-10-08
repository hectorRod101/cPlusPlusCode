/* This program shows the implementation and the use of the ADT
    Stack that uses an array. Implementing the basic functions 
    of the ADT; Create List, Delete List, Insert into List, 
    Delete Item from List, Retrieve Item from List, Size of List, 
    and Check if List is Empty */

// Created By: Hector Rodriguez
// Date: --
#include "stackArray.h"
using namespace std;

int main()
{
    Stack st1;
    st1.push(2);
    st1.push(4);
    st1.push(5);
    st1.push(3);
    st1.push(7);
    st1.push(12);
    st1.print();

    st1.emptyStack();
    st1.print();

    return 0;
}