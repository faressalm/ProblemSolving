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
private: int temp(TreeNode * root){
        if(root==NULL)
            return 1e6;
        if(!root->right&&!root->left)
            return 1;
        return 1+ min(temp(root->right),temp(root->left));
    }    
public:
    int minDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        if(root->right)
            return (root->left)?1+min(temp(root->right),temp(root->left)):1+temp(root->right);
        if(root->left)
            return 1+temp(root->left);   
        return 1;
    }
};