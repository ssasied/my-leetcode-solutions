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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode *current = head;
        ListNode *dummy = new ListNode(0, head);
        ListNode *groupheader = dummy;        
        ListNode *startofgroup;
        std::vector<ListNode*> group;
        int i = 0;

        while (current != nullptr) {     
            startofgroup = current;       
            for (i = 0; i < k; i++) {
                if (current == nullptr) break;
                group.push_back(current);
                current = current->next;
            }

            if (i == k) {                
                for (int j = k - 1; j >= 0; j--) {
                    groupheader->next = group[j];
                    groupheader = groupheader->next;
                }
                groupheader->next = current; 
                std::vector<ListNode*>().swap(group);
            } else {                
                groupheader->next = startofgroup;   
            }
        }
        
        return dummy->next;
    }
};