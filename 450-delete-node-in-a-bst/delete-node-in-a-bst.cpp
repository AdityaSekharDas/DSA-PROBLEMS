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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == NULL) return NULL;

        if(root->val == key) return solve(root);

        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->val > key) {
                if(curr->left != NULL && curr->left->val == key) curr->left = solve(curr->left);
                else curr = curr->left;
            } 
            else {
                if(curr->right != NULL && curr->right->val == key) curr->right = solve(curr->right);
                else curr = curr->right;
            }
        }
        return root;
    }

    TreeNode* solve(TreeNode* root) {
        if(root->left == NULL) return root->right;
        else if(root->right == NULL) return root->left;

        TreeNode* rightchild = root->right;
        TreeNode* lastright = last(root->left);
        lastright->right = rightchild;
        return root->left;
    }

    TreeNode* last(TreeNode* root) {
        if(root->right == NULL) return root;
        return last(root->right);
    }
};