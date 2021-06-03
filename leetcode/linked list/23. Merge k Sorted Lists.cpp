/*You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.

 

Example 1:

Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
  1->4->5,
  1->3->4,
  2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6
Example 2:

Input: lists = []
Output: []
Example 3:

Input: lists = [[]]
Output: []
*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head=NULL,*curr=NULL;
        
        while(1){
            int minm=INT32_MAX,minind = -1;
            
            for(int i =0;i<lists.size();i++){
                if(lists[i]==NULL)continue;
                else if(lists[i]->val<minm){minm = lists[i]->val;minind = i;}
            }
            
            if(minind ==-1)break;
            if(head==NULL){head = lists[minind];lists[minind]=lists[minind]->next;head->next=NULL;curr=head;}
            else {curr->next =lists[minind]; lists[minind]=lists[minind]->next; curr=curr->next;curr->next=NULL;}
        }
        
        
        return head;
    }
};