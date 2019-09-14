#include <iostream>
#include "list.h"
using std::cout;
using std::endl;

class Solution {
   public:
    ListNode* detectCycle(ListNode* head) {
        ListNode* meetNode = meetingNode(head);
        if (!meetNode) return nullptr;

        ListNode* pAhead = meetNode;
        int nNodes = 1;
        //统计环中节点数目
        while (pAhead->next != meetNode) {
            ++nNodes;
            pAhead = pAhead->next;
        }

        pAhead = head;
        //先移动pAhead,次数为环中节点数目
        for (int i = 0; i < nNodes; ++i) {
            pAhead = pAhead->next;
        }
        //再同时移动pAhead和pBehind,当它们相遇时便是换的入口节点
        ListNode* pBehind = head;
        while (pBehind != pAhead) {
            pAhead = pAhead->next;
            pBehind = pBehind->next;
        }
        return pAhead;
    }

   private:
    ListNode* meetingNode(ListNode* head) {
        if (!head || !head->next) return nullptr;

        ListNode* slow = head;
        ListNode* fast = slow->next;
        while (fast && fast->next && slow) {
            if (slow == fast) return fast;
            slow = slow->next;
            fast = fast->next->next;
        }
        return nullptr;
    }
};

int main() {
    Solution solution;
    ListNode* pNode1 = new ListNode(1);
    ListNode* pNode2 = new ListNode(2);
    ListNode* pNode3 = new ListNode(3);
    ListNode* pNode4 = new ListNode(4);
    ListNode* pNode5 = new ListNode(5);

    connectListNodes(pNode1, pNode2);
    connectListNodes(pNode2, pNode3);
    connectListNodes(pNode3, pNode4);
    connectListNodes(pNode4, pNode5);
    connectListNodes(pNode5, pNode3);
    ListNode* node = solution.detectCycle(pNode1);
    cout << node->val << endl;
    
    delete pNode1;
    pNode1 = nullptr;
    delete pNode2;
    pNode2 = nullptr;
    delete pNode3;
    pNode3 = nullptr;
    delete pNode4;
    pNode4 = nullptr;
    delete pNode5;
    pNode5 = nullptr;
    return 0;
}