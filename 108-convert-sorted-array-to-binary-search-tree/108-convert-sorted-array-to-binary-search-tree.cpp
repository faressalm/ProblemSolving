/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private: TreeNode* temp(vector<int>& nums,int start,int end){
    if(start>end)
        return NULL;
    int mid= (end-start)/2+start;
    return new TreeNode(nums[mid],temp(nums,start,mid-1),temp(nums,mid+1,end));
    
}   
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return temp(nums,0,nums.size()-1);
    }
};