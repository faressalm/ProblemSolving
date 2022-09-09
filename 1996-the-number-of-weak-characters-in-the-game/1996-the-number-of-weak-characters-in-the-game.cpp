class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        sort(properties.begin(), properties.end(), [](const vector < int > & i1,
        const vector < int > & i2) {
            if(i1[0]==i2[0])
                return i1[1]>i2[1];
            return i1[0] < i2[0];
         });
        int size  = properties.size();
        int maxDef = properties[size-1][1];
        int ans = 0;
        for(int i=size-2;i>=0;i--)
        {
            if(properties[i][1]<maxDef)
                ans++;
            else maxDef = properties[i][1];
        }
        return ans;
    }
};