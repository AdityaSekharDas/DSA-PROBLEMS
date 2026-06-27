class Solution {
public:
    int maximumLength(vector<int>& nums) {
        map<long long,int> mp;
        int one = 0;
        for(int x : nums) {
            if(x == 1) one++;
            else mp[x]++;
        }
        if(one != 0 && one%2 == 0) one--;
        int ans = one;
        for(auto it : mp) {
            long long val = it.first;
            long long  base = sqrt(val);
            if(base*base == val && mp[base] >= 2) continue;
            int cnt = 0;
            while(mp.count(val) && mp[val] >= 2) {
                cnt += 2;
                val *= val;
            }
            if(mp[val] == 1) cnt++;
            else cnt--;
            ans = max(cnt,ans);
        }
        return ans;
    }
};