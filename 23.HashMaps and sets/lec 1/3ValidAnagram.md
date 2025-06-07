```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;

        for(int i=0,j=0;i<s.length();i++){
            map1[s[i]]++;//map1[a]++ => isse agar koi repeat bhi hoga toh uski freq me add ho jayegi
        }
        for(int j=0;j<t.length();j++){
         map2[t[j]]++;
        }
        for(auto x:map1){
            char ch1=x.first;
            int freq1=x.second;

            if(map2.find(ch1)!=map2.end()){
                int freq2= map2[ch1];
                if(freq1!=freq2) return false;
            }else return false;           
        }
        return true;
    }
};

// with this approach we are using two maps to store the frequency of characters in both strings.
// We then compare the frequencies of each character in both maps to determine if the strings are anagrams. 
// Time Complexity: O(n) where n is the length of the strings
// Space Complexity: O(n) for the two maps
```

## Method 2: Using a single map

```c++
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int>map1;
       
        for(int i=0,j=0;i<s.length();i++){
            map1[s[i]]++;
        }
        //1 map me saari entrykara do and use dusre se compare kr do
        for(int i=0; i<t.length();i++){
            char ch= t[i];
            if(map1.find(ch)!=map1.end()){
                map1[ch]--;
                if(map1[ch]==0) map1.erase(ch);
            }
            else return false;
        }
        if(map1.size()>0) return false;
        return true;
    }
};

```