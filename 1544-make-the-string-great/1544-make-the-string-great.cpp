class Solution {
public:
    string makeGood(string s) {
        vector<char> cs;
        vector<bool> has(s.size(),true);
        stack<int> valid;
        valid.push(0);
        for(int i=1;i<s.size();i++){
            if(!valid.empty()&&abs(int(s[i]-s[valid.top()])) == 32){
                has[valid.top()] = false;
                has[i] = false;
                valid.pop();
            }else
                valid.push(i);
        }
        for(int i=0;i<s.size();i++)
            if(has[i])
                cs.push_back(s[i]);
        return string(cs.begin(),cs.end());
    }
};