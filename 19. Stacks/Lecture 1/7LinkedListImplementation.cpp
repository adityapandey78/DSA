//Node implementation
#include<iostream>
using namespace std;
//! Defining the Node of the stack
class Node{
    public:
    int val;
    Node* next;
    Node(int val){
        this->val=val;
        this->next=NULL;
    }
}; 
class Stack{
    public:Node * head;
    int size;
    Stack(){ //instance create kr diya 
        head=NULL;
        size=0;
    }
    void push(int val){
        Node* temp=new Node(val); //ek temp node bnaya
        temp->next=head; //temp ko jod diya head se
        head=temp; //head ko temp pe le aaya
    }
    void pop(){
        if(head==NULL){
             cout<<"Stack is Empty!"<<endl;
             return;
        }
        head=head->next; //isse top wala hat jaayega
    }
    int top(){
        if(head==NULL){
            cout<<"Stack is empty!"<<endl;
            return -1;
        }
        return head->val;
    }
    void display(){
        Node* temp=head;
        while(temp){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
};
int main(){
    Stack st;
    cout<<st.top()<<endl;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);
    st.push(70);
    cout<<st.size<<endl;
    cout<<st.top()<<endl;
    st.display();
return 0;
}