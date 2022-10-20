class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0;
        int left = 0;
        for(auto &c:s)
        {
            left += c == '('? 1:-1;
            if(left == -1)
            {
                count++;
                left = 0;
            }
        }
        
        return count + left;
    }
};