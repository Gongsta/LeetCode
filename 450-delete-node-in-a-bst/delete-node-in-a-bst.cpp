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
    TreeNode* RemoveMinOfTree(TreeNode* node) {
        // Find min of tree and remove the edge to that leaf
        if (!node) return nullptr;

        TreeNode* node_parent = nullptr;
        while (node->left) {
            node_parent = node;
            node = node->left;
        }

        // Remove edge to that leaf if applicable
        if (node_parent) {
            node_parent->left = node->right;
        }
        return node;
    }
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if (!root) return nullptr;

        TreeNode* prev = nullptr;
        TreeNode* curr = root;
        while (curr) {
            cout << curr->val << endl;
            if (key < curr->val) {
                prev = curr;
                curr = curr->left;
            } else if (key > curr->val){
                prev = curr;
                curr = curr->right;
            } else { // Node found, update parent
                // Node to remove is the root node
                if (!prev) {
                    if (curr->right && curr->left) {
                        // set parent->left to Min of curr->right substree
                        auto node = RemoveMinOfTree(curr->right);
                        node->left = curr->left;
                        if (curr->right != node) {
                            node->right = curr->right;
                        }
                        root = node;
                    } else if (curr->right) {
                        root = curr->right;
                    } else if (curr->left) {
                        root = curr->left;
                    } else {
                        root = nullptr;
                    }
                // Node is left of parent and prev is not nullptr
                } else if (curr->val < prev->val) {
                    if (curr->right && curr->left) {
                        // set parent->left to Min of curr->right substree
                        auto node = RemoveMinOfTree(curr->right);
                        node->left = curr->left;
                        if (curr->right != node) { // prevent cycle
                            node->right = curr->right;
                        }
                        prev->left = node;
                    } else if (curr->right) {
                        prev->left = curr->right;
                    } else if (curr->left) {
                        prev->left = curr->left;
                    } else {
                        prev->left = nullptr;

                    }
                // Node is right of parent, and prev is not nullptr
                } else {
                    if (curr->left && curr->right) {
                    // Find min of right subtree, and keep track of its parent
                        auto node = RemoveMinOfTree(curr->right);
                        node->left = curr->left;
                        if (curr->right != node) { // prevent cycle
                            node->right = curr->right;
                        }
                        prev->right = node;
                    } else if (curr->right) {
                        prev->right = curr->right;
                    } else if (curr->left) {
                        prev->right = curr->left;
                    } else {
                        prev->right = nullptr;
                    }
                }
                break;
            }
        }

        return root;
    }
};