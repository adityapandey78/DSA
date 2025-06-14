```c++
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.length()!=word2.length()) return false;
        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(int i=0;i<word1.length();i++){
            mp1[word1[i]]++;
            mp2[word2[i]]++;
        }

        for(auto x:mp1){
            char ch=x.first;
            if(mp2.find(ch)==mp2.end())
            return false; //in case wo letter aggar mp2 me ni exist kiya toh
        }

        unordered_map<int,int> h1,h2;
        for(auto x:mp1){
            int freq=x.second;
            h1[freq]++;
        }

        for(auto x:mp2){
            int freq=x.second;
            h2[freq]++;
        }

        //comparing the helper 1 and helper 2 maps 
        for(auto x:h1){
            int key=x.first;
            if(h2.find(key)==h2.end()) return false;//agar wo freq hi  nahi milti toh
            if(h2[key]!=h1[key]) return false; //agar freq same ni hai toh
        }
        return true;
    }
};
```