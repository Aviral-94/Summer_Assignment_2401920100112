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
ListNode* reverse(ListNode* head)
{    ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        while (curr != NULL)
        {
            next = curr -> next;
            curr->next = prev;
            prev = curr;
            curr = next ;
        }
        return prev ;
}
    bool isPalindrome(ListNode* head) {
       ListNode* slow = head;
ListNode* fast = head;

while (fast != NULL && fast->next != NULL) {
    slow = slow->next;
    fast = fast->next->next;
}
ListNode* sec = reverse(slow);
ListNode* first = head;
ListNode* sechalf = sec;
while (sechalf != NULL)
{
    if (sechalf -> val != first -> val)
    {
return false;
    }
    first =first -> next ;
    sechalf = sechalf -> next;
}


return true;

    }
};