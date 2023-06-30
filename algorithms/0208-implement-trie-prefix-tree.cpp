// Title: Implement Trie (Prefix Tree)
// Source: https://leetcode.com/problems/implement-trie-prefix-tree
// Difficulty: Medium
// Tags: Hash Table, String, Design, Trie
// Author: nxphuc
// Time Complexity: O(length(word))
// Space Complexity: O(N)
// Note: 

/**
 * A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
 * Implement the Trie class:
 * - Trie() Initializes the trie object.
 * - void insert(String word) Inserts the string word into the trie.
 * - boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
 * - boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.
 *  
 * Example 1:
 * Input
 * ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
 * [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
 * Output
 * [null, null, true, false, true, null, true]
 * Explanation
 * Trie trie = new Trie();
 * trie.insert("apple");
 * trie.search("apple");   // return True
 * trie.search("app");     // return False
 * trie.startsWith("app"); // return True
 * trie.insert("app");
 * trie.search("app");     // return True
 *  
 * Constraints:
 * - 1 <= word.length, prefix.length <= 2000
 * - word and prefix consist only of lowercase English letters.
 * - At most 3 * 10^4 calls in total will be made to insert, search, and startsWith.
**/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    int child[26];
    int cntPass;
    int cntWord;

    TrieNode() {
        memset(child, 0, sizeof(child));
        cntPass = cntWord = 0;
    }
};

class Trie {
private:
    vector<TrieNode> nodes;
public:
    Trie() {
        nodes.emplace_back();
    }
    
    void insert(string word) {
        int cur = 0;
        for (char c : word) {
            if (!nodes[cur].child[c - 'a']) {
                nodes[cur].child[c - 'a'] = nodes.size();
                nodes.emplace_back();
            }
            cur = nodes[cur].child[c - 'a'];
            ++nodes[cur].cntPass;
        }
        ++nodes[cur].cntWord;
    }
    
    bool search(string word) {
        int cur = 0;
        for (char c : word) {
            if (!nodes[cur].child[c - 'a'])
                return false;
            cur = nodes[cur].child[c - 'a'];
        }
        return nodes[cur].cntWord > 0;
    }
    
    bool startsWith(string prefix) {
        int cur = 0;
        for (char c : prefix) {
            if (!nodes[cur].child[c - 'a'])
                return false;
            cur = nodes[cur].child[c - 'a'];
        }
        return nodes[cur].cntPass > 0;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */