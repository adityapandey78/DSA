#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
    vector<int>v={3,4,11,9,14,-1,30,44,50};
    int arr[]={8,4,15,9,14,-2,30,44,50};
    // Max heap and Min heap using STL priority queue
    // Max heap is a priority queue where the largest element is at the top 
    // Min heap is a priority queue where the smallest element is at the top
    // By default, priority queue in C++ is a max heap
    priority_queue<int>hp; //default is max heap
    priority_queue<int , vector<int>, greater<int>>mHp; //min heap
    priority_queue<int, vector<int>,greater<int>> minHipVector(v.begin(), v.end()); //min heap using vector
    priority_queue<int>mhpArrar(arr,arr+8); //max heap using array
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);

    mHp.push(3);
    mHp.push(4);    
    mHp.push(11);
    mHp.push(9);
    mHp.push(14);   
    mHp.push(-1);
    mHp.push(30);
    mHp.push(44);

    cout << "Max element: " << hp.top() << endl; // Access the maximum element
    cout << "Min element: " << mHp.top() << endl; // Access the minimum element

    cout << "Min element from vector: " << minHipVector.top() << endl; // Access the minimum element from vector
    cout << "Max element from array: " << mhpArrar.top() << endl; // Access the maximum element from array
        return 0;
}