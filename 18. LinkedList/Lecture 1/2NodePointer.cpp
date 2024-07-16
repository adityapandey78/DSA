#include<iostream>
using namespace std;
class Node{
public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
};

void display(Node*head){
    Node * temp=head;
    while(temp!=NULL){
        cout<<temp->val<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

//displaying recursively

void displayRec(Node * head){
    if(head==NULL) return;
    cout<<head->val<<" ";
    displayRec(head->next);
}

void reverseDisplay(Node* head){
    if(head==NULL) return; //base case
    reverseDisplay(head->next); //call
    cout<<head->val<<" "; //print
}
int main(){
    Node* a=new Node(10);
    Node* b=new Node(20);
    Node* c=new Node(30);
    Node* d=new Node(40);
    Node* e=new Node(50);

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    //cout<<c->val<<" ";

   display(a); //passing down a as head node
   displayRec(a);
   cout<<endl;
   reverseDisplay(a);
return 0;
}