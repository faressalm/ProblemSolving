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
    vector<int> rightSideView(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<int> rights;
        queue<TreeNode*>q;
        q.push(root);
        int size;
        while(!q.empty()){
            size = q.size();
            rights.push_back(q.front()->val);
            while(size!=0){
                size--;
                root = q.front(); q.pop();
                if(root->right)
                    q.push(root->right);
                if(root->left)
                    q.push(root->left);                
            }
        }
        return rights;
    }
};