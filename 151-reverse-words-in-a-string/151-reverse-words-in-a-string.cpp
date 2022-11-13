class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(),s.end());
        int size = s.size();
        int start= 0;
        int next = 0;
        int end = 0;
        for(int i=0;i<size;i++){
            while(i<size&&s[i]==' ')
                i++;
            start = i;
            while(i<size&&s[i]!=' '){
                swap(s[end++],s[i++]);
            }
            reverse(s.begin()+next,s.begin()+end);
            i--;
            next = end+1;
            end = next;
        }       
        while(s[s.size()-1] == ' ')
            s.pop_back();
        return s;
    }
};