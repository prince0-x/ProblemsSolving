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
    int l(ListNode*head)
    {
        int cnt=0;
        ListNode*temp=head;
        while(temp!=NULL)
        {
            temp=temp->next;
            cnt++;
        }
        return cnt/2;
    }
    ListNode* middleNode(ListNode* head) {
        ListNode*temp=head;
        int ans=l(head);
        int cnt=0;
        while(cnt<ans)
        {
            temp=temp->next;
            cnt++;
        }
        return temp;
        
    }
};