class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = *max_element(nums.begin(), nums.end());
        while(l <= r) {
            int mid =  l + (r-l)/2;
            int sum = 0;
            for(int i=0; i<nums.size(); i++) sum += ceil((double)nums[i] / mid);
            if(sum <= threshold) r = mid - 1;
            else l = mid + 1;
        }
        return l;
    }
};