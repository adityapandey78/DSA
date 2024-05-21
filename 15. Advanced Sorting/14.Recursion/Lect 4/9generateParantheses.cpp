// leetcode 22
#include <iostream>
#include <string>
using namespace std;
void generate(string s, int open, int close, int n)
{
    // base case
    if (open == n && close == n)
    {
        cout << s << endl;
        return;
    }

    //isme open > close rehta hai..tb run krayenge
    if (open < n)
    {
        generate(s + '(', open + 1, close, n);
    }
    //and close open se hmesha km hona chaiye
    if (close < open)
    {
        generate(s + ')', open, close + 1, n);
    }
}
int main()
{
    int n = 4;
    string s = "";
    generate(s, 0, 0, n);
    return 0;
}