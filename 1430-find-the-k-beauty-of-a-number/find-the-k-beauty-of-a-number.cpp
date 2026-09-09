class Solution {
public:
    int divisorSubstrings(int num, int k) {
        int cnt = 0;
        string ans = to_string(num);
        for(int i=0; i+k<=ans.size(); i++) {
            string temp = "";
            for(int j=i; j<i+k; j++) {
                temp += ans[j];
            }
            int x = stoi(temp);
            if(x != 0 && num % x == 0) cnt++;
        }
        return cnt;
    }
};