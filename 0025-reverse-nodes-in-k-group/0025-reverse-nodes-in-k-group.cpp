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
private:
    int length(ListNode*head){
        int l=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            l++;
        }
        return l;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(length(head) < k)
        {
            return head;
        }
        ListNode*prev=NULL;
        ListNode*next;
        ListNode*curr=head;
        int i=0;
        while(curr!=NULL&&i<k)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i++;
        }
        if(next!=NULL)
        {
            head->next=reverseKGroup(next,k);
        }
       return prev;
    }
};