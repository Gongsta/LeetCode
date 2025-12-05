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
    vector<int> depths;

    void search(TreeNode* root, int depth) {
        if (!root) return;
        if (depth == depths.size()) {
            depths.push_back(root->val);
        } else {
            depths[depth] += root->val;
        }
        search(root->left, depth+1);
        search(root->right, depth+1);
    }

    int maxLevelSum(TreeNode* root) {
        /*
        Recrusive call, increment value at depth
        For all depths, return the smallest one
        */
        search(root, 0);
        int ans = 0;
        for (int i = 1; i< depths.size();i++) {
            if (depths[i] > depths[ans]) {
                ans = i;
            }
        }
        return ans + 1; // for 1 indexing

        
    }
};