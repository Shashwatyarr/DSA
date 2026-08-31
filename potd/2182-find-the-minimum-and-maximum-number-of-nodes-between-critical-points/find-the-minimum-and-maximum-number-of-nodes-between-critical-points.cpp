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
        ListNode* temp=head;
        vector<int> a;
        while(temp){
            a.push_back(temp->val);
            temp=temp->next;
        }
        vector<int> idx;
        for(int i=1;i<a.size()-1;i++){
            if((a[i]>a[i-1] && a[i]>a[i+1] ||(a[i]<a[i-1] && a[i]<a[i+1]) )) idx.push_back(i);
        }
        int mini=INT_MAX;
        if(idx.size()<2) return {-1,-1};
        for(int i=1;i<idx.size();i++){
            mini=min(mini,idx[i]-idx[i-1]);
        }
        return {mini,idx.back()-idx.front()};
    }
};