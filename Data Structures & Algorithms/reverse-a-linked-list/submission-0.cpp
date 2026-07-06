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
    
    ListNode* reverseList(ListNode* head) {
        ListNode* cur = head;
        ListNode* prev = nullptr;
        ListNode* next;

        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            }
    return prev;
   }
};

/*
* Approach: While loop assigning head to tail
* 1. Create three nodes; cur=head,prev=nullptr,next=cur->next
* 2. Use a while loop to traverse the list
* 3. Set next= cur->next, then cur->next=prev, then prev=cur, then cur=next
* 4. Return prev
* 
*/
