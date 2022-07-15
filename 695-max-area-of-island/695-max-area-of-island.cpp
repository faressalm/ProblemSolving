class Solution {
private: int getArea(vector<vector<int>>& grid,int r,int c){
    queue<pair<int,int>> q;
    q.push({r,c});
    int area=0;
    pair<int,int> node;
    while(!q.empty()){
        node =q.front(); 
        if(grid[node.first][node.second]==1)
        {
            area++;
            grid[node.first][node.second]=0;
            if(node.first+1<grid.size())
                q.push({node.first+1,node.second});
            if(node.first-1>=0)
                q.push({node.first-1,node.second});            
            if(node.second+1<grid[0].size())
                q.push({node.first,node.second+1});
            if(node.second-1>=0)
                q.push({node.first,node.second-1});            
        }
        q.pop();
    }
    return area;
}    
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area =0;
        for(int r=0;r<grid.size();r++){
            for(int c=0;c<grid[0].size();c++){
                if(grid[r][c]==1)
                    area = max(area,getArea(grid,r,c));
            }
        }
        return area;
    }
};