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
    vector<vector<int> > pathSum(TreeNode *root, int sum) {
        vector<vector<int> > res;
        if (!root) { return res; }
        
        stack<TreeNode*> s;
        s.push(root);
        TreeNode* pre = NULL;
        
        vector<int> x;
        x.push_back(root->val);
        int cur_sum = root->val;
        
        while (!s.empty()) {
            TreeNode* cur = s.top();
            if (!pre || pre->left == cur || pre->right == cur) {
                if (cur->left) { s.push(cur->left); }
                else if (cur->right) { s.push(cur->right); }
                
                if (cur->left || cur->right) { x.push_back(s.top()->val); cur_sum += x.back(); }
            } else if (cur->left == pre) {
                if (cur->right) { s.push(cur->right); }
                
                if (cur->right) { x.push_back(s.top()->val); cur_sum += x.back(); }
            } else {
                s.pop();

                if (!cur->left && !cur->right && cur_sum == sum) {
                    res.push_back(x);
                }
                cur_sum -= cur->val; x.pop_back();
            }
            pre = cur;
        }
        
        return res;
    }
};