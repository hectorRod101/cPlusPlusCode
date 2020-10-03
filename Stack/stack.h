/*  ----------------------------------------------------------------- 
    File stack.h stores the declaration of variable(s) and 
    function(s) for the assembly of a stack. Also includes 
    constructor(s), overloaded operator(s) and class(es)/structure(s).
    ----------------------------------------------------------------- */
//
// Copyright(c) 2020 Hector Rodriguez.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//
// Created By: Hector Rodriguez
// Date: --
#define SIZE 20
#include <iostream>
using namespace std;

class Stack
{
    public:
        // Default Constructor
        Stack() : size_(0), minItem_(0), head_(NULL){};

        // Parameterized Contructor
        Stack(int inputData);

        // Sort unorganzied Stack
        Stack sort(Stack& mStack);

        // Print Stack
        void print();

        // Pop from Stack
        void pop();

        // Pop until index reached
        void popAt(int index);

        // Push to Stack
        void push(int item);

        // Check if Stack is Empty
        bool isEmpty();

        // Increment Size of Stack
        void increment();

        // Decrement Size of Stack
        void decrement();
        
        // Check first item on Stack
        int peek();

        // Minimum item in Stack
        void minimum(int item);

        // Print minimum
        void printMin();

        // Returns the size of the Stack
        int sizeOfStack();
    private:
        // Node structure to create a stack
        typedef struct NODE{
            int data_;      // store integer data
            NODE* next_;    // point to next node in stack

            // Default constructor
            NODE() : data_(0), next_(NULL){}
        }* NODEPTR;
        
        int size_;
        int minItem_;
        NODEPTR head_;
};