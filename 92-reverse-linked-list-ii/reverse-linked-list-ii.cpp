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
   ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* current = dummy;

        for(int i = 0; i < left - 1; i++){
            current = current->next;
        }

        ListNode* Left = current;

        current = current->next;

        std::vector<ListNode*> group;
        for(int i = 0; i < right - left + 1; i++){
            group.push_back(current);
            current = current->next;
        }

        ListNode* Right = current;

        int gs = group.size();
        for(int i = gs - 1; i >= 0; i--){
            Left->next = group[i];
            Left = Left->next;
        }

        Left->next = Right;

        return dummy->next; 
    }
};