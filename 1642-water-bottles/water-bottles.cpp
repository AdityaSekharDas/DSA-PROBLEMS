class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int cnt = 0;
        int emp = 0;
        while(numBottles > 0) {
            cnt += numBottles;
            emp += numBottles;
            numBottles = emp / numExchange;
            emp = emp % numExchange;
        }
        return cnt;
    }
};