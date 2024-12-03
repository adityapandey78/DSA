#include<iostream>
using namespace std;

class Node{ //user defined data type
    public:
    int val;
    Node* next;
    Node (int val){
        this->val=val;
        this->next=NULL;
    }
};
class Queue {//user defined data structure
public:
    Node *head=NULL;
    Node *tail=NULL;
    int size=0;
    Queue(){ //ye hai linked List ka constructure
        head=tail=NULL;//jab LL khali hai to sb NULL hai 
        size=0;
    }

    //Insert at End mka function
    void push(int val){
        Node * temp=new Node(val);
        if(size==0)head=tail=temp;// agar size ek hai to usse koi issue hi nahi hai
        else{
            tail->next=temp; //fir ye uske next ko point our krne lgega
            tail=temp;
        }
        size++;
    }

    void pop(){
        if(size==0){
            cout<<"List is Empty!";
            return;
        }
        Node *temp=head;
        head=head->next;
        size--;
        delete(temp); // it prevents the wastage of memory as it'll delete the node and save memory
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
    void display(){
        Node* temp=head;
        while (temp!=NULL)
        {
            
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }
    int Size(){
        return size;
    }
    
};
int main(){
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40); 
    q.push(50);
    q.push(60);
    q.display();
    q.pop();
    q.display();
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    cout<<q.Size()<<endl;


return 0;
}