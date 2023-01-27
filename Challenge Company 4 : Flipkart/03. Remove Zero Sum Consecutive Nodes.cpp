/*
https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
*/

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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* temp = new ListNode(0);    //head can also be deleted
        temp->next = head;
        ListNode* curr = temp;
        
        unordered_map<int, ListNode*> mp;
        int pSum=0;
        while(curr){
            pSum += curr->val;
            mp[pSum] = curr;  //if pSum appears >1 times, prev sublist get ignored 
            curr = curr->next;
        }
        
        pSum=0;
        curr = temp;
        while(curr){
            pSum += curr->val;
            curr->next = mp[pSum]->next;
            curr = curr->next;
        }
        
        return temp->next;
    }
};
