class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0;
        for(int i=0; i<n; i++) {
            map<char,int> mp;
            for(int j=i; j<n; j++) {
                if(mp.find(s[j]) != mp.end()) {
                    break;
                }
                mp[s[j]]++;
                ans = max(ans,j-i+1);
            }
        }
        return ans;
    }
};