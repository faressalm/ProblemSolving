class Solution {
    

public:
    int lengthOfLongestSubstring(string s) {
        if(s.size()==0)
            return 0;
        unordered_map<char,int> indexs;
        queue<char> q;
        int longest  =0;
        for(int i=0;i<s.size();i++){
            if(indexs.find(s[i])!=indexs.end()&&indexs[s[i]]!=0){
                while(q.front()!=s[i]){
                    indexs[q.front()]=0;
                    q.pop();
                }
                q.pop();
            }
            indexs[s[i]] =1;
            q.push(s[i]);
            longest = max(longest,(int)q.size());
        }
        return longest ;
    }
};