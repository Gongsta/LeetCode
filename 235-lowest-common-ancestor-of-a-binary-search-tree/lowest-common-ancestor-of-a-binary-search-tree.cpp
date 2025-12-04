/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        /*
        p is an ancestor of q
        q is an ancestor of p
        p and q have ancestor v.
        */
        if (p->val > q->val) swap(p,q); // Assume p is the smaller value one
        if (p->val <= root->val && q->val >= root->val) return root; // This is a split
        if (p->val < root->val) return lowestCommonAncestor(root->left, p, q);
        return lowestCommonAncestor(root->right, p, q);
        
    }
};