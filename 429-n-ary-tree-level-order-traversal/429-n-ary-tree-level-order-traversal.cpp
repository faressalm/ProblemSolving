/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(root==NULL)
            return {};
        vector<vector<int>> sol;
        queue<Node*>q;q.push(root);
        int size;
        while(!q.empty()){
            sol.push_back({});
            size = q.size();
            for(int i=0;i<size;i++){
                root = q.front();
                sol[sol.size()-1].push_back(root->val); q.pop();
                for(auto &child:root->children)
                    q.push(child);
            }
        }
        return sol;
    }
};