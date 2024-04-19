    // class Solution {
    // public:
    // void permutation(vector<string>&v,string ans,string original){
    //     if(original==""){
    //         v.push_back(ans);
    //         return;
    //     }
    //     for(int i=0;i<original.length();i++){
    //         char ch=original[i];
    //         string left=original.substr(0,i);
    //         string right=original.substr(i+1);
    //         permutation(v,ans+ch,left+right);
    //     }
    // }
    //     string getPermutation(int n, int k) {
    //     //123
    //     //123 132 213 231 312 321
    //         string str="";
    //         for(int i=1;i<=n;i++){
    //             str+=to_string(i);        
    //         }

    //         vector<string>v;
    //         permutation(v,"",str);
    //         return v[k-1];

    //     }
    //};
    //ye method sahi to hai but isse hoga ni ye