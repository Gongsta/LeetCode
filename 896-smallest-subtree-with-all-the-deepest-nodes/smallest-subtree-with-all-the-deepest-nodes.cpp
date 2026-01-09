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
    pair<int, TreeNode*> solve(TreeNode* root) {
        if (!root) return {0, nullptr};
        auto [left_depth, ln] = solve(root->left);
        auto [right_depth, rn] = solve(root->right);
        if (left_depth < right_depth) return {right_depth + 1, rn};
        if (right_depth < left_depth) return {left_depth + 1, ln};
        // This is the first common ancestor where both left and right are rooted
        return {left_depth + 1, root};
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        return solve(root).second;
    }

};