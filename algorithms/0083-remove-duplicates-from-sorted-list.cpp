// Title: Remove Duplicates from Sorted List
// Source: https://leetcode.com/problems/remove-duplicates-from-sorted-list
// Difficulty: Easy
// Tags: Linked List
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
 *  
 * Example 1:
 * 
 * Input: head = [1,1,2]
 * Output: [1,2]
 * Example 2:
 * 
 * Input: head = [1,1,2,3,3]
 * Output: [1,2,3]
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
        ListNode* dummy = new ListNode(-101, head);
        ListNode* tail = dummy;
        while (head) {
            if (head->val != tail->val) {
                tail->next = head;
                tail = head;
            }
            head = head->next;
        }
        tail->next = nullptr;
        return dummy->next;
    }
};