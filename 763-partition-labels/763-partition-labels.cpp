class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> letters(26,-1);
        for(int i=0;i<s.size();i++)
            letters[s[i]-'a']=i;
        int start =0; int end=0;
        vector<int> sol;
        int begin=0;
        while(start<s.size()){
            end = letters[s[start++]-'a'];
            while(start<=end)
                end = max(letters[s[start++]-'a'],end);
            sol.push_back(end-begin+1);
            begin=start;
        }
        return sol;
            
    }
};