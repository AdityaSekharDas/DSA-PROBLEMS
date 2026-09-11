class Solution {
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) {
        vector<vector<int>> ans;
        int n = items1.size() , m = items2.size();
        for(int i=0; i<n; i++) {
            int val = items1[i][0];
            int weight = items1[i][1];
            for(int j=0; j<m; j++) {
                if(items2[j][0] == val) weight += items2[j][1];
            }
            ans.push_back({val,weight});
        }
        for(int i=0; i<m; i++) {
            bool found = false;
            for(int j=0; j<n; j++) {
                if(items2[i][0] == items1[j][0]) {
                    found = true;
                    break;
                }
            }
            if(!found) ans.push_back(items2[i]);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};