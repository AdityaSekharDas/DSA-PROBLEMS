class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int ans = 0 , l = 0;
        vector<int> arr(256,-1);
        for(int r=0; r<n; r++) {
            if(arr[s[r]] != -1 && arr[s[r]] >= l) l = arr[s[r]] + 1;
            arr[s[r]] = r;
            ans = max(ans,r-l+1);
        }
        return ans;
    }
};