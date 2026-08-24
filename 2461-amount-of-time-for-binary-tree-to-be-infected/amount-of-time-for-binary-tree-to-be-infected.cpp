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
    void makeparent(TreeNode* root , unordered_map<TreeNode* , TreeNode*> &parent) {
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->left) {
                q.push(node->left);
                parent[node->left] = node;
            }

            if(node->right) {
                q.push(node->right);
                parent[node->right] = node;
            }
        }
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode* , TreeNode*> parent;
        makeparent(root , parent);

        TreeNode* startNode = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if(node->val == start) {
                startNode = node;
                break;
            }

            if(node->left) q.push(node->left);
            if(node->right) q.push(node->right);
        }

        unordered_map<TreeNode* , bool> visited;

        queue<TreeNode*> temp;
        temp.push(startNode);
        visited[startNode] = true;

        int time = 0;

        while(!temp.empty()) {
            int size = temp.size();
            bool infected = false;

            for(int i=0; i<size; i++) {
                TreeNode* node = temp.front();
                temp.pop();

                if(node->left && !visited[node->left]) {
                    temp.push(node->left);
                    visited[node->left] = true;
                    infected = true;
                }

                if(node->right && !visited[node->right]) {
                    temp.push(node->right);
                    visited[node->right] = true;
                    infected = true;
                }

                if(parent[node] && !visited[parent[node]]) {
                    temp.push(parent[node]);
                    visited[parent[node]] = true;
                    infected = true;
                }
            }

            if(infected) time++;
        }

        return time;
    }
};