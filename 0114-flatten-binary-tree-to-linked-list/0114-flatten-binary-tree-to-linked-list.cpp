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
    void flatten(TreeNode* root) {
        if(!root)return ;
        TreeNode*ptr=root;

        while(ptr){
            if(ptr->left){
                TreeNode * start= ptr->left;
                TreeNode* end = ptr->left;
                while(end->right){
                    end = end->right;
                }
                end->right = ptr->right;
                ptr->right= start;
                ptr->left=nullptr;
            }
            ptr=ptr->right;
            
        }
    }
};