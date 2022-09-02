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
    vector<double> averageOfLevels(TreeNode* root) {
        queue<TreeNode*> q; q.push(root);
        int size;
        double avg;
        vector<double> sol;
        while(!q.empty()){
            size =q.size();
            avg=0;
            for(int i=0;i<size;i++){
                root =q.front();q.pop();
                avg +=root->val;
                if(root->right)
                    q.push(root->right);
                if(root->left)
                    q.push(root->left);
            }
            sol.push_back(avg/size);
        }
        return sol;
    }
};