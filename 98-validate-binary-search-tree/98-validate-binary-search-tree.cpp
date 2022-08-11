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
    private:
    bool validate(int max ,int min ,TreeNode* node,bool chaL,bool chaR){
        if(node==NULL)
            return true;
        if((node->val <= min && chaR) || (node-> val >=max &&chaL)){
            return false;
        }else{
            return validate(node->val,min,node->left,true,chaR)&&validate(max,node->val,node->right,chaL,true);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(root->val,INT_MIN,root->left,true,false)&&validate(INT_MAX ,root->val,root->right,false,true);
    }
};