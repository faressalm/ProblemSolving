class Solution {
public:
    int numMatchingSubseq(string t, vector<string>& words) {
        int counter=words.size();
        vector<vector<int>> hash(26); //chars -> list of indices;
        for(int i=0; i<t.length();i++) hash[t[i]-'a'].push_back(i);
        for(auto word:words){
            int prev = -1;
            int i;
            for(auto c:word){
                vector<int>& vec = hash[c-'a'];
                auto pos = upper_bound(vec.begin(), vec.end(), prev);
                // find the first pos whose value is greater than prev
                if(vec.empty()||pos == vec.end()) {
                    counter--;
                    break;}
                prev = *pos;
            }
        }
        return counter;
    }
};