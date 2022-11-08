class Solution {
public:
    string makeGood(string s) {
        stack<char> valid;
        valid.push(s[0]);
        for(int i=1;i<s.size();i++){
            if(!valid.empty()&&abs(int(s[i]-valid.top())) == 32)
                valid.pop();
            else
                valid.push(s[i]);
        }
        vector<char> cs(valid.size());
        int index = valid.size()-1;
        while(index>=0)
        {
            cs[index--]= valid.top();valid.pop();
        }
        return string(cs.begin(),cs.end());
    }
};