// Title: Course Schedule
// Source: https://leetcode.com/problems/course-schedule
// Difficulty: Medium
// Tags: Depth-First Search, Breadth-First Search, Graph, Topological Sort
// Author: nxphuc
// Time Complexity: O(N + M)
// Space Complexity: O(N)
// Note: 

/**
 * There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
 * - For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
 * Return true if you can finish all courses. Otherwise, return false.
 *  
 * Example 1:
 * Input: numCourses = 2, prerequisites = [[1,0]]
 * Output: true
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0. So it is possible.
 * Example 2:
 * Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
 * Output: false
 * Explanation: There are a total of 2 courses to take. 
 * To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
 *  
 * Constraints:
 * - 1 <= numCourses <= 2000
 * - 0 <= prerequisites.length <= 5000
 * - prerequisites[i].length == 2
 * - 0 <= ai, bi < numCourses
 * - All the pairs prerequisites[i] are unique.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool dfs(vector<vector<int>>& adj, vector<int>& visited, int u) {
        visited[u] = 1;
        for (int v : adj[u]) {
            if (visited[v] == 1)
                return false;
            if (visited[v] == 0 && !dfs(adj, visited, v))
                return false;
        }
        visited[u] = 2;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for (auto v : prerequisites)
            adj[v[0]].push_back(v[1]);
        vector<int> visited(numCourses, 0);
        for (int i = 0; i < numCourses; ++i)
            if (visited[i] == 0 && !dfs(adj, visited, i))
                return false;
        return true;
    }
};