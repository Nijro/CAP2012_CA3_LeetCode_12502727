// LeetCode 1342: Number of Steps to Reduce a Number to Zero
#include <iostream>
using namespace std;

class Solution {
public:
    int numberOfSteps(int num) {
        int steps = 0;
        while (num > 0) {
            if (num % 2 == 0) {
                num /= 2;
            } else {
                num -= 1;
            }
            steps++;
        }
        return steps;
    }
};

int main() {
    Solution sol;
    cout << "num = 14 -> " << sol.numberOfSteps(14) << endl; // Expected: 6
    cout << "num = 8  -> " << sol.numberOfSteps(8) << endl;  // Expected: 4
    cout << "num = 0  -> " << sol.numberOfSteps(0) << endl;  // Expected: 0 (boundary)
    return 0;
}