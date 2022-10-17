class Solution {
public:
    bool checkIfPangram(string sentence) {
        if(sentence.size()<26)
            return false;
        vector<bool> letters(26,false);
        for(auto &c:sentence)
            letters[c-'a'] =true;
        bool sol=true;
        for(auto b:letters)
            sol=sol&&b;
        return sol;
    }
};