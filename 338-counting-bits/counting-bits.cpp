class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> v;

        for (int i = 0; i <= n; i++) {
            int x = i;
            int cnt = 0;

            while (x) {
                x = x & (x - 1);
                cnt++;
            }

            v.push_back(cnt);
        }

        return v;
    }
};