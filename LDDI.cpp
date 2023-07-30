/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Linear DataStruture Dynamic Implementation
/////////////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
using namespace std;

/////////////////////////////////////////////////////////////////////////////////////////////////////////
// Node Creation for Singly Linked lists
/////////////////////////////////////////////////////////////////////////////////////////////////////////

typedef class node1
{
public:
    int data;
    struct node1 *next;

    node1()
    {
        data = 0;
        next = NULL;
    }

    node1(int value)
    {
        data = value;
        next = NULL;
    }
} SNODE, *SPNODE;

///////////////////////////////////////////////////////////////////////////////////////////////////////
// Node Creation for Doubly Linked List
//////////////////////////////////////////////////////////////////////////////////////////////////////

typedef class node2
{
public:
    int data;
    struct node2 *next;
    struct node2 *prev;

    node2()
    {
        data = 0;
        next = NULL;
        prev = NULL;
    }
    node2(int value)
    {
        data = value;
        next = NULL;
        prev = NULL;
    }
} DNODE, *DPNODE;

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Linkedlist template creation for all 32 Functions
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

class LinkedList
{
public:
    SPNODE First;
    DPNODE First1;
    int iCount;

public:
    LinkedList()
    {
        First = NULL;
        First1 = NULL;
        iCount = 0;
    }
    virtual void InsertFirst(int no) = 0;
    virtual void InsertLast(int no) = 0;
    virtual void InsertAtPos(int no, int pos) = 0;
    virtual void DeleteFirst() = 0;
    virtual void DeleteLast() = 0;
    virtual void DeleteAtPos(int pos) = 0;

    int Count()
    {
        return iCount;
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Singly Linear Linked List
//////////////////////////////////////////////////////////////////////////////////////////////////////

class SinglyLinearLL : public LinkedList
{
public:
    //////////////////////////////////////////////////////////////////////
    // Deletion of Linked List
    //////////////////////////////////////////////////////////////////////

    ~SinglyLinearLL()
    {
        SPNODE temp = First;

        while (First != NULL)
        {
            temp = First;
            First = First->next;
            delete temp;
            iCount--;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert First Function
    ///////////////////////////////////////////////////////////////////////

    void InsertFirst(int no)
    {
        SPNODE newn = new SNODE(no);

        if (First == NULL)
        {
            First = newn;
        }
        else
        {
            newn->next = First;
            First = newn;
        }
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert Last Function
    ///////////////////////////////////////////////////////////////////////

    void InsertLast(int no)
    {
        SPNODE newn = new SNODE(no);
        SPNODE temp = First;
        if (First == NULL)
        {
            First = newn;
        }
        else
        {
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert At Position Function
    ///////////////////////////////////////////////////////////////////////

    void InsertAtPos(int no, int pos)
    {

        if ((pos < 1) || (pos > iCount + 1))
        {
            cout << "Invalid Position";
            return;
        }
        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            SPNODE newn = new SNODE(no);
            SPNODE temp = First;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }
            newn->next = temp->next;
            temp->next = newn;
            iCount++;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Delete First Function
    ///////////////////////////////////////////////////////////////////////

    void DeleteFirst()
    {
        SPNODE temp = First;

        if (First == NULL)
        {
            cout << "Singly Linear Linked List is empty"
                 << "\n";
            return;
        }
        else if (First->next == NULL)
        {
            delete First;
            First = NULL;
        }
        else
        {
            First = First->next;
            delete temp;
        }
        iCount--;
    }

    ///////////////////////////////////////////////////////////////////////
    // Delete Last Function
    ///////////////////////////////////////////////////////////////////////

    void DeleteLast()
    {
        if (First == NULL)
        {
            cout << "Singly Linear Linked List is empty"
                 << "\n";
            return;
        }
        else if (First->next == NULL)
        {
            delete First;
            First = NULL;
        }
        else
        {
            SPNODE temp = First;

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        iCount--;
    }

    ///////////////////////////////////////////////////////////////////////
    // Delete At Position Function
    ///////////////////////////////////////////////////////////////////////

    void DeleteAtPos(int pos)
    {

        if ((pos < 1) || (pos > iCount))
        {
            cout << "Invalid Position";
            return;
        }
        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            SPNODE temp = First;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }
            SPNODE tempX = temp->next;
            temp->next = temp->next->next;
            delete tempX;
            iCount--;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Display Function
    ///////////////////////////////////////////////////////////////////////

    void DisplaySLLL()
    {
        if (First != NULL)
        {
            cout << "Elements of Linked List are : ";
            SPNODE temp = First;
            while (temp != NULL)
            {
                cout << " | " << temp->data << " | -> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
        else
        {
            cout << "Singly Linear Linked List is empty"
                 << "\n";
        }
    }
};

//////////////////////////////////////////////////////////////////////////////////////////////////////
// Singly Circular Linked List
//////////////////////////////////////////////////////////////////////////////////////////////////////

class SinglyCircularLL : public LinkedList
{
private:
    SPNODE Last;

public:
    SinglyCircularLL()
    {
        Last = NULL;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Deletion of Linked List
    ///////////////////////////////////////////////////////////////////////////

    ~SinglyCircularLL()
    {
        if (First == Last)
        {
            delete First;
            First = NULL;
            Last = NULL;
            iCount--;
        }
        else
        {
            do
            {
                First = First->next;
                delete Last->next;
                iCount--;
                Last->next = First;
            } while (First != Last);
            delete First;
            iCount--;
            First = NULL;
            Last = NULL;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert First Function
    ///////////////////////////////////////////////////////////////////////

    void InsertFirst(int no)
    {
        SPNODE newn = new SNODE(no);

        if ((First == NULL) && (Last == NULL))
        {
            First = newn;
            Last = newn;
        }
        else
        {
            newn->next = First;
            First = newn;
        }
        Last->next = First;
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert Last Function
    ///////////////////////////////////////////////////////////////////////

    void InsertLast(int no)
    {
        SPNODE newn = new SNODE(no);

        if ((First == NULL) && (Last == NULL))
        {
            First = newn;
            Last = newn;
        }
        else
        {
            Last->next = newn;
            Last = newn;
        }
        Last->next = First;
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert At Position Function
    ///////////////////////////////////////////////////////////////////////

    void InsertAtPos(int no, int pos)
    {
        if ((pos < 1) || (pos > iCount + 1))
        {
            cout << "Invalid Position"
                 << "\n";
            return;
        }
        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            SPNODE temp = First;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }

            SPNODE newn = new SNODE(no);

            newn->next = temp->next;
            temp->next = newn;
            iCount++;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Delete First Function
    ///////////////////////////////////////////////////////////////////////

    void DeleteFirst()
    {
        if ((First == NULL) || (Last == NULL))
        {
            cout << "Singly Circular Linked List is empty"
                 << "\n";
            return;
        }
        else if (First == Last)
        {
            delete First;
            First = NULL;
            Last = NULL;
        }
        else
        {
            First = First->next;
            delete Last->next;
            Last->next = First;
        }
        iCount--;
    }

    ///////////////////////////////////////////////////////////////////////
    // Delete Last Function
    ///////////////////////////////////////////////////////////////////////

    void DeleteLast()
    {
        if ((First == NULL) || (Last == NULL))
        {
            cout << "Singly Circular Linked List is empty"
                 << "\n";
            return;
        }
        else if (First == Last)
        {
            delete First;
            First = NULL;
            Last = NULL;
        }
        else
        {
            SPNODE temp = First;

            while (temp->next != Last)
            {
                temp = temp->next;
            }
            delete temp->next;
            Last = temp;
            Last->next = First;
        }
        iCount--;
    }

    ///////////////////////////////////////////////////////////////////////
    // Delete At Position Function
    ///////////////////////////////////////////////////////////////////////

    void DeleteAtPos(int pos)
    {
        if ((pos < 1) || (pos > iCount))
        {
            cout << "Invalid Position"
                 << "\n";
            return;
        }
        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            SPNODE temp = First;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }
            SPNODE tempX = temp->next;

            temp->next = temp->next->next;
            delete tempX;
            iCount--;
        }
    }

    ///////////////////////////////////////////////////////////////////////
    // Display Function
    ///////////////////////////////////////////////////////////////////////

    void DisplaySCLL()
    {
        SPNODE temp = First;

        if ((First != NULL) && (Last != NULL))
        {
            do
            {
                cout << " | " << temp->data << " | -> ";
                temp = temp->next;
            } while (temp != Last->next);
            cout<<"\n";
        }
        else
        {
            cout << "Singly Circular Linked list is empty"
                 << "\n";
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////////////
// Doubly Linear Linked List
///////////////////////////////////////////////////////////////////////////////////////////

class DoublyLinearLL : public LinkedList
{
public:
    ///////////////////////////////////////////////////////////////////////
    // Deletion of Linked List
    ///////////////////////////////////////////////////////////////////////

    ~DoublyLinearLL()
    {
        if (First1->next == NULL)
        {
            delete First1;
            First1 = NULL;
            iCount--;
        }
    else
    {
        while (First1->next != NULL)
        {
            First1 = First1->next;
            delete First1->prev;
            iCount--;
            First1->prev = NULL;
        }
        delete First1;
        iCount--;
        First1 = NULL;
    }
        
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert First Function
    ///////////////////////////////////////////////////////////////////////

    void InsertFirst(int no)
    {
        DPNODE newn = new DNODE(no);

        if (First1 == NULL)
        {
            First1 = newn;
        }
        else
        {
            newn->next = First1;
            First1->prev = newn;
            First1 = newn;
        }
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert Last Function
    ///////////////////////////////////////////////////////////////////////

    void InsertLast(int no)
    {
        DPNODE newn = new DNODE(no);

        if (First1 == NULL)
        {
            First1 = newn;
        }
        else
        {
            DPNODE temp = First1;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
            newn->prev = temp;
        }
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////
    // Insert At Position Function
    ///////////////////////////////////////////////////////////////////////

    void InsertAtPos(int no, int pos)
    {
        DPNODE newn = new DNODE(no);

        if ((pos < 1) || (pos > iCount + 1))
        {
            cout << "Invalid Position"
                 << "\n";
            return;
        }
        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            DPNODE temp = First1;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next->prev = newn;
            temp->next = newn;
            newn->prev = temp;
            iCount++;
        }
    }

    ////////////////////////////////////////////////////////////////////////
    // Delete First Function
    ////////////////////////////////////////////////////////////////////////

    void DeleteFirst()
    {
        if (First1 == NULL)
        {
            cout << "Doubly Linear Linked List is Empty"
                 << "\n";
            return;
        }
        else if (First1->next == NULL)
        {
            delete First1;
            First1 = NULL;
        }
        else
        {
            First1 = First1->next;
            delete First1->prev;
            First1->prev = NULL;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////////
    // Delete Last Function
    ////////////////////////////////////////////////////////////////////////

    void DeleteLast()
    {
        if (First1 == NULL)
        {
            cout << "Doubly Linear Linked List is Empty"
                 << "\n";
            return;
        }
        else if (First1->next == NULL)
        {
            delete First1;
            First1 = NULL;
        }
        else
        {
            DPNODE temp = First1;

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////////
    // Delete At Position Function
    ////////////////////////////////////////////////////////////////////////

    void DeleteAtPos(int pos)
    {
        if ((pos < 1) || (pos > iCount + 1))
        {
            cout << "Invalid Position"
                 << "\n";
            return;
        }
        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount + 1)
        {
            DeleteLast();
        }
        else
        {
            DPNODE temp = First1;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;
            iCount--;
        }
    }

    /////////////////////////////////////////////////////////////////////////////
    // Display Function
    /////////////////////////////////////////////////////////////////////////////

    void DisplayDLLL()
    {
        if (First1 != NULL)
        {
            DPNODE temp = First1;

            cout << "NULL <=> ";
            while (temp != NULL)
            {
                cout << temp->data << " <=> ";
                temp = temp->next;
            }
            cout << "NULL\n";
        }
        else
        {
            cout << "Doubly Linear Linked List is empty"
                 << "\n";
        }
    }
};

///////////////////////////////////////////////////////////////////////////////////
// Doubly Circular Linked List
///////////////////////////////////////////////////////////////////////////////////

class DoublyCircularLL : public LinkedList
{
private:
    DPNODE Last;

public:
    DoublyCircularLL()
    {
        Last = NULL;
    }

    ////////////////////////////////////////////////////////////////////////////
    //  Deletion of Linked List
    ////////////////////////////////////////////////////////////////////////////

    ~DoublyCircularLL()
    {

        if (First1 == Last)
        {
            delete First1;
            First1 = NULL;
            Last = NULL;
        }
        else
        {
            do
            {
                First1 = First1->next;
                delete Last->next;
                iCount--;
                First1->prev = Last;
                Last->next = First1;
            } while (First1 != Last);
            delete First1;
            iCount--;
            First1 = NULL;
            Last = NULL;
        }
    }

    ////////////////////////////////////////////////////////////////////////////
    // Insert First Function
    ////////////////////////////////////////////////////////////////////////////

    void InsertFirst(int no)
    {
        DPNODE newn = new DNODE(no);

        if ((First1 == NULL) && (Last == NULL))
        {
            First1 = newn;
            Last = newn;
        }
        else
        {
            newn->next = First1;
            First1->prev = newn;

            First1 = newn;
        }
        Last->next = First1;
        First1->prev = Last;
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Insert Last Function
    ///////////////////////////////////////////////////////////////////////////

    void InsertLast(int no)
    {
        DPNODE newn = new DNODE(no);

        if ((First1 == NULL) && (Last == NULL))
        {
            First1 = newn;
            Last = newn;
        }
        else
        {
            Last->next = newn;
            newn->prev = Last;

            Last = newn;
        }
        Last->next = First1;
        First1->prev = Last;
        iCount++;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Insert At Position
    ///////////////////////////////////////////////////////////////////////////

    void InsertAtPos(int no, int pos)
    {
        if ((pos < 1) || (pos > iCount + 1))
        {
            cout << "Invalid Position"
                 << "\n";
            return;
        }
        if (pos == 1)
        {
            InsertFirst(no);
        }
        else if (pos == iCount + 1)
        {
            InsertLast(no);
        }
        else
        {
            DPNODE temp = First1;
            DPNODE newn = new DNODE(no);

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }

            newn->next = temp->next;
            temp->next->prev = newn;

            temp->next = newn;
            newn->prev = temp;
            iCount++;
        }
    }

    /////////////////////////////////////////////////////////////////////////
    // Delete First Function
    /////////////////////////////////////////////////////////////////////////

    void DeleteFirst()
    {
        if ((First1 == NULL) || (Last == NULL))
        {
            cout << "Doubly Circular Linked List is empty"
                 << "\n";
        }
        else if (First1 == Last)
        {
            delete First1;
            First1 = NULL;
            Last = NULL;
        }
        else
        {
            First1 = First1->next;
            delete Last->next;

            Last->next = First1;
            First1->prev = Last;
        }
        iCount--;
    }

    ////////////////////////////////////////////////////////////////////////
    // Delete Last Function
    ////////////////////////////////////////////////////////////////////////

    void DeleteLast()
    {
        if ((First1 == NULL) || (Last == NULL))
        {
            cout << "Doubly Circular Linked List is empty"
                 << "\n";
            return;
        }
        else if (First1 == Last)
        {
            delete First1;
            First1 = NULL;
            Last = NULL;
        }
        else
        {
            Last = Last->prev;
            delete Last->next;
            Last->next = First1;
            First1->prev = Last;
        }
        iCount--;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Delete At Position Function
    ///////////////////////////////////////////////////////////////////////////

    void DeleteAtPos(int pos)
    {
        if ((pos < 0) || (pos > iCount + 1))
        {
            cout << "Invalid Position"
                 << "\n";
            return;
        }
        if (pos == 1)
        {
            DeleteFirst();
        }
        else if (pos == iCount)
        {
            DeleteLast();
        }
        else
        {
            DPNODE temp = First1;

            for (int iCnt = 1; iCnt < pos - 1; iCnt++)
            {
                temp = temp->next;
            }

            temp->next = temp->next->next;
            delete temp->next->prev;
            temp->next->prev = temp;
            iCount--;
        }
    }

    //////////////////////////////////////////////////////////////////////////
    // Display Function
    //////////////////////////////////////////////////////////////////////////

    void DisplayDCLL()
    {
        if ((First1 != NULL) && (Last != NULL))
        {
            DPNODE temp = First1;

            cout << " <=> ";
            do
            {
                cout << temp->data << " <=> ";
                temp = temp->next;
            } while (temp != Last->next);
            cout << "\n";
        }
        else
        {
            cout << "Doubly Circular Linked List is empty"
                 << "\n";
        }
    }
};

//////////////////////////////////////////////////////////////////////////////
// Stack Linear Datastructre
//////////////////////////////////////////////////////////////////////////////

class Stack
{
public:
    SPNODE First;
    int iCount;

    Stack()
    {
        First = NULL;
        iCount = 0;
    }

    /////////////////////////////////////////////////////////////////
    // Deletion of stack
    /////////////////////////////////////////////////////////////////

    ~Stack()
    {
        SPNODE temp = First;
        while (First != NULL)
        {
            temp = First;
            First = First->next;
            delete temp;
            iCount--;
        }
    }

    /////////////////////////////////////////////////////////////////
    // Push Function
    /////////////////////////////////////////////////////////////////

    void InsertLast(int no)
    {
        SPNODE newn = new SNODE(no);

        if (First == NULL)
        {
            First = newn;
        }
        else
        {
            SPNODE temp = First;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }

    /////////////////////////////////////////////////////////////////
    // Pop Function
    /////////////////////////////////////////////////////////////////

    void DeleteLast()
    {
        if (First == NULL)
        {
            cout << "Stack is empty"
                 << "\n";
            return;
        }
        else if (First->next == NULL)
        {
            delete First;
            First = NULL;
        }
        else
        {
            SPNODE temp = First;

            while (temp->next->next != NULL)
            {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = NULL;
        }
        iCount--;
    }

    /////////////////////////////////////////////////////////////////
    // Display Function
    /////////////////////////////////////////////////////////////////

    void Display()
    {
        if (First == NULL)
        {
            cout << "No elements to display as Stack is empty"
                 << "\n";
            return;
        }
        SPNODE temp = First;
        cout << "Elements of stack are : ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    /////////////////////////////////////////////////////////////////
    // Count Function
    /////////////////////////////////////////////////////////////////

    int Count()
    {
        return iCount;
    }
};

////////////////////////////////////////////////////////////////////////////////
// Queue Linear Datastructure
////////////////////////////////////////////////////////////////////////////////

class Queue
{
public:
    SPNODE First;
    int iCount;

    Queue()
    {
        First = NULL;
        iCount = 0;
    }

    ///////////////////////////////////////////////////////////////////////////
    // Deletion of Queue
    ///////////////////////////////////////////////////////////////////////////

    ~Queue()
    {
        SPNODE temp = First;
        while (First != NULL)
        {
            temp = First;
            First = First->next;
            delete temp;
            iCount--;
        }
    }

    ///////////////////////////////////////////////////////////////////////////
    // Enqueue Function
    ///////////////////////////////////////////////////////////////////////////

    void InsertLast(int no)
    {
        SPNODE newn = new SNODE(no);

        if (First == NULL)
        {
            First = newn;
        }
        else
        {
            SPNODE temp = First;

            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newn;
        }
        iCount++;
    }

    //////////////////////////////////////////////////////////////////////////
    // Dequeue Function
    //////////////////////////////////////////////////////////////////////////

    void DeleteFirst()
    {
        if (First == NULL)
        {
            cout << "Queue is empty"
                 << "\n";
            return;
        }
        else if (First->next == NULL)
        {
            delete First;
            First = NULL;
        }
        else
        {
            SPNODE temp = First;
            First = temp->next;
            delete temp;
        }
        iCount--;
    }

    /////////////////////////////////////////////////////////////////////////
    // Display Function
    /////////////////////////////////////////////////////////////////////////

    void Display()
    {
        SPNODE temp = First;
        if (First == NULL)
        {
            cout << "Queue is empty"
                 << "\n";
            return;
        }

        cout << "Elements of Queue are : ";
        while (temp != NULL)
        {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }

    /////////////////////////////////////////////////////////////////
    // Count Function
    /////////////////////////////////////////////////////////////////

    int Count()
    {
        return iCount;
    }
};

///////////////////////////////////////////////////////////////////////////////
// Main Function
///////////////////////////////////////////////////////////////////////////////

int main()
{
    while (1)
    {
        int iChoice1 = 0, iChoice2 = 1, iValue = 0, Position = 0;

        cout << "---------------------------------------------------------------------------\n";

        cout << "Choose type of Linked List: \n";

        cout << "---------------------------------------------------------------------------\n";

        cout << "1 : Singly Linear Linked List \n";
        cout << "2 : Singly Circular Linked List \n";
        cout << "3 : Doubly Linear Linked List \n";
        cout << "4 : Doubly Circular Linked List \n";
        cout << "5 : Stack \n";
        cout << "6 : Queue \n";
        cout << "7 : Terminate the application \n";

        cout << "---------------------------------------------------------------------------\n";

        cout << "Please enter the option : ";
        cin >> iChoice1;

        cout << "---------------------------------------------------------------------------\n";

        switch (iChoice1)
        {

            ///////////////////////////////////////////////////////////////////////////////////////
            // Dynamic Implementation of Singly Linear Linked List
            ///////////////////////////////////////////////////////////////////////////////////////

        case 1:
        {
            SinglyLinearLL obj;

            cout << "--------------------------------------------------------------------------\n";
            cout << "Dynamic Implementation of Singly Linear Linked List \n";
            cout << "--------------------------------------------------------------------------\n";

            while (iChoice2 != 0)
            {

                cout << "--------------------------------------------------------------------------\n";

                cout << "Please select your choice \n\n";

                cout << "1 : Insert node at first position \n";
                cout << "2 : Insert node at last position \n";
                cout << "3 : Insert node at the given position \n";
                cout << "4 : Delete node at first position \n";
                cout << "5 : Delete node at Last position \n";
                cout << "6 : Delete node at the given position \n";
                cout << "7 : Display the elements of Linked List \n";
                cout << "8 : Count number of nodes from Linked List \n";
                cout << "0 : Terminate the Linked List \n";

                cout << "--------------------------------------------------------------------------\n";

                cout << "Please enter the option : ";
                cin >> iChoice2;

                cout << "--------------------------------------------------------------------------\n";

                switch (iChoice2)
                {
                case 1:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertLast(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;

                    cout << "Enter the position : \n";
                    cin >> Position;

                    obj.InsertAtPos(iValue, Position);
                    break;

                case 4:
                    obj.DeleteFirst();
                    break;

                case 5:
                    obj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : \n";
                    cin >> Position;

                    obj.DeleteAtPos(Position);
                    break;

                case 7:
                    obj.DisplaySLLL();
                    break;

                case 8:
                    cout << "Number of elements are : " << obj.Count() << "\n";
                    break;

                case 0:
                    obj.~SinglyLinearLL();
                    cout << "Thank you for using Singly Linear Linked List\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
                    break;
                } // End of switch
            }     // End of while
            break;
        } // End of case 1

            ///////////////////////////////////////////////////////////////////////////////////////
            // Dynamic Implementation of Singly Circular Linked List
            ///////////////////////////////////////////////////////////////////////////////////////

        case 2:
        {
            SinglyCircularLL obj;

            cout << "--------------------------------------------------------------------------\n";
            cout << "Dynamic Implementation of Singly Circular Linked List \n";
            cout << "--------------------------------------------------------------------------\n";

            while (iChoice2 != 0)
            {
                cout << "--------------------------------------------------------------------------\n";

                cout << "Please select your choice \n\n";

                cout << "1 : Insert node at first position \n";
                cout << "2 : Insert node at last position \n";
                cout << "3 : Insert node at the given position \n";
                cout << "4 : Delete node at first position \n";
                cout << "5 : Delete node at Last position \n";
                cout << "6 : Delete node at the given position \n";
                cout << "7 : Display the elements of Linked List \n";
                cout << "8 : Count number of nodes from Linked List \n";
                cout << "0 : Terminate the Linked List \n";

                cout << "--------------------------------------------------------------------------\n";

                cout << "Please enter the option : ";
                cin >> iChoice2;

                cout << "--------------------------------------------------------------------------\n";

                switch (iChoice2)
                {
                case 1:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertLast(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;

                    cout << "Enter the position : \n";
                    cin >> Position;

                    obj.InsertAtPos(iValue, Position);
                    break;

                case 4:
                    obj.DeleteFirst();
                    break;

                case 5:
                    obj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : \n";
                    cin >> Position;

                    obj.DeleteAtPos(Position);
                    break;

                case 7:
                    obj.DisplaySCLL();
                    break;

                case 8:
                    cout << "Number of elements are : " << obj.Count() << "\n";
                    break;

                case 0:
                    obj.~SinglyCircularLL();
                    cout << "Thank you for using Singly Circular Linked List\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
                    break;
                } // End of switch
            }     // End of while
            break;
        } // End of case 2

            ///////////////////////////////////////////////////////////////////////////////////////
            // Dynamic Implementation of Doubly Linear Linked List
            ///////////////////////////////////////////////////////////////////////////////////////

        case 3:
        {
            DoublyLinearLL obj;

            cout << "--------------------------------------------------------------------------\n";
            cout << "Dynamic Implementation of Doubly Linear Linked List \n";
            cout << "--------------------------------------------------------------------------\n";

            while (iChoice2 != 0)
            {
                cout << "--------------------------------------------------------------------------\n";

                cout << "Please select your choice \n\n";

                cout << "1 : Insert node at first position \n";
                cout << "2 : Insert node at last position \n";
                cout << "3 : Insert node at the given position \n";
                cout << "4 : Delete node at first position \n";
                cout << "5 : Delete node at Last position \n";
                cout << "6 : Delete node at the given position \n";
                cout << "7 : Display the elements of Linked List \n";
                cout << "8 : Count number of nodes from Linked List \n";
                cout << "0 : Terminate the Linked List \n";

                cout << "--------------------------------------------------------------------------\n";

                cout << "Please enter the option : ";
                cin >> iChoice2;

                cout << "--------------------------------------------------------------------------\n";

                switch (iChoice2)
                {
                case 1:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertLast(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;

                    cout << "Enter the position : \n";
                    cin >> Position;

                    obj.InsertAtPos(iValue, Position);
                    break;

                case 4:
                    obj.DeleteFirst();
                    break;

                case 5:
                    obj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : \n";
                    cin >> Position;

                    obj.DeleteAtPos(Position);
                    break;

                case 7:
                    obj.DisplayDLLL();
                    break;

                case 8:
                    cout << "Number of elements are : " << obj.Count() << "\n";
                    break;

                case 0:
                    obj.~DoublyLinearLL();
                    cout << "Thank you for using Doubly Linear Linked List\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
                    break;
                } // End of switch
            }     // End of while
            break;
        } // End of case 3

            ///////////////////////////////////////////////////////////////////////////////////////
            // Dynamic Implementation of Doubly Circular Linked List
            ///////////////////////////////////////////////////////////////////////////////////////

        case 4:
        {
            DoublyCircularLL obj;

            cout << "--------------------------------------------------------------------------\n";
            cout << "Dynamic Implementation of Doubly Circular Linked List \n";
            cout << "--------------------------------------------------------------------------\n";

            while (iChoice2 != 0)
            {
                cout << "--------------------------------------------------------------------------\n";

                cout << "Please select your choice \n\n";

                cout << "1 : Insert node at first position \n";
                cout << "2 : Insert node at last position \n";
                cout << "3 : Insert node at the given position \n";
                cout << "4 : Delete node at first position \n";
                cout << "5 : Delete node at Last position \n";
                cout << "6 : Delete node at the given position \n";
                cout << "7 : Display the elements of Linked List \n";
                cout << "8 : Count number of nodes from Linked List \n";
                cout << "0 : Terminate the Linked List \n";

                cout << "--------------------------------------------------------------------------\n";

                cout << "Please enter the option : ";
                cin >> iChoice2;

                cout << "--------------------------------------------------------------------------\n";

                switch (iChoice2)
                {
                case 1:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertFirst(iValue);
                    break;

                case 2:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertLast(iValue);
                    break;

                case 3:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;

                    cout << "Enter the position : \n";
                    cin >> Position;

                    obj.InsertAtPos(iValue, Position);
                    break;

                case 4:
                    obj.DeleteFirst();
                    break;

                case 5:
                    obj.DeleteLast();
                    break;

                case 6:
                    cout << "Enter the position : \n";
                    cin >> Position;

                    obj.DeleteAtPos(Position);
                    break;

                case 7:
                    obj.DisplayDCLL();
                    break;

                case 8:
                    cout << "Number of elements are : " << obj.Count() << "\n";
                    break;

                case 0:
                    obj.~DoublyCircularLL();
                    cout << "Thank you for using Doubly Circular Linked List\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
                    break;
                } // End of switch
            }     // End of while
            break;
        } // End of case 4

            ///////////////////////////////////////////////////////////////////////////////////////
            // Dynamic Implementation of Stack
            ///////////////////////////////////////////////////////////////////////////////////////

        case 5:
        {
            Stack obj;

            cout << "--------------------------------------------------------------------------\n";
            cout << "Dynamic Implementation of Stack \n";
            cout << "--------------------------------------------------------------------------\n";

            while (iChoice2 != 0)
            {
                cout << "--------------------------------------------------------------------------\n";

                cout << "Please select your choice \n\n";

                cout << "1 : Push element into stack \n";
                cout << "2 : Pop element from stack \n";
                cout << "3 : Display elements from stack \n";
                cout << "4 : Count number of elements from stack \n";
                cout << "0 : Terminate the Stack \n";

                cout << "--------------------------------------------------------------------------\n";

                cout << "Please enter the option : ";
                cin >> iChoice2;

                cout << "--------------------------------------------------------------------------\n";

                switch (iChoice2)
                {
                case 1:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertLast(iValue);
                    break;

                case 2:
                    obj.DeleteLast();
                    break;

                case 3:
                    obj.Display();
                    break;

                case 4:
                    cout << "Number of elements are : " << obj.Count() << "\n";
                    break;

                case 0:
                    obj.~Stack();
                    cout << "Thank you for using Stack\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
                    break;
                } // End of switch
            }     // End of while
            break;
        } // End of case 5
        case 6:
        {
            Queue obj;

            cout << "--------------------------------------------------------------------------\n";
            cout << "Dynamic Implementation of Queue \n";
            cout << "--------------------------------------------------------------------------\n";

            while (iChoice2 != 0)
            {
                cout << "--------------------------------------------------------------------------\n";

                cout << "Please select your choice \n\n";

                cout << "1 : Push element into Queue \n";
                cout << "2 : Pop element from the Queue \n";
                cout << "3 : Display elements from Queue \n";
                cout << "4 : Count number of elements from Queue \n";
                cout << "0 : Terminate the Queue \n";

                cout << "--------------------------------------------------------------------------\n";

                cout << "Please enter the option : ";
                cin >> iChoice2;

                cout << "--------------------------------------------------------------------------\n";

                switch (iChoice2)
                {
                case 1:
                    cout << "Enter the value that you want to insert: \n";
                    cin >> iValue;
                    obj.InsertLast(iValue);
                    break;

                case 2:
                    obj.DeleteFirst();
                    break;

                case 3:
                    obj.Display();
                    break;

                case 4:
                    cout << "Number of elements are : " << obj.Count() << "\n";
                    break;

                case 0:
                    obj.~Queue();
                    cout << "Thank you for using Queue\n";
                    break;

                default:
                    cout << "Invalid Choice\n";
                    break;
                } // End of switch
            }     // End of while
            break;
        } // End of case 6

        case 7:
            cout << "Thank you for using the application"
                 << "\n";
            return 0;

        default:
            cout << "Invalid Choice\n";
            break;
        }
    }
    return 0;
}