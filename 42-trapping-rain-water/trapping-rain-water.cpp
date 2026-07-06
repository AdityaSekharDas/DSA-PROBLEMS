class Solution {
public:
    int trap(vector<int>& arr) {
        int leftmax = 0 , rightmax = 0;
        int total = 0;
        int l = 0 , r = arr.size()-1;
        while(l < r) {
            if(arr[l] <= arr[r]) {
                if(leftmax > arr[l]) total += leftmax - arr[l];
                else leftmax = arr[l];
                l++;
            }
            else {
                if(rightmax > arr[r]) total += rightmax - arr[r];
                else rightmax = arr[r];
                r--;
            }
        }
        return total;
    }
};