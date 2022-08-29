class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        stack<pair<int,int>> s;
        int counter=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    s.push({i,j});
                    counter++;
                    while(!s.empty()){
                        pair<int,int> p =s.top();s.pop();
                        if(grid[p.first][p.second]=='1'){
                            grid[p.first][p.second]='0';
                            if(p.second+1<grid[0].size())
                                s.push({p.first,p.second+1});
                            if(p.first+1<grid.size())
                                s.push({p.first+1,p.second});
                            if(p.second-1>=0)
                                s.push({p.first,p.second-1});
                            if(p.first-1>=0)
                                s.push({p.first-1,p.second});
                        }
                    }
                }
            }
        }
        return counter;
    }
};