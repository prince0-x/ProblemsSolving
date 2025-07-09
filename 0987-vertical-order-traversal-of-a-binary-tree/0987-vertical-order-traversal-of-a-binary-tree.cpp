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
    map<int ,map<int, multiset<int>>>m;

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        queue<tuple<TreeNode*, int, int>>q;
        q.push({root, 0, 0});
        while(!q.empty()){
            auto [node, axis, lvl]= q.front();
            q.pop();
            m[axis][lvl].insert(node->val);
            if(node->left)q.push({node->left, axis-1, lvl+1});
            if(node->right)q.push({node->right, axis+1, lvl+1});
        }
        for(auto& [_,b] : m){
            vector<int> curr;
            for(auto& [_,c] : b)
                for(auto& num : c) curr.push_back(num);
            res.push_back(curr);
        }
        return res;
    }
};