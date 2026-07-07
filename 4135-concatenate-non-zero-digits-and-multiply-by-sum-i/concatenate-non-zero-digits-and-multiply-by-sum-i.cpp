class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        int res = 0 , place = 1;
        while(n > 0) {
            if(n%10 != 0) {
                res += place * (n%10);
                place *= 10;
                sum += n%10;
            }
            n /= 10;
        }
        return res*sum;
    }
};