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
public:
    int countNodes(TreeNode* root) {
        if(root == NULL)
            return 0;
        TreeNode* left = root->left, *right = root->right;
        int leftHeight =1,rightHeight =1;
        
        while(left) {leftHeight++;left= left->left; }
        while(right) {rightHeight++;right= right->right; }
        
        if(rightHeight == leftHeight) return (1<<leftHeight) -1;
        return 1+countNodes(root->right)+countNodes(root->left);
    }
};