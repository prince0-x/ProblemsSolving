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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return nullptr;
        ListNode dummy(-1);
        ListNode*temp= &dummy;
        ListNode* curr = head;
        while (curr) {
            temp->next = new ListNode(curr->val);
            temp = temp->next;
            if (curr->next) curr = curr->next->next;
            else break;
       }
        
               
    curr = head->next;
    while(curr){
        temp->next= new ListNode(curr->val);
        temp = temp ->next;
        if(curr->next)curr=curr->next->next;
        else break;
    }
        return dummy.next;
        
    }
};