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
    unordered_map<TreeNode*, int> m;
    int rob(TreeNode* root) {
        if (root == nullptr) return 0;
        if (m.count(root)) return m[root];
        // Rob current house, or both houses below
        int below = rob(root->left) + rob(root->right);
        int curr = root->val;
        if (root->left != nullptr) {
            curr += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right != nullptr) {
            curr += rob(root->right->left) + rob(root->right->right);
        }
        
        m[root] = max(below, curr);
        return m[root];
    }
};