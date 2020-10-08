/*  ----------------------------------------------------------------- 
    File doubleLL.h stores the declaration of variable(s) and 
    function(s) for the assembly of a double linked list. Also 
    includes constructor(s), overloaded operator(s) and class(es)/
    structure(s).
    ----------------------------------------------------------------- */
//
// Copyright(c) 2020 Hector Rodriguez.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//
// Created By: Hector Rodriguez
// Date: --
#include <cctype>
#include <cstddef>
#include <cstdlib>
#include <algorithm>
#include <iomanip>
#include <iostream>
#define SIZE 5

class Stack{
    public:
        // default constructor
        Stack();

        // 
        bool isEmpty();

        //
        void print();

        //
        void doubleSize();

        //
        void push(int data);

        //
        void pop();

        void emptyStack();

        int stackSize();

        void increment();

        void decrement();

        bool isFull();

        void expandStack();
 
    private:
        // Node structure for to create a list
        int* listArray_;
        int size_;
        int maxSize_;
};