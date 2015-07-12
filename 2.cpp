/* Add Two Numbers
*  2015.07.12 published.
*  Author: Tai-Yi Wu.
*  Runtime 40ms 1555/1555 passed.
*/

/* Simple link-list exercise.
*  Original inputs are altered.
*  Time : O(M+n)
*  Space: O(1)
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // Checking special cases.
        if(l1 == NULL && l2 == NULL) return NULL;
        if(l1 == NULL && l2 != NULL) return l2;
        if(l1 != NULL && l2 == NULL) return l1;
        // Add a new head
        ListNode* head = new ListNode(-1);
        ListNode* cur = head->next;
        int add_one = 0;
        while(l1!=NULL || l2!=NULL){
            int val = add_one;
            if(l1!=NULL) val += l1->val;
            if(l2!=NULL) val += l2->val;
            int record = val%10;
            add_one = val/10;
            if(cur == NULL){
                cur = new ListNode(record);
                head->next = cur;
            }
            else{
                cur->next = new ListNode(record);
                cur = cur->next;
            }
            if(l1!=NULL)
                l1=l1->next;
            if(l2!=NULL)
                l2=l2->next;
        }
        if(add_one)
            cur->next = new ListNode(add_one);
        cur = head;
        head = head->next;
        delete cur; // Avoiding memory leak.
        return head;
    }
};
