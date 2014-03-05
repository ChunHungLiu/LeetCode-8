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
    TreeNode *buildTree(vector<int> &pre, int start, int s2, int len, map<int, int> &table) {
        if (len <= 0) { return NULL; }
        if (len == 1) { return new TreeNode(pre[start]); }
        TreeNode *root = new TreeNode(pre[start]);
        int idx = table[pre[start]];
        root->left  = buildTree(pre, start+1, s2, idx-s2, table);
        root->right = buildTree(pre, start+(idx-s2)+1, idx+1, len-(idx-s2)-1, table);
        
        return root;
    }

    TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
        if (preorder.size() != inorder.size() || preorder.size() == 0) { return NULL; }
        map<int, int> table;
        for (int i = 0; i < inorder.size(); ++i) { table[inorder[i]] = i; }
        
        return buildTree(preorder, 0, 0, preorder.size(), table);        
    }
};