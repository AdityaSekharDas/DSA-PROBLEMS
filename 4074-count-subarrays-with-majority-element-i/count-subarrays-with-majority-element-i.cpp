class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int cnt = 0;
        for(int i=0; i<nums.size(); i++) {
            int x = 0;
            for(int j=i; j<nums.size(); j++) {
                if(nums[j] == target) x++;
                if(x>(j-i+1)/2)cnt++;
            }
        }
        return cnt;
    }
};