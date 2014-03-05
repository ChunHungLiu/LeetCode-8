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
    void recoverTree(TreeNode *root) {
        if (!root) { return; }
        vector<TreeNode*> table;
        stack<TreeNode*> s;
        TreeNode* cur = root;

        while (cur || !s.empty()) {
            if (cur) {
                s.push(cur);
                cur = cur->left;
            } else {
                cur = s.top(); s.pop();
                table.push_back(cur);
                cur = cur->right;
            }
        }

        TreeNode *first;
        for (int i = 1; i < table.size(); ++i) {
            if (table[i]->val < table[i-1]->val) { 
                first = table[i-1]; break;
            }
        }
        TreeNode* second;
        for (int i = table.size()-2; i >= 0; --i) {
            if (table[i]->val > table[i+1]->val) {
                second = table[i+1]; break;
            }
        }
    
        swap(first->val, second->val);
    }
};