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
#include "stack.h"

/*  ================ Parameterized Constructor ======================
    Constructor initializes the given object with the given 
    parameter.

    INPUT  -- inputData: an integer to initialize
    OUTPUT -- None
    ================================================================= */
Stack::Stack(int inputData)
{
    if(isEmpty())
    {
        head_ = new NODE;
        head_->data_ = inputData;
        minimum(inputData);
        increment();
    }
}

/*  ========================= pop ==================================
    Pop deletes the first item on top of the Stack.

    INPUT  -- None
    OUTPUT -- None

    Run Time Complexity: O(1)
    ================================================================= */
void Stack::pop()
{
    if(isEmpty())
    {
        std::cout << "Can't pop from the Stack because it is empty.\n";
    }
    else
    {
        NODEPTR start = head_;
        head_ = head_->next_;
        start->next_ = NULL;
        delete start;
        start = NULL;
        decrement();
    }
}

/*  ========================= push ==================================
    Push adds the given parameter on top of the Stack.

    INPUT  -- dItem: an integer to add to stack
    OUTPUT -- None

    Run Time Complexity: O(1)
    ================================================================= */
void Stack::push(int item)
{
    if(isEmpty())
    {
        head_ = new NODE;
        head_->data_ = item;
        minimum(item);
        increment();
    }
    else
    {
        NODEPTR newNode;
        newNode = new NODE;
        newNode->data_ = item;
        newNode->next_ = head_;
        head_ = newNode;
        minimum(item);
        increment();
    }
}

/*  ======================== print =================================
    Print, prints all stack data from the object call.

    INPUT  -- None
    OUTPUT -- None

    Run Time Complexity: Best Case O(1)
                         Worst Case O(n)
    ================================================================= */
void Stack::print()
{
    cout << "==================== Stack Data ==================\n";

    if(isEmpty())
    {
        std::cout << "Nothing to print, stack is empty.\n";
    }
    else
    {
        NODEPTR start = head_;

        while (start)
        {
            std::cout << "| " << start->data_ << " | " << " |\n" << " |\n" << " V\n";
            start = start->next_;
        }
        std::cout << " NULL\n\n";
    }
}

/*  ========================= peek =================================
    Peek, checks what lays on to top of the Stack.

    INPUT  -- None
    OUTPUT -- Integer of top item.

    Run Time Complexity: O(1)
    ================================================================= */
int Stack::peek()
{
    if(isEmpty())
    {
        std::cout << "Nothing to peek, Stack is empty.\n";
        return 0;
    }  
    return head_->data_;
}

/*  ======================== isEmpty ===============================
    IsEmpty, checks if Stack is empty. 

    INPUT  -- None
    OUTPUT -- Returns true if Stack is empty, else returns false.

    Run Time Complexity: O(1)
    ================================================================= */
bool Stack::isEmpty()
{
    return (sizeOfStack() == 0);
}

/*  ====================== sizeOfStack ==============================
    SizeOfStack, returns the Stack size.

    INPUT  -- None
    OUTPUT -- Returns stack size as an integer.

    Run Time Complexity: O(1)
    ================================================================= */
int Stack::sizeOfStack()
{
    return size_;
}

/*  ====================== increment ================================
    Increment, increases the size of the Stack.

    INPUT  -- None
    OUTPUT -- None

    Run Time Complexity: O(1)
    ================================================================= */
void Stack::increment()
{
    size_ += 1;
}

/*  ====================== decrement ===============================
    Decrements, decreases the size of the Stack.

    INPUT  -- None
    OUTPUT -- None

    Run Time Complexity: O(1)
    ================================================================= */
void Stack::decrement()
{
    size_ -= 1;
}

/*  ======================== minimum ===============================
    Minimum, checks whether the given data is the new minimum inside
    of the Stack.

    INPUT  -- item: integer to check if it's minimum
    OUTPUT -- None

    Run Time Complexity: O(1)
    ================================================================= */
void Stack::minimum(int item)
{
    if(isEmpty())
    {
        minItem_ = item;
    }
    else if(item < minItem_)
    {
        minItem_ = item;
    }
}

/*  ======================= printMin ================================
    PrintMin, prints the current minimum data inside of the Stack.

    INPUT  -- None
    OUTPUT -- None

    Run Time Complexity: O(1)
    ================================================================= */
void Stack::printMin()
{
    if(isEmpty())
    {
        std::cout << "Stack is empty, no minimum to print.\n";
    }
    else
    {
        std::cout << "Minimum: " << minItem_ << std::endl;
    }
}

/*  ======================== popAt =================================
    PopAt, will pop stack until the given index.

    INPUT  -- index: pop up to given index
    OUTPUT -- None

    Run Time Complexity: Best Case O(1)
                         Worst Case O(n)
    ================================================================= */
void Stack::popAt(int index)
{
    if(isEmpty())
    {
        std::cout << "Stack is empty, can't pop items.\n";
    }
    else if(index - 1 > sizeOfStack() || index < 0)
    {
        std::cout << "Can't pop at index " << index << " because it doesn't fall in Stack limits.\n";
    }
    else
    {
        int many = sizeOfStack() - (index - 1);

        for (int i = 0; i < many; i++)
        {
            pop();
        }
        
    }
}

/*  ======================== mStack ================================

    INPUT  -- mStack
    OUTPUT -- None
    ================================================================= */
Stack Stack::sort(Stack& mStack)
{
    Stack leftStack;
    Stack rightStack;
    int item;

    while (!mStack.isEmpty())
    {
        item = mStack.peek();
        mStack.pop();

        if(item > leftStack.peek() || leftStack.isEmpty())
        {
            leftStack.push(item);
        }
        else
        {
            rightStack.push(item);
        }
    }
    leftStack.print();
    rightStack.print();
    return mStack;
}