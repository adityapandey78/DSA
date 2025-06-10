#include<iostream>
#include<map>
#include<set>
using namespace std;
int main(){
    set<int>s;
    s.insert(5);
    s.insert(3);
    s.insert(8);

    map<int,int>m;
    m[2]=20;
    m[1]=30;
    m[3]=10;

    for(int ele:s){
        cout<<ele<<" "; //isse ordered output milega
    }

    cout<<"Ordered map elements: "<<endl;
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl; //map ke elements ordered hote hain
    }

return 0;
}