#include "bits/stdc++.h"
#include "../include/helper.hpp"
#include "../include/singly-linked-list.h"
using namespace std;
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* pA = headA;
        ListNode* pB = headB;
        while (pA || pB) {
            if (pA == pB) {
                return pA;
            }
            if (!pA) {
                pA = headB;
            } else {
                pA = pA->next;
            }
            if (!pB) {
                pB = headA;
            } else {
                pB = pB->next;
            }
        }
        return nullptr;
    }
};