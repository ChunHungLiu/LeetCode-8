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
    TreeNode *buildTree(vector<int> &post, int start, int s2, int len, map<int, int> &table) {
        if (len == 0) { return NULL; }
        if (len == 1) { return new TreeNode(post[start+len-1]); } 
        
        TreeNode *root = new TreeNode(post[start+len-1]);
        int idx = table[post[start+len-1]];
        root->left  = buildTree(post, start, s2, idx-s2, table);
        root->right = buildTree(post, start+(idx-s2), idx+1, len-(idx-s2)-1, table);
        
        return root;
    }

    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        if (inorder.size() != postorder.size() || inorder.size() == 0) { return NULL; }
        map<int, int> table;
        for (int i = 0; i < inorder.size(); ++i) { table[inorder[i]] = i; }
        
        return buildTree(postorder, 0, 0, postorder.size(), table);
    }
};