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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int,int> mp;
        ListNode* temp = head;
        while(temp != NULL) {
            mp[temp->val]++;
            temp = temp->next;
        }

        ListNode* dumm = new ListNode(-1);
        ListNode* curr = dumm;

        for(auto it : mp) {
            if(it.second == 1) {
                curr->next = new ListNode(it.first);
                curr = curr->next;
            }
        }

        return dumm->next;
    }
};