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
class Deque
{ // user defined data structure
public:
    Node *head;
    Node *tail;
    int size = 0;
    Deque()
    {                       // ye hai linked List ka constructure
        head = tail = NULL; // jab LL khali hai to sb NULL hai
        size = 0;
    }

    // Insert at End mka function
    void pushBack(int val)
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
    void pushFront(int val)
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

   

    void popFront()
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

    void popBack()
    {
        if (size == 0)
        {
            cout << "List is Empty" << endl;
            return;
        }
        else if (size == 1)
        {
            popFront();
            return; // extra
        }

        Node *temp = tail->prev; // ssedhe temp ki prev pe le jaao
        temp->next = NULL;
        tail = temp;
        size--;
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
    int front(){
        if(size==0){
            cout<<"Queue is Empty!";
            return -1;
        }
        return head->val;
    }
    int back(){
        if(size==0){
            cout<<"Queue is empty!";
            return -1;
        }
        return tail->val;
    }
    int Size(){
        return size;
    }
};
int main()
{
    Deque dq; // ll naam ki ek data structure bann gyi
    
    dq.pushBack(10);
    dq.pushBack(20);
    dq.pushBack(30);
    dq.pushBack(40); 
    dq.pushBack(50);
    dq.pushBack(60);
    dq.display();
    dq.popFront();
    dq.display();
    dq.pushFront(90);
    dq.pushFront(20);
    dq.display();
    cout<<dq.front()<<endl;
    cout<<dq.back()<<endl;
    cout<<dq.Size()<<endl;
    return 0;
}