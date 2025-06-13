```c++
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>mp;
        for(string str:arr){
            string lexo=str;
            sort(lexo.begin(),lexo.end());
            if(mp.find(lexo)==mp.end()){//pehle se present nahi hai to
                vector<string>v;
                v.push_back(str); //ye har bar us string me push_back krte rahega...
                mp[lexo]=v; // aur last me map me daal dega
            }
            else{
                mp[lexo].push_back(str);
            }
        }
        for(auto x:mp){
            vector<string>v=x.second;
            ans.push_back(v);
        }
        return ans;

    }
};
```