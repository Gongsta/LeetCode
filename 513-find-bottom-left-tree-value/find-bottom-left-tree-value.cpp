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
    int max_depth = -1;
    int val = -1;
    void visit(TreeNode* node, int depth) {
        if (node == nullptr) return;
        // Process
        if (depth > max_depth) {
            val = node->val;
            max_depth = depth;
        }
        visit(node->left, depth+1);
        visit(node->right, depth+1);
    }

    int findBottomLeftValue(TreeNode* root) {
        visit(root, 0);
        return val;
    }
};