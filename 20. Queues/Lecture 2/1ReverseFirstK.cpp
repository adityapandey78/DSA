//reverse firrst k elements in a queue
#include<iostream>
#include<stack>
#include<queue>
#include<iostream>
using namespace std;
void reverse(queue<int>&q,int k){
    stack<int>st;
    //pehl;e stack me store kr liya
    for(int i=0;i<k;i++){
        int x=q.front();
        st.push(x);
        q.pop();
    }
    //fir mene use queue me daal diya
    for(int j=0;j<k;j++){
        q.push(st.top());
        st.pop();
    }
    //fir wapas se jese reverse krna tha to use kr diya reverse
    for(int l=0;l<k;l++){
        int x=q.front();
        q.pop();
        q.push(x);
    }
}
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
    int k=3;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40); 
    q.push(50);
    q.push(60);
    reverse(q,k);
    display(q);
return 0;
}