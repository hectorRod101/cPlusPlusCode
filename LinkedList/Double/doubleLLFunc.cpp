/*  ----------------------------------------------------------------- 
    File doubleLLFunc.cpp impelments the function(s), constructor(s),
    and overloaded operator(s) declared inside file doubleLL.h.
    ----------------------------------------------------------------- */
//
// Copyright(c) 2020 Hector Rodriguez.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//
// Created By: Hector Rodriguez
// Date: --
#include "doubleLL.h"

/*  ======================== Copy Constructor ===========================
    This copy contructor creates a deep copy of the given object. Copying
    every node to newly allocated object.

    INPUT  -- copyList: main object to copy from
    OUTPUT -- N/A on contructor
    ===================================================================== */
List::List(List& copyList)
{
    if(copyList.isEmpty())
    {
        std::cout << "List that needs to be copied is empty. No list to copy.\n";
    }
    else
    {
        NODEPTR copyStart = copyList.head_;
        head_ = new NODE;
        head_->item_ = copyStart->item_;
        increment();
        NODEPTR newStart = head_;

        while(copyStart)
        {
            copyStart = copyStart->next_;
            NODEPTR newNode = new NODE;
            newNode->item_ = copyStart->item_;
            newStart->next_ = newNode;
            newNode->prev_ = newStart;
            newStart = newStart->next_;
            increment();
        }
    }
}

/*  ================= Destructor ====================================
    This destructor deallocates the dynamic data created by the 
    program.

    INPUT  -- NONE
    OUTPUT -- NONE
    ================================================================= */
List::~List()
{
    if(isEmpty())
    {
        std::cout << "List is already empty and cannot be deallocated.\n";
    }
    else
    {
        NODEPTR start = head_;

        while(head_)
        {
            start = start->next_;
            delete head_;
            head_ = start;
            decrement();
        }
    }
}

/*  ====================== deleteItem ===============================
    DeleteItem deletes the node given by the user.

    INPUT  -- dItem: an integer to find in the list
    OUTPUT -- None

    Run Time Complexity: Best Case O(1)
                         Worst Case O(n)
    ================================================================= */
void List::deleteItem(const int dItem)
{
    if(isEmpty())
    {
        std::cout << dItem << " cannot be deleted from the List because List is empty.\n";
    }
    else
    {
        NODEPTR start = head_;
        while(start->item_ < dItem)
        {
            start = start->next_;
        }

        if(start->item_ == dItem)
        {
            if(start == head_)
            {
                head_ = head_->next_;
                head_->prev_ = NULL;
                delete start;
                start = NULL;
                decrement();
            }
            else if(start->next_ == NULL)
            {
                NODEPTR prev = start->prev_;
                prev->next_ = NULL;
                start->prev_ = NULL;
                delete start;
                start = NULL;
                decrement();
            }
            else
            {
                start->prev_->next_ = start->next_;
                start->next_->prev_ = start->prev_;
                start->next_ = NULL;
                start->next_ = NULL;
                delete start;
                start = NULL;
                decrement();
            }
        }
        else
        {
            std::cout << "Item doesn't exist in the List.\n";
        }
    }
    
}

/*  ========================== insertItem ===========================
    InsertItem inserts a node to the list.

    INPUT  -- dItem: an integer to insert into the list
    OUTPUT -- None

    Run Time Complexity: Best Case O(1)
                         Worst Case O(n)
    ================================================================= */
void List::insertItem(const int dItem)
{
    if(isEmpty())
    {
        head_ = new NODE;
        head_->item_ = dItem;
        increment();
    }
    else
    {
       NODEPTR start = head_;
       NODEPTR before = new NODE;

       while(start->item_ < dItem && start->next_ != NULL)
       {
           before = start;
           start = start->next_;
       }

       if(start->item_ == dItem || before->item_ == dItem)
       {
           std::cout << dItem << " already exists in the List, can't be added.\n\n";
       }
       else
       {
           if(before->next_ == NULL && dItem < start->item_)
           {
               NODEPTR newNode = new NODE;
               newNode->item_ = dItem;
               newNode->next_ = start;
               start->prev_ = newNode;
               head_ = newNode;
               increment();
           }
           else if(start->next_ == NULL && dItem > start->item_)
           {
               NODEPTR newNode = new NODE;
               newNode->item_ = dItem;
               start->next_ = newNode;
               newNode->prev_ = start;
               increment();
           }
           else
           {
               NODEPTR newNode = new NODE;
               newNode->item_ = dItem;
               before->next_ = newNode;
               newNode->prev_ = before;
               newNode->next_ = start;
               start->prev_ = newNode;
               increment();
           }
       }
    }
}

/*  ======================= isEmpty =================================
    IsEmpty returns true or false whether the list is empty.

    INPUT  -- None
    OUTPUT -- True if list is empty, false if not empty.

    Run Time Complexity: O(1)
    ================================================================= */
bool List::isEmpty() const
{
    return (sizeOfList() == 0);
}

/*  ======================= sizeOfList ==============================
    SizeOfList returns the size of the list. 

    INPUT  -- none
    OUTPUT -- integer of the size of the list

    Run Time Complexity: O(1)
    ================================================================= */
int List::sizeOfList() const
{
    return size_;
}

/*  ========================= print ================================
    Print prints the list and the size of the list.

    INPUT  -- NONE
    OUTPUT -- Display list and size of list

    Run Time Complexity: O(n)
    ================================================================= */
void List::print() const
{
    NODEPTR start = head_;

    while (start)
    {
        std::cout << " <--[ " << start->prev_ << std::setw(15) << 
        "|" << start->item_ << "|" << std::setw(20) << start->next_ << " ]---> " << std::endl;
        start = start->next_;
    }
    std::cout << "Size: " << sizeOfList() << std::endl << std::endl;
}

/*  ========================= increment =============================
    Increment, increases the variable size.

    INPUT  -- None
    OUTPUT -- None

    Run Time Complexity: O(1)
    ================================================================= */
void List::increment()
{
    size_ += 1;
}

/*  ========================= decrement =============================
    Decrement, decreases the variable size.

    INPUT  -- None
    OUTPUT -- None

    Run Time Complexity: O(n)
    ================================================================= */
void List::decrement()
{
    size_ -= 1;
}

/*  ===================== insertUnsortedList ========================
    InsertUnsortedList inserts into the list at the beginning. Not 
    checking whether the given item should be sorted.

    INPUT  -- dItem: Integer to insert.
    OUTPUT -- None

    Run Time Complexity: O(1)
    ================================================================= */
void List::insertUnsortedList(int dItem)
{
    if(isEmpty())
    {
        head_ = new NODE;
        head_->item_ = dItem;
        increment();
    }
    else
    {
        NODEPTR newNode = new NODE;
        newNode->item_ = dItem;
        newNode->next_ = head_;
        head_->prev_ = newNode;
        head_ = newNode;
        increment();
    }
}

/*  ========================= duplicates ===========================
    Duplicates takes in the original list and deletes duplicates
    onto a new list.

    INPUT  -- newList:  empty list to store nonduplicates
              mainList: list containing data
    OUTPUT -- None

    Run Time Complexity: O(n)
    ================================================================= */
void List::duplicates(List& newList, List& mainList)
{
    NODEPTR oldList = mainList.head_;
    NODEPTR newNode;

    while (oldList)
    {
        if(newList.isEmpty())
        {
            newList.head_ = new NODE;
            newList.head_->item_ = oldList->item_;
            newList.increment();
        }
        else
        {
            bool checkNode = true;
            NODEPTR startNew = newList.head_;
            newNode = new NODE;
            newNode->item_ = oldList->item_;

            for (; startNew->next_ != NULL; startNew = startNew->next_)
            {
                if(startNew->item_ == newNode->item_)
                {
                    checkNode = false;
                }
            }

             if(checkNode && startNew->item_ != newNode->item_)
             {
                 startNew->next_ = newNode;
                 newNode->prev_ = startNew;
                 newList.increment();
             }
        }
        oldList = oldList->next_;
    }
}

