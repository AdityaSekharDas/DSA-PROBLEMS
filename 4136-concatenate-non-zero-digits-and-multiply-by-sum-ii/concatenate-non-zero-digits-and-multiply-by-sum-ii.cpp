class Solution {
public:
    using ll = long long;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        const int mod = 1e9 + 7;

        ll pow[100001];
        pow[0] = 1;

        for (int i = 1; i < 100001; i++) {
            pow[i] = (pow[i - 1] * 10) % mod;
        }

        vector<ll> prefix(n + 1, 0);
        vector<ll> number(n + 1, 0);
        vector<int> len(n + 1, 0);

        for (int i = 0; i < n; i++) {
            int dig = s[i] - '0';

            prefix[i + 1] = prefix[i] + dig;
            number[i + 1] = dig ? (number[i] * 10 + dig) % mod : number[i];
            len[i + 1] = dig ? len[i] + 1 : len[i];
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            ll sum = prefix[r + 1] - prefix[l];

            int digits = len[r + 1] - len[l];

            if (digits == 0) {
                ans.push_back(0);
                continue;
            }

            ll num = (number[r + 1] - number[l] * pow[digits] % mod + mod) % mod;

            ans.push_back((num * (sum % mod)) % mod);
        }

        return ans;
    }
};