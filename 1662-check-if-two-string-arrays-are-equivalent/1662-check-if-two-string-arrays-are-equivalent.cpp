class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        vector<int> letters(26,0);
        int size=0;
        for(int i=0;i<word1.size();i++){
            for(int c=0;c<word1[i].size();c++)
                letters[word1[i][c]-'a']+=(size+c+1);
            size+=word1[i].size();
        }
        size=0;
        for(int i=0;i<word2.size();i++){
            for(int c=0;c<word2[i].size();c++)
                letters[word2[i][c]-'a']-=(size+c+1);
            size+=word2[i].size();
        }
        for(auto &x:letters)
            if(x!=0)
                return false;
        return true;
    }
};