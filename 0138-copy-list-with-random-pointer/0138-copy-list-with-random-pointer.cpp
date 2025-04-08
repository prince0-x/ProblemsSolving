/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        Node* temp = head;
        while (temp) {
            Node* copy = new Node(temp->val);
            copy->next = temp->next;
            temp->next = copy;
            temp = copy->next;
        }

        temp = head;
        while (temp) {
            if (temp->random)
                temp->next->random = temp->random->next;
            temp = temp->next->next;
        }

        Node* orig = head;
        Node* copyHead = head->next;
        Node* copy = copyHead;

        while (orig) {
            orig->next = orig->next->next;
            if (copy->next)
                copy->next = copy->next->next;
            orig = orig->next;
            copy = copy->next;
        }

        return copyHead;
    }
};