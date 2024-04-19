/* given n no of string consisting of digits from 0 to 9. Return the index of string which has maximum value. (take 0 bases indexing)


INPUT:0123,0023,456,00182,940,2901
OUTPUT: 5 */
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string arr[] ={"0123","0023","456","00182","940","002901"};
    int max= stoi(arr[0]);
    string maxs=arr[0];
    for (int i = 1; i <=5; i++)
    {
        int x= stoi(arr[i]);
        if (x>max)
        {
           max=x;
           maxs=arr[i];
        }
        
    }
    cout<<max<<" "<<maxs;

//maxs for printing the maximum array i.e actual array
    return 0;
}



