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
    
    ListNode *res = NULL;
    ListNode *prev = NULL;
    ListNode *temp = NULL;
    int sum = 0;
    int carry = 0; 
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        
        while(l1 != NULL || l2 != NULL){
            sum = carry + (l1? l1->val: 0) + (l2? l2->val: 0);
            carry = sum>=10 ? 1 : 0;
            sum = (sum % 10);

            temp = new ListNode(sum);

            if(res == NULL){
                res = temp;
            }else{
                prev->next = temp;
            }

            prev = temp;

            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        
        if(carry){
            prev->next = new ListNode(carry);
        }
        
        return res;   
    }
};
