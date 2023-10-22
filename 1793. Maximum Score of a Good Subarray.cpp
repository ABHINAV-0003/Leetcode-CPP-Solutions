#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int sol = nums[k];
        int mini = nums[k];
        int i = k;
        int j = k;
        int n = nums.size();
        while (i > 0 || j < n - 1) {
            if (i == 0) {
                j++;
            } else if (j == n - 1) {
                i--;
            } else if (nums[i - 1] < nums[j + 1]) {
                j++;
            } else {
                i--;
            }
            mini = min(mini, min(nums[i], nums[j]));
            sol = max(sol, mini * (j - i + 1));
        }
        return sol;
    }
};

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int& num : nums) {
        cin >> num;
    }
    cout << Solution().maximumScore(nums, k) << endl;
    return 0;
}