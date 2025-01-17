class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        priority_queue<int> q;
        for(auto &row:matrix){
            for(auto &e:row){
                q.push(e);
                if(q.size()>k)
                    q.pop();
            }
        }
        return q.top();
    }
};