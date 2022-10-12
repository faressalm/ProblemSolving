class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> s={{}};
        int size;
        for(auto &num:nums){
            size = s.size();
            for(int i=0;i<size;i++){
                vector<int> newv(s[i]);
                newv.push_back(num);
                s.push_back(newv);
            }
        }
        vector<vector<int>> sol;
        for(int i=0;i<s.size();i++){
            sol.push_back(s[i]);
            for(int j=i+1;j<s.size();j++){
                if(s[i] == s[j])
                {
                    sol.pop_back();
                    break;
                }
            }
        }
        return sol;
    }
};