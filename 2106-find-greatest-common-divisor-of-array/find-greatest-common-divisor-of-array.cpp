class Solution {
public:
    int findGCD(vector<int>& nums) {
        int mini = nums[0] , maxi = nums[0];
        for(int x : nums) {
            mini = min(mini,x);
            maxi = max(maxi,x);
        }
        return gcd(mini,maxi);
    }
};