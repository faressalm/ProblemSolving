/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
       ListNode *slow =head;
       ListNode *fast =head;
       bool meet=false;
       while(fast!=NULL&&fast->next!=NULL&&slow!=NULL){
           fast = fast->next->next;
           slow=slow->next;
           if(fast==slow)
           {
               meet= true;
               break;
           }
       }
       if(!meet)
           return NULL;
       slow=head;
       while(fast!=slow){
           fast=fast->next;
           slow=slow->next;
       }
       return fast; 
    }
};