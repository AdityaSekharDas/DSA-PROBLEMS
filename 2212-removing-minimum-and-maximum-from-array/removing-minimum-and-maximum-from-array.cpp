class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mini = INT_MAX , maxi = INT_MIN , l = -1 , r = -1;
        int n = nums.size();
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] > maxi) {
                maxi = nums[i];
                r = i;
            }
            if(nums[i] < mini) {
                mini = nums[i];
                l = i;
            }
        }
        int case1 = max(l, r) + 1;
        int case2 = n - min(l, r);
        int case3 = min(l, r) + 1 + n - max(l, r);

        return min({case1, case2, case3});

    }
};