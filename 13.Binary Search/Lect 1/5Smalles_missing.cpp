/* Given a sorted array of non negative distinct integers, find the smallest missing non-negative element in it*/

#include<iostream>
using namespace std;

int main() {
//method 1
    int arr[] = {0, 1, 2, 3, 4, 6, 7, 9};
    int n=9;

//     for (int i = 0; i < 10; i++) {
//         if (i != arr[i]) {
//             cout << i;
//             break;
//         }
//     }

int lo=0;
int hi=n-1;
int ans=-1;

while (lo<=hi)
{
    int mid=lo+(hi-lo)
/2;
if(arr[mid]==mid) lo=mid+1;
else
{
    ans=mid;
    hi=mid-1;
}


}
cout<<ans;
    return 0;
}