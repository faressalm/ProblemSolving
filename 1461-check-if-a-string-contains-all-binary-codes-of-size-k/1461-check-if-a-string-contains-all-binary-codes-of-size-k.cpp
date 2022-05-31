class Solution {
public:
    bool hasAllCodes(string s, int k) {
        unordered_set<string> table;
        int permutations = pow(2,k);
        int size = s.size();
        for(int i=0;i<(-k+size+1);i++){
            table.insert(s.substr(i,k));
        }

        if(table.size()==permutations)
            return true;
        return false;
    }
};