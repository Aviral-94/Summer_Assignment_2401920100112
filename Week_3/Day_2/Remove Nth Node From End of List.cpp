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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* temp = head;

        // count total nodes
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }

        // if first node is to be deleted
        if (n == count) {
            ListNode* del = head;
            head = head->next;
            delete del;
            return head;
        }

        // move till the (count-n)th node
        temp = head;
        int i = 1;
        while (i < count - n) {
            temp = temp->next;
            i++;
        }

        // delete next node
        ListNode* del = temp->next;
        temp->next = temp->next->next;
        delete del;

        return head;
    }
};
