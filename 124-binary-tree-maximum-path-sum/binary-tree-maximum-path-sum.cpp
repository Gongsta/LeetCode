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
    int maxPathSingle(TreeNode* root, int& best) {
        if (!root) return 0;
        int left = maxPathSingle(root->left, best);
        int right = maxPathSingle(root->right, best);
        best = max(best, root->val + max(left, 0) + max(right, 0));

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
        int best = -INT_MAX;
        maxPathSingle(root, best);
        return best;
        
    }
};