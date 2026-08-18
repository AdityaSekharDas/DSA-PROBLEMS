class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int maxi = -1;

        for(int x : nums) {
            int cnt = 0;
            for(int i=0; i<=n-k; i++) {
                for(int j=i; j<i+k; j++) {
                    if(nums[j] == x) {
                        cnt++;
                        break;
                    }
                }
            }
            if(cnt == 1) maxi = max(maxi,x);
        }
        return maxi;
    }
};