#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(int n) {
        vector<int> dp(n + 1, 0);
        for (int i = 2; i <= n; i++) {
            dp[i] = i;
            for (int j = i / 2; j > 1; j--) {
                if (i % j == 0) {
                    dp[i] = dp[j] + (i / j);
                    break;
                }
            }
        }
        return dp[n];
    }
};

int main() {
    int n;
    cin >> n;
    cout << Solution().minSteps(n);
    return 0;
}