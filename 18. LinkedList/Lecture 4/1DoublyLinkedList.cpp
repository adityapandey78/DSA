#include<iostream>
using namespace std;
class Node{
    public:
    int val;
    Node*next;
    Node*prev; 
    Node(int val){
        this->val=val;
        this->next=NULL;
        this->prev=NULL; //extra for DLL
    }
};
//iterative display
void display(Node*head){
    while(head){
        cout<<head->val<<" ";
        head=head->next;
    }
}
void displayrev(Node*head){
    while(head){
        cout<<head->val<<" ";
        head=head->prev;
    }
}
//recursive display

void displayrec(Node* head){
    if(head==NULL)return;
    cout<<head->val<<" ";
    displayrec(head->next);
}
void displayrecRev(Node* head){
    if(head==NULL)return;
    displayrecRev(head->next);
    cout<<head->val<<" ";
}

int main(){
    //10 20 30 40 50
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    Node* e=new Node(50);
    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->prev=d;
    d->prev=c;
    c->prev=b;
    b->prev=a;
    display(a);
    cout<<endl;
    displayrev(e);
    cout<<endl;
    displayrec(a);
    cout<<endl;
    displayrecRev(a); //isme head hi pass kr rhe hain fir bhi jaa rha hai

return 0;
}