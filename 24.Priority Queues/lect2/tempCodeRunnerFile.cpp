#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class MaxHeap{
    vector<int> h; // heap array
    public:
    int sz = 0; // current heap size
    
    // Time: O(log n), Space: O(1)
    // Moves element up to maintain max heap property
    void upHeapify(int ci){
        while(ci > 0){
            int pi = (ci - 1) / 2; // parent index
            if(h[pi] < h[ci]){
                swap(h[pi], h[ci]);
                ci = pi;
            } else break;
        }
    }
    
    // Time: O(log n), Space: O(1)
    // Moves element down to maintain max heap property within boundary
    void downHeapify(int pi, int bound){
        while(pi < bound){
            int lc = 2 * pi + 1; // left child
            int rc = 2 * pi + 2; // right child
            
            if(lc >= bound) break; // no children
            
            int max_i = pi; // index of largest element
            
            // find largest among parent and children
            if(h[lc] > h[max_i]) max_i = lc;
            if(rc < bound && h[rc] > h[max_i]) max_i = rc;
            
            // swap if needed and continue
            if(max_i != pi){
                swap(h[pi], h[max_i]);
                pi = max_i;
            } else break;
        }
    }
    
    // Time: O(log n), Space: O(1)
    // Removes maximum element (root)
    void pop(){
        if(empty()) return;
        swap(h[0], h[sz - 1]);
        sz--;
        if(!empty()) downHeapify(0, sz);
    }
    
    // Time: O(1), Space: O(1)
    bool empty(){
        return sz == 0;
    }
    
    // Time: O(n), Space: O(1)
    void display(){
        cout << '[';
        for(int i = 0; i < sz; i++) cout << h[i] << " ";
        cout << ']' << endl;
    }
    
    // Time: O(1), Space: O(1)
    void peek(){
        if(empty()) return;
        cout << h[0] << endl;
    }
    
    // Time: O(n), Space: O(1) extra
    // Builds max heap from unsorted array using bottom-up approach
    void buildMaxHeap(vector<int> arr){
        h = arr;
        sz = h.size();
        
        // start from last non-leaf and heapify down
        for(int i = (sz / 2) - 1; i >= 0; i--){
            downHeapify(i, sz);
        }
    }
    
    // Time: O(n log n), Space: O(1)
    // Sorts array in ascending order using heap
    void heapSort(){
        if(sz <= 1) return;
        
        // repeatedly extract max and place at end
        while(sz > 1){
            swap(h[0], h[sz - 1]); // move max to sorted position
            sz--; // shrink heap
            downHeapify(0, sz); // restore heap property
        }
        
        sz = h.size(); // reset size to show all elements
    }
    
    // Time: O(n), Space: O(1)
    void displayFullArray(){
        cout << '[';
        for(int i = 0; i < h.size(); i++) cout << h[i] << " ";
        cout << ']' << endl;
    }
};

int main(){
    MaxHeap mh;
    vector<int> arr = {9, 6, 1, 19, 3, 2, 8, 12, 5};
    
    cout << "Original array: ";
    for(int x : arr) cout << x << " ";
    cout << endl;
    
    mh.buildMaxHeap(arr);
    cout << "After building max heap: ";
    mh.display();
    
    mh.heapSort();
    cout << "After heap sort (ascending): ";
    mh.displayFullArray();
    
    return 0;
}
