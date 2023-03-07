/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int mx = 0;
    int diameter(TreeNode* node) {
        if (node == nullptr) return 0;
        int l = diameter(node->left);
        int r = diameter(node->right);
        mx = max(mx, l+r);
        return 1 + max(l, r);
    }
        


    int diameterOfBinaryTree(TreeNode* root) {
        diameter(root);
        return mx;
        
    }
};