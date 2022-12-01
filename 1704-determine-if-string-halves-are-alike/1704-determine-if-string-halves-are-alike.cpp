class Solution {
private: 
    bool isVowel(char &c){
        string vowels = "aeiouAEIOU";
        return vowels.find(c) == string::npos;
    }
public:
    bool halvesAreAlike(string s) {
        int count =0;
        for(int i=0;i<s.size();i++)
            count += (i<s.size()/2?1:-1)*isVowel(s[i]);
        return !count;
    }
};