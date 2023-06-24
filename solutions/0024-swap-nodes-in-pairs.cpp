// Title: Swap Nodes in Pairs
// Source: https://leetcode.com/problems/swap-nodes-in-pairs
// Difficulty: Medium
// Tags: Linked List, Recursion
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given a linked list, swap every two adjacent nodes and return its head. You must solve the problem without modifying the values in the list's nodes (i.e., only nodes themselves may be changed.)
 *  
 * Example 1:
 * 
 * Input: head = [1,2,3,4]
 * Output: [2,1,4,3]
 * Example 2:
 * Input: head = []
 * Output: []
 * Example 3:
 * Input: head = [1]
 * Output: [1]
 *  
 * Constraints:
 * - The number of nodes in the list is in the range [0, 100].
 * - 0 <= Node.val <= 100
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
    ListNode* swapPairs(ListNode* head) {
        if (!head || head->next == nullptr) return head;

        head = new ListNode(0, head);
        ListNode* prev = head;
        ListNode* cur = prev->next;
        ListNode* next = cur->next;;
        while (cur && next) {
            prev->next = next;
            cur->next = next->next;
            next->next = cur;
            prev = cur;
            cur = cur->next;
            next = cur ? cur->next : nullptr;
        }
        return head->next;
    }
};