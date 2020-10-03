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

class List{
    public:
        // Default Constructor
        List() : head_(NULL), size_(0){}

        // Copy Constructor
        List(List &copyList);

        // Destructor
        ~List();

        // Delete Node from List
        void deleteItem(const int dItem);

        // Insert Item to List
        void insertItem(const int dItem);

        // Check if List is Empty
        bool isEmpty() const;

        // List size
        int sizeOfList() const;

        // Print items from List
        void print() const;

        // Increment List Size
        void increment();

        // Decrement List Size
        void decrement();

        // Unsorted list
        void insertUnsortedList(int dItem);

        // Delete duplicates
        void duplicates(List& newList, List& mainList);

        // Delete middle node
        void deleteMiddleNode(List& mainList);

    private:
        // Node structure for to create a list
        typedef struct NODE{
            int item_;      // store integer data
            NODE* prev_;    // point to previous
            NODE* next_;    // point to next

            // Default Constructor
            NODE() : item_(0), prev_(NULL), next_(NULL){}
        }* NODEPTR;
        
        NODEPTR head_;
        int size_;
};