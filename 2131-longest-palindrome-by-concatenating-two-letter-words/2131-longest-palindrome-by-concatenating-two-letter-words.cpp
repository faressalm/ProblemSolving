class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        int longestLen = 0;
        vector<string> singles;
        for(auto &word: words){
            string rev = {word[1],word[0]};
            if(word[0]==word[1])
                singles.push_back(word);
            if(m.find(rev)!=m.end()&&m[rev]!=0)
            {
                longestLen+=4;
                m[rev]++;
            }else{
                m[word]--;
            }
        }
        for(auto &word:singles)
            if(m[word]!=0){
                longestLen+=2;
                break;
            }
        return longestLen;
    }
};