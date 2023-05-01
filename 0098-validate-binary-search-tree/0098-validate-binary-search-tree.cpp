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
    bool isValidBST(TreeNode* root) {
        TreeNode* prev = nullptr;
        return validate(root, prev);
    }
    bool validate(TreeNode* curr, TreeNode* &prev) {
        if (curr == nullptr) return true;
        if (!validate(curr->left, prev)) return false;
        if (prev != nullptr && prev->val >= curr->val) return false;
        prev = curr;
        return validate(curr->right, prev);
    }
};