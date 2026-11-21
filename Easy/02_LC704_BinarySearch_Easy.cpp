// LeetCode 704: Binary Search
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = (int)nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1, 0, 3, 5, 9, 12};
    cout << "Target 9 -> Index: " << sol.search(nums, 9) << endl;   // Expected: 4
    cout << "Target 2 -> Index: " << sol.search(nums, 2) << endl;   // Expected: -1
    vector<int> single = {5};
    cout << "Single [5], Target 5 -> Index: " << sol.search(single, 5) << endl; // Expected: 0
    return 0;
}