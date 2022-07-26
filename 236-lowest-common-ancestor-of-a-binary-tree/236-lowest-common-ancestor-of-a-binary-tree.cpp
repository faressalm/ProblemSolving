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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
       stack< TreeNode*> s;
        s.push(root);
        TreeNode* parent =root;
        TreeNode* node;
        TreeNode* nextNode;
        while(!s.empty()){
            if(s.top() == p||s.top()==q){
                nextNode =(s.top() == p)?q:p;
                parent = s.top();
                break;
            }
            if(s.top()->left){
                node = s.top();
                s.push(s.top()->left);
                node->left =NULL;
            }else if(s.top()->right){
                node = s.top();
                s.push(node->right);
                node->right =NULL;                
            }else{
                s.pop();
            }
        }
        cout<<parent->val;
        while(!s.empty()){
            if(s.top() == nextNode){
                return parent;
            }
            if(s.top()->left){
                node = s.top();
                s.push(s.top()->left);
                node->left =NULL;
            }else if(s.top()->right){
                node = s.top();
                s.push(node->right);
                node->right =NULL;
            }else{
                if(s.top()==parent){
                    s.pop();
                    parent =s.top();
                }else
                    s.pop();
            }
        }   
        return parent; 
    }
};