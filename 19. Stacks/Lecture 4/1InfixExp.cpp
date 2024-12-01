#include <iostream>
#include <stack>
using namespace std;

int prio(char ch2)
    {
        if (ch2 == '+' || ch2 == '-')
            return 1;
        else
            return 2; // *,/
    }

int solve(int val1, int val2, char ch){
        if(ch=='+')return val1+val2;
        else if(ch=='-') return val1-val2;
        else if(ch=='*') return val1*val2;
        else return  val1/val2;
    }

int main()
{
    string s = "2+6*4/8-3";
    // we need to create 1 stack for the val and other for the ops
    stack<int> val;
    stack<int> op;
    
    for (int i = 0; i < s.length(); i++)
    {
        // check if s[i]is a digit (0-9)
        if (s[i] >= 48 & s[i] <= 57)
        {
            // above check if they are digits or not from the ASCII vals
            val.push(s[i] - 48); // valuee me push kr diya
        }
        else
        { // else the s[i]is an operator
            if (op.size() == 0 || prio(s[i]) >prio(op.top()))
            {
                // prio jyda hai uski to push krni hi pdegi
                // and blank stack ke caseme bhi
                op.push(s[i]);
            }
            else
            {
                // priority of(s[i])<=priority(op.top();)
                // we have to do val2 op val1
                while (op.size() > 0 && prio(s[i]) <= prio(op.top()))
                {
                    char ch = op.top();
                    op.pop();
                    int val2 = val.top();
                    val.pop();
                    int val1 = val.top();
                    val.pop();
                    int ans = solve(val1, val2, ch);
                    val.push(ans);
                }
                op.push(s[i]);
            }
        }
    }
    //the operator stack canhavee still values
    while(op.size()>0){
        //work krte raho
        char ch = op.top();
        op.pop();
        int val2 = val.top();
        val.pop();
        int val1 = val.top();
        val.pop();
        int ans = solve(val1, val2, ch);
        val.push(ans);
    }
    cout<<val.top();
    return 0;
}