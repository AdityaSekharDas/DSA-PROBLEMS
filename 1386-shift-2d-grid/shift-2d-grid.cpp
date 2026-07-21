class Solution {
public:
    void reverse(vector<vector<int>>& grid, int l, int r, int col) {
        while(l < r) {
            swap(grid[l/col][l%col],grid[r/col][r%col]);
            l++;
            r--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int row = grid.size() , col = grid[0].size();
        int n = row * col;
        k  = k % n;

        reverse(grid,0,n-1,col);
        reverse(grid,0,k-1,col);
        reverse(grid,k,n-1,col);
        return grid;
    }
};