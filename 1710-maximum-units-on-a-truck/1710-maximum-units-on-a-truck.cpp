class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(),boxTypes.end(),[](const vector<int> & i1,const vector<int> &i2){
            return i1[1]>i2[1];
        });
        int total = 0;
        int takenBoxes;
        for(int i=0;i<boxTypes.size()&&truckSize!=0;i++){
            takenBoxes = min(truckSize,boxTypes[i][0]);
            truckSize -= takenBoxes;
            total += takenBoxes*boxTypes[i][1];
        } 
        return total;
    }
};