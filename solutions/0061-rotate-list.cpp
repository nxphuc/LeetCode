// Title: Rotate List
// Source: https://leetcode.com/problems/rotate-list
// Difficulty: Medium
// Tags: Linked List, Two Pointers
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given the head of a linked list, rotate the list to the right by k places.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5], k = 2
 * Output: [4,5,1,2,3]
 * Example 2:
 * 
 * Input: head = [0,1,2], k = 4
 * Output: [2,0,1]
 *  
 * Constraints:
 * - The number of nodes in the list is in the range [0, 500].
 * - -100 <= Node.val <= 100
 * - 0 <= k <= 2 * 10^9
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head)
            return head;
        int n = 1;
        ListNode* tail = head;
        while (tail->next != nullptr) {
            ++n;
            tail = tail->next;
        }
        k = (n - k % n) % n;
        if (!k)
            return head;
        ListNode* cur = head;
        for (int i = 1; i < k; i++)
            cur = cur->next;
        tail->next = head;
        head = cur->next;
        cur->next = nullptr;
        return head;
    }
};