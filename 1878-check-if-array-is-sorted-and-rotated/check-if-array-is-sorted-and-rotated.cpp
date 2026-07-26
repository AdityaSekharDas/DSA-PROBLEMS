class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();

        for(int i=0; i<n; i++) {
            bool sorted = true;
            for(int j=0; j<n-1; j++) {
                if(nums[j] > nums[j+1]) {
                    sorted = false;
                    break;
                }
            }
            if(sorted) return true;
            int x = nums[0];
            for(int j=1; j<n; j++) nums[j-1] = nums[j];
            nums[n-1] = x;            
        }

        return false;
    }
};