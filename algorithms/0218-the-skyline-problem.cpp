// Title: The Skyline Problem
// Source: https://leetcode.com/problems/the-skyline-problem
// Difficulty: Hard
// Tags: Array, Divide and Conquer, Binary Indexed Tree, Segment Tree, Line Sweep, Heap (Priority Queue), Ordered Set
// Author: nxphuc
// Time Complexity: O(NlogN)
// Space Complexity: O(N)
// Note: 

/**
 * A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.
 * The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:
 * - lefti is the x coordinate of the left edge of the i^th building.
 * - righti is the x coordinate of the right edge of the i^th building.
 * - heighti is the height of the i^th building.
 * You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.
 * The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.
 * Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]
 *  
 * Example 1:
 * 
 * Input: buildings = [[2,9,10],[3,7,15],[5,12,12],[15,20,10],[19,24,8]]
 * Output: [[2,10],[3,15],[7,12],[12,0],[15,10],[20,8],[24,0]]
 * Explanation:
 * Figure A shows the buildings of the input.
 * Figure B shows the skyline formed by those buildings. The red points in figure B represent the key points in the output list.
 * Example 2:
 * Input: buildings = [[0,2,3],[2,5,3]]
 * Output: [[0,3],[5,0]]
 *  
 * Constraints:
 * - 1 <= buildings.length <= 10^4
 * - 0 <= lefti < righti <= 2^31 - 1
 * - 1 <= heighti <= 2^31 - 1
 * - buildings is sorted by lefti in non-decreasing order.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector< pair<int, int> > walls;
        vector<vector<int>> res;
        for (auto& b : buildings){
            walls.push_back(make_pair(b[0], -b[2]));
            walls.push_back(make_pair(b[1], b[2]));
        }
        sort(walls.begin(), walls.end());
        
        multiset<int> heights = {0};
        int top = 0;
        
        for (pair<int,int> w : walls){
            if (w.second < 0)
                heights.insert(w.second);
            else
                heights.erase(heights.find(-w.second));
            
            if (*heights.begin() != -top)
                res.push_back({w.first, top = - *heights.begin()});
        }
        return res;
    }
};