class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n = s.size();
        vector<int> val;
        int one = count(s.begin() , s.end() , '1');
        int i = 0;
        while(i < n) {
            int cnt = 0;
            if(s[i] == '0') {
                int start = i;
                while(i < n && s[i] == '0') i++;
                val.push_back(i - start);
            }
            else  {
                i++;
            }
        }

        int max_pair = 0;
        for(int i=1; i<val.size(); i++) {
            max_pair = max(max_pair , val[i] + val[i-1]);
        }

        return max_pair + one;
        
    }
};