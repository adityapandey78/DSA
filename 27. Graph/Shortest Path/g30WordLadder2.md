
## Word Ladder II Leetcode 126
Solved using the BFS approach
- It will give memory limit exceeded
```cpp
class Solution {## Word Ladder II Leetcode 126
Solved using the BFS approach
- It will give memory limit exceeded

### Problem Overview
Word Ladder II asks us to find **all shortest transformation sequences** from `beginWord` to `endWord`, where:
- Each transformation changes exactly one letter
- Each intermediate word must exist in the given word list
- We need to return all paths with the minimum length

### Algorithm Explanation

This BFS solution explores all possible transformation paths level by level, ensuring we find the shortest sequences first.

#### Key Data Structures:
- `unordered_set<string> st`: Contains all valid words for O(1) lookup
- `queue<vector<string>> q`: Stores complete transformation sequences (not just words)
- `vector<string> usedOnLevel`: Tracks words used in current level to avoid cycles
- `vector<vector<string>> ans`: Stores all shortest paths found

#### Step-by-Step Process:

1. **Initialize**: Start with `beginWord` as the first sequence in queue
2. **Level-by-level BFS**: Process all sequences of the same length together
3. **Word Generation**: For each sequence, try changing every character of the last word to 'a'-'z'
4. **Valid Word Check**: Only proceed if the new word exists in our word set
5. **Path Extension**: Add valid words to create new sequences
6. **Answer Collection**: When we reach `endWord`, store the sequence if its optimal length

#### Code Walkthrough:

```cpp
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>>q;// queue me store krunga har level ke wordLists
        q.push({beginWord}); //first wale ko push kr diya
        vector<string>usedOnLevel; // us level pe kya use ho rha hai wo hai
        usedOnLevel.push_back(beginWord); //begin word use push krdiya
        int level=0;

        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>vec=q.front();// this is the sequence
            q.pop();
            //erase all the words that has been used 
            // in the previous levels to transform 
            if(vec.size()>level){
                level++; //level badhao 
                for(auto it: usedOnLevel){
                    st.erase(it);
                }
            }

            
            string word= vec.back();
            if(word==endWord){
                //the first seq where we reached the end
                if(ans.size()==0){
                    ans.push_back(vec);
                }else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        //mark as visited on the level
                        usedOnLevel.push_back(word);
                        q.push(vec); // ab new seq ko q me daal diya bfs ke liye
                        vec.pop_back();
                    }
                }
            word[i]=original;
            }
        }
        return ans;
    }
};
```

### Why Memory Limit Exceeded?

This approach has several memory issues:

1. **Storing Complete Paths**: Each queue element contains the entire transformation sequence, not just the current word
2. **Exponential Growth**: If multiple paths exist, we store all of them simultaneously
3. **Inefficient Word Removal**: We only remove used words after processing an entire level

### Time & Space Complexity:
- **Time**: O(N × M × 26^L) where N = word count, M = word length, L = transformation length
- **Space**: O(N × L × P) where P = number of possible paths (can be exponential)

### Optimization Hints:
1. Use bidirectional BFS to reduce search space
2. Build the graph first, then reconstruct paths
3. Remove words immediately when visited, not at level boundaries
4. Consider using DFS with memoization for path reconstruction
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>>q;// queue me store krunga har level ke wordLists
        q.push({beginWord}); //first wale ko push kr diya
        vector<string>usedOnLevel; // us level pe kya use ho rha hai wo hai
        usedOnLevel.push_back(beginWord); //begin word use push krdiya
        int level=0;

        vector<vector<string>>ans;
        while(!q.empty()){
            vector<string>vec=q.front();// this is the sequence
            q.pop();
            //erase all the words that has been used 
            // in the previous levels to transform 
            if(vec.size()>level){
                level++; //level badhao 
                for(auto it: usedOnLevel){
                    st.erase(it);

                }
            }

            
            string word= vec.back();
            if(word==endWord){
                //the first seq where we reached the end
                if(ans.size()==0){
                    ans.push_back(vec);
                }else if(ans[0].size()==vec.size()){
                    ans.push_back(vec);
                }
            }
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char c='a';c<='z';c++){
                    word[i]=c;
                    if(st.count(word)>0){
                        vec.push_back(word);
                        //mark as visited on the level
                        usedOnLevel.push_back(word);
                        q.push(vec); // ab new seq ko q me daal diya bfs ke liye
                        vec.pop_back();
                    }
                }
            word[i]=original;
            }
        }
        return ans;


    }
};
```