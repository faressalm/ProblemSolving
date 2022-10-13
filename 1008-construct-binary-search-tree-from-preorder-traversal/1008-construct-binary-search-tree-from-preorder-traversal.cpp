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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        TreeNode *root =  new TreeNode(preorder[0]);
        stack<pair<int,TreeNode*>> s;
        s.push({INT_MAX,root});
        pair<int,TreeNode*> node;
        int index = 1;
        while(!s.empty()&&index<preorder.size()){
            node = s.top();
            if(node.second->val>preorder[index]){
                node.second->left = new TreeNode(preorder[index++]);
                s.push({node.second->val,node.second->left});
            }
            else if(node.first< preorder[index]){
                s.pop();
            }else{
                s.pop();
                node.second->right = new TreeNode(preorder[index++]);
                s.push({node.first,node.second->right});
            }
            
        }
        return root;

    }
};