# Complete Dynamic Programming Guide - Minimum Falling Path Sum

## Problem Statement
Given an `n x n` array of integers matrix, return the minimum sum of any falling path through matrix.

A falling path starts at any element in the first row and chooses the element in the next row that is either directly below or diagonally left/right. Specifically, the next element from position `(row, col)` will be `(row + 1, col - 1)`, `(row + 1, col)`, or `(row + 1, col + 1)`.

## All Approaches Overview

| **Approach** | **Time** | **Space** | **Best For** |
|--------------|----------|-----------|--------------|
| **Memoized** | O(n²) | O(n²) | Learning DP, debugging |
| **Tabular** | O(n²) | O(n²) | Standard DP practice |
| **Space Optimized** | O(n²) | O(n) | **Interviews** ⭐ |
| **In-Place** | O(n²) | O(1) | Memory constraints |

---

## 1. Memoized (Top-Down) Approach

**Best for**: Learning DP concepts, easy to understand and debug

```cpp
class MemoizedSolution {
private:
    int solve(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
        int n = matrix.size();
        
        // Base cases
        if (j < 0 || j >= n) return 1e9;  // Out of bounds
        if (i == 0) return matrix[0][j];   // First row
        
        // Check if already computed
        if (dp[i][j] != INT_MAX) return dp[i][j];
        
        // Recursive calls
        int up = matrix[i][j] + solve(i - 1, j, matrix, dp);
        int leftDiag = matrix[i][j] + solve(i - 1, j - 1, matrix, dp);
        int rightDiag = matrix[i][j] + solve(i - 1, j + 1, matrix, dp);
        
        // Store and return result
        return dp[i][j] = min({up, leftDiag, rightDiag});
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MAX));
        
        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, solve(n - 1, j, matrix, dp));
        }
        
        return result;
    }
};
```

**Complexity:**
- Time: O(n²)
- Space: O(n²) + O(n) recursion stack

**Pros:**
- Intuitive and natural thinking process
- Easy to debug and understand
- Directly translates the problem statement

**Cons:**
- Extra recursion overhead
- Uses call stack space

---

## 2. Tabular (Bottom-Up) Approach

**Best for**: Standard DP practice, better performance than recursive

```cpp
class TabularSolution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n));
        
        // Initialize first row
        for (int j = 0; j < n; j++) {
            dp[0][j] = matrix[0][j];
        }
        
        // Fill the DP table row by row
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = dp[i-1][j];
                int leftDiag = (j > 0) ? dp[i-1][j-1] : 1e9;
                int rightDiag = (j < n-1) ? dp[i-1][j+1] : 1e9;
                
                dp[i][j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
        }
        
        // Find minimum in the last row
        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, dp[n-1][j]);
        }
        
        return result;
    }
};
```

**Complexity:**
- Time: O(n²)
- Space: O(n²)

**Pros:**
- No recursion overhead
- Predictable memory access patterns
- Easier to optimize further

**Cons:**
- Uses O(n²) extra space
- Less intuitive than top-down approach

---

## 3. Space Optimized Approach ⭐

**Best for**: Interviews, optimal balance of time and space

```cpp
class SpaceOptimizedSolution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> prev(matrix[0]);  // Previous row (initialized with first row)
        
        // Process each row starting from row 1
        for (int i = 1; i < n; i++) {
            vector<int> curr(n);  // Current row
            
            for (int j = 0; j < n; j++) {
                int up = prev[j];
                int leftDiag = (j > 0) ? prev[j-1] : 1e9;
                int rightDiag = (j < n-1) ? prev[j+1] : 1e9;
                
                curr[j] = matrix[i][j] + min({up, leftDiag, rightDiag});
            }
            
            prev = curr;  // Update prev for next iteration
        }
        
        // Return minimum from the last processed row
        return *min_element(prev.begin(), prev.end());
    }
};
```

**Complexity:**
- Time: O(n²)
- Space: O(n)

**Pros:**
- Optimal space complexity
- Still maintains readability
- Perfect for interviews

**Cons:**
- Slightly more complex than basic tabular

---

## 4. Ultra Space Optimized (In-Place)

**Best for**: Extreme memory constraints, when input modification is allowed

```cpp
class InPlaceSolution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Modify matrix in-place
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int up = matrix[i-1][j];
                int leftDiag = (j > 0) ? matrix[i-1][j-1] : 1e9;
                int rightDiag = (j < n-1) ? matrix[i-1][j+1] : 1e9;
                
                matrix[i][j] += min({up, leftDiag, rightDiag});
            }
        }
        
        // Return minimum from last row
        return *min_element(matrix[n-1].begin(), matrix[n-1].end());
    }
};
```

**Complexity:**
- Time: O(n²)
- Space: O(1)

**Pros:**
- Minimal space usage
- Fastest execution
- Good for competitive programming

**Cons:**
- Destroys original input
- May not be acceptable in some scenarios

---

## 5. Alternative Memoized (HashMap)

**Best for**: When you want to avoid sentinel value issues

```cpp
class HashMapMemoizedSolution {
private:
    unordered_map<string, int> memo;
    
    string getKey(int i, int j) {
        return to_string(i) + "," + to_string(j);
    }
    
    int solve(int i, int j, vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        if (j < 0 || j >= n) return 1e9;
        if (i == 0) return matrix[0][j];
        
        string key = getKey(i, j);
        if (memo.count(key)) return memo[key];
        
        int up = matrix[i][j] + solve(i - 1, j, matrix);
        int leftDiag = matrix[i][j] + solve(i - 1, j - 1, matrix);
        int rightDiag = matrix[i][j] + solve(i - 1, j + 1, matrix);
        
        return memo[key] = min({up, leftDiag, rightDiag});
    }
    
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        memo.clear();
        
        int result = INT_MAX;
        for (int j = 0; j < n; j++) {
            result = min(result, solve(n - 1, j, matrix));
        }
        
        return result;
    }
};
```

**Complexity:**
- Time: O(n²)
- Space: O(n²) for hashmap + O(n) recursion stack

**Pros:**
- Completely avoids sentinel value issues
- Handles any possible answer value
- Good for debugging

**Cons:**
- HashMap overhead
- String operations for key generation

---

## 6. Optimized Tabular (Single Pass)

**Best for**: Clean implementation with minimal operations

```cpp
class OptimizedTabularSolution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        if (n == 1) return matrix[0][0];
        
        vector<int> dp = matrix[0];  // Initialize with first row
        
        for (int i = 1; i < n; i++) {
            vector<int> temp(n);
            for (int j = 0; j < n; j++) {
                temp[j] = matrix[i][j] + dp[j];  // Up direction
                
                if (j > 0) 
                    temp[j] = min(temp[j], matrix[i][j] + dp[j-1]);  // Left diagonal
                    
                if (j < n-1) 
                    temp[j] = min(temp[j], matrix[i][j] + dp[j+1]);  // Right diagonal
            }
            dp = temp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};
```

**Complexity:**
- Time: O(n²)
- Space: O(n)

---

## Usage Example

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
#include <unordered_map>
using namespace std;

int main() {
    vector<vector<int>> matrix = {{2,1,3},{6,5,4},{7,8,9}};
    
    MemoizedSolution sol1;
    TabularSolution sol2;
    SpaceOptimizedSolution sol3;
    InPlaceSolution sol4;
    
    cout << "Memoized: " << sol1.minFallingPathSum(matrix) << endl;
    cout << "Tabular: " << sol2.minFallingPathSum(matrix) << endl;
    cout << "Space Optimized: " << sol3.minFallingPathSum(matrix) << endl;
    
    // Note: InPlace modifies original matrix
    vector<vector<int>> matrix_copy = matrix;
    cout << "In-Place: " << sol4.minFallingPathSum(matrix_copy) << endl;
    
    return 0;
}
```

## Performance Comparison

| **Approach** | **Time** | **Space** | **Pros** | **Cons** |
|--------------|----------|-----------|----------|----------|
| **Memoized** | O(n²) | O(n²) | Intuitive, easy debug | Extra recursion overhead |
| **Tabular** | O(n²) | O(n²) | No recursion overhead | Uses extra space |
| **Space Optimized** | O(n²) | O(n) | Optimal space usage | Slightly complex |
| **In-Place** | O(n²) | O(1) | Minimal space usage | Modifies input |
| **HashMap Memoized** | O(n²) | O(n²) | Handles edge cases well | HashMap overhead |

## Key Insights

### 1. **Memoization Bug Fix**
- **Problem**: Using `-1` as sentinel value can fail when valid answer equals `-1`
- **Solution**: Use `INT_MAX` or `unordered_map` for safe memoization

### 2. **Space Optimization Technique**
- Only need previous row to compute current row
- Reduces space complexity from O(n²) to O(n)

### 3. **Transition from Recursive to Iterative**
- Start with recursive solution for clarity
- Convert to iterative for performance
- Optimize space usage step by step

## Interview Strategy

1. **Start with**: Memoized approach (shows understanding of DP)
2. **Optimize to**: Tabular approach (shows iterative thinking)
3. **Further optimize**: Space-optimized version (shows advanced optimization)
4. **Discuss**: Trade-offs between approaches

## Recommendation

**Use SpaceOptimizedSolution** for the best balance of time/space efficiency and code readability. It's commonly expected in technical interviews and performs well in practice.