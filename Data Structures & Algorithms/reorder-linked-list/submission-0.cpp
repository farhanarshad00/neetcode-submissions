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
    void reorderList(ListNode* head) {
        ListNode* slow=head;
        ListNode* fast=head->next;

        while(fast != nullptr && fast->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }

        ListNode* r_head = slow->next;
        slow->next=nullptr;

        ListNode* cur=r_head;
        ListNode* next;
        ListNode* prev=nullptr;

        while(cur != nullptr){
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
            }
        while(prev != nullptr){
            ListNode* l_save = head->next;
            ListNode* r_save = prev->next;
            head->next = prev;
            prev->next=l_save;
            head = l_save;
            prev = r_save;
        }


        
    }
};
