class Solution {
public:
    int compress(vector<char>& chars) {
        chars.push_back(chars[chars.size()-1]+5);
        int write = 0;
        char prev = chars[0];
        int count =1;
        for(int i=1;i<chars.size();i++){
            if(chars[i]==prev){
                count++;
                continue;
            }
            chars[write++] = prev;
            if(count/10!=0)
            {
                string digits = to_string(count);
                for(int j=0;j<digits.size();j++)
                    chars[write++]= digits[j];
            }else if(count!=1)
                chars[write++]= '0'+count;
            count=1;
            prev = chars[i];
        }
        chars.pop_back();
        return write;
    }
};