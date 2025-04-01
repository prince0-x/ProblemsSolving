/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:

    vector<vector<int>> levelOrder(Node* root) {
        if(!root)return {{}};
        queue<Node*>q;
        q.push(root);
        vector<vector<int>>ans;

        while(!q.empty()){
            vector<int>temp;
            int size = q.size();


            for(int i =0;i<size ;i++){
                Node*f = q.front();
                q.pop();
                temp.push_back(f->val);

                for(Node* child: f->children){
                    q.push(child);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};