#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Comparator function to sort items by profit/weight ratio in descending order
bool cmp(pair<int,int>&p1, pair<int,int>&p2){
    double r1= (p1.first*1.0)/(p1.second*1.0);  // Profit/weight ratio for item 1
    double r2= (p2.first*1.0)/(p2.second*1.0);  // Profit/weight ratio for item 2
    return r1 > r2;  // Sort in descending order of ratio
}

// Function to solve fractional knapsack problem
double fractionalKnapsack(vector<int>&profit, vector<int>&weights, int n, int W){
    // Create array of pairs (profit, weight) for easier sorting
    vector<pair<int, int> > arr;
    for(int i=0;i<n;i++){
        arr.push_back({profit[i],weights[i]});
    }
    
    // Sort items by profit/weight ratio in descending order
    sort(arr.begin(),arr.end(),cmp);
    
    double result=0;  // Total profit accumulated
    
    // Process each item in sorted order
    for(int i=0;i<n;i++){
        // If current item can fit completely in remaining capacity
        if(arr[i].second<=W){
            result+=arr[i].first;  // Add full profit
            W-=arr[i].second;      // Reduce remaining capacity
        }
        // If current item cannot fit completely, take fraction
        else{
            // Add fractional profit based on remaining capacity
            result+=((arr[i].first*1.0)/(arr[i].second*1.0))*W;
            W=0;    // Knapsack is now full
            break;  // No more items can be added
        }
    }
    return result;
}

int main(){
    // Sample input: profits and weights of items
    vector<int>profit={60,100,120};
    vector<int>weights={10,20,30};
    int W=50;  // Knapsack capacity
    int n=3;   // Number of items
    
    // Calculate and display the maximum profit
    cout<<"Fractional Knapsack:"<<" "<<fractionalKnapsack(profit,weights,n, W);

return 0;
}