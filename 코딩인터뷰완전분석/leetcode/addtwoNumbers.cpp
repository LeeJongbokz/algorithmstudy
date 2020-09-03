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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
           
          int flag = 0; 
          ListNode* res = NULL;
          ListNode* prev = NULL;
        
          while(l1 != NULL || l2 != NULL){
              
              int num1=0;
              int num2=0;
              int num;
              
              if(l1 != NULL){
                  num1 = l1->val;
                  l1 = l1->next;
              }
              
              if(l2 != NULL){
                  num2 = l2->val;
                  l2 = l2->next;
              }
              
              num = num1+num2+flag;
              
              if(num >= 10){
                  num %= 10;
                  flag = 1;
              }else{
                  flag = 0; 
              }
              
              ListNode* temp = new ListNode(num);
              
              if(res == NULL){
                  res = temp;
              }else{
                  prev->next = temp;
              }
              
              prev = temp; 
             
          }
        
          if(flag == 1){
              ListNode* temp = new ListNode(1);
              prev->next = temp;
          }
        
          return res; 
          
    }
};
