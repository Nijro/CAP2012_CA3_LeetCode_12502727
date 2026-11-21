// LeetCode 42: Trapping Rain Water
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0;
        int right = static_cast<int>(height.size()) - 1;
        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (left < right) {
            if (height[left] <= height[right]) {
                if (height[left] >= leftMax) {
                    leftMax = height[left];
                } else {
                    water += leftMax - height[left];
                }
                ++left;
            } else {
                if (height[right] >= rightMax) {
                    rightMax = height[right];
                } else {
                    water += rightMax - height[right];
                }
                --right;
            }
        }

        return water;
    }
};

int main() {
    Solution sol;

    vector<int> h1 = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << "Test 1 (Expected 6): " << sol.trap(h1) << endl;

    vector<int> h2 = {4, 2, 0, 3, 2, 5};
    cout << "Test 2 (Expected 9): " << sol.trap(h2) << endl;

    // Boundary: Too few bars to trap water
    vector<int> h3 = {2, 1};
    cout << "Test 3 boundary (Expected 0): " << sol.trap(h3) << endl;
    return 0;
}