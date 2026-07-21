class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int  n = nums.size();
        vector<int> temp;
        k = k%n;
        for(int i=n-k; i<n; i++) {
            temp.push_back(nums[i]);
        }
        int x = 1;
        for (int i = n - k - 1; i >= 0; i--) {
            nums[i + k] = nums[i];
        }
        for(int i=0; i<k; i++) {
            nums[i] = temp[i];
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size() , n = grid[0].size();
        vector<int> temp;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                temp.push_back(grid[i][j]);
            }
        }
        rotate(temp,k);
        int x = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                grid[i][j] = temp[x++];
            }
        }
        return grid;
    }
};