class StockSpanner {
    vector<int> arr;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        arr.push_back(price);
        int n = arr.size();
        int cnt = 1;
        for(int i=n-2; i>=0; i--) {
            if(arr[i] <= price) cnt++;
            else break;
        }
        return cnt;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */