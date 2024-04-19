/* leetcode 42
class Solution {
public:
int min(int a, int b){
    if(a<b) return a; else return b;
}
    int trap(vector<int>& height) {
        int n=height.size();
        //prev greatest element
         int prev[n];
         prev[0]=-1;
         int maxm=height[0];
         for(int i=1;i<n;i++){
             prev[i]=maxm;
             if(maxm<height[i]) maxm=height[i];
         }

         //next greatest element
         int next[n];
         next[n-1]=-1;
         maxm=height[n-1];
         for(int i=n-2;i>=0;i--){
             next[i]=maxm;
             if(maxm <height[i]) maxm=height[i];
         }

         //minimum array
         int mini[n];
         for(int i=0;i<n;i++){
             mini[i]= min((prev[i]),(next[i]));
         }
         //calculating water
         int water =0;
         for(int i=1;i<n;i++){
             if(height[i]<mini[i]){
                 water+=(mini[i]-height[i]);
             }
         }

        return water;
    }
};
*/