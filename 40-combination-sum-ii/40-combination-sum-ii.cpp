class Solution {
    private: vector<vector<int>> combinations;
    void temp(vector<int>& candidates, int target,int next, vector<int>& comb){
        if(target==0)
            combinations.push_back(comb);
        if(next==candidates.size())
            return ;
        int brev=-1;
        for(int i=next;i<candidates.size();i++){
            if(brev!=candidates[i])
            if(target-candidates[i]>=0){
               comb.push_back(candidates[i]);
               temp(candidates,target-candidates[i],i+1,comb);
               comb.pop_back(); 
               brev = candidates[i];
            }else{
                return;
            }
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<int> comb;
        temp(candidates,target,0,comb);
        return combinations;
    }
};