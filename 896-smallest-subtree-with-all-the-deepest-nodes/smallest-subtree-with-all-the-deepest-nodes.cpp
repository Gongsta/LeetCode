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
    int getDepth(TreeNode* root, int curr_depth) {
        if (!root) return curr_depth - 1;
        return max(getDepth(root->left, curr_depth + 1), getDepth(root->right, curr_depth + 1));
    }

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (!root->left && !root->right) return root;
        int left_depth = getDepth(root->left, 0);
        int right_depth = getDepth(root->right, 0);
        if (!root->left || left_depth < right_depth) return subtreeWithAllDeepest(root->right);
        if (!root->right || right_depth < left_depth) return subtreeWithAllDeepest(root->left);
        // This is the first common ancestor where both left and right are rooted
        return root;
    }

};