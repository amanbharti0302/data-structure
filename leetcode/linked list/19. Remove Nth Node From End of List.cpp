/*
Given the head of a linked list, remove the nth node from the end of the list and return its head.
Follow up: Could you do this in one pass?
Example 1:

Input: head = [1,2,3,4,5], n = 2
Output: [1,2,3,5]
Example 2:

Input: head = [1], n = 1
Output: []
Example 3:

Input: head = [1,2], n = 1
Output: [1]
=====================================>>>>>My approach
Simply using stack we can solve this
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        stack<ListNode*>s;
        ListNode* curr;
        curr = head;
        while(curr!=NULL){
            s.push(curr);
            curr=curr->next;
        }
        int cnt=1;
        ListNode *newn;
        newn =NULL;
        while(!s.empty()){
            if(cnt==n+1)s.top()->next=newn->next;
            newn=s.top();
            s.pop();
            cnt++;
        }
        if(cnt<n+2){
            head=head->next;
        }
        
        return head;
        
    }
};