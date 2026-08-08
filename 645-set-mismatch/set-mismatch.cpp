class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        vector<int> arr(n+1,0);
        for(int x : nums) arr[x]++;
        for(int i=1; i<=n; i++) {
            if(arr[i] == 2) ans.push_back(i);
        }
        for(int i=1; i<=n; i++) {
            if(arr[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};