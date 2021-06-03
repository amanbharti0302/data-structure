/*
Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
The first node is considered odd, and the second node is even, and so on.
Note that the relative order inside both the even and odd groups should remain as it was in the input. 

Example 1:

Input: head = [1,2,3,4,5]
Output: [1,3,5,2,4]
Example 2:

Input: head = [2,1,3,5,6,4,7]
Output: [2,3,6,7,1,5,4]
*/

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
    ListNode* oddEvenList(ListNode* head) {
        ListNode *e=NULL,*o=NULL,*ehead=NULL,*ohead=NULL;
        bool al = false;
        
        while(head!=NULL){
            if(al==false){
                if(o==NULL){o=head;head=head->next;ohead =o;o->next=NULL;}
                else{o->next = head;head=head->next;o=o->next;o->next=NULL;}
            }
            else{
                if(e==NULL){e=head;head=head->next;ehead =e;e->next=NULL;}
                else{e->next = head;head=head->next;e=e->next;e->next=NULL;}
            }
            al = !al;
        }
        
        head = ohead;
        if(o!=NULL)o->next = ehead;
        return head;
    }
};