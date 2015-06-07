class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if (head == NULL)
            return NULL;
        ListNode* head1 = head;
        ListNode* headn = head;
        for (int i = 0; i < n; ++i){
            headn = headn -> next;
        }
        if (!headn)
            return head->next;
        while(headn -> next){
            headn = headn->next;
            head1 = head1->next;
        }
        ListNode* midNode = head1-> next;
        head1 -> next = midNode -> next;
        delete midNode;
        return head;
    }
};