class Solution {
public:
    string minWindow(string s, string t) {
        vector<int> arr(256,0);
        for(char c : t) arr[c]++;
        int l = 0 , cnt = 0 , minlen = INT_MAX , start = -1;
        for(int r=0; r<s.size(); r++) {
            if(arr[s[r]] > 0) cnt++;
            arr[s[r]]--;

            while(cnt == t.size()) {
                if(r - l + 1 < minlen) {
                    minlen = r - l + 1;
                    start = l;
                }

                arr[s[l]]++;
                if(arr[s[l]] > 0) cnt--;
                l++;
            }
        }
        return start == -1 ? "" : s.substr(start,minlen);
    }
};