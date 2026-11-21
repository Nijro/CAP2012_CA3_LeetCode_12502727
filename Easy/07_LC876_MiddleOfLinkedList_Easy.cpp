// LeetCode 876: Middle of the Linked List
#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

ListNode* buildList(const vector<int>& vals) {
    ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : vals) {
        tail->next = new ListNode(v);
        tail = tail->next;
    }
    return dummy.next;
}

int main() {
    Solution sol;
    ListNode* oddList = buildList({1, 2, 3, 4, 5});
    cout << "Odd length middle (Expected 3): " << sol.middleNode(oddList)->val << endl;

    ListNode* evenList = buildList({1, 2, 3, 4, 5, 6});
    cout << "Even length middle (Expected 4): " << sol.middleNode(evenList)->val << endl;
    return 0;
}