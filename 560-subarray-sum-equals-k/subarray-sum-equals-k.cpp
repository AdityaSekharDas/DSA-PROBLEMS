class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int cnt = 0;
        int psum = 0;
        int n = nums.size();
        map<int,int> mp;
        mp[0] = 1;
        for(int i=0; i<n; i++) {
            psum += nums[i];
            int remove = psum - k;
            if(mp.find(remove) != mp.end()) cnt += mp[remove];
            mp[psum] += 1;
        }
        return cnt;
    }
};