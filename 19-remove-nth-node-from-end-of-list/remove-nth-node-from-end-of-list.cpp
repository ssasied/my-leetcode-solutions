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
    ListNode* solution(ListNode* current,int& n){        
        if(current->next!=nullptr){
         current->next=solution(current->next,n);
        }
        else if(current->next==nullptr){     
            n--;
            if(n==0) return nullptr;

            return current;
        }
        n--;
        if(n==0){
            return current->next;
        }
        return current;
    }
    ListNode* removeNthFromEnd(ListNode* head, int n) {      
      return solution(head,n);
      


    }
};