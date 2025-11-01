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
class Solution
{
public:
    ListNode *modifiedList(vector<int> &nums, ListNode *head)
    {
        sort(nums.begin(), nums.end());
        ListNode dummy(0);
        dummy.next = head;
        ListNode *current = &dummy;

        while (current->next != nullptr)
        {
            if (binary_search(nums.begin(), nums.end(), current->next->val))
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        return dummy.next;
    }
};