class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> letters(26,-2);
        int index;
        for(int i=0;i<s.size();i++){
            index =int(s[i]-'a');
            if(letters[index]==-2)
                letters[index] = i;
            else if(letters[index]!=-1)
                letters[index]=-1;
        }
        index=INT_MAX;
        for(int i=0;i<26;i++)
            if(letters[i]>=0&&letters[i]<index)
                index= letters[i];
        return index==INT_MAX?-1:index;
    }
};