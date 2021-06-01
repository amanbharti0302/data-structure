/*
Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

Example 1:
Input: head = [1,2,3,4,5], left = 2, right = 4
Output: [1,4,3,2,5]
Example 2:

Input: head = [5], left = 1, right = 1
Output: [5]
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *dumhead=head,*l=NULL,*r=NULL,*prev=NULL,*nex=NULL;
        int cnt =1;
        
        while(dumhead!=NULL){
            if(cnt==left)l=dumhead;
            else if(cnt==right)r=dumhead;
            if(l==NULL){prev=dumhead;}
            dumhead=dumhead->next;
            cnt++;
        }
        
        if(!l||!r)return head;
        nex = r->next;        
              
        ListNode *temp = NULL;
        ListNode *strt =l;
        
        while(1){
            ListNode *ah=l->next;
            l->next=temp;
            temp=l;
            if(l==r)break;
            l=ah;
        }
        
        if(prev!=NULL)prev->next=r;
        else head = r;
        strt->next=nex;
        return head;
    }
};