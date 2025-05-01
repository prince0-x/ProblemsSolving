/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* bstToGst(TreeNode* root) {
        if(!root || (!root->left & !root->right))return root;
        queue<TreeNode*>q;
        q.push(root);
        int count =0;
        while(!q.empty())
        {
            TreeNode * temp = q.front();
            q.pop();
           
            if(temp->val!=0) count++;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        int totalsum=(count*(count+1))/2;
        q.push(root);
        while(!q.empty())
        {
            TreeNode * temp = q.front();
            q.pop();
            int v = temp->val;
            temp->val = v+totalsum-(v*(v+1))/2;
            if(temp->left)q.push(temp->left);
            if(temp->right)q.push(temp->right);
        }
        return root;

    }
};