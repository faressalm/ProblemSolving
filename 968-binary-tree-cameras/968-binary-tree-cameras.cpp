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
private: pair<bool,bool> temp(TreeNode* root, int & count){
    if(root->right==NULL&&root->left==NULL)
        return {false,false};
    pair<bool,bool> nodeP = {false,false};
    if(root->left!=NULL)
    {
       pair<bool,bool> p = temp(root->left,count);
       if(!p.first){
           nodeP = {true,true};
           count++;
       }else if(p.first&&p.second)
       {
           nodeP.first=true;
       }
    }
    if(root->right!=NULL)
    {
       pair<bool,bool> p = temp(root->right,count);
       if(!nodeP.second){
         if(!p.first){
           nodeP = {true,true};
           count++;
         }else if(p.first&&p.second)
         {
           nodeP.first=true;
         }
       }

    }
    return nodeP;
}    
public:
    int minCameraCover(TreeNode* root) {
       int count =0;
       pair<bool,bool> p= temp(root,count);
       if(!p.first)
           count++;
       return count;   
    }
};