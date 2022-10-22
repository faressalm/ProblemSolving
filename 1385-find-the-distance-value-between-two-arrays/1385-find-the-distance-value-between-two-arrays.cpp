class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(),arr2.end());
        int count =0;
        for(auto &num: arr1){
                if (upper_bound(begin(arr2), end(arr2), num + d) == lower_bound(begin(arr2), end(arr2), num - d)) ++count;
        }        
        return count;
    }
};