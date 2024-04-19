/*Given a string 'str' , return the word that is occuring the most number of times*/

#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<algorithm>
using namespace std;
int main(){
    string str="Aditya Pandey DSA learning DSA. DSA is most important subject in CSE DSA DSA .";
    stringstream ss(str);
    string temp;
    vector<string>v;
    while (ss>>temp)
    {
        v.push_back(temp);
    }

    //sorting the vector ,taaki same words ek pass aa jaaye
    sort(v.begin(),v.end());
    int maxCount=1;
    int count=1;
    for (int i = 1; i < v.size(); i++)
    {
        if(v[i]==v[i-1]) count++;
        /* it checkes the neighbouringf word , agar same hai to badh jayega nahi to same hi rahega*/
        else count=1;
        maxCount=max(maxCount,count);

        //getting the maxm count
    }
    
    count=1;
    for (int i = 1; i < v.size(); i++)
    {
        if(v[i]==v[i-1]) count++;
        else count=1;
        if (count==maxCount)
        {
            cout<<v[i]<<" "<<maxCount<<endl;
        }
        
    }
    


    // // //pritning the vector
    // for (int i = 0; i < v.size(); i++)
    // {
    //     cout<<v[i]<<endl;
    // }
    
    //cout<<endl<<maxCount;
    return 0;
}