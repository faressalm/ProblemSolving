class Solution {
private: string patternToInt(string pattern){
    int index=0;
    vector<char> num;
    unordered_map<int,int> m;
    for(auto d:pattern){
        if(m.find(d)==m.end())
            m[d]=++index;
       num.push_back(m[d]);
    }
    return string(num.begin(),num.end());
}
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        string patternInt = patternToInt(pattern);
        vector<string> sol;
        for(auto word:words)
            if(patternInt == patternToInt(word))
                sol.push_back(word);
        return sol;
    }
};