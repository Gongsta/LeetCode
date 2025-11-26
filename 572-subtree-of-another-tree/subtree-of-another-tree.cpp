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
    bool isSame(TreeNode* root, TreeNode* subRoot) {
        if (!root && !subRoot) return true; // both are nullptr
        if ((!root && subRoot) || (root && !subRoot)) return false; // Both must be valid nodes
        if (root->val != subRoot->val) return false;
        return isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        /*
        Two trees are the same if somewhere down the tree, there is a match.
        The first node that matches, everything else should be the same.
        */
        if (!root && !subRoot) return true; // both are nullptr
        if ((!root && subRoot) || (root && !subRoot)) return false; // Both must be valid nodes
        bool match = false;
        if (root->val == subRoot->val) {
            match= isSame(root->left, subRoot->left) && isSame(root->right, subRoot->right);
        }  
        return match || isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};