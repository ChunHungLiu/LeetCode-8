/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode *sortedArrayToBST(vector<int> &num, int start, int end) {
        if (start > end) { return NULL; }
        else if (start == end) { return new TreeNode(num[start]); }
        
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(num[mid]);
        root->left = sortedArrayToBST(num, start, mid-1);
        root->right = sortedArrayToBST(num, mid+1, end);
        return root;
    }
    
    TreeNode *sortedListToBST(ListNode *head) {
        if (!head) { return NULL; }
        vector<int> num;
        ListNode* cur = head;
        while (cur) { num.push_back(cur->val); cur = cur->next; }
        
        return sortedArrayToBST(num, 0, num.size()-1);
    }
};