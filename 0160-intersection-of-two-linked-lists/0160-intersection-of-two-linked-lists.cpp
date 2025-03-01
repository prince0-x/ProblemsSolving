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
        ListNode*a=headA;
        ListNode*ans=NULL;
        ListNode*temp;
        while(a!=NULL)
        {
            temp=headB;
            while(temp!=NULL)
            {
                if(temp==a)
                {
                    ans=a;
                    break;
                }
                temp=temp->next;
            }
            if(ans)
            {
                break;
            }
            a=a->next;
        }
        return ans;
    }
};