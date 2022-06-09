class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<pair<bool,int>> sums(2004,{false,-1});
        for(int i=0;i<numbers.size();i++)
            sums[numbers[i]+1000] = {true,i};
        for(int i=0;i<numbers.size();i++){
            int next = target - numbers[i]+1000;
            if(next<2004&&sums[next].first&&sums[next].second!=i)
                return {i+1,sums[next].second+1};
        }
        return {};
    }
};