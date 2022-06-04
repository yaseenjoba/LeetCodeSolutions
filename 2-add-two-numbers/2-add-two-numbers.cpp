
// struct ListNode {
//       int val;
//       ListNode *next;
//       ListNode() : val(0), next(nullptr) {}
//       ListNode(int x) : val(x), next(nullptr) {}
//       ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int c = 0;
        ListNode* head =NULL ,*mov = NULL;
        while(l1!=NULL && l2!=NULL){
            int res = l1->val + l2->val + c;
            if(head == NULL){
               ListNode* temp =new ListNode(res%10);
                temp->next = NULL;
                head = temp;
                mov = head;
            }else{
                ListNode* temp =new ListNode(res%10);
                temp->next = NULL;
                mov->next = temp;
                mov = temp;
            }
            c = res/10; 
            l1 = l1->next;            
            l2 = l2->next;
        }
        if(l1 == NULL && l2 ==NULL && c == 0)return head;
        if(l1 == NULL){
            while(l2 !=NULL){
                int res = l2->val + c;
                c = res/10;
                ListNode* temp =new ListNode(res%10);
                temp->next = NULL;
                mov->next = temp;
                mov = temp;
                l2 = l2->next;
            }
        }else if(l2 == NULL){
            while(l1 !=NULL){
                int res = l1->val + c;
                c = res/10;
                ListNode* temp =new ListNode(res%10);
                temp->next = NULL;
                mov->next = temp;
                mov = temp;
                 l1 = l1->next;
            }
        }
        if(c !=0){
            int res = c;
           ListNode* temp =new ListNode(res%10);
            temp->next = NULL;
            mov->next = temp;
            mov = temp;
        }
        return head;
    }
};