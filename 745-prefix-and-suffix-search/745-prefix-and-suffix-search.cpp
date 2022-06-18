class WordFilter {
private: vector<pair<vector<bool>,unordered_map<string,int>>> trie;
// vector<int> -> next letters . unordered_map -> words index ends with this letter     
public:
    WordFilter(vector<string>& words) {
        vector<pair<vector<bool>,unordered_map<string,int>>> 
            trie(27,{vector<bool>(27,false),unordered_map<string,int>()});
        for(int index = 0 ;index<words.size();index++){
            int prev = 0;
            for(int j=0;j<words[index].size();j++){
                int charIndex = words[index][j] -'a'+1;
                trie[prev].first[charIndex] = true;
                prev = charIndex;
            }
            trie[prev].second[words[index]] = index;
        }
        this->trie = trie;
    }
    
    int searchSuffix(vector<char>& word,string suffix,int prev){
        if(word.size()+suffix.size()>10)
            return -1;
        int suffInd = suffix[0]-'a'+1;
        int position = -1;
        for(int i=1;i<=26;i++){
            if(trie[prev].first[i])
            {   word.push_back((char)(i-1+'a'));
                position = max(position,searchSuffix(word,suffix,i));
                if(i==suffInd){
                position = max(getIndex(word,suffix),position);
                }
                word.pop_back();
            }
        }
        return position;
    }
    int getIndex(vector<char> word,string suffix){
       if(word.size()+suffix.size()>11)
            return -1; 
       int prev = suffix[0]-'a'+1; 
       for(int i=1;i<suffix.size();i++){
            int charIndex = suffix[i] -'a'+1;
            if(!trie[prev].first[charIndex])
                 return -1;
            prev = charIndex;
            word.push_back(suffix[i]);
        }
       string c(word.begin(),word.end());
       if(trie[prev].second.find(c) != trie[prev].second.end()){
           return trie[prev].second[c];
       } 
        return -1;
    }
    int f(string prefix, string suffix) {
        int prev=0;
        vector<char> word;
        int position =-1;
        for(int i=0;i<prefix.size();i++){
            int charIndex = prefix[i] -'a'+1;
            if(!trie[prev].first[charIndex])
                 return -1;
            prev = charIndex;
            word.push_back(prefix[i]);
            if(prefix.substr(i) == suffix.substr(0,prefix.size()-i)){
                position = max(position,getIndex(word,suffix));
            }
        }
        return max(position,searchSuffix(word,suffix,prev));
    }
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */