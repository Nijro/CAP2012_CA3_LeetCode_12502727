// LeetCode 283: Move Zeroes
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int write = 0;

        for (int read = 0; read < (int)nums.size(); ++read) {
            if (nums[read] != 0) {
                if (read != write) {
                    swap(nums[write], nums[read]);
                }
                ++write;
            }
        }
    }
};

void printVec(const vector<int>& v) {
    cout << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        cout << v[i] << (i + 1 < v.size() ? ", " : "");
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    vector<int> nums1 = {0, 1, 0, 3, 12};
    sol.moveZeroes(nums1);
    cout << "Test 1: "; printVec(nums1); // Expected: [1, 3, 12, 0, 0]

    vector<int> nums2 = {0};
    sol.moveZeroes(nums2);
    cout << "Test 2 (boundary): "; printVec(nums2); // Expected: [0]
    return 0;
}