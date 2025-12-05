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
    unordered_map<long long, int>  prefix;
    int dfs(TreeNode* root, long long targetSum, long long currSum) {
        if (!root) return 0;
        currSum += root->val;
        long long need = currSum - targetSum;
        int total = prefix[need];
        prefix[currSum]++;
        total += dfs(root->left, targetSum, currSum) + dfs(root->right, targetSum, currSum);
        prefix[currSum]--;
        return total;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;
        prefix[0] = 1;
        return dfs(root, targetSum, 0);
    }
};