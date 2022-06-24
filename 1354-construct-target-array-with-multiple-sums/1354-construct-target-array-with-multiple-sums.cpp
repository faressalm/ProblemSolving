class Solution {
public:
    bool isPossible(vector<int>& target) {
        long sum= 0;
        priority_queue<int> q;
        for(auto t:target){
            q.push(t);
            sum+=t;
        }
        while(q.top()!=1){
            int largest = q.top();q.pop();
            sum-=largest;
            if (largest<= sum || sum < 1) return false;
            largest%= sum;
            sum+=largest;
            q.push(largest?largest: sum);
        }
        return true;
    }
};