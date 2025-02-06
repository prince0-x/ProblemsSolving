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
ListNode*fmid(ListNode*head)
{
    if(head == nullptr)
    {
        return head;
    }
    ListNode*s=head,*f=head;
    while(f->next != nullptr)
    {
        f=f->next;
        if(f->next!=nullptr)
        {
            f=f->next;
            s= s->next;
        }
        
    }
    return s;
}
ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode head(-1);
        ListNode *curr=&head;
        while(list1 and list2)
        {
            if(list1->val < list2->val)
            {
                curr->next= list1;
                list1 = list1->next;
                curr= curr->next;
            }
            else{
                curr -> next = list2;
                list2 = list2->next;
                curr = curr ->next;
            }
        }
        if (list1) curr->next = list1;
        else curr->next = list2;
        return head.next;
    }
    ListNode* sortList(ListNode* head) {
        if(head == nullptr or head->next == nullptr) return head;

        ListNode*mid = fmid(head);
        ListNode * left = head;
        ListNode * right = mid->next;
        mid -> next = nullptr;
        left =  sortList(left);
        right = sortList(right);
        
        ListNode * ans = merge(left,right);
        return ans;
    }
};