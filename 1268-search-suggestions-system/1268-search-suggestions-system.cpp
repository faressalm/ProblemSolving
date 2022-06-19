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
    int getLow(char c, vector<string>& products,int index,int low,int high){ 
        int startIndex = -1;
        while(low<=high){
            int mid = low+ (high-low)*0.5;
            if(products[mid][index]==c){
                startIndex = mid;
                high = mid-1;
            }
            else if(products[mid].size()>index&&products[mid][index]>c)
                high = mid-1;
            else 
                low = mid+1;
        }
        return startIndex;
    }
    int getHigh(char c, vector<string>& products,int index,int low,int high){
        int endIndex = -1;
        while(low<=high){
            int mid = low+ (high-low)*0.5;
            if(products[mid][index]==c){
                endIndex = mid;
                low = mid+1;
            }
            else if(products[mid].size()>index&&products[mid][index]>c)
                high = mid-1;
            else 
                low = mid+1;
        }
        return endIndex;
    }
     vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<vector<string>> sol;
        sort(products.begin(), products.end());
        int left = 0, right = products.size() - 1;
        for(int  i =0;i<searchWord.size();i++){
            if(left!=-1){
                int nLeft = getLow(searchWord[i],products,i,left,right);
                int nRight = getHigh(searchWord[i],products,i,left,right);
                left = nLeft;
                right= nRight;                
            }
            if(left!=-1)
              sol.push_back(vector<string> (products.begin()+left,products.begin()+left+min(3,right-left+1)));
            else sol.push_back({});
        }         
        return sol;
    }

};