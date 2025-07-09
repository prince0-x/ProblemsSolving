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
unordered_map<TreeNode*, TreeNode*>parent;
    int amountOfTime(TreeNode* root, int start) {
        if(!root)return 0;
        queue<TreeNode*>q,q2;
        unordered_set<TreeNode*> st;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();
            if(node->val==start){
                q2.push(node);
                st.insert(node);
            }
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]= node;
                q.push(node->right);
            }
        }

        int ans=-1;
        while(!q2.empty()){
            ans++;
            int size=q2.size();
            for(int i=0;i<size;i++){
                TreeNode*node = q2.front();
                q2.pop();
                if(node->left && !st.count(node->left)){
                    q2.push(node->left);
                    st.insert(node->left);
                }
                if(node->right && !st.count(node->right)){
                    q2.push(node->right);
                    st.insert(node->right);
                }
                if(parent.find(node)!=parent.end() && !st.count(parent[node])){
                    q2.push(parent[node]);
                    st.insert(parent[node]);
                }
            }
            
        }
        return ans;

    }
};