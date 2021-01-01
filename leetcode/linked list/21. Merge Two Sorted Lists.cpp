/*
Merge two sorted linked lists and return it as a new sorted list. The new list should be made by splicing together the nodes of the first two lists.
Example 1:

Input: l1 = [1,2,4], l2 = [1,3,4]
Output: [1,1,2,3,4,4]
Example 2:
Input: l1 = [], l2 = []
Output: []
Example 3:

Input: l1 = [], l2 = [0]
Output: [0]

======================================>>MY approach
simply like 2 pointer
*/
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *l3=NULL,*l3head=NULL;
        
        while(1){
            if(l1==NULL&&l2==NULL)break;
            ListNode *curr;
            if(l1==NULL){curr=new ListNode(l2->val);l2=l2->next;}
            else if(l2==NULL){curr=new ListNode(l1->val);;l1=l1->next;}
            else if(l1->val<l2->val){curr=new ListNode(l1->val);l1=l1->next;}
            else {curr=new ListNode(l2->val);l2=l2->next;}
            
            if(l3==NULL){l3=curr;l3head=l3;}
            else {l3->next=curr;l3=l3->next;}
        }
        return l3head;
    }
};