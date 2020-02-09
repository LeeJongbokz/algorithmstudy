#include <cmath> 

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
    int getDecimalValue(ListNode* head) {
      ListNode *temp;
      temp = head;
        
      int len = 0; 
      int num = 0;
      int result = 0; 
        
      while(temp != NULL){
          len += 1;
          temp = temp->next;
      }
      
      num = len;
        
      while(head != NULL){
          result += (head->val)*pow(2, num-1);
          num -= 1;
          head = head->next;
      } 
        
      return result;   
        
        
        
    }
};
