class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp;

        for(int i=0; i<m; i++) temp.push_back(nums1[i]);
        for(int y : nums2) temp.push_back(y);

        sort(temp.begin(),temp.end());
        
        for(int i=0; i<m+n; i++) {
            nums1[i] = temp[i];
        }
    }
};