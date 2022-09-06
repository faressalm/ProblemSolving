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
private: bool hasOne(TreeNode* root){
    if(root==NULL)
        return false;
    bool has = false;
    if(root->val==1)
        has=true;
    if(!hasOne(root->right))
        root->right = NULL;
    else has =true;
    if(!hasOne(root->left))
        root->left = NULL;
    else has =true;
    return has;
}
public:
    TreeNode* pruneTree(TreeNode* root) {
        if(hasOne(root))
            return root;
        return NULL;
    }
};