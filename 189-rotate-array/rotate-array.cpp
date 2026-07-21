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
};