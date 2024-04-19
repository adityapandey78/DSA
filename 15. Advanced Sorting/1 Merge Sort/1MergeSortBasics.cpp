#include<iostream>
#include<vector>
using namespace std;

//me idhr by address pass kr rha hu coz dont wan tto use extra space
void merge(vector<int>&a,vector<int>&b,vector<int>&res){
int i=0; //a
int j=0; //b
int k=0; //res

while(i<a.size()&&j<b.size()){
    if(a[i]<=b[j]){  //to make the merge sort stable-> see notes 
        res[k]=a[i];
        k++;
        i++;

        //or we can just write these as 
        //res[k++]=a[i++];
    }
    else{
        res[k++]=b[j++];
    }
    if(i==a.size()){
        //iska matlab hai ki a end pe hai ekdm //that is a chhota hai to ab baaki saare b ke bacyhe huye bhar do
        while(j<b.size()){
            res[k++]=b[j++];
        }
    }
        //jab b hi chhota ho to a ko bhr do pehle
    if (j==b.size()){
        //b is at the end
        while(i<a.size()){
            res[k++]=a[i++];
        }
    }
    
        
}
}



int main(){
    int arr[]={1,4,5,8,45};
    int n1=sizeof(arr)/sizeof(arr[0]);
    int brr[]={2,3,6,7,10,12,82};
    int n2=sizeof(brr)/sizeof(brr[0]);
    
    //creating the exact copy of these as vectors
    vector<int>a(arr,arr+n1);
    vector<int>b(brr,brr+n2);
    vector<int>res(n1+n2);

    //calling the merge function
    merge(a,b,res);

    for(int i=0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
return 0;
}