/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
 public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL)
            return head;
        vector<ListNode*> s;
        ListNode* node= head;
        while(node!=NULL)
        {
            s.push_back(node);
            node=node->next;
        }
        
        node=NULL;
        bool take=true;
        int i=s.size()-1;
        if(i==0)
            return s[0];
        while(i>=0){
            if(i==0)
            {
                s[i]->next = node;
                return s[i];
            }
            if(s[i]->val!=s[i-1]->val)
            {
                s[i]->next=node;
                node=s[i];
            }else{
             while(i-1!=0&&s[i]->val==s[i-1]->val){
                i--;
              }
             if(i-1==0&&s[i]->val==s[i-1]->val)
                 return node;
            }
            i--;
        }
        return node;
    }
};