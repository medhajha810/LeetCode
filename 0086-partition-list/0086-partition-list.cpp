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
    ListNode* partition(ListNode* head, int x) {
        if(!head || !head->next) return head;
        ListNode* dummy=new ListNode(0);
        ListNode* dummy2=new ListNode(0);
        ListNode* prev = dummy;
        ListNode* after=dummy2;
        while(head){
            if(head->val<x){
                prev->next=head;
                prev=prev->next;
            }
            else{
                after->next=head;
                after=after->next;
            }
            head=head->next;
        }
        after->next=NULL;
        prev->next = dummy2->next;          // link the two parts

        ListNode* newHead = dummy->next;
        return newHead;
        
    }
};