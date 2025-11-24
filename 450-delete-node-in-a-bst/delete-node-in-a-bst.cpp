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
            if (key < curr->val) {
                prev = curr;
                curr = curr->left;
            } else if (key > curr->val){
                prev = curr;
                curr = curr->right;
            } else { // Node found, update parent
                TreeNode** source; // pointer to pointer to simpify logic
                if (!prev) {
                    source = &root; // We are removing the root node, don't need to update any more edges
                } else  if (curr->val < prev->val) {
                    source = &(prev->left);
                } else {
                    source = &(prev->right);
                }

                if (curr->right && curr->left) {
                    // set parent->left to Min of curr->right substree
                    auto node = RemoveMinOfTree(curr->right);
                    node->left = curr->left;
                    if (curr->right != node) {
                        node->right = curr->right;
                    }
                    *source = node;
                } else if (curr->right) {
                    *source = curr->right;
                } else if (curr->left) {
                    *source = curr->left;
                } else {
                    *source = nullptr;
                }
                break;
            }
        }

        return root;
    }
};