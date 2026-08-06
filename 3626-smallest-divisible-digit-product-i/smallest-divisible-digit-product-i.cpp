class Solution {
public:
    int smallestNumber(int n, int t) {
        int ans = 0;
        for(int i=n; i<=100; i++) {
            int dig = i , prod = 1;

            while(dig != 0) {
                prod *= dig%10;
                dig /= 10;
            }

            if(prod % t == 0) {
                ans = i;
                break;
            }
        }

        return ans;
    }
};