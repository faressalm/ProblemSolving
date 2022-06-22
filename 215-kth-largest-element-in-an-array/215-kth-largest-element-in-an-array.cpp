class Solution {
private:
    priority_queue<int,vector<int>,greater<int>> q;   
    int K;
    int add(int val) {
        q.push(val);
        if(q.size()>K)
            q.pop();
        return q.top();
    }    
public:
    int findKthLargest(vector<int>& nums, int k) {
        K=k;
        for(auto num:nums)
            add(num);
        return q.top();
    }

};