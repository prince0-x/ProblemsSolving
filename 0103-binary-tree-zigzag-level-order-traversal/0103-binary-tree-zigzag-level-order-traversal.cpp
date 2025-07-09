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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root == NULL){
            return ans;
        }
        int flag = 1;
        deque<TreeNode*>q;
        q.push_back(root);
        while(!q.empty()){
            int size = q.size();
            vector<int>temp;
            if(flag){
                for(int i=0;i<size;i++){
                    TreeNode* node = q.front();
                    q.pop_front();
                   
                    temp.push_back(node->val);
                    if(node->left != NULL)q.push_back(node->left);
                    if(node->right != NULL)q.push_back(node->right);
                }
            }else{
                for(int i=0;i<size;i++){
                     TreeNode* node = q.back();
                    q.pop_back();
                    temp.push_back(node->val);
                    if(node->right != NULL)q.push_front(node->right);
                    if(node->left != NULL)q.push_front(node->left);
                    
                }
            }

            flag = 1-flag;
            ans.push_back(temp);
        }
        return ans;
    }
};