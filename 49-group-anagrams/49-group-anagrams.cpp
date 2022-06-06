class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> anagrams;
        vector<vector<string>>  sol;
        int index=0;
        for(int i=0;i<strs.size();i++){
           string temp =strs[i];
           sort(temp.begin(),temp.end());
           if(anagrams.find(temp)==anagrams.end()){
              anagrams[temp]=index;
              index++;
              sol.push_back({strs[i]});
           }else{
              sol[anagrams[temp]].push_back(strs[i]); 
           }
        }
        return sol;
    }
};