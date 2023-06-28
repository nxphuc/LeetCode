// Title: Reorder List
// Source: https://leetcode.com/problems/reorder-list
// Difficulty: Medium
// Tags: Linked List, Two Pointers, Stack, Recursion
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * You are given the head of a singly linked-list. The list can be represented as:
 * L0 → L1 → … → Ln - 1 → Ln
 * Reorder the list to be on the following form:
 * L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
 * You may not modify the values in the list's nodes. Only nodes themselves may be changed.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,3,4]
 * Output: [1,4,2,3]
 * Example 2:
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,5,2,4,3]
 *  
 * Constraints:
 * - The number of nodes in the list is in the range [1, 5 * 10^4].
 * - 1 <= Node.val <= 1000
**/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head) {
        ListNode* newHead = nullptr;
        while (head) {
            ListNode* temp = head->next;
            head->next = newHead;
            newHead = head;
            head = temp;
        }
        return newHead;
    }

    void reorderList(ListNode* head) {
        if (!head || !head->next) return;
        ListNode* middle = middleNode(head);
        ListNode* secondHead = reverseList(middle->next);
        middle->next = nullptr;
        ListNode* node = head;
        while (secondHead) {
            ListNode* temp = secondHead->next;
            secondHead->next = node->next;
            node->next = secondHead;
            node = secondHead->next;
            secondHead = temp;
        }
    }
};