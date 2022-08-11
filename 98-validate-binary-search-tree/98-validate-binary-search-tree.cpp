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
    bool validate(long long max ,long long min ,TreeNode* node){
        if(node==NULL)
            return true;
        if(node->val <= min || node-> val >=max){
            return false;
        }else{
            return validate(node->val,min,node->left)&&validate(max,node->val,node->right);
        }
    }
public:
    bool isValidBST(TreeNode* root) {
        return validate(LONG_MAX,LONG_MIN,root);
    }
};