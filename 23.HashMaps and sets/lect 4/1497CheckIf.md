## Check if Arrya paisa re divisible by K
```c++

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int , int>mp;
        for(int ele:arr){
            ele=((ele%k)+k)%k; // to tackle the negative nums //VVI //given in HINTs
            mp[ele]++;
        }
        if(mp.find(0)!=mp.end()){
        if(mp[0]%2!=0) return false;
        mp.erase(0);
        }
        
        for(auto x:mp){
            int ele =x.first;
            int rem=k-ele; //k- remaining, usse map me khojenge 
            if(mp.find(rem)==mp.end()) return false;
            if(mp[ele]!=mp[rem]) return false; // agar eles ki freq same nai hai toh

        }
        return true;
    }
};
```