// Title: Reverse Nodes in k-Group
// Source: https://leetcode.com/problems/reverse-nodes-in-k-group
// Difficulty: Hard
// Tags: Linked List, Recursion
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.
 * k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.
 * You may not alter the values in the list's nodes, only nodes themselves may be changed.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [2,1,4,3,5]
 * Example 2:
 * 
 * Input: head = [1,2,3,4,5], k = 3
 * Output: [3,2,1,4,5]
 *  
 * Constraints:
 * - The number of nodes in the list is n.
 * - 1 <= k <= n <= 5000
 * - 0 <= Node.val <= 1000
 *  
 * Follow-up: Can you solve the problem in O(1) extra memory space?
**/

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    // reverse all node from begin (include) to end (exclude)
    ListNode* reverse(ListNode* begin, ListNode* end) {
        ListNode* cur = begin;
        ListNode* prev = end;
        ListNode *next;
        while (cur != end) {
            next = cur->next;
            cur->next = prev;
            prev = cur;
            cur = next;
        }
        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == nullptr || head->next == nullptr || k == 1) return head;

        head = new ListNode(0, head);
        ListNode* cur = head->next;
        ListNode* prev = head;
        for (int i = 1; cur; ++i) {
            if (i % k == 0) {
                auto temp = prev->next;
                prev->next = reverse(temp, cur->next);
                prev = temp;
                cur = prev->next;
            }
            else
                cur = cur->next;
        }
        return head->next;
    }
};