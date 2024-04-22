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

void display(Node* head){
    Node* temp=head;
    while(head!=NULL){
        cout<<head->val<<" ";
        head=head->next;
    }
}
void deleteNode(Node* head, Node* target){
    Node* temp=head;
    while(temp->next!=target){
        temp=temp->next;
    }
    temp->next=temp->next->next;
}

int main(){
    Node *a = new Node(10);
    Node *b = new Node(20);
    Node *c = new Node(30);
    Node *d = new Node(40);
    Node *e = new Node(50);
    Node *f = new Node(60);

    a->next=b;
    b->next=c;
    c->next=d;
    d->next=e;
    e->next=f;
    display(a);
    deleteNode(a,d);
    cout<<endl;
    display(a);
return 0;
}