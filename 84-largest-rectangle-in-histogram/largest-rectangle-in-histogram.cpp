class Solution {
public:
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
    vector<int> findPSEE(vector<int> arr) {
        int n = arr.size();
        vector<int> ans(n);
        stack<int> st;
        for(int i=0; i<n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i]) st.pop();
            ans[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }    
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        int maxi = INT_MIN;
        vector<int> left = findPSEE(arr);
        vector<int> right = findNSE(arr);
        for(int i=0; i<arr.size(); i++) {
            int val = arr[i] * (right[i] - left[i] - 1);
            maxi = max(maxi,val);
        }
        return maxi;
    }
};