class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {
        int n = drones.size() , m = drones[0].size();
        int mini = INT_MAX , ind = -1;
        for(int i=0; i<n; i++) {
            int dist = abs(drones[i][0]-target[0])+abs(drones[i][1]-target[1]);
            if(dist <= drones[i][2] && dist < mini) {
                ind = i;
                mini = min(mini,dist);
            }
        }
        return ind;
    }
};