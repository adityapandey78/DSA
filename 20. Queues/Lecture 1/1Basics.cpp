#include<iostream>
#include<queue>
using namespace std;
void display(queue<int>&q){
    int n=q.size();
    for(int i=0;i<n;i++){
        int x=q.front();
        cout<<x<<endl;
        q.pop();
        q.push(x);

    }
    cout<<endl;
}
int main(){
    queue<int>q;
    //push 
    //pop
    //front -> top
    //size ,empty
    //back
    //empty() returns if the size is =0 or false
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40); 
    q.push(50);//push peeche see hoga
    cout<<q.size()<<endl;
    cout<<q.back()<<endl;
    q.pop(); //pop aage se hoga
    cout<<q.size()<<endl;
    cout<<q.front(); //front to
    display(q);
return 0;
}