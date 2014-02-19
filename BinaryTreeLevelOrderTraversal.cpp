/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) { return res; }
        
        queue<TreeNode *> q[2];
        int which = 0;
        q[which].push(root);
        
        vector<int> x;
        while (!q[which].empty()) {
            TreeNode* cur = q[which].front(); q[which].pop();
            x.push_back(cur->val);
            if (cur->left) { q[(which+1)%2].push(cur->left); }
            if (cur->right) { q[(which+1)%2].push(cur->right); }
            
            if (q[which].empty()) {
                res.push_back(x); x.clear();
                which = (which+1)%2;
            }
        }
        
        return res;
    }
};