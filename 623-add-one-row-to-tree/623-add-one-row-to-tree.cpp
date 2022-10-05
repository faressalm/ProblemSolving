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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* node = new TreeNode(val,root,NULL);
            return node;
        }
        vector<vector<int>> levels;
        queue<TreeNode*> q;
        q.push(root);
        depth--;
        while(!q.empty()&&depth>1){
            int size = q.size();
            while(size!=0){
                size--;
               TreeNode* node = q.front();
               q.pop();
               if(node->left!=NULL)
                   q.push(node->left);
               if(node->right!=NULL)
                   q.push(node->right);
            }
            depth--;
        }
        int size = q.size();
        while(size!=0){
           size--;
           TreeNode* node = q.front();
           q.pop();
            TreeNode* right= node->right;
            TreeNode* left= node->left;
            node->left =  new TreeNode(val,left,NULL);
            node->right =  new TreeNode(val,NULL,right);
        }
        return root;
        
    }
};