class Solution {
public:
    string reversePrefix(string word, char ch) {
        int ind = -1 , i = 0;
        for(char c : word) {
            if(c == ch) {
                ind = i;
                break;
            }
            i++;
        }
        if(ind == -1) return word;
        string ans = "";
        for(int i=ind; i>=0; i--) {
            ans += word[i];
        }
        for(int i=ind+1; i<word.size(); i++) {
            ans += word[i];
        }
        return ans;
    }
};