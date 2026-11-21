// LeetCode 54: Spiral Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        vector<int> res;
        res.reserve(m * n);

        int top = 0, bottom = m - 1;
        int left = 0, right = n - 1;

        while (top <= bottom && left <= right) {
            for (int c = left; c <= right; ++c) {
                res.push_back(matrix[top][c]);
            }
            ++top;

            for (int r = top; r <= bottom; ++r) {
                res.push_back(matrix[r][right]);
            }
            --right;

            if (top <= bottom) {
                for (int c = right; c >= left; --c) {
                    res.push_back(matrix[bottom][c]);
                }
                --bottom;
            }

            if (left <= right) {
                for (int r = bottom; r >= top; --r) {
                    res.push_back(matrix[r][left]);
                }
                ++left;
            }
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> mat = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    vector<int> ans = sol.spiralOrder(mat);
    cout << "Spiral order: [";
    for (size_t i = 0; i < ans.size(); ++i) {
        cout << ans[i] << (i + 1 < ans.size() ? ", " : "");
    }
    cout << "]" << endl; // Expected: [1, 2, 3, 6, 9, 8, 7, 4, 5]
    return 0;
}