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
    vector<int> printListReversingly(ListNode* head) {
        vector<int> res;
        ListNode *tail = head;
        while(tail != NULL) {
            res.push_back(tail->val);
            tail = tail->next;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
