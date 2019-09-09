#include "list/list.h"

class Solution {
   public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == nullptr) return nullptr;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = even;
        while (even && even->next) {
            odd->next = even->next;
            odd = odd->next;
            even->next = odd->next;
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    }
};

int main() {
    Solution solution;
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    ListNode* head = createLinkedList(arr, size);
    printLinkedList(head);
    ListNode* head2 = solution.oddEvenList(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}