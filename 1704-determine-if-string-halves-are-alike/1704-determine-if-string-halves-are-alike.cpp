class Solution {
private: 
    bool isVowel(char &c){
        string vowels = "aeiouAEIOU";
        return vowels.find(c) == string::npos;
    }
public:
    bool halvesAreAlike(string s) {
        int count =0;
        for(int i=0;i<s.size()/2;i++)
            count += isVowel(s[i]);
        for(int i=s.size()/2; i<s.size();i++)
            count -= isVowel(s[i]);
        return !count;
    }
};