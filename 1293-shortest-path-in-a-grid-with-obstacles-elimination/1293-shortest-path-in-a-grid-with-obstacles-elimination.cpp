class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n= grid.size();
        int m = grid[0].size();
        queue<vector<int>> q;
        vector<vector<int>> visit(n,vector<int>(m,-1));
        q.push({0,0,k,0});
        int path = INT_MAX;
        while(!q.empty()){
            int size = q.size();
            for(int i=0;i<size;i++){
                vector<int> v = q.front(); q.pop();
                if(v[0]==n-1&&v[1]==m-1)
                    path =  min( path,v[3]);
                //right 
                if(v[1]+1<m&&(grid[v[0]][v[1]+1]==0 || v[2]!=0)&&visit[v[0]][v[1]+1]<(v[2]-grid[v[0]][v[1]+1])){
                    q.push({v[0],v[1]+1,grid[v[0]][v[1]+1]==0?v[2]:v[2]-1,v[3]+1});
                    visit[v[0]][v[1]+1] = (v[2]-grid[v[0]][v[1]+1]);
                }
                //down 
                if(v[0]+1<n&&(grid[v[0]+1][v[1]]==0 || v[2]!=0)&&visit[v[0]+1][v[1]]<(v[2]-grid[v[0]+1][v[1]])){
                    q.push({v[0]+1,v[1],grid[v[0]+1][v[1]]==0?v[2]:v[2]-1,v[3]+1});
                    visit[v[0]+1][v[1]] = (v[2]-grid[v[0]+1][v[1]]);
                }
                //left 
                if(v[1]>0&&(grid[v[0]][v[1]-1]==0 || v[2]!=0)&&visit[v[0]][v[1]-1]<(v[2]-grid[v[0]][v[1]-1])){
                    q.push({v[0],v[1]-1,grid[v[0]][v[1]-1]==0?v[2]:v[2]-1,v[3]+1});
                    visit[v[0]][v[1]-1] = (v[2]-grid[v[0]][v[1]-1]);
                }
                //up 
                if(v[0]>0&&(grid[v[0]-1][v[1]]==0 || v[2]!=0)&&visit[v[0]-1][v[1]]<(v[2]-grid[v[0]-1][v[1]])){
                    q.push({v[0]-1,v[1],grid[v[0]-1][v[1]]==0?v[2]:v[2]-1,v[3]+1});
                    visit[v[0]-1][v[1]] = (v[2]-grid[v[0]-1][v[1]]);
                }                
            }
        }
       return path==INT_MAX? -1: path; 
    }
};