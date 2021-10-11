#include "bits/stdc++.h"
#include "../include/helper.hpp"
#include "../include/singly-linked-list.h"

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 双指针（快慢指针）
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

// 递归
class Solution_2 {
public:
    int cnt;

    int kthToLast(ListNode* head, int k) {
        if (head == nullptr) {
            return 0;
        }
        int val = kthToLast(head->next, k);
        cnt++;
        if (cnt < k) {
            return 0;
        } else if (cnt == k) {
            return head->val;
        } else if (cnt > k) {
            return val;
        }
        return 0;
    }
};