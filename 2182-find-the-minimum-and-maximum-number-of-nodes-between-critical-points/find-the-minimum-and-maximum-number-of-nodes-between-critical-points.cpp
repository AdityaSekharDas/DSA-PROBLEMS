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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> arr;
        vector<int> ans = {-1,-1};
        ListNode* temp = head;
        while(temp) {
            arr.push_back(temp->val);
            temp = temp->next;
        }
        if(arr.size() <= 2) return ans;
        vector<int> cri;
        for(int i=1; i<arr.size()-1; i++) {
            if(arr[i] > arr[i-1] && arr[i] > arr[i+1]) cri.push_back(i);
            else if(arr[i] < arr[i-1] && arr[i] < arr[i+1]) cri.push_back(i);
        } 
        if(cri.size() < 2) return ans;
        ans[1] = cri.back() - cri[0];
        int mindist = INT_MAX;
        for(int i=1; i<cri.size(); i++) mindist = min(mindist,cri[i]-cri[i-1]);
        ans[0] = mindist;
        return ans;
    }
};