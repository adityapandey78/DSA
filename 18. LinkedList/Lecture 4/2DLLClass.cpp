#include <iostream>
using namespace std;

class Node
{ // user defined data type
public:
    int val;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class DLL
{ // user defined data structure
public:
    Node *head;
    Node *tail;
    int size = 0;
    DLL()
    {                       // ye hai linked List ka constructure
        head = tail = NULL; // jab LL khali hai to sb NULL hai
        size = 0;
    }

    // Insert at End mka function
    void insertAtEnd(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp; // agar size ek hai to usse koi issue hi nahi hai
        else
        {
            tail->next = temp; // fir ye uske next ko point our krne lgega
            temp->prev = tail;
            tail = temp;
        }
        size++;
    }

    // Insert at Head
    void insertAtHead(int val)
    {
        Node *temp = new Node(val);
        if (size == 0)
            head = tail = temp;
        else
        {
            temp->next = head; // temp ke next ko head assign kr diya and
            head->prev = temp;
            head = temp; // ab head ko temp assign kr  diya
        }
        size++;
    }

    void insertAt(int idx, int val)
    {

        if (idx == 0)
            insertAtHead(val);
        if (idx == size - 1)
            insertAtEnd(val);
        if (idx > size)
            cout << "Entered Index is Invalid" << endl;
        else
        {
            Node *t = new Node(val);
            Node *temp = head;                 // temp wali node head ko point kr rhi hai
            for (int i = 1; i <= idx - 1; i++) // jaha jodna hai usse ek step pehle tk jaaye
            {
                temp = temp->next; // aur jispe add rha hai uske next ka value ko  pehle temp ko assign kr de
            }
            t->next = temp->next;
            temp->next = t;
            t->prev = temp;    // extra
            t->next->prev = t; // extra
            size++;
        }
    }

    void deleteAtHead()
    {
        if (size == 0)
        {
            cout << "List is Empty!";
            return;
        }
        head = head->next;
        if (head)
        {
            head->prev = NULL;
        }
        if (head == NULL)
            tail = NULL;
        size--;
    }

    void deleteAtTail()
    {
        if (size == 0)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (size == 1)
        {
            deleteAtHead();
            return; // extra
        }

        Node *temp = tail->prev; // ssedhe temp ki prev pe le jaao
        temp->next = NULL;
        tail = temp;
        size--;
    }

    void deleteAtIdx(int idx)
    {
        if (idx < 0 || idx > size)
        {
            cout << "Invalid Index" << endl;
        }
        if (idx == 0)
            deleteAtHead();
        if (idx == size - 1)
            deleteAtTail();
        else
        {
            Node *temp = head;
            for (int i = 1; i <= idx - 1; i++)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            temp->next->prev = temp; // temp ki next ki prev ko temp bna idya
            // extra

            size--;
        }
    }

    // Get value at specific index function
    int getAtIndex(int idx) {
        if (idx < 0 || idx >= size) {
            cout << "Invalid Index" << endl;
            return -1;
        }
        Node *temp;
        if (idx < size / 2) { //aagar aagese km steps me ho jaayega to kr denge nhi toh peeche se
            temp = head;
            for (int i = 0; i < idx; i++) {
                temp = temp->next;
            }
        } else {
            temp = tail;
            for (int i = size - 1; i > idx; i--) {
                temp = temp->prev;
            }
        }
        return temp->val;
    }
    void display()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    DLL list; // ll naam ki ek data structure bann gyi
    list.insertAtEnd(10);
    list.insertAtEnd(20);
    list.display();

    list.insertAtEnd(50);
    list.insertAtEnd(70);
    list.display();
    cout << list.size << " Inseting at the end of the LL" << endl;

    cout << "Inserting at head" << endl;

    list.insertAtHead(50);
    list.insertAtHead(90);
    list.insertAtHead(110);
    list.display();

    list.insertAt(5, 60);
    list.insertAt(4, 7);
    cout << "Inserting at Index" << endl;
    list.display();

    cout << "Getting the values at Index " << endl;
    cout << list.getAtIndex(4) << endl;
    cout << list.getAtIndex(5) << endl;
    cout << list.getAtIndex(11) << endl;

    cout << "Deletion Operation" << endl;
    list.display();
    list.deleteAtHead();
    list.display();
    list.deleteAtTail();
    list.display();

    list.deleteAtIdx(0);
    list.display();
    list.deleteAtIdx(2);
    list.display();
    cout<<list.getAtIndex(6);

    return 0;
}