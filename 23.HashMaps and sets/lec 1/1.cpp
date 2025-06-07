#include<iostream>
#include<unordered_set>
using namespace std;
int main(){
    unordered_set<int>s;
    s.insert(1);
    s.insert(2);
    s.insert(3);
    s.insert(4);
    s.insert(5);
    s.insert(6);
    s.insert(1); //stores only unique elements, so this will not be added again
    s.erase(2); //removes the element 2 from the set
    int target=40;

    if(s.find(target)!=s.end()){
        cout<<"Element found in the set"<<endl;
    }
    cout<<"Size of the set: "<<s.size()<<endl;


    //for each loop
    for(int ele:s){
        cout<<ele<<" ";
    }

return 0;
}