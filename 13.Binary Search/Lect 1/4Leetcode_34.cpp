//getting the range of index occuring from 1st occurance to last
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0;
        int hi = nums.size() - 1;

        // Initialize result to -1, meaning not found
        vector<int> result = {-1, -1};

        // Binary search for the leftmost occurrence
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                result[0] = mid;
                hi = mid - 1;  // Continue searching in the left subarray
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        // Reset lo and hi for binary search on the right subarray
        lo = 0;
        hi = nums.size() - 1;

        // Binary search for the rightmost occurrence
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (nums[mid] == target) {
                result[1] = mid;
                lo = mid + 1;  // Continue searching in the right subarray
            } else if (nums[mid] < target) {
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        return result;
    }
};
