/*  ----------------------------------------------------------------- 
    File singleLLFunc.cpp impelments the function(s), constructor(s),
    and overloaded operator(s) declared inside file singleLL.h.
    ----------------------------------------------------------------- */
//
// Copyright(c) 2020 Hector Rodriguez.
// Distributed under the MIT License (http://opensource.org/licenses/MIT)
//
// Created By: Hector Rodriguez
// Date: --
#include "singleLL.h"

/*  ================= Copy Constructor ====================================
    This copy contructor creates a deep copy of the given object. Copying
    every node to newly allocated object.

    INPUT  -- aList: main object to copy from
    OUTPUT -- N/A on contructor
    ======================================================================= */
SingleLL::SingleLL(const SingleLL& originalList)
{
    if(originalList.isEmpty())
    {
        return; 
    }
    else
    {
        NODEPTR startL = originalList.head_;
        NODEPTR newNode;
        head_ = new NODE;
        head_->data_ = startL->data_;
        tail_ = head_;
        startL = startL->next_;
        increment();

        while (startL)
        {
            newNode = new NODE;
            newNode->data_ = startL->data_;
            tail_->next_ = newNode;
            tail_ = newNode;
            startL = startL->next_;
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
SingleLL::~SingleLL()
{
    NODEPTR curr = head_;

    while(head_)
    {
        curr = curr->next_;
        delete head_;
        head_ = curr;
        decrement();
    }
    head_ = tail_ = NULL;
}

/*  ========================== isEmpty ==============================
    IsEmpty function checks whether any nodes are inside the List.

    INPUT  -- None
    OUTPUT -- Returns true if the List is empty, false if not empty.

    Time Complexity: O(1)
    ================================================================= */
bool SingleLL::isEmpty() const
{
    return (sizeOfList() == 0);
}

/*  ========================= sizeOfList ============================
    SizeOfList returns the current size of the List.

    INPUT  -- None
    OUTPUT -- An integer of the size.

    Time Complexity: O(1)
    ================================================================= */
int SingleLL::sizeOfList() const
{
    return size_;
}

/*  ===================== printList =================================
    PrintList displays the List, its' nodes and the size of the List.

    INPUT  -- None
    OUTPUT -- If list is empty, display empty list and size. Else, if 
              not empty display list and its' size.

    Time Complexity: Best Case  O(1) 
                     Worst Case O(n)
    ================================================================= */
void SingleLL::printList() const
{

    if(isEmpty())
    {
        std::cout << "[ NULL ]\n";
        std::cout << "Size: " << sizeOfList() << std::endl << std::endl;
    }
    else
    {
        for (NODEPTR startPtr = head_; startPtr; startPtr = startPtr->next_)
        {
            std::cout << "[ " << startPtr->data_ << " ]-->";
        }
        std::cout << tail_->next_ << std::endl;
        std::cout << "Size: " << sizeOfList() << std::endl << std::endl;
    }
}

/*  ===================== insertCheck ==============================
    InsertCheck takes the given input and checks if it exists in 
    the List.

    INPUT  -- Integer of given data.
    OUTPUT -- Returns true if integer exists in the List, else 
              returns false.

    Time Complexity: Best Case  O(1) 
                     Worst Case O(n)
    ================================================================= */
bool SingleLL::insertCheck(const int item)
{
    if(isEmpty())
    {
        return false;
    }
    else
    {
        NODEPTR start = head_;

        while (start)
        {
            if(start->data_ == item)
            {
                return true;
            }
            start = start->next_;
        }
        return false;
    }
}

/*  ===================== insertSorted ==============================
    InsertSorted takes the given input and inserts into linked list
    in ascending order.

    INPUT  -- Integer of given data.
    OUTPUT -- None.

    Time Complexity: Best Case  O(1) 
                     Worst Case O(n)
    ================================================================= */
void SingleLL::insertSorted(const int inputData)
{
    if(insertCheck(inputData))
    {
        std::cout << inputData << " already exists in the List.\n";
    }
    else
    {
        if(isEmpty())
        {
            head_ = new NODE;
            head_->data_ = inputData;
            tail_ = head_;
            increment();
        }
        else
        {
            NODEPTR curr;
            NODEPTR prev = NULL;
            curr = head_;

            while(curr && curr->data_ < inputData)
            {
                prev = curr;
                curr = curr->next_;
            }

            if(!prev)
            {
                prev = new NODE;
                prev->data_ = inputData;
                prev->next_ = head_;
                head_ = prev;
                increment();
            }
            else if(!curr)
            {
                curr = new NODE;
                curr->data_ = inputData;
                prev->next_ = curr;
                tail_ = curr;
                increment();
            }
            else
            {
                NODEPTR newPtr = new NODE;
                newPtr->data_ = inputData;
                prev->next_ = newPtr;
                newPtr->next_ = curr;
                increment();
            }
        }
    }
}

/*  ===================== deleteDuplicates =============================
    DeleteDuplicates deletes all the duplicates in the List. Returning
    a list with no duplicates.

    INPUT  -- Original object list.
    OUTPUT -- Returns object with no duplicates.

    Time Complexity: Best Case  O(1) 
                     Worst Case O(n^2)
    ==================================================================== */
SingleLL SingleLL::deleteDuplicates(SingleLL& nList)
{
    if(isEmpty())
    {
        std::cout << "Can't delete duplicates because List is empty.\n";
    }
    else
    {
        NODEPTR mStart = head_;

        while(mStart)
        {
            int item;
            item = mStart->data_;

             if(nList.isEmpty())
            {
                nList.head_ = new NODE;
                nList.head_->data_= item;
                nList.increment();
            }
            else
            {
                NODEPTR newNode = nList.head_;
                
                while (newNode && newNode->data_ != item)
                {
                    newNode = newNode->next_;
                }
                
                if(!newNode)
                {
                    newNode = new NODE;
                    newNode->data_ = item;
                    newNode->next_ = nList.head_;
                    nList.head_ = newNode;
                    nList.increment();
                }
            }
            mStart = mStart->next_;
        }
    }
    return nList;
}

/*  ===================== retrieve =============================
    Retreive takes the item given and checks whether it exists
    in the list and retrieves it.

    INPUT  -- Integer for item.
    OUTPUT -- Returns true if item is in the list, else it 
              returns false.

    Time Complexity: Best Case  O(1) 
                     Worst Case O(n)
    ============================================================ */
bool SingleLL::retrieve(const int findItem) const
{
    if(isEmpty())
    {
        std::cout << "List is empty, can't retrieve data.\n";
        return false;
    }
    else
    {
       for (NODEPTR start = head_; start; start = start->next_)
       {
           if(start->data_ == findItem)
           {
               return true;
           }
       }
       return false;
    }
}


/*  ================== insertUnsorted ==========================
    InsertUnsorted enters items into the List. There can be
    duplicates, negatives, and in any order.

    INPUT  -- Integer for item.
    OUTPUT -- None

    Time Complexity: Best Case  O(1) 
                     Worst Case O(1)
    ============================================================ */
void SingleLL::insertUnsorted(const int inputData)
{
    if(isEmpty())
    {
        head_ = new NODE;
        head_->data_ = inputData;
        tail_ = head_;
        increment();
    }
    else
    {
        NODEPTR newNode = new NODE;
        newNode->data_ = inputData;
        newNode->next_ = head_;
        head_ = newNode;
        increment();
    }
}

/*  =================== overload + ============================
    Operator + 
    ============================================================ */
SingleLL operator+(const SingleLL& oneList, const SingleLL& secondList)
{
    SingleLL totalList;

    return totalList;
}

/*  ================== returnKthTerm ==========================
    ReturnKthTerm returns the Kth to last term in the List.

    INPUT  -- Integer for Kth to last index.
    OUTPUT -- Returns an integer for the index found, else
              returns 0 if index does not exist.

    Time Complexity: Best Case  O(1) 
                     Worst Case O(n)
    ============================================================ */
int SingleLL::returnKthTerm(const int nTerm) const
{
    NODEPTR start = head_;
    if(isEmpty() || nTerm > sizeOfList())
    {
        std::cout << "There is no " << nTerm << " to last element in the List.\n";
        return 0;
    }
    else
    {
        int kthTerm = sizeOfList() - nTerm;

        for(int i = 1; i < kthTerm; i++, start = start->next_);
        return start->data_;
    }
}

/*  ================== deleteMiddleNode ========================
    DeleteMiddleNode deletes the middle node of the List.

    INPUT  -- None
    OUTPUT -- Outputs to screen the middle being deleted from 
              the List.

    Time Complexity: Best Case  O(1) 
                     Worst Case O(n)
    ============================================================ */
void SingleLL::deleteMiddleNode()
{
    if(sizeOfList() < 2)
    {
        std::cout << "There is no middle node to delete.\n";
    }
    else
    {
        int mid = sizeOfList() / 2;

        if(0 != (mid % 2))
        {
            mid -= 1;
        }
        std::cout << mid << std::endl;

        NODEPTR start = head_;
        NODEPTR prev;

        for (int i = 0; i < mid; i++, prev = start, start = start->next_);

        prev->next_ = start->next_;

        std::cout << "Deleting middle node: " << start->data_ << std::endl;
        delete start;
        start = NULL;
        decrement();
    }
}

/*  ===================== increment =================================
    Increment increases the size of how many nodes are in the list.

    INPUT  -- Integer of given data.
    OUTPUT -- None.

    Time Complexity: O(1)
    ================================================================= */
void SingleLL::increment()
{
    size_ += 1;
}

/*  ===================== decrement ================================
    Decrement decreases the size of how many nodes are in the list.

    INPUT  -- Integer of given data.
    OUTPUT -- None.

    Time Complexity: O(1)
    ================================================================= */
void SingleLL::decrement()
{
    size_ -= 1;
}

/*  ====================== sumLists =================================
    SumLists sums two objects of the same length. Starting from the
    head_ node is the n*10^0, n*10^1, n*10^2, ..... n*10^i.

    INPUT  -- firstL = [1]->[2]->[3]->NULL ; 321
              secondL = [3]->[7]->[2]->NULL; 273
    OUTPUT -- Return the sum of both lists into a list.
              Sum: [4]->[9]->[5]->NULL ; 594

    Time Complexity: Best Case  O(1) 
                     Worst Case O(n)
    ================================================================= */
SingleLL SingleLL::sumLists(SingleLL& firstL, SingleLL& secondL, SingleLL& sumList)
{
    if(firstL.sizeOfList() != secondL.sizeOfList())
    {
        std::cout << "Can't sum Lists because they are not the same size.\n";
        return sumList;
    }
    else
    {
        int remainder = 0;
        int input;
        NODEPTR sumH;
        NODEPTR firstH = firstL.head_;
        NODEPTR secondH = secondL.head_;

        for (int i = 0; i < firstL.sizeOfList(); i++, firstH= firstH->next_, secondH = secondH->next_)
        {
            if(remainder == 0)
            {
                input = firstH->data_ + secondH->data_;
                remainder = input / 10;
                input = input % 10;   

                if(sumList.isEmpty())
                {
                    sumList.head_ = new NODE;
                    sumList.head_->data_ = input;
                    sumList.tail_ = sumList.head_;
                    sumList.increment();
                }
                else
                {
                    sumH = new NODE;
                    sumH->data_ = input;
                    sumList.tail_->next_ = sumH;
                    sumList.tail_ = sumH;
                    sumList.increment();
                }
            }
            else
            {
                input = firstH->data_ + secondH->data_ + remainder;
                remainder = input / 10;
                input = input % 10;

                if(sumList.isEmpty())
                {
                    sumList.head_ = new NODE;
                    sumList.head_->data_ = input;
                    sumList.increment();
                }
                else
                {
                    sumH = new NODE;
                    sumH->data_ = input;
                    sumList.tail_->next_ = sumH;
                    sumList.tail_ = sumH;
                    sumList.increment();
                }
            }
        }
    return sumList;       
    }
}

/*  ====================== isPalindrome ==============================
    IsPalindrome checks whether the given List is a palindrome.

    INPUT  -- None
    OUTPUT -- Returns true if a palindrome, else it returns false.

    Time Complexity: O(n)
    ================================================================= */
bool SingleLL::isPalindrome()
{
    NODEPTR newNode;
    NODEPTR newHead = newNode;
    NODEPTR start = head_;
    int mid = sizeOfList() / 2;

    

    if(0 == sizeOfList() % 2)
    {
        for (int i = 0; i < mid; i++, start = start->next_)
        {
            newNode = new NODE;
            newNode->data_ = start->data_;
            newNode->next_ = newHead;
            newHead = newNode;
        }

        while(start)
        {
            if(start->data_ != newHead->data_)
            {
                return false;
            }
            start = start->next_;
            newHead = newHead->next_;
        }
    }
    else
    {
        for (int i = 0; i < mid; i++, start = start->next_)
        {
            newNode = new NODE;
            newNode->data_ = start->data_;
            newNode->next_ = newHead;
            newHead = newNode;
        }

        start = start->next_;

        while(start)
        {
            if(start->data_ != newHead->data_)
            {
                return false;
            }
            start = start->next_;
            newHead = newHead->next_;
        }
    }
    return true;
}