// Title: Remove Nth Node From End of List
// Source: https://leetcode.com/problems/remove-nth-node-from-end-of-list
// Difficulty: Medium
// Tags: Linked List, Two Pointers
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note:

/**
 * Given the head of a linked list, remove the n^th node from the end of the list and return its head.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5], n = 2
 * Output: [1,2,3,5]
 * Example 2:
 * Input: head = [1], n = 1
 * Output: []
 * Example 3:
 * Input: head = [1,2], n = 1
 * Output: [1]
 *  
 * Constraints:
 * - The number of nodes in the list is sz.
 * - 1 <= sz <= 30
 * - 0 <= Node.val <= 100
 * - 1 <= n <= sz
 *  
 * Follow up: Could you do this in one pass?
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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fast = head;
        for (int i = 0; i < n; ++i)
            fast = fast->next;
        if (!fast) return head->next;
    
        ListNode* slow = head;
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        slow->next = slow->next->next;
        return head;
    }
};