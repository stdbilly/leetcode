#pragma once
#include <iostream>
using std::cout;
using std::endl;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* createLinkedList(int arr[], int size) {
    if (size == 0) return nullptr;
    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for (int i = 1; i < size; ++i) {
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }
    return head;
}

void printLinkedList(ListNode* head) {
    ListNode* curNode = head;
    while (curNode) {
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }
    cout << "NULL" << endl;
}

void destroyLinkedList(ListNode* head) {
    ListNode* curNode = head;
    while (curNode) {
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }
    return;
}