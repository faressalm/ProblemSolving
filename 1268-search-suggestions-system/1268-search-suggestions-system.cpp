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
void insert(struct TrieNode *root, string key)
{
    struct TrieNode *pCrawl = root;
 
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->children[index])
            pCrawl->children[index] = getNode();
        pCrawl = pCrawl->children[index];
    }
    // mark last node as leaf
    pCrawl->isEndOfWord = true;
}    
struct TrieNode * search(struct TrieNode *root, char key)
{   if(root==NULL)
       return root;
    int index = key - 'a';
    if (!root->children[index])
      return NULL;
    return root->children[index];
}
void getThreeMin(vector<string>& v,struct TrieNode *root,vector<char> word){
    if(root==NULL||v.size()==3)
        return;
    if(root->isEndOfWord){
         v.push_back(string (word.begin(),word.end()));
    }
    for(int i=0;i<26;i++){
        if (root->children[i]){
            word.push_back((char)(i+'a'));
            getThreeMin(v,root->children[i],word);
            word.pop_back();
        }
    }
}    
public:
    // vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    //     struct TrieNode *root = getNode();
    //     vector<vector<string>> sol;
    //     for (int i = 0; i < products.size(); i++)
    //          insert(root, products[i]);
    //     vector<char> word;
    //     for(int  i =0;i<searchWord.size();i++){
    //         root = search(root,searchWord[i]);
    //         vector<string> v;
    //         word.push_back(searchWord[i]);
    //         getThreeMin(v,root,word);
    //         sol.push_back(v);
    //     }
    //     return sol;
    // } 
     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> sol;
        sort(products.begin(), products.end());
        int left = 0, right = products.size() - 1;
        for(int  i =0;i<searchWord.size();i++){
            while (left <= right && (products[left].length() == i || products[left][i] < searchWord[i])) left++;
            while (left <= right && (products[right].length() == i || products[right][i] > searchWord[i])) right--;                                       sol.push_back(vector<string> (products.begin()+left,products.begin()+left+min(3,right-left+1)));
        }         
        return sol;
    }

};