class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || k == 1) return head;

        // Check if there are at least k nodes to reverse
        ListNode* temp = head;
        for (int i = 0; i < k; ++i) {
            if (temp == nullptr) return head;  // Not enough nodes to reverse
            temp = temp->next;
        }

        // Reverse first k nodes
        ListNode* prev = nullptr;
        ListNode* curr = head;
        ListNode* next = nullptr;
        int count = 0;
        while (curr != nullptr && count < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            count++;
        }

        // After reversing, head becomes the tail of the group
        // Recurse for the rest of the list
        head->next = reverseKGroup(curr, k);

        // prev is the new head of the reversed group
        return prev;
    }
};
