class Solution {
private: int temp(string word,unordered_map<string,int>& dic){
    if(word.empty()||dic.find(word)==dic.end())
        return 0;
    if(dic[word]!=-1)
        return dic[word];
    int len = dic[word];
    for(int i=0;i<word.size();i++){
        string x = word;
        x.erase(i, 1);
        len =  max(len,1+temp(x,dic));
    }
    dic[word] = len;
    return len;
}
public:
    int longestStrChain(vector<string>& words) {
    unordered_map<string,int> dic;
        for(auto word:words)
            dic[word]=-1;
        int sol =0;
        for(auto word:words)
            sol = max(sol,temp(word,dic));
        return sol;
    }
};