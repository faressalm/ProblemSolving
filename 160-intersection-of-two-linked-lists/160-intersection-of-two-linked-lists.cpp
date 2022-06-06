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
        unordered_set<ListNode *> s;
        while(headA!=NULL&&headB!=NULL)
        {   if(s.find(headA)==s.end())
               s.insert(headA);
            else
                return headA;
            if(s.find(headB)==s.end())
               s.insert(headB);
            else
                return headB;
            headA= headA->next;
            headB=headB->next;
        }
        if(headB!=NULL)
        {while(headB!=NULL&&s.find(headB)==s.end())
             headB=headB->next;
        return headB;
        }
        while(headA!=NULL&&s.find(headA)==s.end())
            headA=headA->next;
        return  headA;
    }
};