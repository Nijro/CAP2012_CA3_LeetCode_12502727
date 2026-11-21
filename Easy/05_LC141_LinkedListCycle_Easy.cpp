// LeetCode 141: Linked List Cycle
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head;

        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;

    // Test 1: [3, 2, 0, -4] with cycle at index 1
    ListNode* n1 = new ListNode(3);
    ListNode* n2 = new ListNode(2);
    ListNode* n3 = new ListNode(0);
    ListNode* n4 = new ListNode(-4);
    n1->next = n2; n2->next = n3; n3->next = n4; n4->next = n2;
    cout << "Has cycle (Expected 1): " << sol.hasCycle(n1) << endl;

    // Test 2: Single node without cycle (boundary)
    ListNode* single = new ListNode(1);
    cout << "Single node cycle (Expected 0): " << sol.hasCycle(single) << endl;
    return 0;
}