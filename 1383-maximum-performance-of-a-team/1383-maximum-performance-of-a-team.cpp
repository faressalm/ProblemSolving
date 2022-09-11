class Solution {
    
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
        priority_queue<int,vector<int>, greater<int> > minSpeed;
        vector<pair<int,int>> se;
        int mode = 1e9+7;
        int currEff = 0;
        int currSpeed = 0;
        for(int i=0;i<n;i++)
            se.push_back({efficiency[i],speed[i]});
        sort(se.begin(),se.end(),greater<pair<int,int>>());
        long ans=0;long totalSpeed = 0;
        for(auto p:se){
            currEff = p.first;
            currSpeed = p.second;
            if(minSpeed.size()==k){
                totalSpeed -= minSpeed.top(); minSpeed.pop();
            }
            minSpeed.push(currSpeed);
            totalSpeed += currSpeed;
            ans = max(ans, totalSpeed*currEff);
        }
        return ans%mode;
    }
};