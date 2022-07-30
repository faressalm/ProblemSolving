class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char,int> subset;
        vector<string> sol;
        for(auto word:words2){
            unordered_map<char,int> temp;
            for(auto &c:word){
                temp[c]++;
                subset[c] = max(subset[c],temp[c]);   
            }
        }
        bool take;
        for(auto word:words1){
            unordered_map<char,int> temp = subset;
            for(auto &c:word)
                if(temp.find(c)!=temp.end())
                    temp[c]--;
            take=true;
            for(auto &m:temp)
                if(m.second>0)
                    take=false;
            if(take)
                sol.push_back(word);
        }
        return sol;
    }
};