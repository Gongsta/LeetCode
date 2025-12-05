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
    void dfs(TreeNode* node, int depth, vector<int>& depth_to_val) {
        if (!node) return;
        dfs(node->right, depth + 1, depth_to_val);
        if (depth_to_val[depth] == INT_MIN) {
            depth_to_val[depth] = node->val;
        }
        max_depth = max(max_depth, depth);
        dfs(node->left, depth + 1, depth_to_val);

    }
    vector<int> rightSideView(TreeNode* root) {
        // Traverse tree
        vector<int> depth_to_val(101, INT_MIN);
        dfs(root, 0, depth_to_val);
        depth_to_val.resize(max_depth + 1);
        return depth_to_val;
        
    }
};