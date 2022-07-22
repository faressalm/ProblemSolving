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
    ListNode* partition(ListNode* head, int x) {
        if(head==NULL)
            return NULL;
        vector<ListNode* > s;
        ListNode*  curr = head;
        while(curr!=NULL){
            s.push_back(curr);
            if(curr->val<x){
                for(int i=s.size()-2;i>=0&&s[i]->val>=x;i--){
                  swap(s[i],s[i+1]);                    
                }
            }
            curr = curr->next;
        }
        for(int i=0;i<s.size()-1;i++){
            s[i]->next =s[i+1];
        }
        s[s.size()-1]->next=NULL;
        return s[0];
    }
};