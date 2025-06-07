#include<iostream>
#include<unordered_map>
using namespace std;
int main(){
    unordered_map<int,int>mp; //this is called pairing, it stores key-value pairs
    pair<string,char>p; //pairing of string and char
    p.first="hello"; //first element of the pair
    p.second='c'; //second element of the pair
    cout<<p.first<<" "<<p.second<<endl;
    //unordered_map is a hash table implementation of map, it stores key-value pairs    
    mp[1]=2; //inserting key-value pair, key is 1 and value is 2
    mp[2]=3; //inserting key-value pair, key is 2 and value is 3    
    cout<<"Size of the map: "<<mp.size()<<endl; //size of the map
    cout<<"Value of key 1: "<<mp[1]<<endl; //accessing value of key 1 
    cout<<"Value of key 2: "<<mp[2]<<endl; //accessing value of key 2
    cout<<"Value of key 3: "<<mp[3]<<endl; //accessing value of key 3, this will return 0 as key 3 is not present in the map


    unordered_map<string,int >m;
    pair<string,int>p1;
    pair<string,int>p2;
    pair<string,int>p3;
    p1.first="Aditya"; //first element of the pair
    p1.second=1; //second element of the pair
    p2.first="Shivesh"; //first element of the pair
    p2.second=2; //second element of the pair
    p3.first="Ankit"; //first element of the pair
    p3.second=3; //second element of the pair
    m.insert(p1); //inserting pair into the map
    m.insert(p2); //inserting pair into the map
    m.insert(p3); //inserting pair into the map
    
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl; //printing key-value pairs
    }
    m.erase("Aditya"); //removing the pair with key "Aditya"
    cout<<"After erasing Aditya: "<<endl;
    for(auto p:m){
        cout<<p.first<<" "<<p.second<<endl; //printing key-value pairs after erasing
    }

    cout<<m.size()<<endl; //size of the map after erasing
}