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
private: int counter=0;
    void temp(TreeNode* root,int greates){
         if(root==NULL)
            return;
         if(root->val>=greates)
         {
             counter++;
             greates = root->val;
         }
         temp(root->right,greates);
         temp(root->left,greates);
    }    
public:
    int goodNodes(TreeNode* root) {
                temp(root,INT_MIN);
        return counter;
    }
};