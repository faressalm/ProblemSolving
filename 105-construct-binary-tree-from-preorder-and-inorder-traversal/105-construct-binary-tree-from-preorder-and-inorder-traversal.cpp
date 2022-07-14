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
private: TreeNode* temp(vector<int>& preorder, vector<int>& inorder,unordered_map<int,int> &m,int& pre,int inoStart,int inoEnd){
    if(inoStart>inoEnd)
        return NULL;
    TreeNode * root = new TreeNode(preorder[pre]);
    int rootIndex = m[preorder[pre]];
    pre++;
    root->left = temp(preorder,inorder,m,pre,inoStart,rootIndex-1);
    root->right = temp(preorder,inorder,m,pre,rootIndex+1,inoEnd);
    return root;
}    
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]] =i;
        int pre =0;
        return temp(preorder,inorder,m,pre,0,inorder.size()-1);
    }
};