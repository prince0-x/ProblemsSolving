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
vector<vector<int>>ans;
    void solve(TreeNode*root, vector<int>&temp, int target)
    {
        if (!root) return;

        temp.push_back(root->val);
        target -= root->val;

        if (!root->left && !root->right && target == 0) {
            ans.push_back(temp);
        }

        solve(root->left, temp, target);
        solve(root->right, temp, target);

        temp.pop_back(); 
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>temp;
        if(!root)return {};
        solve(root, temp, targetSum);
        return ans;
    }
};