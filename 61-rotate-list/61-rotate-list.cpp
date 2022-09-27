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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL)
            return NULL;
        ListNode* node = head;
        int size=1;
        while(node->next!=NULL){
            size++;
            node = node->next;
        }
        k = k%size;
        if(k==0)
            return head;
        node->next = head;
        node = head;
        for(int i=0;i<size-k-1;i++){
            node= node->next;
        }
        head = node->next;
        node->next = NULL;
        return head;
        
    }
};