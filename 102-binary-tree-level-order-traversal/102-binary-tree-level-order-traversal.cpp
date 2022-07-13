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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            levels.push_back({});
            while(size!=0){
                size--;
               TreeNode* node = q.front();
               q.pop();
               levels[levels.size()-1].push_back(node->val);
               if(node->left!=NULL)
                   q.push(node->left);
               if(node->right!=NULL)
                   q.push(node->right);
            }
        }
        return levels;
    }
};