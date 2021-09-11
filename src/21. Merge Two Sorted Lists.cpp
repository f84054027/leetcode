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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        
        if (l1 == NULL && l2 == NULL) {
            return NULL;
        }  
        
        ListNode *result = new ListNode; 
        ListNode *cur;
        ListNode *pos;
        cur = result;
        while (l1 != NULL && l2 != NULL) {
           
            if (l1->val <= l2->val) {
                cur->val = l1->val;
                l1 = l1->next;
            } else {
                cur->val = l2->val;
                l2 = l2->next;
            }    
            cur->next = new ListNode;
            pos = cur;
            cur = cur->next;
        }
        while (l1 != NULL) {
            cur->val = l1->val;
            l1 = l1->next;
            cur->next = new ListNode;
            pos = cur;
            cur = cur->next;
        }
        while (l2 != NULL) {
            cur->val = l2->val;
            l2 = l2->next;
            cur->next = new ListNode;
            pos = cur;
            cur = cur->next;
        }
        
        pos->next = NULL;
        delete cur;
        return result;
    }
};
