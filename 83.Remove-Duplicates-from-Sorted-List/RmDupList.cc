#include "list/list.h"

class Solution {
   public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* cur = head;
        while (cur && cur->next) {
            if (cur->val == cur->next->val) {
                cur->next = cur->next->next;
            } else {
                cur = cur->next;
            }
        }
        return head;
    }
};

int main() {
    Solution solution;
    int arr[5] = {1, 1, 2, 3, 3};
    int size = sizeof(arr) / sizeof(int);
    ListNode* head = createLinkedList(arr, size);
    printLinkedList(head);
    ListNode* head2 = solution.deleteDuplicates(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}