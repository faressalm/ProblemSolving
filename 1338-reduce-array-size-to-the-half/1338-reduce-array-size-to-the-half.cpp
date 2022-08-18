class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int size= arr.size();
        unordered_map<int,int> freq;
        for(auto a:arr)
            freq[a]++;
        priority_queue<int> q;
        for(auto &f:freq)
            q.push(f.second);
        int setSize = 0;
        int newSize=0;
        while(!q.empty()&&newSize<size/2){
            newSize+=q.top();q.pop();
            setSize++;
        }
        return setSize;
    }
};