class Solution {
private: bool checkValid(string str1, string str2, string target){
    for(int i=0;i<str1.size();i++)
        if(str1[i]!=target[i])
            return false;
    int j=target.size()-1;
    for(int i=str2.size()-1;i>=0;i--)
        if(str2[i]!=target[j--])
            return false;
    return true;
}
public:
    int numOfPairs(vector<string>& nums, string target) {
        int count =0;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i].size()+nums[j].size()== target.size())
                    count += checkValid(nums[i],nums[j],target)+checkValid(nums[j],nums[i],target);
            }
        }
        return count;
    }
};