//two elements of an array a, a[i] and a[j] form an inversion if a[i]<a[j] and i<j. Given an array of integers. find the inversion count in the array.
/*
n-> 0 1 2 3 4 
a-> 5 1 8 2 3
(5,1),(5,2),(5,3),(8,2),(8,3)
*/

//Method 2- Using Merge Sort without any global var


#include<iostream>
#include<vector>
using namespace std;
// int c=0; //making a global variale to count all 
int inversion(vector<int>&a,vector<int>&b){
    int count =0;
    int i=0,j=0;//a ,b
    while(i<a.size()&&j<b.size()){
        if(a[i]>b[j]){
            count+=(a.size()-i);
            j++;
        }
        else{//a[i]<=b
            i++;
        }
    }
    return count;
}
void merge(vector<int>&a,vector<int>&b,vector<int>&res){
    int i=0,j=0,k=0;//for a,b,res
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j])res[k++]=a[i++];
        else res[k++]=b[j++];
    
        if(i==a.size())while(j<b.size())res[k++]=b[j++];
        if(j==b.size())while(i<a.size())res[k++]=a[i++];
    }
}

int mergesort(vector<int>&v){
    int n=v.size();
    int count=0; //*
    if(n==1) return 0; //jab sbse last me vectors ki size 1 hi hogi to 1 return  krega

     int n1=n/2;
     int n2=(n-n/2);
    vector<int>a(n1),b(n2);

    //copy pasting these two part in these respective array
    for(int i=0;i<n1;i++)a[i]=v[i];
    for(int i=0;i<n2;i++)b[i]=v[i+n1];
    
    //magic aka recursion
     count+=mergesort(a);
     count+=mergesort(b);
    //isse global var hat raha hai
    //har inke baad to inverion chalega hi uske baad wo compare ho jayenge
    //count the inversions
    count+=inversion(a,b);
     //merge
     merge(a,b,v);

    //delete th extra spaces
    a.clear();
    b.clear();
    return count;
    //merge function hi mene return type int kra diya hai
}
int main(){
    int arr[]{5,1,3,0,4,2,6};
    int n1=sizeof(arr)/sizeof(arr[0]);vector<int> a(arr,arr+n1);

    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    
    cout<<mergesort(a);


return 0;
}
/*
Note->
1.) *-> jab n=1 hoga tb to count 0 hi rhega
2.) fir aage recursion proceed krega and agar inversion hota hai to count badhte jaayega
3.) isme hmne mergesort() ko hi int return type bna diya hai
 
*/