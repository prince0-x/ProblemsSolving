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
    ListNode* swapPairs(ListNode* head) {
        if(!head or !head->next)return head;

        ListNode *curr=head;
        while(curr and curr->next){
           int data = curr->val;
           curr->val = curr->next->val;
           curr->next->val = data;
           curr = curr->next->next;
        }
        return head;
    }
};