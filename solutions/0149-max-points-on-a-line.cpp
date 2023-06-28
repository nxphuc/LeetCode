// Title: Max Points on a Line
// Source: https://leetcode.com/problems/max-points-on-a-line
// Difficulty: Hard
// Tags: Array, Hash Table, Math, Geometry
// Author: nxphuc
// Time Complexity: O(N^2)
// Space Complexity: O(N^2)
// Note: 

/**
 * Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.
 *  
 * Example 1:
 * 
 * Input: points = [[1,1],[2,2],[3,3]]
 * Output: 3
 * Example 2:
 * 
 * Input: points = [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
 * Output: 4
 *  
 * Constraints:
 * - 1 <= points.length <= 300
 * - points[i].length == 2
 * - -10^4 <= xi, yi <= 10^4
 * - All the points are unique.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            map<pair<int, int>, int> slopes;

            for (int j = i + 1; j < n; ++j) {
                // slope of line of two points i and j: (y[j] - y[i]) / (x[j] - x[i])
                int deltaY = points[j][1] - points[i][1];
                int deltaX = points[j][0] - points[i][0];
                if (deltaX < 0) {
                    deltaX = -deltaX;
                    deltaY = -deltaY;
                }
                int g = __gcd(deltaX, deltaY);
                deltaX /= g;
                deltaY /= g;

                res = max(res, ++slopes[{deltaX, deltaY}]);
            }
        }
        return res;
    }
};