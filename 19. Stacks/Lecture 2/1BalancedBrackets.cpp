#include <iostream>
#include <stack>
using namespace std;
bool isBalanced(string s)
{
    if (s.length() % 2 != 0)
        return false; // if the str is odd length

    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(s[i]);
        else // s[i]=')'
        {
            if (st.size() == 0)
                return false;
            else // ya fir
            {
                st.pop();//agar ) ye ho toh
            }
        }
    }
    if (st.size() == 0)
        return true;
    else
        return false;
}
/*
 TODO ek stack lenge usme ( isko insert kr denge and and fir compare krenge baaki se agar ) ye aaya toh stack me se pop kr denge  
 */
int main()
{
    string s = "()()())";
    cout<<isBalanced(s);
    return 0;
}