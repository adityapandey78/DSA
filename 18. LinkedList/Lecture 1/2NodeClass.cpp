#include <iostream>
using namespace std;

class Node
{
public:
    int val;
    Node *next;
    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

int main()
{
    // 10 20 30
    Node a(10);
    Node b(20);
    Node c(30);
    Node d(40);
    // forming All
    a.next = &b;
    b.next = &c;
    c.next = &d;
    d.next = NULL;
    cout << (c.next)->val << endl;         // C ke next i.e. D ki value
    cout << (((a.next)->next)->next)->val; // D ki value
    Node temp = a;                         // ek temporary node bnaya jiska khud ka address kuchh dusra hai but wo point kr rha hai a ko
    while (1)
    {
        cout << temp.val << " ";
        if (temp.next == NULL)
            break;
        temp = *(temp.next);
    }
    return 0;
}