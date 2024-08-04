#include <bits/stdc++.h>
using namespace std;

class Solution0 {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        if (n1 < n2) {
            return findMedianSortedArrays(nums2, nums1);
        }
        int l = 0;
        int h = 2 * n2;
        while (l <= h) {
            int mid2 = (l + h) / 2;
            int mid1 = n1 + n2 - mid2;
            double l1 = mid1 == 0 ? INT_MIN : nums1[(mid1 - 1) / 2];
            double l2 = mid2 == 0 ? INT_MIN : nums2[(mid2 - 1) / 2];
            double r1 = mid1 == 2 * n1 ? INT_MAX : nums1[mid1 / 2];
            double r2 = mid2 == 2 * n2 ? INT_MAX : nums2[mid2 / 2];
            if (l1 > r2) {
                l = mid2 + 1;
            } else if (l2 > r1) {
                h = mid2 - 1;
            } else {
                return (max(l1, l2) + min(r1, r2)) / 2;
            }
        }
        return -1;
    }
};

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> merge(n1 + n2, 0);
        int i = 0, j = 0, k = 0;
        while (i < n1 || j < n2) {
            if (i < n1 && j < n2) {
                if (nums1[i] <= nums2[j]) {
                    merge[k++] = nums1[i++];
                } else {
                    merge[k++] = nums2[j++];
                }
            } else if (i < n1) {
                merge[k++] = nums1[i++];
            } else {
                merge[k++] = nums2[j++];
            }
        }
        int total = n1 + n2;
        if (total % 2 == 0) {
            int mid1 = merge[total / 2 - 1];
            int mid2 = merge[total / 2];
            return ((double)mid1 + (double)mid2) / 2.0;
        } else {
            return static_cast<double>(merge[total / 2]);
        }
    }
};

int main() {
    int m, n;
    cin >> m >> n;
    vector<int> nums1(m), nums2(n);
    for (int i = 0; i < m; i++) {
        cin >> nums1[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> nums2[i];
    }
    cout << Solution().findMedianSortedArrays(nums1, nums2) << endl;
    return 0;
}