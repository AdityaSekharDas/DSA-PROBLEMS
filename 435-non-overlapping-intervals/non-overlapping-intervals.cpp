class Solution {
public:
    static bool comp(vector<int> &a , vector<int> &b) {
        if(a[1] == b[1]) return a[0] < b[0];
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        
        sort(intervals.begin(),intervals.end(),comp);

        int cnt = 1 , last = intervals[0][1];
        for(int i=1; i<n; i++) {
            if(intervals[i][0] >= last) {
                cnt++;
                last = intervals[i][1];
            }
        }

        return n - cnt;
    }
};