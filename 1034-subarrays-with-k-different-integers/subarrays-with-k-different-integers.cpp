class Solution {
public:
    int atmost(vector<int>& nums, int k) {
        int l = 0 , cnt = 0;
        int n = nums.size();
        map<int,int> mp;
        for(int r=0; r<n; r++) {
            mp[nums[r]]++;
            while(mp.size()>k) {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                l++;
            }
            cnt += r-l+1;
            
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atmost(nums,k) - atmost(nums,k-1);
    }
};