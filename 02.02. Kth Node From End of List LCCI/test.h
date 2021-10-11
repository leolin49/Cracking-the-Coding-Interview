#include "bits/stdc++.h"
#include "../datastruct/helper.hpp"
#include "../datastruct/singly-linked-list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    int kthToLast(ListNode* head, int k) {
        ListNode* p1 = head;
        ListNode* p2 = head;
        for (int i = 0; i < k; i++) {
            p1 = p1->next;
        }
        while (p1 != nullptr) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p2->val;
    }
};