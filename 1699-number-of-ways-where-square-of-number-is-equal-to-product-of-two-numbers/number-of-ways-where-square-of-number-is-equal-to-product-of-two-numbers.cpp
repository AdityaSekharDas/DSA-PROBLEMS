class Solution {
public:
    int numTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size() , m = nums2.size();
        int cnt = 0;

        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                for(int k=j+1; k<m; k++) {
                    if(1LL*nums1[i]*nums1[i] == 1LL*nums2[j]*nums2[k]) cnt++;
                }
            }
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                for(int k=j+1; k<n; k++) {
                    if(1LL*nums2[i]*nums2[i] == 1LL*nums1[j]*nums1[k]) cnt++;
                }
            }
        }

        return cnt;
    }
};