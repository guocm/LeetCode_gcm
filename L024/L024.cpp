class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* helper = new ListNode(0);
        ListNode* p2 = head -> next;
        ListNode* p1 = head;
        ListNode* help = helper;
        while(p1 && p2)
        {
            helper -> next = p2;
            helper = helper -> next;
            p2 = p2->next;
            helper -> next = p1;
            helper = helper -> next;
            p1 = p2;
            if(p2){
                p2 = p2 -> next;
            }
        }
        if (p1){
            helper -> next = p1;
            helper = helper -> next;
            helper -> next = NULL;
        }
        else{
            helper -> next = NULL;
        }
        return help -> next;
    }
};