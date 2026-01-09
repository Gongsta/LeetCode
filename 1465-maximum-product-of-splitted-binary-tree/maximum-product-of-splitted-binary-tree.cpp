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
    unordered_map<TreeNode*, int> sum;
    long long ans = 0;
    long long total_sum;
    int computeSum(TreeNode* root) {
        if (!root) return 0;
        return sum[root] = root->val + computeSum(root->left) + computeSum(root->right);
    }

    void dfs(TreeNode* root) {
        if (!root) return;
        ans = max(ans, (total_sum - sum[root]) * sum[root]);
        dfs(root->left);
        dfs(root->right);
    }

    int maxProduct(TreeNode* root) {
        computeSum(root);
        total_sum = sum[root];
        dfs(root);
        return ans % (long long)(1e9 + 7);
        
    }
};