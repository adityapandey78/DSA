/*
class Solution {
public:
    int bestClosingTime(string customers) {
         int n=customers.length();

         //generating the presum array
         int pre[n+1]; //No  of N before Kth hour
         int suff[n+1]; //No. of Y after and including Kth hour
         pre[0]=0;
         int Ncount=0;
         for(int i=0;i<n;i++){
         pre[i+1]=pre[i] +((customers[i]=='N')?1:0);
         }
        suff[n]=0;
         for(int i=n-1;i>=0;i--)
        {
            suff[i]=suff[i+1] +((customers[i]=='Y') ? 1:0);
        }
        int minPen=n;
        for(int i=0;i<=n;i++){
            pre[i]+=suff[i];
            int pen=pre[i];
            minPen=min(minPen,pen);
        }
        for(int i=0;i<=n;i++){
            int pen=pre[i];
            if(pen==minPen) return i;
        }
    return n;
                           
    }
};*/