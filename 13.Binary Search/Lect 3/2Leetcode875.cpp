//Koko Eating Bananas
// class Solution {
// public:
// bool check(int speed,vector<int>& piles,int h){
//     long long count=0;
//     int n=piles.size();
//     for(int i=0; i<n;i++){
//         //if(count>h) return false;
//         if(speed>=piles[i])count++;  //agar piles mera speed piles se hi jyada hai to wo ek baari me hi kha lega
//         else if(piles[i]%speed==0) count+=piles[i]/speed; //agar same uska multiple hai to 
//         else{
//             count+=(piles[i]/speed) +1; //agart uska multiple ni hai to jitnes e divide ho + jb speed piles se jyada hai
//         }
        
//     }
//     if(count>(long long)h) return false; //iske kaaran integer overflow ho raha tha so iske pehle bhi ceheck kr skte hain 
//     else return true;
// }
    


//     int minEatingSpeed(vector<int>& piles, int h) {
//         int n=piles.size();
//         int mx=-1;
//         for(int i=0;i<n;i++){
//             mx =max(mx,piles[i]);
//         }
//         int lo=1;
//         int hi=mx;
//         int ans=-1;
//         while(lo<=hi){
//             int mid=lo+(hi-lo)/2;
//             if(check(mid,piles,h)==true){
//                 ans=mid;
//                 hi=mid-1;
//             }
//             else lo=mid+1;

//         }
//         return ans;
    
//     }
    
// };