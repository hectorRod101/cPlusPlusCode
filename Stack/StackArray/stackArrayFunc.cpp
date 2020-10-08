/*  ----------------------------------------------------------------- 
    File stackFunc.cpp implements the function(s), constructor(s),
    and overloaded operator(s) declared inside file stack.h.
    ----------------------------------------------------------------- */
//
// Copyright(c) 2020 Hector Rodriguez.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//
// Created By: Hector Rodriguez
// Date: --
#include "stackArray.h"

/*  ================ Parameterized Constructor ======================
    Constructor initializes the given object with the given 
    parameter.

    INPUT  -- inputData: an integer to initialize
    OUTPUT -- None
    ================================================================= */
Stack::Stack() : size_(0), maxSize_(SIZE)
{
    listArray_ = new int[SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        listArray_[i] = 0;
    }
}

void Stack::print()
{
    if(isEmpty())
    {
        std::cout << "No data in Stack, can't print.\n";
    }
    else
    {
        for (int i = stackSize() - 1; i >= 0 ; i--)
        {   
            std::cout << " [" <<  listArray_[i] << "]\n  | \n  v\n"; 
        }
        std::cout << " NULL\n";
    }
    std::cout << "Size: " << stackSize() << std::endl;
}

void Stack::pop()
{
    if(isEmpty())
    {
        std::cout << "Stack is empty, can't pop.\n";
    }
    else
    {
        listArray_[stackSize()] = 0;
        decrement();
    }
}

void Stack::push(int data)
{
    if(isFull())
    {
        std::cout << "Stack is Full, dynamically creating more space...\n\n";
        expandStack();
        listArray_[stackSize()] = data;
        increment();
    }
    else
    {
        listArray_[stackSize()] = data;
        increment();
    }
}

bool Stack::isFull()
{
    return (stackSize() == maxSize_);
}

void Stack::expandStack()
{
    maxSize_ *= 2;
    int* p = new int[maxSize_];

    for (int i = 0; i < stackSize(); i++)
    {
        p[i] = listArray_[i];
    }
    *listArray_ = *p;
}

void Stack::emptyStack()
{
    if(isEmpty())
    {
        std::cout << "Can't empty out Stack because Stack is empty.\n";
    }
    else
    {
        for (int i = stackSize() - 1; i >= 0; i--)
        {
            listArray_[i] = 0;
            decrement();
        }
        
    }
}

bool Stack::isEmpty()
{
    return (stackSize() == 0);
}

int Stack::stackSize()
{
    return size_;
}

void Stack::increment()
{
    size_ += 1;
}

void Stack::decrement()
{
    size_ -= 1;
}