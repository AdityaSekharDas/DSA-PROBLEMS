class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorr = 0;
        for (int x : nums) {
            xorr ^= x;
        }
        int rm = xorr & (-xorr);
        int a = 0, b = 0;
        for (int x : nums) {
            if (x & rm)
                a ^= x;
            else
                b ^= x;
        }
        return {a, b};
    }
};