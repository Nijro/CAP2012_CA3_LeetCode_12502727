// LeetCode 160: Intersection of Two Linked Lists
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA != pB) {
            pA = (pA == nullptr) ? headB : pA->next;
            pB = (pB == nullptr) ? headA : pB->next;
        }

        return pA;
    }
};

int main() {
    Solution sol;

    // Shared tail: c1(8) -> c2(4) -> c3(5)
    ListNode* c1 = new ListNode(8);
    c1->next = new ListNode(4);
    c1->next->next = new ListNode(5);

    // List A: 4 -> 1 -> c1
    ListNode* headA = new ListNode(4);
    headA->next = new ListNode(1);
    headA->next->next = c1;

    // List B: 5 -> 6 -> 1 -> c1
    ListNode* headB = new ListNode(5);
    headB->next = new ListNode(6);
    headB->next->next = new ListNode(1);
    headB->next->next->next = c1;

    ListNode* res = sol.getIntersectionNode(headA, headB);
    cout << "Intersection value (Expected 8): " << (res ? res->val : -1) << endl;

    // Boundary: No intersection
    ListNode* disA = new ListNode(2);
    ListNode* disB = new ListNode(3);
    cout << "Disjoint lists (Expected nullptr/0): " << (sol.getIntersectionNode(disA, disB) != nullptr) << endl;
    return 0;
}