class Solution {
public:
    int mySqrt(int x) {
        for(int i=0; i<=x; i++) {
            if(1ll * i*i > x) return i-1;
        }
        return x;

        
    }
};