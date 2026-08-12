class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int len = 0;
        int l = 0;
        unordered_map<int,int> mp;

        for(int r=0; r<n; r++) {
            mp[nums[r]]++;

            if(mp[nums[r]] <= k) len = max(len,r-l+1);
            
            while(mp[nums[r]] > k) {
                mp[nums[l]]--;
                l++;            
            }
        }

        return len;
    }
};