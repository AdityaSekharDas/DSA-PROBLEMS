class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> v = arr;
        sort(v.begin(),v.end());
        int n = arr.size();
        if (n == 0) return arr;
        unordered_map<int,int> mp;
        int x = 1;
        mp[v[0]] = x;
        for(int i=1; i<n; i++) {
            if(v[i] == v[i-1]) mp[v[i]] = x;
            else mp[v[i]] = ++x;
        }
        for(int i=0; i<n; i++) {
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};