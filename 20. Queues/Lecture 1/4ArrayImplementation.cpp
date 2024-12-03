///Array implementation of the queue
#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class Queue{
    public:
    int f;
    int b;
    int arr[5]; 
    Queue(){
        f=0;
        b=0;
    }
    void push(int n){
        if((b-f==5)){
            cout<<"Queue is full"<<endl;
            return;
        }
        arr[b]=n;
        b++;
    }
    void pop(){
        if(b-f==0){
            cout<<"Queue is empty"<<endl;
            return;
        }
        f++;
    }
    int front(){
        cout<<arr[f];
    }
    int back(){
        cout<<arr[b];
    }
    int size(){
        cout<<b-f<<endl;
    }

    
void display(){
   for(int i=f;i<b;i++){
    cout<<arr[i]<<" ";
   }
   cout<<endl;
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

return 0;
}