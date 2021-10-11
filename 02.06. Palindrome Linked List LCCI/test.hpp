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

/**
 * 链表转数组后判断
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode* p = head;
        vector<int> arr;
        while (p) {
            arr.emplace_back(p->val);
            p = p->next;
        }
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            if (arr[i] != arr[n - i - 1]) {
                return false;
            }
        }
        return true;
    }
};

/**
 * 递归，前后指针
 * 时间复杂度 O(n)
 * 空间复杂度 O(n)
 */
class Solution_2 {
public:
    ListNode* frontPointer;
    
    bool recursivelyCheck(ListNode* currentNode) {
        if (currentNode != nullptr) {
            if (!recursivelyCheck(currentNode->next)) {
                return false;
            }
            if (currentNode->val != frontPointer->val) {
                return false;
            }
            frontPointer = frontPointer->next;
        }
        return true;
    }
    
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        frontPointer = head;
        return recursivelyCheck(head->next);
    }
};

class Solution_3 {
public:
    bool isPalindrome(ListNode* head) {
        if (!head) {
            return true;
        }
        
        ListNode* firstHalfEnd = endOfFirstHalf(head);
        ListNode* secondHalfBegin = reverseList(firstHalfEnd->next);

        while (secondHalfBegin != nullptr) {
            if (head->val != secondHalfBegin->val) {
                return false;
            }
            head = head->next;
            secondHalfBegin = secondHalfBegin->next;
        }

        return true;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* pre = nullptr;
        ListNode* cur = head;
        while (cur != nullptr) {
            ListNode* tmp = cur->next;
            cur->next = pre;
            pre = cur;
            cur = tmp;
        }
        return pre;
    }

    ListNode* endOfFirstHalf(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        return slow;
    }
};