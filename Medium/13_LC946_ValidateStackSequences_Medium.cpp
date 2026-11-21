// LeetCode 946: Validate Stack Sequences
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0;

        for (int x : pushed) {
            st.push(x);

            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                ++j;
            }
        }

        return st.empty();
    }
};

int main() {
    Solution sol;
    vector<int> pushed = {1, 2, 3, 4, 5};
    vector<int> popped1 = {4, 5, 3, 2, 1};
    vector<int> popped2 = {4, 3, 5, 1, 2};

    cout << "Test 1 (Expected 1): " << sol.validateStackSequences(pushed, popped1) << endl;
    cout << "Test 2 (Expected 0): " << sol.validateStackSequences(pushed, popped2) << endl;
    return 0;
}