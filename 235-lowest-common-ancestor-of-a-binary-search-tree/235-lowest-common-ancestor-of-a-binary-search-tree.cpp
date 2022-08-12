/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* node, TreeNode* p, TreeNode* q) {
        while(node!=NULL){
            if(node->val<p->val&&node->val<q->val)
                node=node->right;
            else if(node->val>p->val&&node->val>q->val)
                node= node->left;
            else
                return node;
        }
        return node;
    }
};