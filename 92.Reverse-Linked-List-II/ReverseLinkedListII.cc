#include <iostream>
#include <vector>
#include "list/list.h"
using std::cout;
using std::endl;
using std::vector;

class Solution {
   public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == nullptr) {
            return nullptr;
        }
        // Move the two pointers until they reach the proper starting point
        // in the list.
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (m > 1) {
            pre = cur;
            cur = cur->next;
            --m;
            --n;
        }
        // The two pointers that will fix the final connections.
        ListNode* con = pre;
        ListNode* tail = cur;
        // Iteratively reverse the nodes until n becomes 0.
        ListNode* next = nullptr;
        while (n > 0) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
            --n;
        }
        if (con) {
            con->next = pre;
        } else {
            head = pre;
        }
        tail->next = cur;
        return head;
    }
};

int main() {
    Solution solution;
    int arr[5] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(int);
    ListNode* head = createLinkedList(arr, size);
    printLinkedList(head);
    ListNode* head2 = solution.reverseBetween(head, 2, 4);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}