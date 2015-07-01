
#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res = head;
        ListNode *final = head;
        if (!head){
            return NULL;
        }
        while (head){
            head = head->next;
            if (head != NULL && res->val != head->val){
                res = res->next;
                res->val = head->val;
            }
        }
///////////释放其后的内存空间,有没有必要????
        ListNode *del = res->next;        
        while(del){
            ListNode *ptr = del;
            del = del->next;
            free(ptr);
        }
//////////
        res->next = NULL;
        return final;
    }
};