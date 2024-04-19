//merge two sorted arrays
#include <iostream>
#include <vector>
using namespace std;

vector<int> merge(vector<int> &v1,vector<int>&v2){
    //vector bhi return kr skte hain
    int n=v1.size();
    int m=v2.size();
    
    int i=0;//arr1
    int j=0;//arr2
    int k=0;//arr3
    vector <int>res(n+m);

    while(i<=n-1 && j<=m-1){
        //jo chhota hoga usko pehle bhrna hai and then bada wala bhrna hai 
        if (v1[i]<v2[j])
        {
            res[k]=v1[i];
            i++;
            k++;
            //jiska bhi bhr rhe hain array me use hi increase kr rhe hain and then array aage badh rha hai
        }
        else
        { //v2[j]<v1[i] 
        //idhr dusre ka elememt bada hai so ise bhr rhe 
            res[k]=v2[j];
            j++;
            k++;
        }

        // ab sbse last me bachi hui elements ko dekhna hai like jisme arrayt croos ho jaata hai

        if (i==n)
        {
            //arr1 ke saare elements utha chuka hoon

            while (j<=m-1)
            {
                res[k]=v2[j];
                k++;
                j++;
            }

        }
        if(j==m){
            while (j<=n-1)
            {
                res[k]=v1[i];
                k++;
                i++;
            }
            
        }
        
        
    }
    return res;
}


int main(){
    // int arr1[4]={1,4,5,8};
    // int arr2[6]={2,3,6,7,10,12};
    // int arr3[10];

    vector<int>arr1;
    
    arr1.push_back(1);
    arr1.push_back(4);
    arr1.push_back(5);
    arr1.push_back(8);
    for (int i = 0; i < arr1.size(); i++)
    {
        cout<<arr1[i]<<" ";
    }
    cout<<endl;

    vector<int>arr2;
    arr2.push_back(2);
    arr2.push_back(3);
    arr2.push_back(13);
    arr2.push_back(7);
    arr2.push_back(10);
    arr2.push_back(12);
    for (int i = 0; i < arr2.size(); i++)
    {
        cout<<arr2[i]<<" ";
    }
    cout<<endl;

    vector<int>arr3=merge(arr1,arr2);
    

    for (int i = 0; i < arr3.size(); i++)
    {
        cout<<arr3[i]<<" ";
    }
    

}










