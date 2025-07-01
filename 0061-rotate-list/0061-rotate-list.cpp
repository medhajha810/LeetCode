/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
       if (!head || !head->next || k == 0) return head;

        // Step 1: Count length of the list
        int n = 1; // Initialize as 1 to count the head node
        ListNode* tail = head;
        while (tail->next) {
            tail = tail->next;
            n++;
        }

        // Step 2: Make the list circular
        tail->next = head;

        // Step 3: Find the new tail (n - k % n - 1)th node
        k %= n;
        int stepsToNewTail = n - k;
        ListNode* newTail = head;
        for (int i = 1; i < stepsToNewTail; i++) {
            newTail = newTail->next;
        }

        // Step 4: Set the new head and break the circle
        ListNode* newHead = newTail->next;
        newTail->next = nullptr;

        return newHead;
        
    }
};