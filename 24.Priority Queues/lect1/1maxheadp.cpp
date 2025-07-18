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
    void downHeapify(int idx){
        while(idx<hp.size()){
            int lc=2*idx+1;
            int rc= 2*idx+2;
            if(lc>=hp.size()) break; //no left child, so no need to check further , last leaf node hai wo
            int maxEl=idx;
            if(hp[lc]>hp[maxEl]){
                maxEl=lc; //left child is greater than parent
            }
            if(rc<hp.size() && hp[rc]>hp[maxEl]){
                maxEl=rc; //right child is greater than parent
            }
            if(maxEl!=idx){
                swap(hp[idx],hp[maxEl]);
                idx=maxEl; //move to the next level
            } 
            else{
                break; //both children are smaller than parent, so no need to swap
            }
        }
    }
    //remove the highest priority element
    void pop(){
        if(empty())return;
        swap(hp[0],hp[hp.size()-1]); //swap the root with the last element
        hp.pop_back();
        if(!empty())
        downHeapify(0); //downHeapify from the root
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

    hp.pop();
    hp.display();
    hp.pop();
    hp.display();
 
return 0;
}