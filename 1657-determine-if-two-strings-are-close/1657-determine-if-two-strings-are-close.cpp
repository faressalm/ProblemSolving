class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size())
            return false;
        vector<int> letter1(26,0);
        vector<int> letter2(26,0);
        unordered_set<char> s;
        for(auto &c: word1){
            s.insert(c);
            letter1[c-'a']++;
        }
        for(auto &c: word2){
            if(s.find(c)==s.end())
                return false;
            letter2[c-'a']++;
        }
        sort(letter1.begin(),letter1.end());
        sort(letter2.begin(),letter2.end());
        return letter1 == letter2;
    }
};