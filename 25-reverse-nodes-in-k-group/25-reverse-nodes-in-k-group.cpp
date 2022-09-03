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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (k <= 1 || head == nullptr) {
              return head;
        }
        int  n = 0;
        ListNode* t = head;
        while(t){
            n++;
            t=t->next;
        }
        int times = n/k;
        ListNode *curr = head, *previous = nullptr;
        while(times--){
            ListNode *prev = previous , *nxt = NULL;
            ListNode*last = curr;
            int it = k;
            while(curr && it--){
                nxt = curr->next;
                curr->next = previous;
                previous = curr;
                curr = nxt;
            }
             if (prev != nullptr) {
                prev->next =previous;  
              } else {         
                head = previous;
              }

            last->next = curr;
            if(curr == NULL){
                break;
            }
            previous = last;
        }
        return head;
    }
};