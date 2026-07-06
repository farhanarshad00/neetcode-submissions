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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode dummy(0);
        ListNode* node = &dummy;

        while(list1 != nullptr && list2 != nullptr){
            if(list1->val < list2->val){
                node->next = list1;
                list1=list1->next;
            }else{
                node->next=list2;
                list2 = list2->next;
            }
            node = node->next;
        }

        if(list1 != nullptr){
            node->next=list1;
        }else if(list2 != nullptr){
            node->next=list2;
        }
        return dummy.next;


    }
};

/*
* Approach: Comparing each node in list while traversing
* 1. Initialize a dummy ListNode with value 0 and node called node
* 2. Loop while both lists are not empty
* 3. Check if list1->data < list2->data, if so set node->next=list1 & list1=list1->next.
* 4. If list values are equal append list2 first. Update node=node->next after checks
* 5. After loop check if list1 or list2 is not empty and if true append respective list to node
* 6. return dummy.next
*/