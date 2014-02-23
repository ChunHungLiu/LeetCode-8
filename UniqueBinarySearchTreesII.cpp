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
    vector<TreeNode *> generateTrees(int start, int end) {
        vector<TreeNode *> res;
        if (start > end) { res.push_back(NULL); return res; }
        if (start == end) { res.push_back(new TreeNode(start)); return res; }
        
        for (int i = start; i <= end; ++i) {
            vector<TreeNode*> left = generateTrees(start, i-1);
            vector<TreeNode*> right = generateTrees(i+1, end);
            
            for (int x = 0; x < left.size(); ++x) {
                for (int y = 0; y < right.size(); ++y) {
                    TreeNode* cur = new TreeNode(i);
                    cur->left = left[x];
                    cur->right = right[y];
                    res.push_back(cur);
                }
            }
        }
        
        return res;
    }

    vector<TreeNode *> generateTrees(int n) {
        return generateTrees(1, n);
    }
};