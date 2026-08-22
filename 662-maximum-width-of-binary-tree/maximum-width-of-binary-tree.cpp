class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, long long>> q;
        q.push({root, 0});

        int ans = 0;

        while (!q.empty()) {

            int size = q.size();

            long long mini = q.front().second;
            long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {

                long long cur_ind = q.front().second - mini;

                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0)
                    first = cur_ind;

                if (i == size - 1)
                    last = cur_ind;

                if (node->left)
                    q.push({node->left, 2 * cur_ind + 1});

                if (node->right)
                    q.push({node->right, 2 * cur_ind + 2});
            }

            ans = max(ans, (int)(last - first + 1));
        }

        return ans;
    }
};