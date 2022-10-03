class Solution {
private: 
    vector<vector<int>> sol;
    void temp(int start,int n,int k,vector<int> &set){
        if(set.size()==k)
        {
            sol.push_back(set);
        }
        for(int i=start;i<=n;i++)
        {
                set.push_back(i);
                temp(i+1,n,k,set);
                set.pop_back();
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> set;
        temp(1,n,k,set);
        return sol;
    }
};