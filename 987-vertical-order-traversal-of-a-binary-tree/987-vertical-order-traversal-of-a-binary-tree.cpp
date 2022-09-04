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
    void temp(vector<vector<pair<int,int>>>&postive,vector<vector<pair<int,int>>>& nagative,
                   pair<TreeNode*,pair<int,int>> &node){
        int row = node.second.first;
        int col = node.second.second;
        int val = node.first->val;
        if(col>=int(postive.size())) // push new vec
        {
            postive.push_back({{row,val}}); 
        }else if (col>=0){
            pushSort(row,val,postive[col]); 
        }else if ((-col-1)>=int(nagative.size())){ //push new vec
            nagative.push_back({{row,val}});
        }else{
            pushSort(row,val,nagative[-col-1]);
        }


    }
    void pushSort(int &row,int &val,vector<pair<int,int>> &cols){
        int i;
        for(i=cols.size()-1;i>=0;i--){
            if(cols[i].first!=row||cols[i].second<=val)
                break;
        }
        cols.insert(cols.begin()+i+1,{row,val});
    }
    void pushToSol(vector<vector<pair<int,int>>>& cols, vector<vector<int>>& sol ){
       for(auto vp:cols){
            vector<int> col;
            for(auto p:vp){
                col.push_back(p.second);
            }
            sol.push_back(col);
        }
    }
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> sol;
        pair<TreeNode*,pair<int,int>> node = {root,{0,0}};
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push(node);
        vector<vector<pair<int,int>>> postive;
        vector<vector<pair<int,int>>> nagative;
        int size;
        int row,col;
        while(!q.empty()){
            size = q.size();
            for(int i=0;i<q.size();i++){
                node = q.front();q.pop();
                if(node.first!=NULL){
                    temp(postive,nagative,node);
                    row = node.second.first;
                    col = node.second.second;
                    q.push({node.first->left,{row+1,col-1}});
                    q.push({node.first->right,{row+1,col+1}});
                }
            }
        }
        reverse(nagative.begin(),nagative.end());
        pushToSol(nagative,sol);
        pushToSol(postive,sol);
        return sol;
        
    }
};