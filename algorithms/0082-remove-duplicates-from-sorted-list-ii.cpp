// Title: Remove Duplicates from Sorted List II
// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii
// Difficulty: Medium
// Tags: Linked List, Two Pointers
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,3,3,4,4,5]
 * Output: [1,2,5]
 * Example 2:
 * 
 * Input: head = [1,1,1,2,3]
 * Output: [2,3]
 *  
 * Constraints:
 * - The number of nodes in the list is in the range [0, 300].
 * - -100 <= Node.val <= 100
 * - The list is guaranteed to be sorted in ascending order.
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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        head = new ListNode(-101, head);
        ListNode* prev = head;
        ListNode* slow;
        ListNode* fast;
        while (slow) {
            fast = slow->next;
            // duplicate
            if (fast && fast->val == slow->val) {
                while (fast && fast->val == slow->val) fast = fast->next;
                slow = fast;
            }
            else {
                prev->next = slow;
                prev = slow;
                slow = fast;
            }
        }
        prev->next = nullptr;
        return head->next;
    }
};