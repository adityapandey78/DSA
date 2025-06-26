```c++

class MedianFinder {
public:
    priority_queue<int> left_max_heap; // max heap (lower half)
    priority_queue<int, vector<int>, greater<int>> right_min_heap; // min heap (upper half)

    MedianFinder() {}

    void addNum(int num) {
        // Step 1: Insert number into appropriate heap
        if (left_max_heap.empty() || num <= left_max_heap.top()) {
            left_max_heap.push(num);
        } else {
            right_min_heap.push(num);
        }

        // Step 2: Rebalance the heaps if needed
        if (left_max_heap.size() > right_min_heap.size() + 1) {
            right_min_heap.push(left_max_heap.top());
            left_max_heap.pop();
        } else if (right_min_heap.size() > left_max_heap.size()) {
            left_max_heap.push(right_min_heap.top());
            right_min_heap.pop();
        }
    }

    double findMedian() {
        if (left_max_heap.size() == right_min_heap.size()) {
            return (left_max_heap.top() + right_min_heap.top()) / 2.0;
        } else {
            return left_max_heap.top();
        }
    }
};

```