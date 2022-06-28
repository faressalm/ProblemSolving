class Solution {
public:
    int minDeletions(string s) {
        vector<int> c(27,0);
        for(auto x:s)
            c[int(x-'a')]++;
        sort(c.begin(),c.end());
        int sol=0;
        for(int i=c.size()-1;i>0&&c[i-1]!=0;i--){
            while(c[i]<=c[i-1]&&c[i-1]!=0){
                sol++;
                c[i-1]--;
            }
        }
        return sol;
    }
};