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
    int goodNodes(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, root->val});
        int num_good = 0;
        // Run BFS and compute answer
        while (!q.empty()) {
            auto [node, X] = q.front();q.pop();
            if (node->val >= X) num_good++;
            if (node->left) q.push({node->left, max(X, node->left->val)});
            if (node->right) q.push({node->right, max(X, node->right->val)});
        }
        return num_good;
        
    }
};