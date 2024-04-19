#include<iostream>
using namespace std;
int main(){
    int arr[]={4,2,6,1,7};
    int *ptr =arr; //giving address
    //int *ptr=&arr error

    for (int i = 0; i <= 4; i++)
    {
        // cout<<*ptr<<" ";
        // ptr++;   //1st method to print
        //cout<<ptr[i]<<" ";    //2nd method to print
        //cout<<ptr[i]<<" ";//3rd method to print the array
        cout<<i[arr]<<" ";//4th method
        
    }
    cout<<endl;
    ptr=arr;  //need to reset ptr to the beginning of the array -- nahi to errors aayenge 

    *ptr=8;//now the first element got updated
    ptr++; //ptr pointing to second element
    *ptr=9;//2nd element got updated
    ptr--;
    //again cameback to its 1srt element
    cout<<endl;
    for (int i = 0; i <= 4; i++)
    {
        cout<<*ptr<<" ";
        ptr++;
    }
    
    ptr=arr;

    return 0;
}