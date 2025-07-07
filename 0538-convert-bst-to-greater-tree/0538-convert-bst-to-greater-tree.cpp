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
    TreeNode* convertBST(TreeNode* root) {
        int total = 0;
        TreeNode* node = root;

        while (node) {
            if (node->right == nullptr) {
                total += node->val;
                node->val = total;
                node = node->left;
            } else {
                TreeNode* succ = node->right;
                while (succ->left && succ->left != node) {
                    succ = succ->left;
                }

                if (succ->left == nullptr) {
                    succ->left = node;
                    node = node->right;
                } else {
                    succ->left = nullptr;
                    total += node->val;
                    node->val = total;
                    node = node->left;
                }
            }
        }
        return root;
    }
};