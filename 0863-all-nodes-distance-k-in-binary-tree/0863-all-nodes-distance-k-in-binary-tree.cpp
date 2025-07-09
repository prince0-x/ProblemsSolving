/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*, TreeNode*>parent;
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> res;
        queue<TreeNode*>q,q2;
        unordered_set<TreeNode*> st;
        q.push(root);
        while(!q.empty()){
            TreeNode*node = q.front();
            q.pop();
            if(node->left){
                parent[node->left]=node;
                q.push(node->left);
            }
            if(node->right){
                parent[node->right]= node;
                q.push(node->right);
            }
        }
        q2.push(target);
        st.insert(target);
        int ans=-1;
        while(!q2.empty()){
            ans++;
            int size=q2.size();
            for(int i=0;i<size;i++){
                TreeNode*node = q2.front();
                if(ans == k) res.push_back(node->val);
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
            if(ans == k) return res;
        }
        return res;
    }
};