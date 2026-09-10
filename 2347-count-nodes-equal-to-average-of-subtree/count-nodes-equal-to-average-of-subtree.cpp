class Solution {
public:

    pair<int, int> getSumCount(TreeNode* root) {
        if (root == NULL)
            return {0, 0};

        auto left = getSumCount(root->left);
        auto right = getSumCount(root->right);

        int sum = left.first + right.first + root->val;
        int cnt = left.second + right.second + 1;

        return {sum, cnt};
    }

    void solve(TreeNode* root, int &ans) {
        if (root == NULL)
            return;

        auto p = getSumCount(root);

        int avg = p.first / p.second;

        if (avg == root->val)
            ans++;

        solve(root->left, ans);
        solve(root->right, ans);
    }

    int averageOfSubtree(TreeNode* root) {
        int ans = 0;
        solve(root, ans);
        return ans;
    }
};