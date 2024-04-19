/* Input a string and retrun the number of times the neighbouring characters are different from each other 
e.g. a b b c d e f f g h h*/

#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;
    int count = 0;
    int l = s.length();

    if (l == 1) {
        count = 0;
    } else {
        for (int i = 0; i < l; i++) {
            if (i == 0) {
                if (s[i] != s[i + 1]) {
                    count++;
                }
            } else if (i == l - 1) {
                if (s[i] != s[i - 1]) {
                    count++;
                }
            } else {
                if (s[i] != s[i + 1] && s[i] != s[i - 1]) {
                    count++;
                }
            }
        }
    }
    
    cout << count;

    return 0;
}
