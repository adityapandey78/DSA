#include<iostream>
#include<vector>
using namespace std;

class Maxheap{
    vector<int>hp;
    public:
    void upheapify(int ci){
        while(ci>0){
            int pi=(ci-1)/2;
            if(hp[pi]<hp[ci]){
                swap(hp[pi],hp[ci]);
                ci=pi;
            }else break;
        }
    }
    void push(int element){
        hp.push_back(element);
        upheapify(hp.size()-1); //since we are adding at the end, so last index is size-1
    }
    bool empty(){
        return hp.size() == 0;
    }
    void display(){
        cout<<'[';
        for(int i=0;i<hp.size();i++){
            cout<<hp[i]<<" ";
        }
        cout<<']'<<endl;
    }
    int peek(){
        if(empty()) return -1; //or throw exception
        return hp[0];
    }
};

int main(){
    Maxheap hp;
    hp.push(3);
    hp.push(4);
    hp.push(11);
    hp.push(9);
    hp.push(14);
    hp.push(-1);
    hp.push(30);
    hp.push(44);
    hp.push(50);

    hp.display();
    cout << "Max element: " << hp.peek() << endl;
 
return 0;
}