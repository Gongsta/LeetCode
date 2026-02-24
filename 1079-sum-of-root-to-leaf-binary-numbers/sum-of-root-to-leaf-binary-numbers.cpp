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
    void solve(TreeNode* node, int curr_num, int& total) {
        curr_num = (curr_num << 1) + node->val;
        cout << curr_num << endl;
        if (node->right) solve(node->right, curr_num, total);
        if (node->left) solve(node->left, curr_num, total);
        if (!node->left && !node->right) total += curr_num;
    }
    int sumRootToLeaf(TreeNode* root) {
        int total = 0;
        solve(root, 0, total);
        return total;
    }
};