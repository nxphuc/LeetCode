// Title: Reverse Linked List II
// Source: https://leetcode.com/problems/reverse-linked-list-ii
// Difficulty: Medium
// Tags: Linked List
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5], left = 2, right = 4
 * Output: [1,4,3,2,5]
 * Example 2:
 * Input: head = [5], left = 1, right = 1
 * Output: [5]
 *  
 * Constraints:
 * - The number of nodes in the list is n.
 * - 1 <= n <= 500
 * - -500 <= Node.val <= 500
 * - 1 <= left <= right <= n
 *  
 * Follow up: Could you do it in one pass?
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left >= right) return head;
        if (head == nullptr) return head;
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy;
        for (int i = 1; i < left; ++i) prev = prev->next;

        ListNode* subTail = prev->next;
        ListNode* subHead = new ListNode(0, subTail);
        ListNode* cur = subTail;
        for (int i = left; i <= right; ++i) {
            ListNode* temp = cur->next;
            cur->next = subHead->next;
            subHead->next = cur;
            cur = temp;
        }

        prev->next = subHead->next;
        subTail->next = cur;
        return dummy->next;
    }
};