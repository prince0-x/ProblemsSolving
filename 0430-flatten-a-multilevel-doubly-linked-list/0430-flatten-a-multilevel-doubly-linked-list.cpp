/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        Node*curr = head, *nxt=nullptr;
       
        while(curr){ 
            if(curr->child){
                Node * ctail = curr->child;
                while(ctail->next){
                    ctail=ctail->next;
                }
                ctail->next= curr->next;
               if(curr->next) curr->next->prev=ctail;
                curr->next = curr->child;
                curr->child->prev=curr;
                curr->child = nullptr;
            }
            curr=curr->next;
        }
        return head;
    }
};