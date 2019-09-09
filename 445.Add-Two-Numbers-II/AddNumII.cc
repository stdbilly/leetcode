#include <stack>
#include "list/list.h"
using std::stack;

class Solution {
   public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1, s2;
        while (l1) {
            s1.push(l1->val);
            l1 = l1->next;
        }
        while (l2) {
            s2.push(l2->val);
            l2 = l2->next;
        }
        int carry = 0;
        ListNode* cur = nullptr;
        ListNode* pre = nullptr;
        while (!s1.empty() || !s2.empty() || carry) {
            int sum = carry;
            if (!s1.empty()) {
                sum += s1.top();
                s1.pop();
            }
            if (!s2.empty()) {
                sum += s2.top();
                s2.pop();
            }
            carry = sum / 10;
            pre = new ListNode(sum % 10);
            pre->next = cur;
            cur = pre;
        }

        return cur;
    }
};

int main() {
    Solution solution;
    vector<int> arr1{7, 2, 4, 3};
    vector<int> arr2{5, 6, 4};
    ListNode* l1 = createLinkedList(arr1);
    ListNode* l2 = createLinkedList(arr2);
    printLinkedList(l1);
    printLinkedList(l2);
    ListNode* res = solution.addTwoNumbers(l1, l2);
    printLinkedList(res);
    destroyLinkedList(res);
    destroyLinkedList(l1);
    destroyLinkedList(l2);
    return 0;
}