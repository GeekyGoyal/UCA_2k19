/**  Problem Link: https://leetcode.com/problems/linked-list-cycle-ii/
*
*   @Aparna Goyal, 1911981092, 03/09/2021  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *detectCycle(struct ListNode *head) {
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        while(fast != NULL && fast -> next != NULL) {
            fast = fast -> next -> next;
            slow = slow -> next;
            if(fast == slow) {
                break;
            }
        }
        
        if(fast == NULL || fast -> next == NULL) {
            return NULL;
        }
        
        slow = head;
        
        while(slow != fast) {
            slow = slow -> next;
            fast = fast -> next;
        }
        return slow;        
}
