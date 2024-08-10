#include <iostream>
#include <stack>
using namespace std;
void displayRecRev(stack<int> &st)
{
    if (st.size() == 0)
        return;
    int x = st.top();
    //  cout<<x<<" "; //idhr krne se reverse me print hoga ye
    st.pop();
    displayRecRev(st);
    cout << x << " "; // idhr krne se seedhe print hogaye sb recursion ka khel hai
    st.push(x);
}

// void push at bottom,
void pushAtBottom(stack<int>&st, int val)
{
    if (st.size() == 0){
        st.push(val);
        return;
    }
    int x = st.top();
    st.pop();
    pushAtBottom(st,val);
    st.push(x);
}

//? reverse a stack
void reverse(stack<int>&st){
    if(st.size()==1) return;
    int x= st.top();
    st.pop();
    reverse(st);
    pushAtBottom(st,x); //TODO Here using the pushAtBottom Function 
    // Ye sbse pehle 1 length tk pahunchega and then uske baad reverse krega if size 1 rhega toh hoga and then uske baad push at bottom kr dega 
    //? uske baad pushAtBottom wale function ke hisab se chalega
}

// printingof the stacks
void print(stack<int> st)
{
    stack<int> temp;
    while (st.size() > 0)
    {
        temp.push(st.top());
        st.pop();
    }
    // putting elements back from temp to st

    while (temp.size() > 0)
    {
        cout << temp.top() << " ";
        st.push(temp.top());
        temp.pop();
    }
}
int main() 
{
    stack<int> st;              
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);
    st.push(60);

    displayRecRev(st); // display recursive
    pushAtBottom(st, -10);
    cout<<endl;
    print(st); //printing the stack
    return 0;
}