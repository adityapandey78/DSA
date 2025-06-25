// https://www.geeksforgeeks.org/problems/attend-all-meetings-ii/1

```c++
#include <algorithm>

class Solution {
public:
    int minMeetingRooms(vector<int>& start, vector<int>& end) {
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        int ans = 0;
        int rooms = 0;
        int i = 0, j = 0;

        while (i < start.size()) {
            if (start[i] < end[j]) {
                rooms++;                     // One more room needed
                ans = max(ans, rooms);       // Update max
                i++;
            } else {
                rooms--;                     // One meeting ended, free a room
                j++;
            }
        }

        return ans;
    }
};


```