// LeetCode 4: Median of Two Sorted Arrays
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int halfLen = (m + n + 1) / 2;
        int low = 0, high = m;

        while (low <= high) {
            int cut1 = low + (high - low) / 2;
            int cut2 = halfLen - cut1;

            int L1 = (cut1 == 0) ? INT_MIN : nums1[cut1 - 1];
            int R1 = (cut1 == m) ? INT_MAX : nums1[cut1];
            int L2 = (cut2 == 0) ? INT_MIN : nums2[cut2 - 1];
            int R2 = (cut2 == n) ? INT_MAX : nums2[cut2];

            if (L1 <= R2 && L2 <= R1) {
                if ((m + n) % 2 == 1) {
                    return max(L1, L2);
                }
                return (max(L1, L2) + min(R1, R2)) / 2.0;
            } else if (L1 > R2) {
                high = cut1 - 1;
            } else {
                low = cut1 + 1;
            }
        }
        return 0.0;
    }
};

int main() {
    Solution sol;

    vector<int> a1 = {1, 3}, b1 = {2};
    cout << "Test 1 (Expected 2): " << sol.findMedianSortedArrays(a1, b1) << endl;

    vector<int> a2 = {1, 2}, b2 = {3, 4};
    cout << "Test 2 (Expected 2.5): " << sol.findMedianSortedArrays(a2, b2) << endl;

    // Boundary: One empty array
    vector<int> emptyArr = {}, nonEmpty = {1};
    cout << "Test 3 boundary (Expected 1): " << sol.findMedianSortedArrays(emptyArr, nonEmpty) << endl;
    return 0;
}