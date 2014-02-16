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
    int height(TreeNode* root) {
        if (!root) { return 0; }
        return max(height(root->left), height(root->right)) + 1;
    }

    bool isBalanced(TreeNode *root) {
        if (!root) { return true; }
        int diff = abs( height(root->left) - height(root->right) );
        if (diff > 1) { return false; }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

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
    map<TreeNode*, int> dp;

    int height(TreeNode* root) {
        if (!root) { return 0; }
        
        if (dp.find(root) == dp.end()) {
            int res;
            res = max(height(root->left), height(root->right)) + 1;
            dp[root] = res;
        }
        
        return dp[root];
    }

    bool isBalanced(TreeNode *root) {
        if (!root) { return true; }
        int diff = abs( height(root->left) - height(root->right) );
        if (diff > 1) { return false; }
        return isBalanced(root->left) && isBalanced(root->right);
    }
};