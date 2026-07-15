class Solution {
public:
    int count(vector<int>& nums , int k) {
        int cnt = 0;
        if(k < 0) return 0;
        int l = 0;
        int ans = 0;
        int n = nums.size();
        for(int r=0; r<n; r++) {
            if(nums[r] %2 == 1) cnt++;
            while(cnt > k) {
                if(nums[l] %2 == 1) {
                    cnt--;
                }
                l++;
            }
            ans += r-l+1;
        }
        return ans;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return count(nums,k) - count(nums,k-1);
    }
};