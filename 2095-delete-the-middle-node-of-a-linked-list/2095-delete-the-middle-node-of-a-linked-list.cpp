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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* first = head;
        ListNode* second = head;
        if(head->next == NULL){
            return NULL;
        }
        ListNode* t = head;
        while(second && second->next != NULL){
            t = first;
            first = first->next;           
            second = second->next->next;
        }
        t->next = first->next;
        return head;
        
    }
};