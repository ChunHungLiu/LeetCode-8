// should use <= and >=!!!  remember BST!
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
    bool isValidBST(int MIN, int MAX, TreeNode* root) {
        if (!root) { return true; }
        if (root->val >= MAX || root->val <= MIN) { return false; }
        
        return isValidBST(root->val, MAX, root->right) && isValidBST(MIN, root->val, root->left);
    }

    bool isValidBST(TreeNode *root) {
        return isValidBST(INT_MIN, INT_MAX, root);        
    }
};