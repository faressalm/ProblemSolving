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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * a= headA;
        ListNode * b =headB;
        int aSize=0;
        int bSize=0;
        while(a!=NULL){
            a=a->next;
            aSize++;    
        }
        while(b!=NULL){
            b=b->next;
            bSize++;    
        }
        if(aSize>bSize){
            int diff =  aSize-bSize;
            while(diff!=0){
                headA=headA->next;
                diff--;
            }
            while(bSize!=0){
                if(headA==headB)
                    return headA;
                headA=headA->next;
                headB=headB->next;
            }
        }else{
            int diff = -aSize+bSize;
            while(diff!=0){
                headB=headB->next;
                diff--;
            }
            while(aSize!=0){
                if(headA==headB)
                    return headA;
                headA=headA->next;
                headB=headB->next;
            }            
        }

        return  NULL;
    }
};