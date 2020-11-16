//simple linked list problem

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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode *h;
        h=head;
        
        int carry =0;
        
        while(l1!=NULL&&l2!=NULL){
            int sum = l1->val+l2->val+carry;
            ListNode* temp = new ListNode(sum%10);
            carry = sum/10;
            head->next = temp;
            head = temp;
            l1=l1->next;
            l2=l2->next;
        }
        while(l1!=NULL){
            int sum = l1->val+carry;
            ListNode* temp = new ListNode(sum%10);
            carry = sum/10;
            head->next = temp;
            head = temp;
            l1=l1->next;
        }
        while(l2!=NULL){
            int sum = l2->val+carry;
            ListNode* temp = new ListNode(sum%10);
            carry = sum/10;
            head->next = temp;
            head = temp;
            l2=l2->next;
        }
        if(carry>0){
            ListNode* temp = new ListNode(carry);
            head->next = temp;
            head = temp;
        }
        return h->next;
    }
};