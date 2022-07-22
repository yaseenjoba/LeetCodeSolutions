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
        ListNode* less = new ListNode(-1);  
        ListNode* more = new ListNode(-1);
        ListNode* headLess = less, *headMore = more;
        ListNode* temp = head;
        while(temp){
            if(temp->val < x){
                less->next = temp;
                less = less->next;
            }else{
                more->next = temp;
                more = more->next;
            }
            temp = temp->next;
        }
        less->next = headMore->next;
        more->next = NULL;
        return headLess->next;

        
    }
};