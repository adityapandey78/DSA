## MEthod 1 - (TLE)
```c++
class Solution {
public:
int rev(int n){
    int r=0;
    while(n>0){
        r*=10;
        r+=(n%10);
        n/=10;
    }
    return r;
}   
int fact(int n){
    int f=1;
    for(int i=2;i<=n;i++){
        f*=i;
    }
    return f;
}
int comb(int n, int r){
    return fact(n)/fact(r)*fact(n-r);
}
    int countNicePairs(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]= nums[i]-rev(nums[i]);
        }
        unordered_map<int,int>m;

        for(int ele:nums){
            m[ele]++;
        }

        for(auto ele:m){
            int f= ele.second;
            count+=comb(f,2);   
        }
        
    return count;
    }
};
```

## Method 2:
```c++
class Solution {
public:
int rev(int n){
    int r=0;
    while(n>0){
        r*=10;
        r+=(n%10);
        n/=10;
    }
    return r;
}   
int fact(int n){
    int f=1;
    for(int i=2;i<=n;i++){
        f*=i;
    }
    return f;
}
int comb(int n, int r){
    return fact(n)/fact(r)*fact(n-r);
}
    int countNicePairs(vector<int>& nums) {
        int count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            nums[i]= nums[i]-rev(nums[i]);
        }
        unordered_map<int,int>m;

        for(int ele:nums){
            m[ele]++;
        }

        for(auto ele:m){
            int f= ele.second;
            count+=comb(f,2);   
        }
        
    return count;
    }
};
```

## Method 3 - (Optimized)
```c++
class Solution {
public:
    int rev(int n) {
        int r = 0;
        while (n > 0) {
            r *= 10;
            r += (n % 10);
            n /= 10;
        }
        return r;
    }
    int countNicePairs(vector<int>& nums) {
        long long count = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] -= rev(nums[i]);
        }
        unordered_map<int, int> m;

        for (int ele : nums) {

            if (m.find(ele) != m.end()) {
                count%1000000007;
                count += m[ele];
                m[ele]++;
            } else
                m[ele]++;
        }
        return count%1000000007;
    }
};```