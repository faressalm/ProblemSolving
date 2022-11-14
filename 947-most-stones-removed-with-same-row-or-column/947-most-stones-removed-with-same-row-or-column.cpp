class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        unordered_map<int,vector<int>> rows,cols;
        unordered_set<int> visitedRow;
        unordered_set<int> visitedCol;
        int n= stones.size();
        for(int i=0;i<n;i++){
            rows[stones[i][0]].push_back(i);
            cols[stones[i][1]].push_back(i);
        }
        int cc = 0;
        stack<int> dfs;
        for(int i=0;i<n;i++){
            if(visitedRow.count(stones[i][0])&&visitedCol.count(stones[i][1]))
                continue;
            cc++;
            dfs.push(i);
            while(!dfs.empty()){
                int top = dfs.top(); dfs.pop();
                if(!visitedRow.count(stones[top][0])){
                    for(auto &node: rows[stones[top][0]])
                            dfs.push(node);
                    visitedRow.insert(stones[top][0]);
                }
                if(!visitedCol.count(stones[top][1])){
                    for(auto &node: cols[stones[top][1]])
                            dfs.push(node);
                    visitedCol.insert(stones[top][1]);
                }
            }
        }       
        return n-cc;
    }
};