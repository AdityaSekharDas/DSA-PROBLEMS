class Solution {
public:
    int numberOfSubstrings(string s) {
        int cnt = 0;
        int n = s.size();
        vector<int> arr(3,-1);
        for(int r=0; r<n; r++) {
           arr[s[r] - 'a'] = r;
           cnt += min(arr[0],min(arr[1],arr[2])) + 1;
        }
        return cnt;
    }
};