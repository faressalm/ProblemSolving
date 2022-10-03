class Solution {
private: 
    vector<vector<int>> sol;
    void temp(int start,int n,int k,unordered_set<int> &set){
        if(set.size()==k)
        {
            sol.push_back(vector<int>(0));
            sol[sol.size()-1].insert(sol[sol.size()-1].end(), set.begin(), set.end());
        }
        for(int i=start;i<=n;i++)
        {
            if(set.find(i) == set.end()){
                set.insert(i);
                temp(i+1,n,k,set);
                set.erase(set.find(i));
            }
        }
    }
public:
    vector<vector<int>> combine(int n, int k) {
        unordered_set<int> set;
        temp(1,n,k,set);
        return sol;
    }
};