// https://www.geeksforgeeks.org/problems/minimum-cost-to-cut-a-board-into-squares/1

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define ll long long int

// Comparator function to sort in descending order
bool cmp(int x, int y){
    return x > y;
}

ll minCostToBreak(int n, int m, vector<ll> &vertical, vector<ll> &horizontal){
    // Sort both arrays in descending order (greedy approach - cut expensive cuts first)
    sort(vertical.begin(), vertical.end(), cmp);
    sort(horizontal.begin(), horizontal.end(), cmp);
    
    // Initialize counters for horizontal and vertical segments
    int hz = 1; // number of horizontal segments
    int vr = 1; // number of vertical segments
    int h = 0, v = 0; // indices for horizontal and vertical arrays
    ll ans = 0; // total cost
    
    // Process cuts greedily - always choose the more expensive cut first
    while(h < horizontal.size() && v < vertical.size()){
        if(vertical[v] > horizontal[h]){
            // Vertical cut is more expensive, so cut vertically
            ans += vertical[v] * hz; // multiply by number of horizontal segments
            vr++; // increase vertical segments count
            v++; // move to next vertical cut
        }
        else{
            // Horizontal cut is more expensive or equal, so cut horizontally
            ans += horizontal[h] * vr; // multiply by number of vertical segments
            hz++; // increase horizontal segments count
            h++; // move to next horizontal cut
        }
    }
    
    // Process remaining vertical cuts
    while(v < vertical.size()){
        ans += vertical[v] * hz;
        vr++;
        v++;
    }
    
    // Process remaining horizontal cuts
    while(h < horizontal.size()){
        ans += horizontal[h] * vr;
        hz++;
        h++;
    }
    
    return ans;
}

int main(){
    cout << "Running Test Cases:\n\n";
    
    // Test Case 1
    cout << "Test Case 1:\n";
    int m1 = 6, n1 = 4;
    vector<ll> vertical1 = {2, 1, 3, 1, 4};
    vector<ll> horizontal1 = {4, 1, 2};
    ll result1 = minCostToBreak(n1, m1, vertical1, horizontal1);
    cout << "Input: m=" << m1 << ", n=" << n1 << "\n";
    cout << "Vertical cuts: {2, 1, 3, 1, 4}\n";
    cout << "Horizontal cuts: {4, 1, 2}\n";
    cout << "Output: " << result1 << " (Expected: 42)\n\n";
    
    // Test Case 2
    cout << "Test Case 2:\n";
    int m2 = 2, n2 = 3;
    vector<ll> vertical2 = {5};
    vector<ll> horizontal2 = {3, 4};
    ll result2 = minCostToBreak(n2, m2, vertical2, horizontal2);
    cout << "Input: m=" << m2 << ", n=" << n2 << "\n";
    cout << "Vertical cuts: {5}\n";
    cout << "Horizontal cuts: {3, 4}\n";
    cout << "Output: " << result2 << " (Expected: 13)\n\n";
    
    // Test Case 3
    cout << "Test Case 3:\n";
    int m3 = 3, n3 = 3;
    vector<ll> vertical3 = {1, 2};
    vector<ll> horizontal3 = {3, 4};
    ll result3 = minCostToBreak(n3, m3, vertical3, horizontal3);
    cout << "Input: m=" << m3 << ", n=" << n3 << "\n";
    cout << "Vertical cuts: {1, 2}\n";
    cout << "Horizontal cuts: {3, 4}\n";
    cout << "Output: " << result3 << " (Expected: 13)\n\n";
    
    // Test Case 4
    cout << "Test Case 4:\n";
    int m4 = 4, n4 = 4;
    vector<ll> vertical4 = {1, 1, 1};
    vector<ll> horizontal4 = {1, 1, 1};
    ll result4 = minCostToBreak(n4, m4, vertical4, horizontal4);
    cout << "Input: m=" << m4 << ", n=" << n4 << "\n";
    cout << "Vertical cuts: {1, 1, 1}\n";
    cout << "Horizontal cuts: {1, 1, 1}\n";
    cout << "Output: " << result4 << " (Expected: 9)\n\n";
    
    return 0;
}
