// Title: Search Suggestions System
// Source: https://leetcode.com/problems/search-suggestions-system
// Difficulty: Medium
// Tags: Array, String, Trie
// Author: nxphuc
// Time Complexity: O(N * |S|)
// Space Complexity: O(N * |S|)
// Note: 

/**
 * You are given an array of strings products and a string searchWord.
 * Design a system that suggests at most three product names from products after each character of searchWord is typed. Suggested products should have common prefix with searchWord. If there are more than three products with a common prefix return the three lexicographically minimums products.
 * Return a list of lists of the suggested products after each character of searchWord is typed.
 *  
 * Example 1:
 * Input: products = ["mobile","mouse","moneypot","monitor","mousepad"], searchWord = "mouse"
 * Output: [["mobile","moneypot","monitor"],["mobile","moneypot","monitor"],["mouse","mousepad"],["mouse","mousepad"],["mouse","mousepad"]]
 * Explanation: products sorted lexicographically = ["mobile","moneypot","monitor","mouse","mousepad"].
 * After typing m and mo all products match and we show user ["mobile","moneypot","monitor"].
 * After typing mou, mous and mouse the system suggests ["mouse","mousepad"].
 * Example 2:
 * Input: products = ["havana"], searchWord = "havana"
 * Output: [["havana"],["havana"],["havana"],["havana"],["havana"],["havana"]]
 * Explanation: The only word "havana" will be always suggested while typing the search word.
 *  
 * Constraints:
 * - 1 <= products.length <= 1000
 * - 1 <= products[i].length <= 3000
 * - 1 <= sum(products[i].length) <= 2 * 10^4
 * - All the strings of products are unique.
 * - products[i] consists of lowercase English letters.
 * - 1 <= searchWord.length <= 1000
 * - searchWord consists of lowercase English letters.
**/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int child[26];
    vector<string> words;

    TrieNode() {
        fill(child, child + 26, 0);
    }

    void update(string word) {
        words.push_back(word);
        int i = words.size() - 1;
        while (i > 0 && words[i - 1] > word) {
            words[i] = words[i - 1];
            --i;
        }
        words[i] = word;
        if (words.size() > 3) words.pop_back();
    }
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        vector<TrieNode> trie;
        trie.emplace_back();

        auto add = [&](string word) {
            int cur = 0;
            for (char c : word) {
                if (trie[cur].child[c - 'a'] == 0) {
                    trie[cur].child[c - 'a'] = trie.size();
                    trie.emplace_back();
                }
                cur = trie[cur].child[c - 'a'];
                trie[cur].update(word);
            }
        };

        for (string prod : products)
            add(prod);
        
        vector<vector<string>> res(searchWord.length());
        int cur = 0;
        for (int i = 0; i < searchWord.length(); ++i) {
            int idx = searchWord[i] - 'a';
            if (trie[cur].child[idx] == 0) break;
            cur = trie[cur].child[idx];
            res[i] = trie[cur].words;
        }
        return res;
    }
};