class Solution {
    private: vector<vector<int>> combinations;
    void temp(vector<int>& candidates, int target,int next, vector<int>& comb){
        if(target==0)
            combinations.push_back(comb);
        if(next==candidates.size())
            return ;
        for(int i=next;i<candidates.size();i++){
            if(target-candidates[i]>=0){
               comb.push_back(candidates[i]);
               temp(candidates,target-candidates[i],i,comb);
               comb.pop_back(); 
            }else{
                return;
            }
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> comb;
        temp(candidates,target,0,comb);
        return combinations;
    }
};