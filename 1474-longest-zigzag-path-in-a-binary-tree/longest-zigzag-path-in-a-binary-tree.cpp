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
    int ans = 0;
    pair<int, int> dfs(TreeNode* root) {
        if (!root) return {-1, -1};
        auto [ll, lr] = dfs(root->left);
        auto [rl, rr] = dfs(root->right);

        ans = max(ans, max(lr + 1, rl + 1));
        return {lr + 1, rl + 1};
    }

    int longestZigZag(TreeNode* root) {
        dfs(root);
        return ans;
        
    }
};