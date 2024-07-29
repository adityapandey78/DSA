#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack <int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    // cout<< st.size()<<endl;
    // st.pop();
    // cout<<st.size()<<endl;
    st.push(50);

    //printing in reverse order

    // while(st.size()>0){
    //     cout<<st.top()<<endl;
    //     st.pop();
    // }

    /*
    but above code will delete the stack so not an efficient method
    */
    //method 2: create an extra space temp
    
return 0;
}