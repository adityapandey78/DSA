#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution {
public:
    int fun(int idx,vector<int>& heights, int k,vector<int>& dp){
        //base case
        if(idx==0) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int mmSteps=INT_MAX;
        for(int j=1;j<=k;j++){
            if(idx-j>=0){
                int jump= fun(idx-j,heights,k,dp)+abs(heights[idx]-heights[idx-j]);
                //update the minimu energy
                mmSteps=min(jump,mmSteps);
            }
        }
        return dp[idx]= mmSteps;
    }
    int frogJumpKSteps(vector<int>& heights, int k) {
        // Your implementation here
        int idx=heights.size()-1;
        vector<int>dp(idx+1,-1);
        return fun(idx,heights,k,dp);
    }
};

void runTests() {
    Solution sol;
    
    // Test Case 1: Basic example 1
    vector<int> heights1 = {10, 5, 20, 0, 15};
    int k1 = 2;
    int expected1 = 15;
    int result1 = sol.frogJumpKSteps(heights1, k1);
    cout << "Test 1: " << (result1 == expected1 ? "PASS" : "FAIL") 
         << " (Expected: " << expected1 << ", Got: " << result1 << ")" << endl;
    
    // Test Case 2: Basic example 2
    vector<int> heights2 = {15, 4, 1, 14, 15};
    int k2 = 3;
    int expected2 = 2;
    int result2 = sol.frogJumpKSteps(heights2, k2);
    cout << "Test 2: " << (result2 == expected2 ? "PASS" : "FAIL") 
         << " (Expected: " << expected2 << ", Got: " << result2 << ")" << endl;
    
    // Test Case 3: Single step
    vector<int> heights3 = {5};
    int k3 = 1;
    int expected3 = 0;
    int result3 = sol.frogJumpKSteps(heights3, k3);
    cout << "Test 3: " << (result3 == expected3 ? "PASS" : "FAIL") 
         << " (Expected: " << expected3 << ", Got: " << result3 << ")" << endl;
    
    // Test Case 4: Two steps
    vector<int> heights4 = {10, 30};
    int k4 = 1;
    int expected4 = 20;
    int result4 = sol.frogJumpKSteps(heights4, k4);
    cout << "Test 4: " << (result4 == expected4 ? "PASS" : "FAIL") 
         << " (Expected: " << expected4 << ", Got: " << result4 << ")" << endl;
    
    // Test Case 5: k equals n-1 (can jump to any step)
    vector<int> heights5 = {100, 10, 50, 5};
    int k5 = 3;
    int expected5 = 95; // Direct jump from 0 to 3: abs(100-5) = 95, but 0->1->3: 90+45=135, 0->2->3: 50+45=95, 0->3: 95
    int result5 = sol.frogJumpKSteps(heights5, k5);
    cout << "Test 5: " << (result5 == expected5 ? "PASS" : "FAIL") 
         << " (Expected: " << expected5 << ", Got: " << result5 << ")" << endl;
    
    // Test Case 6: Decreasing heights
    vector<int> heights6 = {100, 80, 60, 40, 20};
    int k6 = 2;
    int expected6 = 60; // 0->1->3->4: 20+20+20=60, 0->2->4: 40+40=80, optimal path is 0->1->3->4 with cost 60
    int result6 = sol.frogJumpKSteps(heights6, k6);
    cout << "Test 6: " << (result6 == expected6 ? "PASS" : "FAIL") 
         << " (Expected: " << expected6 << ", Got: " << result6 << ")" << endl;
    
    // Test Case 7: Large k value (k >= n-1)
    vector<int> heights7 = {1, 2, 3, 4, 5};
    int k7 = 10;
    int expected7 = 4; // Direct jump from 0 to 4: abs(1-5) = 4
    int result7 = sol.frogJumpKSteps(heights7, k7);
    cout << "Test 7: " << (result7 == expected7 ? "PASS" : "FAIL") 
         << " (Expected: " << expected7 << ", Got: " << result7 << ")" << endl;
}

int main() {
    runTests();
    return 0;
}