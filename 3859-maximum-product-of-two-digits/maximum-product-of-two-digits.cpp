class Solution {
public:
    int maxProduct(int n) {
        int maxi = 0;
        string s = "";
        while(n != 0) {
            s += n%10 + '0';
            n /= 10;
        }
        for(int i=0; i<s.size(); i++) {
            for(int j=i+1; j<s.size(); j++) {
                maxi = max(maxi,(s[i]-'0') * (s[j]-'0'));
            }
        }
        return maxi;
    }
};