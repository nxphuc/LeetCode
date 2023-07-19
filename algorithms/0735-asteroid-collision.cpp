// Title: Asteroid Collision
// Source: https://leetcode.com/problems/asteroid-collision
// Difficulty: Medium
// Tags: Array, Stack, Simulation
// Author: nxphuc
// Time Complexity: O(N)
// Space Complexity: O(1)
// Note: 

/**
 * We are given an array asteroids of integers representing asteroids in a row.
 * For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.
 * Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.
 *  
 * Example 1:
 * Input: asteroids = [5,10,-5]
 * Output: [5,10]
 * Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
 * Example 2:
 * Input: asteroids = [8,-8]
 * Output: []
 * Explanation: The 8 and -8 collide exploding each other.
 * Example 3:
 * Input: asteroids = [10,2,-5]
 * Output: [10]
 * Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.
 *  
 * Constraints:
 * - 2 <= asteroids.length <= 10^4
 * - -1000 <= asteroids[i] <= 1000
 * - asteroids[i] != 0
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        deque<int> st;

        for (int x : asteroids) {
            if (x > 0)
                st.push_back(x);
            else {
                while (st.size()) {
                    auto& y = st.back();
                    if (y < 0) break;
                    if (y + x <= 0)
                        st.pop_back();
                    if (y + x >= 0) {
                        x = 0;
                        break;
                    }
                }
                if (x < 0)
                    st.push_back(x);
            }
        }

        return vector<int>(st.begin(), st.end());
    }
};