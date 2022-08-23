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
private:
    ListNode* reverseList(ListNode* head) {
        ListNode *curr=head;
        ListNode *pos=NULL;
        ListNode *prev=NULL;
        while(curr!=NULL){
            pos=curr->next;
            curr->next=prev;
            prev=curr;
            curr=pos;
        }
     return prev;
    
    }
public:
    bool isPalindrome(ListNode* head) {
        int size = 0;
        ListNode *temp =head;
        while(temp!=NULL){
            size++;
                temp =temp->next;
        }
        if(size==1)
            return true;
        temp = head;
        for(int i=2;i<=ceil(double(size)/2)+1;i++)
            temp=temp->next;
        temp = reverseList(temp);
        for(int i=1;i<=size/2;i++)
            if(head->val==temp->val){
                head= head->next;
                temp = temp->next;
            }else return false;
        return true;
    }
};