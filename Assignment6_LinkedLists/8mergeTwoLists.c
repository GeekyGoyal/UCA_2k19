/**  Problem Link: https://leetcode.com/problems/merge-two-sorted-lists/
*
*   @Aparna Goyal, 1911981092, 03/09/2021  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2) {
    // Base Case
    if(l1 == NULL) {
        return l2;
    } 
    
    if(l2 == NULL) {
        return l1;
    }
    
    // Take a head pointer
    if(l1 -> val < l2 -> val) {
        l1 -> next = mergeTwoLists(l1 -> next, l2);
        return l1;
    }
    
    else {
        l2 -> next = mergeTwoLists(l1, l2 -> next);
        return l2;
    }
}