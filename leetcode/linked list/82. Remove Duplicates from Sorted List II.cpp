/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

Example 1:
Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:
Input: head = [1,1,1,2,3]
Output: [2,3]

*/


class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)return head;
        
        if(head->val!=head->next->val){
            head->next = deleteDuplicates(head->next);
            return head;
        }
        
        ListNode *temp = head;
        while(head->next!=NULL&&head->next->val==temp->val){head = head->next;}
        return deleteDuplicates(head->next);
    }
};