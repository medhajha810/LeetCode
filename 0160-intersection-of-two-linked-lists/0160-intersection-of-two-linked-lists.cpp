/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (!headA || !headB) return nullptr;

        ListNode* a = headA;
        ListNode* b = headB;

        // Traverse both lists. When either pointer reaches the end,
        // switch it to the other list's head.
        while (a != b) {
            a = a ? a->next : headB;
            b = b ? b->next : headA;
        }

        return a; // Either the intersection node or nullptr
    }
};
