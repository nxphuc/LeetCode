// Title: Merge k Sorted Lists
// Source: https://leetcode.com/problems/merge-k-sorted-lists
// Difficulty: Hard
// Tags: Linked List, Divide and Conquer, Heap (Priority Queue), Merge Sort
// Author: nxphuc
// Time Complexity: O(NlogK)
// Space Complexity: O(K)
// Note: 

/**
 * You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
 * Merge all the linked-lists into one sorted linked-list and return it.
 *  
 * Example 1:
 * Input: lists = [[1,4,5],[1,3,4],[2,6]]
 * Output: [1,1,2,3,4,4,5,6]
 * Explanation: The linked-lists are:
 * [
 *   1->4->5,
 *   1->3->4,
 *   2->6
 * ]
 * merging them into one sorted list:
 * 1->1->2->3->4->4->5->6
 * Example 2:
 * Input: lists = []
 * Output: []
 * Example 3:
 * Input: lists = [[]]
 * Output: []
 *  
 * Constraints:
 * - k == lists.length
 * - 0 <= k <= 10^4
 * - 0 <= lists[i].length <= 500
 * - -10^4 <= lists[i][j] <= 10^4
 * - lists[i] is sorted in ascending order.
 * - The sum of lists[i].length will not exceed 10^4.
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* head = new ListNode();
        ListNode* cur = head;
        auto comparator = [](ListNode* &a, ListNode* &b) {
            return a->val > b->val;
        };
        priority_queue<ListNode*, vector<ListNode*>, decltype(comparator)> pq(comparator);
        for (auto& head : lists)
            if (head) pq.push(head);
        while (!pq.empty()) {
            auto temp = pq.top();
            pq.pop();
            cur->next = temp;
            cur = temp;
            if (temp->next) pq.push(temp->next);
        }
        return head->next;
    }
};