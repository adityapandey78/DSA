//Array Implimentation
#include<iostream>
using namespace std;
class Stack{ //user defined data structure
 public:
 int idx;
 int arr[5];
 Stack(){
    int idx=-1;
  }
  void push(int val){
    if(idx==4){
        cout<<"Stack is full"<<"";
        return;    
    }
    idx++;
    arr[idx]=val;
  } 

  void pop(){
    if(idx==-1){
        cout<<"Stack is empty"<<" ";
        return;
    } idx--;
  }

  int top(){
     if(idx==-1){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return arr[idx];
  }

  int size(){
    return idx+1;
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

    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<" ";
return 0;
}