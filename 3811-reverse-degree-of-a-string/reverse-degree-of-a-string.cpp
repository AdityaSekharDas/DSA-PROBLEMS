class Solution {
public:
    int reverseDegree(string s) {
        int sum = 0;
        for(int i=0; i<s.size(); i++) {
            int rv = 26 - (s[i] - 'a');
            sum += (i+1) * rv;
        }
        return sum;
    }
};