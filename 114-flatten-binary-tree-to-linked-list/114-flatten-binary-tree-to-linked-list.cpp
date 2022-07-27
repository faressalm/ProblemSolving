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
private: TreeNode* temp(TreeNode* root){
    if(!root->right&&!root->left)
        return root;
    TreeNode* next =NULL;
    if(root->left)
        next = temp(root->left);
    if(root->right){
        if(next)
            next->right = root->right;
        next = temp(root->right);
    }
    if(root->left){
     root->right= root->left;
     root->left=NULL;   
    }
    return next;
}
public:
    void flatten(TreeNode* root) {
        if(root)
         temp(root);
    }
};