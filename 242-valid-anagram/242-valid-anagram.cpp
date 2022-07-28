class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        vector<int> lettersFreq(26,0);
        for(int i=0;i<s.size();i++){
           lettersFreq[s[i]-'a']++;
           lettersFreq[t[i]-'a']--;                        
        }
        for(auto freq:lettersFreq)
            if(freq!=0)
              return false;
        return true;
    }
};