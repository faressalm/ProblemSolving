class Solution {
private:
    // trie node
    struct TrieNode
    {
        struct TrieNode *children[26];
        bool isEndOfWord;
    };
    // Returns new trie node (initialized to NULLs)
    struct TrieNode *getNode(void)
    {
        struct TrieNode *pNode =  new TrieNode;
        pNode->isEndOfWord = false;
        for (int i = 0; i < 26; i++)
            pNode->children[i] = NULL;
        return pNode;
    }
    int insert(struct TrieNode *root, string key)
    {   int sum =0;
        struct TrieNode *pCrawl = root;

        for (int i = key.size()-1; i >= 0; i--)
        {
            int index = key[i] - 'a';
            if (!pCrawl->children[index])
                pCrawl->children[index] = getNode();
            pCrawl = pCrawl->children[index];
            if(pCrawl->isEndOfWord){
                pCrawl->isEndOfWord =false;  
                sum-=(key.size()-i+1);
            }
        }
        // mark last node as leaf
        if(!hasChild(pCrawl)){
            pCrawl->isEndOfWord = true;
            sum+=(1+key.size());
        }
        return sum;
    } 
    bool hasChild(struct TrieNode *root){
        for(int i=0;i<26;i++)
            if(root->children[i] !=NULL)
                return true;
        return false;
    }
    int search(struct TrieNode *root,int wordSize){
         if(root->isEndOfWord)
             return 1+wordSize;
        int sum =0;
         for(int i=0;i<26;i++)
            if (root->children[i])
                sum+= search(root->children[i],wordSize+1);
        return sum;
    }
public:
    int minimumLengthEncoding(vector<string>& words) {
        struct TrieNode *root = getNode();
        int sum=0;
        for (int i = 0; i < words.size(); i++)
             sum+=insert(root, words[i]);
        return sum;
    }
};