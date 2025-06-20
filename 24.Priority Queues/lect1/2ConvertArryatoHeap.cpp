#include<iostream>
#include<vector>
using namespace std;

class Maxheap{
    vector<int>hp;
    int i; //[0,i] yaha tk everything is heapified
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
   void maxHeapify(vector<int>v){
    hp=v;
    for(int i=1;i<hp.size();i++){
        upheapify(i);
    }
   }
};

int main(){
    Maxheap hp;
vector<int>v={9,6,1,19,3,2,8,12,5};
    hp.maxHeapify(v);
    hp.display();
    v.push_back(100);
    hp.maxHeapify(v);
    hp.display();

return 0;
}