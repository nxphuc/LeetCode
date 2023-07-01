// Title: Word Search II
// Source: https://leetcode.com/problems/word-search-ii
// Difficulty: Hard
// Tags: Array, String, Backtracking, Trie, Matrix
// Author: nxphuc
// Time Complexity: 
// Space Complexity: 
// Note: 

/**
 * Given an m x n board of characters and a list of strings words, return all words on the board.
 * Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.
 *  
 * Example 1:
 * 
 * Input: board = [["o","a","a","n"],["e","t","a","e"],["i","h","k","r"],["i","f","l","v"]], words = ["oath","pea","eat","rain"]
 * Output: ["eat","oath"]
 * Example 2:
 * 
 * Input: board = [["a","b"],["c","d"]], words = ["abcb"]
 * Output: []
 *  
 * Constraints:
 * - m == board.length
 * - n == board[i].length
 * - 1 <= m, n <= 12
 * - board[i][j] is a lowercase English letter.
 * - 1 <= words.length <= 3 * 10^4
 * - 1 <= words[i].length <= 10
 * - words[i] consists of lowercase English letters.
 * - All the strings of words are unique.
**/

#include <bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode* child[26];
    string word;

    TrieNode() {
        memset(child, 0, sizeof(child));
        word = "";
    }
};

class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};

    void insert(TrieNode* root, string word) {
        int cur = 0;
        for (char c : word) {
            if (!root->child[c - 'a'])
                root->child[c - 'a'] = new TrieNode();
            root = root->child[c - 'a'];
        }
        root->word = word;
    }

    void dfs(vector<vector<char>>& board, TrieNode* root, int x, int y, vector<string>& result) {
        char c = board[x][y];
        if (c == '@' || !root->child[c - 'a']) return;

        root = root->child[c - 'a'];
        board[x][y] = '@';
        if (root->word != "") {
            result.push_back(root->word);
            root->word = "";
        }
        for (int nx, ny, i = 0; i < 4; ++i) {
            nx = x + dx[i];
            ny = y + dy[i];
            if (nx < 0 || nx >= board.size() || ny < 0 || ny >= board[0].size() || board[nx][ny] == '@')
                continue;
            dfs(board, root, nx, ny, result);
        }
        board[x][y] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for (auto& word : words)
            insert(root, word);
        vector<string> result;
        for (int i = 0; i < board.size(); ++i) {
            for (int j = 0; j < board[0].size(); ++j) {
                dfs(board, root, i, j, result);
            }
        }
        return result;
    }
};