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
    bool hasCycle(ListNode* head) {
        if(head == nullptr || head->next == nullptr || head->next->next == nullptr){
            return false;
        }
        ListNode* fastptr=head->next->next;
        ListNode* slowptr=head->next;
        while(fastptr != slowptr){
            if(fastptr == nullptr || fastptr->next == nullptr || slowptr == nullptr || slowptr->next ==nullptr){
                return false;
            }
            fastptr = fastptr->next->next;
            slowptr = slowptr->next;
        }

        return true;
    }
};
/*
* What is known:
* This is a singly linked list with head as the only parameter so no possible way to walk back.
* tail->next=indexptr
* If tail->next=nullptr return false else return true
*/