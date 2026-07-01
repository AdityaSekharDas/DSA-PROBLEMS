class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        int n = nums1.size() , m = nums2.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(nums1[i] == nums2[j]) {
                    int ans = -1;
                    for(int k=j+1; k<m; k++) {
                        if(nums2[k] > nums2[j]) {
                            ans = nums2[k];
                            break;
                        }
                    }
                    v.push_back(ans);
                }
            }
        }
        return v;
    }
};