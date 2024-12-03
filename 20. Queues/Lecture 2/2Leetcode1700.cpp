/*
class Solution {
public:
    int countStudents(vector<int>& arr, vector<int>& sand) {
        stack<int>st;
        queue<int>q;
        for(int i=0;i<arr.size();i++){
         q.push(arr[i]);   
        }
        int i=0; //to traverse the sandiwsches array
        int count=0;//var to count 
        while(q.size()>0 && count!=q.size()){
            if(q.front()==sand[i]){
                count=0; //Very IMP
                q.pop();
                i++;
            }
            else{
                q.push(q.front());
                q.pop();
                count++; //kitni baar aage wala elem pechh egya use countk kr rhe ain
            }
        }
        return q.size(); //agar count ==q.size ke to q,size ans hoga ni to wese bhi 0 hota
        //infinite loop se bachne ke liye count use kra..bahut achha
    }
};
 */