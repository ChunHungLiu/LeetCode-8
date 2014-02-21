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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        vector<vector<int> > res;
        if (!root) return res;
        
        queue<TreeNode*> q[2];
        int which = 0;
        q[which].push(root);
        bool normal = true;
        vector<int> x;
        
        while (!q[which].empty()) {
            TreeNode* cur = q[which].front(); q[which].pop();
            x.push_back(cur->val);
            int nxt = (which+1)%2;
            if (cur->left)  { q[nxt].push(cur->left); }
            if (cur->right) { q[nxt].push(cur->right); }
            
            if (q[which].empty()) {
                if (normal) { res.push_back(x); }
                else { 
                    reverse(x.begin(), x.end());
                    res.push_back(x); 
                }
                x.clear();
                which = nxt; normal = !normal;
            }
        }
        
        return res;
    }
};