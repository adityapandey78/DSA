#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int minProduct(vector<int>&arr){
    int cn=0, cz=0, cp=0;  // Count of negative, zero, positive numbers
    int prod_pos=1;        // Product of positive numbers
    int prod_neg=1;        // Product of negative numbers
    int largestNeg=INT_MIN; // Largest (closest to 0) negative number
    
    // Count numbers and calculate products
    for(int i=0; i<arr.size(); i++){
        if(arr[i]<0){
            cn++;
            prod_neg *= arr[i];
            largestNeg = max(largestNeg, arr[i]); // Find largest negative
        }
        else if(arr[i]==0) {
            cz++;
        }
        else{
            cp++;
            prod_pos *= arr[i];
        }   
    }
    
    // If no negative numbers
    if(cn==0){
        if(cz>0) return 0;  // If zeros exist, min product is 0
        else{
            // Find minimum positive number
            auto it = min_element(arr.begin(), arr.end());
            return *it;
        }
    }
    else{
        // If even count of negative numbers, exclude largest negative
        if(cn%2==0){
            if(cz>0) return 0;  // If zeros exist, better to use 0
            return (prod_neg/largestNeg) * prod_pos;
        }
        else{
            // Odd count of negatives gives negative product
            return prod_neg * prod_pos;
        }
    }
}

int main(){
    // Test case 1: Mix of positive and negative
    vector<int> arr1{-3, -2, 1, 4, -2};
    cout << "Test 1 - Mixed numbers: " << minProduct(arr1) << endl;
    
    // Test case 2: All positive numbers
    vector<int> arr2{1, 2, 3, 4};
    cout << "Test 2 - All positive: " << minProduct(arr2) << endl;
    
    // Test case 3: Contains zero
    vector<int> arr3{-2, 0, 3, -1};
    cout << "Test 3 - Contains zero: " << minProduct(arr3) << endl;
    
    // Test case 4: All negative numbers (even count)
    vector<int> arr4{-1, -2, -3, -4};
    cout << "Test 4 - Even negatives: " << minProduct(arr4) << endl;
    
    // Test case 5: All negative numbers (odd count)
    vector<int> arr5{-1, -2, -3};
    cout << "Test 5 - Odd negatives: " << minProduct(arr5) << endl;
    
    // Test case 6: Single element
    vector<int> arr6{-5};
    cout << "Test 6 - Single negative: " << minProduct(arr6) << endl;
    
    return 0;
}