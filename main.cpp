
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int longestValidParentheses(string s) {
    int n = s.length();

    vector<int> dp(n, 0);
    int maxLength = 0;

    for (int i = 1; i < n; i++) {

        if (s[i] == ')') {

            if (s[i - 1] == '(') {
                dp[i] = 2 + (i >= 2 ? dp[i - 2] : 0);
            }

            else if (i - dp[i - 1] - 1 >= 0 &&
                     s[i - dp[i - 1] - 1] == '(') {

                dp[i] = dp[i - 1] + 2;

                if (i - dp[i - 1] - 2 >= 0) {
                    dp[i] += dp[i - dp[i - 1] - 2];
                }
            }

            maxLength = max(maxLength, dp[i]);
        }
    }

    return maxLength;
}

int main() {
    string s;

    getline(cin, s);

    cout << longestValidParentheses(s) << endl;

    return 0;
}
