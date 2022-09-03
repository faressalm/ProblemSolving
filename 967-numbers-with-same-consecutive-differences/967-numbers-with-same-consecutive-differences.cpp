class Solution {
private: int vecToInt(vector<int>&vec){
    int number=0;
    int digit = pow(10,vec.size()-1);
    for(auto num:vec)
    {
        number+=num*digit;
        digit/=10;
    }
    return number;
}
   void bfs(int n,int k,vector<vector<int>> & vec ){
        if(vec.size()==0||vec[0].size()==n)
            return;
       vector<vector<int>> level;
       for(auto v:vec){
           for(int i=0;i<=9;i++){
                if(abs(v[v.size()-1]-i)==k)
                {   vector<int> temp =v;
                    temp.push_back(i);
                    level.push_back(temp);
                }               
           }
       }
       vec = level;
       bfs(n,k,vec);
    }
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> sol;
        vector<vector<int>> vec;
        for(int i=1;i<=9;i++)
            vec.push_back({i});
        bfs(n,k,vec);
        for(auto v:vec)
            sol.push_back(vecToInt(v));
        return sol;
    }
};

