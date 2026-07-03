class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        for(int i=0; i<n; i++) {
            int x = -1;
            for(int j=i+1; j<i+n; j++) {
                if(nums[j%n] > nums[i]) {
                    x = nums[j%n];
                    break;
                }
            }
            ans.push_back(x);
        }
        return ans;
    }
};