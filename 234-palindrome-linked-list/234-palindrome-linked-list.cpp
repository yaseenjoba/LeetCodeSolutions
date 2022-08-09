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
    bool isPalindrome(ListNode* head) {
      ListNode* slow = head , *fast = head;
      while(fast != NULL && fast->next !=NULL){
        fast = fast ->next ->next;
        slow = slow->next;
      } 
      ListNode* head1 = reverse(slow);
      ListNode* head2 = head;
      ListNode* revert = head1;
      while(head1!=nullptr && head2!=nullptr){
        if(head1 -> val != head2->val){
          break;
        }
        head1 = head1->next;
        head2 = head2 ->next;
      }
      reverse(revert);
      if(head1 == NULL || head2 == NULL)return true;
      return false;

  }
  ListNode* reverse(ListNode* head){
      ListNode* prev = nullptr , *next = nullptr;
      while(head != nullptr){
        next = head->next;
        head->next = prev;
        prev = head;
        head = next;
      }
      return prev;
    }
};