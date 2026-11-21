// LeetCode 203: Remove Linked List Elements
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode dummy(0, head);
        ListNode* curr = &dummy;

        while (curr->next != nullptr) {
            if (curr->next->val == val) {
                curr->next = curr->next->next;
            } else {
                curr = curr->next;
            }
        }

        return dummy.next;
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

void printList(ListNode* head) {
    cout << "[";
    while (head) {
        cout << head->val << (head->next ? " -> " : "");
        head = head->next;
    }
    cout << "]" << endl;
}

int main() {
    Solution sol;
    ListNode* l1 = buildList({1, 2, 6, 3, 4, 5, 6});
    cout << "Remove 6: "; printList(sol.removeElements(l1, 6)); // Expected: [1 -> 2 -> 3 -> 4 -> 5]

    ListNode* l2 = buildList({7, 7, 7, 7});
    cout << "Remove all 7s (boundary): "; printList(sol.removeElements(l2, 7)); // Expected: []
    return 0;
}