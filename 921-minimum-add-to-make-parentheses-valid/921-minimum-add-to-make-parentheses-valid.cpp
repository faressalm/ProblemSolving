class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        stack<char> letter;
        for(auto &c:s)
            if(c=='(')
                letter.push(c);
            else
                if(letter.empty())
                    count++;
                else
                    letter.pop();
        return count + letter.size();
    }
};