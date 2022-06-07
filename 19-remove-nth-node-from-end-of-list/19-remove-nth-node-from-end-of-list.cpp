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
        int sz = 0 ;
        ListNode* temp = head;
        while(temp!=NULL){
            temp = temp ->next;
            sz++;
        }
        int i = 0;
        ListNode* t = head;
        if(n == sz){
            return head->next;
        }
        while(i != sz  - n - 1){
            t = t->next;
            i++;
        }
        if(n == 1){
            t->next = NULL;
        }else  t->next  = t->next->next;
        return head;
    }
};