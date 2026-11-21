// LeetCode 19: Remove Nth Node From End of List
#include <iostream>
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        for (int i = 0; i <= n; ++i) {
            fast = fast->next;
        }

        while (fast != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode* target = slow->next;
        slow->next = slow->next->next;
        delete target;

        return dummy.next;
    }
};

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

    // Test 1: [1, 2, 3, 4, 5], n = 2 -> [1, 2, 3, 5]
    ListNode* head1 = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(4, new ListNode(5)))));
    cout << "Test 1: "; printList(sol.removeNthFromEnd(head1, 2));

    // Test 2 (boundary): [1], n = 1 -> []
    ListNode* head2 = new ListNode(1);
    cout << "Test 2: "; printList(sol.removeNthFromEnd(head2, 1));
    return 0;
}