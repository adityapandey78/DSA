#include <iostream>
#include <stack>
#include <string>
using namespace std;

string solve(string val1, string val2, char ch) {
    return  ch + val1+ val2 ; //isme bs idhr cheange kr diya
}

int main() {
    string s = "79+48*3/-"; // Postfix expression
    stack<string> val;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] >= '0' && s[i] <= '9') { 
            val.push(string(1, s[i])); 
        } else { 
            // Operator encountered
            
            string val2 = val.top(); val.pop();
            string val1 = val.top(); val.pop(); 
            string ans = solve(val1, val2, s[i]); 
            val.push(ans);
        }
    }

    cout << "Infix Expression: " << val.top() << endl; // Final result
    return 0;
}
