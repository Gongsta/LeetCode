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
    map<pair<TreeNode*, char>, int> cnt;
    int dfs(TreeNode* root, char d) {
        if (!root) return -1;
        if (cnt.count({root, d})) return cnt[{root,d}];
        if (d == 'l') return cnt[{root, d}] = 1 + dfs(root->left, 'r');
        return cnt[{root,d}] = 1 + dfs(root->right, 'l');
    }

    int longestZigZag(TreeNode* root) {
        if (!root) return 0;
        int others = max(longestZigZag(root->left), longestZigZag(root->right));
        return max(max(dfs(root, 'l'), dfs(root, 'r')), others);
        
    }
};