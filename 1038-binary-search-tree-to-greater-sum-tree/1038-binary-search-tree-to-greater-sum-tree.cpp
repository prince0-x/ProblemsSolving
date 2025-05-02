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
    if (!root) return root;
    
    int totalSum = 0, sum = 0;

    // First Morris Traversal to calculate total sum of all nodes
    TreeNode* curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            totalSum += curr->val;
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                totalSum += curr->val;
                curr = curr->right;
            }
        }
    }

    // Second Morris Traversal to transform the BST into GST
    curr = root;
    while (curr != NULL) {
        if (curr->left == NULL) {
            int v = curr->val;
            curr->val = totalSum - sum;
            sum += v;
            curr = curr->right;
        } else {
            TreeNode* pred = curr->left;
            while (pred->right != NULL && pred->right != curr) {
                pred = pred->right;
            }

            if (pred->right == NULL) {
                pred->right = curr;
                curr = curr->left;
            } else {
                pred->right = NULL;
                int v = curr->val;
                curr->val = totalSum - sum;
                sum += v;
                curr = curr->right;
            }
        }
    }

    return root;
}

};