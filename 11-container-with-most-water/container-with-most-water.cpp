class Solution {
public:
    int maxArea(vector<int>& height) {
        int area = 0;
        int l = 0 , r = height.size()-1;
        while(l < r) {
            int val = (r - l) * min(height[l] , height[r]);
            area = max(area,val);

            if(height[l] < height[r]) {
                int h = height[l];
                while(l < r && height[l] <= h) l++;
            }

            else {
                int h = height[r];
                while(r > l && height[r] <= h) r--;
            }
        }
        return area;
    }
};