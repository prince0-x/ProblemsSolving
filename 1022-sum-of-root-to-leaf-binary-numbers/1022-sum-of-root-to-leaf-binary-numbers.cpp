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
int sum=0;
void solve(TreeNode*root,int level)
{
    if(!root)return;
    level=(level<<1)|root->val;
    if (!root->left && !root->right) {
            sum += level;
            return;
        }
    solve(root->left,level);
    solve(root->right,level);

}
    int sumRootToLeaf(TreeNode* root) {
        if(!root)return 0;
        solve(root,sum);
        return sum;
    }
};