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
    map<int, TreeNode*> depth_to_node;
    void dfs(TreeNode* node, int depth) {
        if (!node) return;
        dfs(node->right, depth + 1);
        if (!depth_to_node.count(depth)) {
            depth_to_node[depth] = node;
        }

        dfs(node->left, depth + 1);

    }
    vector<int> rightSideView(TreeNode* root) {
        // Traverse tree
        dfs(root, 0);
        vector<int> ans;
        for (auto& [depth, node]: depth_to_node) {
            ans.push_back(node->val);
        }
        return ans;
        
    }
};