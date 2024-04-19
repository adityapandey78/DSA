#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main(){
    string str="Aditya";
    int n=str.length();
    cout<<n<<endl;

    str.push_back('p'); //adds in the end
    cout<<str<<endl;

    str.pop_back(); //deletes from the end
    cout<<str<<endl;

    string s ="Pandey";
    //+ operator
    s= str+s;
    cout<<s<<endl;
    s=s+"Paddy";
    cout<<s<<endl;
    s="paddy"+str;
    cout<<s<<endl;

    //reverse
    reverse(s.begin()+2,s.end()-1);
    cout<<s<<endl;
    reverse(s.begin()+2,s.end()+n/2);
    cout<<s<<endl;

    //substr()
    s.substr(4,2);
    cout<<s<<endl;

    return 0;
}