/*  ----------------------------------------------------------------- 
    File singleLL.h stores the declaration of variable(s) and 
    function(s) for the assembly of a linked list. Also includes
    constructor(s), overloaded operator(s) and class(es)/structure(s).
    ----------------------------------------------------------------- */
//
// Copyright(c) 2020 Hector Rodriguez.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//
// Created By: Hector Rodriguez
// Date: --
#include <iostream>
#include <cstddef>
#include <cstdlib>
#include <cctype>
#include <algorithm>

class SingleLL{
    public:
        // Default Constructor
        SingleLL() : head_(NULL), tail_(NULL), size_(0){}

        // Copy Constuctor: Deep copy
        SingleLL(const SingleLL& originalList);

        // Destructor
        ~SingleLL();

        // Overload Operator + 
        friend SingleLL operator+(const SingleLL& oneList, const SingleLL& secondList);

        // Insert data in sorted order
        void insertSorted(const int inputData);

        // Insert data in unsorted order
        void insertUnsorted(const int inputData);

        // Delete given data from list
        void deleteNode(const int inputData);

        // Retrieve data from List
        bool retrieve(const int findItem) const;

        // List size
        int sizeOfList() const;

        // Check if item exists
        bool insertCheck(const int item);

        // Check if List is Empty
        bool isEmpty() const; 

        // Prints the list
        void printList() const;

        // Return Kth to last term in List
        int returnKthTerm(const int nTerm) const;

        // delete middle node
        void deleteMiddleNode();

        // delete duplicates with no buffer
        SingleLL deleteDuplicates(SingleLL& nList);

        // Sum both given lists
        SingleLL sumLists(SingleLL& firstL, SingleLL& secondL, SingleLL& sumList);

        // Increment List Size
        void increment();

        // Decrement List Size
        void decrement();

        // Check if list is a palindrome
        bool isPalindrome();

    private:
        // Node structure to create a linked list
        typedef struct NODE{
            int data_;      // store integer data
            NODE* next_;    // point to next node

            // default contructor
            NODE() : data_(0), next_(NULL){}
        }* NODEPTR;

        NODEPTR head_;  // point at the begining of the List
        NODEPTR tail_;  // point at the end of the List
        int size_;      // store the size of the List
};


