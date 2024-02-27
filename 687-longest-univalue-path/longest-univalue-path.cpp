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
    int longest(TreeNode* node) {
        if (node == nullptr) return 0;
        int l = longest(node->left);
        int r = longest(node->right);
        int path_len = 0;
        if (node->left != nullptr && node->right != nullptr && node->left->val == node->val && node->right->val == node->val) {
            mx = max(mx, l + r);
            path_len = max(l, r);
        }
        else if (node->left != nullptr && node->left->val == node->val) {
            mx = max(mx, l);
            path_len = l;
        }
        else if (node->right != nullptr && node->right->val == node->val) {
            mx = max(mx, r);
            path_len = r;

        }

        return 1 + path_len;

    }
    int longestUnivaluePath(TreeNode* root) {
        longest(root);
        return mx;
        
    }
};