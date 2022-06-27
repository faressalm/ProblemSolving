class Solution {
public:
    int minPartitions(string n) {
        char c= '1';
        for(auto x:n)
            if(c<x)
                c=x;
        return c-'0';
    }
};