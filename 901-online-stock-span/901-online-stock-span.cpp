class StockSpanner {
private: stack<pair<int,int>> s;
public:
    StockSpanner() {
        
    }
    
    int next(int price) {
        int span=1;
        while(!s.empty())
        {
            if(price>=s.top().first)
            {
                span+=s.top().second;
                s.pop();
            }else break;
        }
        s.push({price,span});
        return span;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */