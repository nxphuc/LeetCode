// Title: Design Add and Search Words Data Structure
// Source: https://leetcode.com/problems/design-add-and-search-words-data-structure
// Difficulty: Medium
// Tags: String, Depth-First Search, Design, Trie
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Design a data structure that supports adding new words and finding if a string matches any previously added string.
 * Implement the WordDictionary class:
 * - WordDictionary() Initializes the object.
 * - void addWord(word) Adds word to the data structure, it can be matched later.
 * - bool search(word) Returns true if there is any string in the data structure that matches word or false otherwise. word may contain dots '.' where dots can be matched with any letter.
 *  
 * Example:
 * Input
 * ["WordDictionary","addWord","addWord","addWord","search","search","search","search"]
 * [[],["bad"],["dad"],["mad"],["pad"],["bad"],[".ad"],["b.."]]
 * Output
 * [null,null,null,null,false,true,true,true]
 * Explanation
 * WordDictionary wordDictionary = new WordDictionary();
 * wordDictionary.addWord("bad");
 * wordDictionary.addWord("dad");
 * wordDictionary.addWord("mad");
 * wordDictionary.search("pad"); // return False
 * wordDictionary.search("bad"); // return True
 * wordDictionary.search(".ad"); // return True
 * wordDictionary.search("b.."); // return True
 *  
 * Constraints:
 * - 1 <= word.length <= 25
 * - word in addWord consists of lowercase English letters.
 * - word in search consist of '.' or lowercase English letters.
 * - There will be at most 2 dots in word for search queries.
 * - At most 10^4 calls will be made to addWord and search.
**/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    Node* children[26];
    bool isWord;

    Node() {
        memset(children, 0, sizeof(children));
        isWord = false;
    }
};

class WordDictionary {
private:
    Node* root;
public:
    WordDictionary() {
        root = new Node();
    }
    
    void addWord(string word) {
        Node* cur = root;
        for (char c : word) {
            if (cur->children[c - 'a'] == nullptr)
                cur->children[c - 'a'] = new Node();
            cur = cur->children[c - 'a'];
        }
        cur->isWord = true;
    }

    bool search(Node* root, string word, int idx = 0) {
        if (!root) return false;
        if (idx == word.length()) return root->isWord;
        if (word[idx] != '.')
            return search(root->children[word[idx] - 'a'], word, idx + 1);
        for (int i = 0; i < 26; i++)
            if (root->children[i] && search(root->children[i], word, idx + 1))
                return true;
        return false;
    }
    
    bool search(string word) {
        return search(root, word);
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */