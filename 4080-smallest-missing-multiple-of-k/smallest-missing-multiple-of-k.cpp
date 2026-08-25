class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();
        int temp = k;

        while(true) {
            bool ans = true;
            for(int i=0; i<n; i++) {
                if(nums[i] == temp) {
                    ans = false;
                    break;
                }
            }
            if(ans == true) return temp;
            temp += k;
        }
    }
};