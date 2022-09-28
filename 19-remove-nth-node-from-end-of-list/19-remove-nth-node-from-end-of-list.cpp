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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len=1;
        ListNode* prev = head;
        while(prev->next!=NULL)
        {
            len++;
            prev=prev->next;
        }
        if(n==len)
            return head->next;
        prev = head;
        ListNode* current = head->next;
        for(int i=2;i<len-n+1;i++)
        {
            prev=current;
            current=current->next;
        }
        prev->next= current->next;
        return head;
    }
};