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
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) { return res; }
        
        queue<TreeNode*> q[2];
        int cur = 0, nxt = 1;
        q[cur].push(root);
        
        vector<int> x;
        
        while (!q[cur].empty()) {
            TreeNode* tmp = q[cur].front(); q[cur].pop();
            x.push_back(tmp->val);
            if (tmp->left) { q[nxt].push(tmp->left); }
            if (tmp->right) { q[nxt].push(tmp->right); }
            if (q[cur].empty()) {
                swap(cur, nxt);
                res.push_back(x);
                x.clear();
            }
        }
        
        reverse(res.begin(), res.end());
        
        return res;
    }
};