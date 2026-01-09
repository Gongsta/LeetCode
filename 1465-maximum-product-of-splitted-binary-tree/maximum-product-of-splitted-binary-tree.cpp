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
    long long ans = 0;
    long long total;
    int computeSum(TreeNode* root) {
        if (!root) return 0;
        return root->val + computeSum(root->left) + computeSum(root->right);
    }

    int dfs(TreeNode* root) {
        if (!root) return 0;
        int s = root->val + dfs(root->left) + dfs(root->right);
        ans = max(ans, (total - s) * s);
        return s;
    }

    int maxProduct(TreeNode* root) {
        total = computeSum(root);
        dfs(root);
        return ans % (long long)(1e9 + 7);
        
    }
};