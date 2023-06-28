// Title: Word Ladder
// Source: https://leetcode.com/problems/word-ladder
// Difficulty: Hard
// Tags: Hash Table, String, Breadth-First Search
// Author: nxphuc
// Time Complexity: O(N * |word|)
// Space Complexity: 
// Note: 

/**
 * A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:
 * - Every adjacent pair of words differs by a single letter.
 * - Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
 * - sk == endWord
 * Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence from beginWord to endWord, or 0 if no such sequence exists.
 *  
 * Example 1:
 * Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
 * Output: 5
 * Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
 * Example 2:
 * Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
 * Output: 0
 * Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 *  
 * Constraints:
 * - 1 <= beginWord.length <= 10
 * - endWord.length == beginWord.length
 * - 1 <= wordList.length <= 5000
 * - wordList[i].length == beginWord.length
 * - beginWord, endWord, and wordList[i] consist of lowercase English letters.
 * - beginWord != endWord
 * - All the words in wordList are unique.
**/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> res;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (wordSet.find(endWord) == wordSet.end())
            return 0;
        
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        while (!q.empty()) {
            int n = q.size();
            ++count;
            cout << count << " " << n << endl;
            unordered_set<string> visited;
            while (n--) {
                string cur = q.front();;
                q.pop();
                for (int i = 0; i < cur.length(); ++i) {
                    string next = cur;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        if (c == cur[i]) continue;
                        next[i] = c;
                        if (wordSet.find(next) == wordSet.end()) continue;
                        if (next == endWord)
                            return count;
                        q.push(next);
                        visited.insert(next);
                    }
                }
            }

            // remove all found word in this layer from wordSet
            for (auto& s : visited)
                wordSet.erase(s);
        }
        return 0;
    }
};