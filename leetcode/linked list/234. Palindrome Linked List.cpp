/*
Given the head of a singly linked list, return true if it is a palindrome.

Example 1:
Input: head = [1,2,2,1]
Output: true
Example 2:

Input: head = [1,2]
Output: false
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
    bool isPalindrome(ListNode* head) {
        if(head==NULL)return true;
        stack<ListNode*>s;
        ListNode * temp = head;
        while(temp!=NULL){s.push(temp);temp=temp->next;}
        while(!s.empty()){
            if(head->val!=s.top()->val)return false;
            head=head->next;
            s.pop();
        }
        
        return true;
    }
};