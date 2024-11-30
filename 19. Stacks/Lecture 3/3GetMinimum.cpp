//! Brute Force-- Method 1
/*
class MinStack {
public:
stack<int>st;
    MinStack() {//constructor
        
    }
    
    void push(int val) { //O(1)
        st.push(val);
    }
    
    void pop() {
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        stack<int>helper;
        int mn=INT_MAX;
        while(st.size()>0){
            mn=min(mn,st.top());
            helper.push(st.top());
            st.pop();
        }
        while(helper.size()>0){
            st.push(helper.top());
            helper.pop();
        }
        return mn;
    }
};

*/
//! Method 2

/**

class MinStack {
public:
stack<int>st;
stack<int>helper;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(helper.size()==0 || val<helper.top())helper.push(val);
        else helper.push(helper.top());
    }
    
    void pop() {
        st.pop();
        helper.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return helper.top();
    }
}; */

//!Method 3
/*
//method 3
class MinStack {
public:
    vector<int>v;
    MinStack() {
        
    }
    
    void push(int val) {
        v.push_back(val);
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        int mn=v[0];
        for(int i=0;i<v.size();i++){ //O(n)
            mn=min(mn,v[i]);
        }
        return mn;
    }
};
 */
 //!Method 4
 /*
 class MinStack {
public:
stack<long long>st;
long long min;
    MinStack() {
        min=LLONG_MAX;
    }
    
    void push(int val) {
        long long x= (long long )val;
        if(st.size()==0){
            st.push(x);
            min=x;
        }
        else if(val>=min) st.push(x);
        else{
            //val<min
            st.push(2*x-min);
            min=x;
        }
    }
    
    void pop() {
        if(st.top()>=min)st.pop();
        else{ //st.pop()<min : A fake  value is present
            //before popping make sure to retrieve the old min
            long long oldMin=2*min-st.top();
            min=oldMin;
            st.pop();
        }
    }
    
    int top() {
        if(st.top()<min) return min;
        else return st.top();
    }
    
    int getMin() {
        return min;
    }
};
  */