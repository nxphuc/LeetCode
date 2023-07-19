// Title: Odd Even Linked List
// Source: https://leetcode.com/problems/odd-even-linked-list
// Difficulty: Medium
// Tags: Linked List
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * Given the head of a singly linked list, group all the nodes with odd indices together followed by the nodes with even indices, and return the reordered list.
 * The first node is considered odd, and the second node is even, and so on.
 * Note that the relative order inside both the even and odd groups should remain as it was in the input.
 * You must solve the problem in O(1) extra space complexity and O(n) time complexity.
 *  
 * Example 1:
 * 
 * Input: head = [1,2,3,4,5]
 * Output: [1,3,5,2,4]
 * Example 2:
 * 
 * Input: head = [2,1,3,5,6,4,7]
 * Output: [2,3,6,7,1,5,4]
 *  
 * Constraints:
 * - The number of nodes in the linked list is in the range [0, 10^4].
 * - -10^6 <= Node.val <= 10^6
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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* dummyOdd = new ListNode();
        ListNode* dummyEven = new ListNode();
        ListNode* curOdd = dummyOdd;
        ListNode* curEven = dummyEven;
        while (head) {
            curOdd->next = head;
            head = head->next;
            curOdd = curOdd->next;
            if (head) {
                curEven->next = head;
                head = head->next;
                curEven = curEven->next;
            }
        }
        curEven->next =nullptr;
        curOdd->next = dummyEven->next;
        return dummyOdd;
    }
};