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
    ListNode *detectCycle(ListNode *head) {
          ListNode *slow = head , *fast = head;
          while(fast != NULL && fast->next!=NULL){
              fast = fast ->next->next;
              slow = slow->next;
              if(slow == fast){
                int len  = 0;
                ListNode *temp = slow;
                do{
                  temp = temp->next;
                  len++;
                }while(temp != slow);
                ListNode *first = head , *second = head;
                while(len--){
                  second = second->next;
                }
                while(second!= first){
                  second = second ->next;
                  first = first->next;
                }
                return first;
              }
          }
          return NULL;
    }
};