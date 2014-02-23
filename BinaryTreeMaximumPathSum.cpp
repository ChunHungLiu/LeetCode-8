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
    map<TreeNode*, int> table;

    int maxSinglePathSum(TreeNode* root) {
        if (!root) { return 0; }
        if (table.find(root) != table.end()) { return table[root]; }
        
        table[root] = root->val + max( maxSinglePathSum(root->left), maxSinglePathSum(root->right) );
        table[root] = max(table[root], 0);

        return table[root];
    }

    int maxPathSum(TreeNode *root) {
        if (!root) { return INT_MIN; }
        int val1 = root->val + maxSinglePathSum(root->left) + maxSinglePathSum(root->right);
        int val2 = maxPathSum(root->left);
        int val3 = maxPathSum(root->right);
        
        return max(val1, max(val2, val3));
    }
};