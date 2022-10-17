class Solution {
public:
    bool checkIfPangram(string sentence) {
        int letters =0;
        for(auto &c:sentence)
            letters |= 1<< (c-'a');
        return letters == ((1<<26) -1);
    }
};