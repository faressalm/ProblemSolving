class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> alph = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        unordered_set<string> s;
        string morse="";
        for(auto &word:words){
            morse="";
            for(auto &letter:word){
                morse+=alph[letter-'a'];
            }
            s.insert(morse);
        }
        return s.size();
    }
};