#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
    int arr[] = {3, -4, -7, 30, 7, -9, 2, 1, 6, -1};
    int k = 3; // window size
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> ans;
    queue<int> q;

    // Process each element in the array
    for (int i = 0; i < n; i++) {
        // Remove elements from the queue that are out of this window
        if (!q.empty() && q.front() < i - k + 1) {
            q.pop();
        }

        // If current element is negative, add its index to the queue
        if (arr[i] < 0) {
            q.push(i);
        }

        // If we have processed at least 'k' elements
        if (i >= k - 1) {
            // If there are no negative numbers in the current window
            if (q.empty()) {
                ans.push_back(0);
            } else {
                // The first negative number is at the front of the queue
                ans.push_back(arr[q.front()]);
            }
        }
    }

    // Print original array
    cout << "Original Array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Print results
    cout << "First Negative in Each Window: ";
    for (int j = 0; j < ans.size(); j++) {
        cout << ans[j] << " ";
    }
    cout << endl;

    return 0;
}