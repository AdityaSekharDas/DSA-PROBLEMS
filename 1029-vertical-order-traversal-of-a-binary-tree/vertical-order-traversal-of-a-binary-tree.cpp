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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;

        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});

        while(!q.empty()) {
            auto p = q.front();
            q.pop();

            TreeNode* node = p.first;
            int ver = p.second.first , lev = p.second.second;

            mp[ver][lev].insert(node->val);

            if(node->left) q.push({node->left,{ver-1,lev+1}});
            if(node->right) q.push({node->right,{ver+1,lev+1}});
        }

        vector<vector<int>> ans;

        for(auto x : mp) {
            vector<int> col;
            for(auto y : x.second) {
                for(int val : y.second) col.push_back(val);
            }
            ans.push_back(col);
        } 
        return ans;
    }
};