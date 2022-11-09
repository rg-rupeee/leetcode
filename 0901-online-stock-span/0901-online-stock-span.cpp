class StockSpanner {
public:
    stack<pair<int, int>> sp;
    StockSpanner() {
        
    }
    
    int next(int price) {
        int ans = 1;
        while(!sp.empty() && sp.top().first <= price){
            ans = ans + sp.top().second;
            sp.pop();
        }
        
        sp.push({price, ans});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */