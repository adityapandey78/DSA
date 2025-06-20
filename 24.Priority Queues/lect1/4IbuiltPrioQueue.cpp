#include<iostream>
#include<vector>
#include<queue>
using namespace std;


int main(){
    priority_queue<int>hp; //default is max heap
    priority_queue<int , vector<int>, greater<int>>mHp; //min heap
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

        return 0;
}