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
int ans=INT_MIN;
    int sum(TreeNode* root){
        if(!root) return 0;

        int lv = sum(root->left);
        if(lv < 0)lv=0;
        int rv = sum(root->right);
        if(rv < 0) rv = 0;

        ans = max(ans, root->val + max({lv,rv,lv+rv}));
        return root->val + max({0,lv,rv});
    }
    int maxPathSum(TreeNode* root) {
        sum(root);
        return ans;
    }
};