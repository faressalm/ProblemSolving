class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        return s;
    }
};