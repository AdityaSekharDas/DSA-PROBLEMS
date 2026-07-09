class Solution {
public:
    vector<int> findPSE(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        return ans;
    }

    vector<int> findNSE(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i]) st.pop();
            ans[i] = st.empty() ? n : st.top();
            st.push(i);
        }
        return ans;
    }
    
    int largest(vector<int> &arr) {
        int n = arr.size();
        vector<int> pse = findPSE(arr);
        vector<int> nse = findNSE(arr);
        int maxi = 0;
        for(int i=0; i<n; i++) {
            maxi = max(maxi,arr[i] * (nse[i] - pse[i] - 1));
        }
        return maxi;

    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int ans = 0;
        if(matrix.empty()) return 0;
        int n = matrix.size() , m = matrix[0].size();
        vector<int> arr(m,0);

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') arr[j]++;
                else arr[j] = 0;
            }
            ans = max(ans,largest(arr));
        }
        return ans;
    }
};