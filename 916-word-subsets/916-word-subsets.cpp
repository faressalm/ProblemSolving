class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> subset(26,0);
        vector<string> sol;
        for(auto word:words2){
            vector<int> temp(26,0);
            for(auto &c:word){
                temp[c-'a']++;
                subset[c-'a'] = max(subset[c-'a'],temp[c-'a']);   
            }
        }
        for(auto word:words1){
            vector<int> temp = subset;
            for(auto &c:word)
                if(temp[c-'a']!=0)
                    temp[c-'a']--;
            if(*max_element(temp.begin(),temp.end())<=0)
                sol.push_back(word);
        }
        return sol;
    }
};