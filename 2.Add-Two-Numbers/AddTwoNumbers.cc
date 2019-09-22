#include "list.h"

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* p = l1;
        ListNode* q = l2;
        ListNode* cur = dummyHead;
        int carry = 0;
        while (p || q || carry) {
            int x = p ? p->val : 0;
            int y = q ? q->val : 0;
            int sum = x + y + carry;
            carry = sum / 10;
            cur->next = new ListNode(sum % 10);
            cur = cur->next;
            if (p) p = p->next;
            if (q) q = q->next;
        }
        
        return dummyHead->next;
    }
};

int main() {
    Solution solution;
    int arr1[3] = {2, 4, 3};
    int arr2[3] = {5, 6, 4};
    int size1 = sizeof(arr1) / sizeof(int);
    int size2 = sizeof(arr2) / sizeof(int);
    ListNode* l1 = createLinkedList(arr1, size1);
    ListNode* l2 = createLinkedList(arr2, size1);
    printLinkedList(l1);
    printLinkedList(l2);
    ListNode* res = solution.addTwoNumbers(l1, l2);
    printLinkedList(res);
    destroyLinkedList(res);
    destroyLinkedList(l1);
    destroyLinkedList(l2);
    return 0;
}