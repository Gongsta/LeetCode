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
    int maxPathSingle(TreeNode* root) {
        if (!root) return 0;
        int left = maxPathSingle(root->left);
        int right = maxPathSingle(root->right);
        return root->val + max(max(left, right), 0);
    }

    int maxPathSum(TreeNode* root) {
        /*
        break it down into cases:
        1. The maximum path goes through the current node, or does not. 

        if it goes through the current node, the child nodes, only one of the paths can be taken
        node->val + max(maxPathSingle(node->left), 0) + max(maxPathSingle(node->right), 0)

        If it doesn't 
        max(maxPathSum(node->left), (maxPathSum(node->right))
        */
        if (!root) return -INT_MAX;
        int through_node = root->val + max(maxPathSingle(root->left), 0) + max(maxPathSingle(root->right), 0);
        int not_through = max(maxPathSum(root->left), (maxPathSum(root->right)));
        if (!root->left && !root->right) return root->val; // To force constraint that path is non zero
        return max(through_node, not_through);
        
    }
};