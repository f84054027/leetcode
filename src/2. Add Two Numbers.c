/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    int sum = 0, carry = 0;
    struct ListNode* result = malloc(sizeof(struct ListNode));
    struct ListNode* pre;
    struct ListNode* start = result;
    while (l1 != NULL || l2 != NULL) {
        if (l1 != NULL && l2 != NULL) {
            sum = l1->val + l2->val + carry;
            if (sum > 9) {
                carry = 1;
                sum = sum - 10;
            } else {
                carry = 0;
            }
            result->val = sum;
            result->next = malloc(sizeof(struct ListNode));
            pre = result;
            result = result->next;
            l1 = l1->next;
            l2 = l2->next;
            continue;
        }
        
        if (l1 == NULL) {
            sum = l2->val + carry;
            if (sum > 9) {
                carry = 1;
                sum = sum - 10;
            } else {
                carry = 0;
            }
            result->val = sum;
            result->next = malloc(sizeof(struct ListNode));
            pre = result;
            result = result->next;
            l2 = l2->next;
            continue;
            
        } 
        
        if (l2 == NULL) {
            sum = l1->val + carry;
            if (sum > 9) {
                carry = 1;
                sum = sum - 10;
            } else {
                carry = 0;
            }
            result->val = sum;
            result->next = malloc(sizeof(struct ListNode));
            pre = result;
            result = result->next;
            l1 = l1->next;
            continue;
            
        } 
        
    }
    if (carry != 0) {
        result->val = carry;
        result->next = NULL;
    } else {
        free(result);
        pre->next = NULL;
    }
    
    return start;
    
}
