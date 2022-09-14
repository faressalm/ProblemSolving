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
private: int temp(TreeNode* root,vector<int> &val){
    if(root==NULL)
        return 0;
    val[root->val]++;
    int count=0; 
    if(!root->right&&!root->left){
        count = isPes(val)?1:0;
        val[root->val]--;
        return count;
    }
    count = temp(root->right,val)+temp(root->left,val);
    val[root->val]--;
    return count;
}
    bool isPes(vector<int> &val){
        bool odd = false;
        for(auto v:val)
            if(v%2!=0)
                if(odd)
                    return false;
                else odd = true;
        return true;
    }
public:
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> val(10,0);
        return temp(root,val);
    }
};