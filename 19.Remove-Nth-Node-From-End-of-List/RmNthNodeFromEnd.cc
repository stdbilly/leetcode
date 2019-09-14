#include <cassert>
#include "list.h"

// pre和last相差n+1个节点, 当last为NULL时, pre就是要删除节点的前一个节点
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n >= 0);
        ListNode dummy(0);
        dummy.next = head;
        ListNode* pre = &dummy;
        ListNode* last = &dummy;
        for (int i = 0; i < n + 1; ++i) {
            assert(last);
            last = last->next;
        }

        while (last) {
            pre = pre->next;
            last = last->next;
        }
        ListNode* delNode = pre->next;
        pre->next = delNode->next;
        delete delNode;

        return dummy.next;
    }
};

int main() {
    Solution solution;
    vector<int> arr{1, 2, 3, 4, 5};
    ListNode* head = createLinkedList(arr);
    printLinkedList(head);
    ListNode* head2 = solution.removeNthFromEnd(head, 5);
    printLinkedList(head2);
    destroyLinkedList(head2);
    return 0;
}