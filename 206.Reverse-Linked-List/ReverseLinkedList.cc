#include "list/list.h"
#include <iostream>
using std::cout;
using std::endl;

class Solution {
   public:
    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        ListNode* next = nullptr;
        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};

int main() {
    Solution solution;
    int arr[5] = {1,2,3,4,5};
    int size = sizeof(arr)/sizeof(int);
    ListNode* head = createLinkedList(arr, size);
    printLinkedList(head);
    ListNode* head2 = solution.reverseList(head);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}