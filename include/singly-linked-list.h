#include "bits/stdc++.h"

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* Vector2List(std::vector<int> vet) {
    ListNode* head = new ListNode(0);
    ListNode* cur = head;
    for (const int& val : vet) {
        cur->next = new ListNode(val);
        cur = cur->next;
    }
    return head->next;
}