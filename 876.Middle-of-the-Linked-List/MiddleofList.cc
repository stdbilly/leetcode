#include "list/list.h"

class Solution {
   public:
    ListNode* middleNode(ListNode* head) {
        if (!head || !head->next) return head;

        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 3, 4, 5, 6};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.middleNode(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}