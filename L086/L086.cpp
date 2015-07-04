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
    ListNode* partition(ListNode* head, int x) {
        ListNode* less = new ListNode(0);
        ListNode* more = new ListNode(0);
        ListNode* lessHead = less;
        ListNode* moreHead = more;
        while(head){
            if(head->val < x){
                less->next = head;
                less = less->next;
            }else{
                more->next = head;
                more = more->next;
            }
            head = head->next;
        } 
        more->next = NULL;
        less->next = moreHead->next;
        return lessHead->next;
    }
};