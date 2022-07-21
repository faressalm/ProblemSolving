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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *curr=head;
        ListNode *pos=NULL;
        ListNode *prev=NULL;
        ListNode *prev2=NULL;
        right-=left;
        while(left!=1){
            prev2=curr;
            curr = curr->next;
            left--;
        }
        ListNode *firstCurr=curr;
        while(right!=0){
            pos=curr->next;
            curr->next=prev;
            prev=curr;
            curr=pos;
            right--;
        }
        pos=curr->next;        
        curr->next=prev;
        prev=curr; 
        firstCurr->next = pos;
        if(prev2!=NULL){
            prev2->next = prev;
        }
     return (prev2!=NULL)?head:prev; 
    }
};