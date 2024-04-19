/* write a program to copy the contents of one array into another in the reverse order without using any extra array


also write a code to get the reverse of the parts of the array
*/
#include<iostream>
#include<vector>
using namespace std;

void display(vector<int>&a){
    for (int  i = 0; i < a.size(); i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
void reversePart(int i, int j, vector<int>& v){
        while (i<=j)
        {
            int temp=v[i];
            v[i]=v[j];
            v[j]=temp;
            i++; 
            j--;
        }
        
    }
int main(){
    vector<int>v1;
    int n;
    cout<<"Enter the size of an array: ";
    cin>>n;
    int q;
    for (int i = 0; i < n; i++)
    {
        cin>>q;
        v1.push_back(q);
    }
    cout<<"Entered array is:";
    display(v1);

//    int i=0;
    //int j=v1.size()-1;
//    while (i<=j)
//    {
//     //swap v[i] and v[j]
//     int temp=v1[i];
//     v1[i]=v1[j];
//     v1[j]=temp;
//     i++;
//     j--;

//    }

   //using for loop
//    for (int  i = 0; i < v1.size()-1; i++,j--)
//    {
//    int temp=v1[i];
//     v1[i]=v1[j];
//     v1[j]=temp;
//    }
//using inbuilt function

   //reverse(v1.begin(),v1.end());

reversePart(0,2,v1);
   display(v1);

}