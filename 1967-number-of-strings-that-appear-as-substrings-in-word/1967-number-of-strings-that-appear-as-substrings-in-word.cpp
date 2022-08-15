class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int count =0;
        for(auto &c: patterns)
            if (word.find(c) != string::npos) {
                count++;
            }         
        return count;
    }
};