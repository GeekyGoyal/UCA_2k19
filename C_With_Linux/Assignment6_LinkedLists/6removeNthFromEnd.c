/**  Problem Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
*
*   @Aparna Goyal, 1911981092, 03/09/2021  */

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
        struct ListNode* slow = head;
        struct ListNode* fast = head;
        struct ListNode* prev = head;
        int c = 0;
        
        while(fast != NULL) {
            if(c >= n) {
                prev = slow;            
                slow = slow -> next;
            }
            
            fast = fast -> next;
            c++;
        }
        
        if(c == n) {
            head = head -> next;
        }
        else {
            prev -> next = slow -> next;
        }
        return head;
}