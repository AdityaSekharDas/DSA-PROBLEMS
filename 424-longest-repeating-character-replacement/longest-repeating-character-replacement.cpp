class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        int len = 0;
        int l = 0;
        int maxfreq = 0;
        vector<int> arr(26,0);
        for(int r=0; r<n; r++) {
            arr[s[r] - 'A']++;
            maxfreq = max(maxfreq,arr[s[r] - 'A']);
            if((r-l+1) - maxfreq <= k) len = max(len , r-l+1);
            if((r-l+1) - maxfreq > k) {
                arr[s[l] - 'A']--;
                l++;
            }
        }
        return len;
    }
};