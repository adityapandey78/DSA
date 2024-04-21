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
class LinkedList {//user defined data structure
public:
    Node *head=NULL;
    Node *tail=NULL;
    int size=0;
    LinkedList(){ //ye hai linked List ka constructure
        head=tail=NULL;//jab LL khali hai to sb NULL hai 
        size=0;
    }

    //Insert at End mka function
    void insertAtEnd(int val){
        Node * temp=new Node(val);
        if(size==0)head=tail=temp;// agar size ek hai to usse koi issue hi nahi hai
        else{
            tail->next=temp; //fir ye uske next ko point our krne lgega
            tail=temp;
        }
        size++;
    }

    //Insert at Head
    void insertAtHead(int val){
        Node* temp=new Node(val);
        if(size==0) head=tail=temp;
        else{
            temp->next=head; //temp ke next ko head assign kr diya and 
            head=temp; //ab head ko temp assign kr  diya
        }
        size++;
    }


    void insertAt(int idx,int val){
       
        if(idx==0) insertAtHead(val);
        if(idx==size-1) insertAtEnd(val);
        if(idx>size ) cout<<"Entered Index is Invalid"<<endl;
        else{
            Node*t=new Node(val);
            Node *temp=head;//temp wali node head ko point kr rhi hai
            for (int i = 1; i <=idx-1; i++) //jaha jodna hai usse ek step pehle tk jaaye
            {
               temp=temp->next;//aur jispe add rha hai uske next ka value ko  pehle temp ko assign kr de
            }
            t->next=temp->next;
            temp->next=t;
            size++;
        }
    }


    int getAtIndex(int idx){
        if(idx<0||idx>size){ 
        cout<<"Invalid Index"<<endl;
        return -1;}
        if(idx==0) return head->val;
        if(idx==size-1) tail->next;
        else{
            Node* temp=head;
            for (int i = 1; i <=idx; i++)
            {
                temp=temp->next;
            }
            return temp->val;
            
        }



    }
    void deleteAtHead(){
        if(size==0){
            cout<<"List is Empty!";
            return;
        }
        head=head->next;
        size--;
    }

    void deleteAtTail(){
        if(size==0){
            cout<<"List is Empty"<<endl;
            return;
        }
        Node * temp=head;
        while(temp->next!=tail){
            temp=temp->next;
        }
        temp->next=NULL;
        tail=temp;
        size--;
    }

    void deleteAtIdx(int idx){
        if(idx<0||idx>size){
        cout<<"Invalid Index"<<endl;}
       if(idx==0) deleteAtHead();
       if(idx==size-1) deleteAtTail();
       else{
        Node*temp=head;
        for(int i=1;i<=idx-1;i++){
            temp=temp->next;
        }
        temp->next = temp->next->next;
        size--;
       }
    
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
    
};
int main(){
    LinkedList ll; // ll naam ki ek data structure bann gyi
    ll.insertAtEnd(10);
    ll.insertAtEnd(20);
    ll.display();

    ll.insertAtEnd(50);
    ll.insertAtEnd(70);
    ll.display();
    cout<<ll.size<<"Inseting at the end of the LL"<<endl;

    cout<<"Inserting at head"<<endl;

    ll.insertAtHead(50);
    ll.insertAtHead(90);
    ll.insertAtHead(110);
    ll.display();

    ll.insertAt(5,60);
    ll.insertAt(4,7);
    cout<<"Inserting at Index"<<endl;
    ll.display();

    cout<<"Getting the values at Index "<<endl;
    cout<<ll.getAtIndex(4)<<endl;
    cout<<ll.getAtIndex(5)<<endl;
    cout<<ll.getAtIndex(11)<<endl;

    cout<<"Deletion Operation"<<endl;
    ll.display();
    ll.deleteAtHead();
    ll.display();
    ll.deleteAtTail();
    ll.display();

    ll.deleteAtIdx(0);
    ll.display();
    ll.deleteAtIdx(2);
    ll.display();

return 0;
}