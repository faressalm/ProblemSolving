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
private: vector<vector<int>> sol;
    void temp(TreeNode* root, int targetSum,vector<int> &path,int &currSum){
        currSum += root->val;
        path.push_back(root->val);        
        if(root->right==NULL&&root->left==NULL){
            if(currSum==targetSum)
                sol.push_back(path);
            currSum -= root->val;
            path.pop_back();  
            return;            
        }
        if(root->left!=NULL){
            temp(root->left,targetSum,path,currSum);
        } 
        if(root->right!=NULL){
            temp(root->right,targetSum,path,currSum);
        }        
        currSum -= root->val;
        path.pop_back();          
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if(root == NULL)
            return {};
        vector<int> path;
        int currSum =0;
        temp(root,targetSum,path,currSum);
        return sol;
    }
};