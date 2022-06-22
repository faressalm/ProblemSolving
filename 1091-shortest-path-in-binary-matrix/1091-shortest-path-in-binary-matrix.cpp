class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r=grid.size();
        int c=grid[0].size();
        if(grid[0][0]==1) return -1;
        if(r==1 && c==1 && grid[0][0]==0) return 1;
        vector<vector<int>> vis (r, vector<int> (c,0));
        int ans = 1;
        queue<pair<int, int>> q;
        q.push({0, 0});
        vis[0][0]=1;
        while(!q.empty()) {
            int n = q.size();
            for(int i=0; i<n; i++) {
                auto curr = q.front();
                q.pop();
                vector<vector<int>> v {{-1,-1}, {-1,0}, {-1,1}, {0,1}, {1,1}, {1,0}, {1,-1}, {0,-1}};
                for(int j=0; j<8; j++) {
                    int a=curr.first+v[j][0];
                    int b=curr.second+v[j][1];
                    if(a>=0 && b>=0 && a<r && b<c && grid[a][b]==0 && !vis[a][b]) {
                        if(a==r-1 && b==c-1) return ans+1;
                           q.push({a,b});
                           vis[a][b]=1;
                    }
                }
            }
            ans++;
        }
     return -1;
    }
};