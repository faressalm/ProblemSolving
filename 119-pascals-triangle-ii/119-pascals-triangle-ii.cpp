class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> prev = {1};
        for(int i=1;i<rowIndex+1;i++){
            vector<int> current;
            current.push_back(1);
            for(int j=0;j<i-1;j++)
                current.push_back(prev[j]+prev[j+1]);
            current.push_back(1);   
            prev =current;
        }
        return prev;
    }
};