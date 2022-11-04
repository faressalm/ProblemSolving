class Solution {
private: bool isVo(char c){
    vector<char> vowels{'a','e','i','o','u','A','E','I','O','U'};
    return find(vowels.begin(),vowels.end(),c) != vowels.end();
}
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.size()-1;
        while(i<=j){
            if(isVo(s[i])&&isVo(s[j]))
                swap(s[i++],s[j--]);
            else{
                if(!isVo(s[i]))
                    i++;
                if(!isVo(s[j]))
                    j--;                
            }
        }
        return s;
    }
};