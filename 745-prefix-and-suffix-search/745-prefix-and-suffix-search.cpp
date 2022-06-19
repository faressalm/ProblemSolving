class WordFilter {
private: 
    struct TrieNode
    {
        struct TrieNode *children[26];
        int wordIndex;
    };
    // Returns new trie node (initialized to NULLs)
    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
        pNode->wordIndex = -1;
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
        return pNode;
    }
    void insert(struct TrieNode *root, string key,int wordIndex)
    {
        struct TrieNode *pCrawl = root;

        for (int i = 0; i < key.length(); i++)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
        }
        pCrawl->wordIndex = wordIndex;
    }    
    struct TrieNode *trie;
public:
    WordFilter(vector<string>& words) {
        struct TrieNode *root = getNode();
        vector<vector<string>> sol;
        for (int i = 0; i < words.size(); i++)
             insert(root, words[i],i);
        this->trie =root;
    }
    
    int searchSuffix(string suffix,struct TrieNode *root){
        if(!root)
            return -1;
        struct TrieNode *pCrawl = root;
        int suffInd = suffix[0]-'a';
        int position = -1;
        for(int i=0;i<26;i++){
            if(pCrawl->children[i] != NULL)
            {  
                position = max(position,searchSuffix(suffix,pCrawl->children[i]));
                if(i==suffInd){
                position = max(getIndex(suffix,pCrawl->children[i]),position);
                }
            }
        }
        return position;
    }
    int getIndex(string suffix,struct TrieNode *root){
       if(!root)
            return -1;
       struct TrieNode *pCrawl = root;        
       for(int i=1;i<suffix.size();i++){
            int index = suffix[i] - 'a';
            if (!pCrawl->children[index])
                return -1;
            pCrawl = pCrawl->children[index];
        }
        return pCrawl->wordIndex;
    }
    int f(string prefix, string suffix) {
        int position =-1;
        struct TrieNode *pCrawl = trie;
        for (int i = 0; i < prefix.length(); i++)
        {
            int index = prefix[i] - 'a';
            if (!pCrawl->children[index])
                return -1;
            pCrawl = pCrawl->children[index];
            if(prefix.substr(i) == suffix.substr(0,prefix.size()-i)){
                position = max(position,getIndex(suffix,pCrawl));
            }
        }
        return max(position,searchSuffix(suffix,pCrawl));
    }
};
