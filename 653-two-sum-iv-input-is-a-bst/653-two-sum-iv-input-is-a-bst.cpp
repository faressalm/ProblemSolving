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
    bool temp(TreeNode* root, int k,unordered_set<int> &s){
        if(root==NULL)
            return false;
        if(s.find(root->val)!=s.end())
            return true;
        s.insert(k-root->val);
        return temp(root->right,k,s)||temp(root->left,k,s);
    }
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> s;
        return temp(root,k,s);
    }
};