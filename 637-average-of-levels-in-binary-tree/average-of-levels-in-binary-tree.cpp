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
        map<int, vector<double>> m;
    void dfs(TreeNode* node, int level) {
        if (node == nullptr) return;
        m[level].push_back(node->val);
        dfs(node->left, level + 1);
        dfs(node->right, level+1);
    }

    vector<double> averageOfLevels(TreeNode* root) {
        m.clear();
        dfs(root, 0);
        vector<double> ans;
        for (auto x: m) {
            double sum = 0;
            for (double val: x.second) {
                sum += val;
            }
            sum /= (double) x.second.size();
            ans.push_back(sum);
        }
        return ans;
    }
};