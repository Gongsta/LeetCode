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
    vector<int> dfs(TreeNode* root) {
        vector<int> leafs;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();s.pop();
            if (!node->left && !node->right) {
                leafs.push_back(node->val);
            } else {
                if (node->right) s.push(node->right);
                if (node->left) s.push(node->left);
            }
        }
        return leafs;

    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        // Compute leafs via dfs with stack.
        vector<int> tree1_leafs = dfs(root1);
        vector<int> tree2_leafs = dfs(root2);

        return tree1_leafs == tree2_leafs;
        
    }
};