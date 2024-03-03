#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <chrono>

using namespace std;
using namespace std::chrono;

class TrieNode {
public:
    unordered_map<char, TrieNode*> children;
    bool is_end_of_word;

    TrieNode() {
        is_end_of_word = false;
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode();
    }

    void insert(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                node->children[c] = new TrieNode();
            }
            node = node->children[c];
        }
        node->is_end_of_word = true;
    }

    bool search(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (node->children.find(c) == node->children.end()) {
                return false;
            }
            node = node->children[c];
        }
        return node != nullptr && node->is_end_of_word;
    }
};

bool isCompounded(string word, Trie* trie) {
    if (word.empty()) return false;
    int n = word.length();
    for (int i = 1; i < n; ++i) {
        string prefix = word.substr(0, i);
        string suffix = word.substr(i);
        if (trie->search(prefix) && (trie->search(suffix) || isCompounded(suffix, trie))) {
            return true;
        }
    }
    return false;
}

string findLongestCompoundedWord(vector<string>& words, Trie* trie) {
    string longest = "";
    for (string word : words) {
        if (isCompounded(word, trie) && word.length() > longest.length()) {
            longest = word;
        }
    }
    return longest;
}

string findSecondLongestCompoundedWord(vector<string>& words, Trie* trie, string longestWord) {
    string secondLongest = "";
    for (string word : words) {
        if (word != longestWord && isCompounded(word, trie) && word.length() > secondLongest.length()) {
            secondLongest = word;
        }
    }
    return secondLongest;
}

void processInputFile(const string& fileName) {
    ifstream file(fileName);
    if (!file.is_open()) {
        cout << "Error opening file " << fileName << endl;
        return;
    }

    Trie trie;
    vector<string> words;
    string word;
    while (getline(file, word)) {
        trie.insert(word);
        words.push_back(word);
    }
    file.close();

    auto start = high_resolution_clock::now();
    string longestWord = findLongestCompoundedWord(words, &trie);
    string secondLongestWord = findSecondLongestCompoundedWord(words, &trie, longestWord);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);

    cout << "Longest Compound Word: " << longestWord << endl;
    cout << "Second Longest Compound Word: " << secondLongestWord << endl;
    cout << "Time taken to process file " << fileName << ": " << duration.count() << " milliseconds" << endl;
}

int main() {
    processInputFile("Input_01.txt");
    processInputFile("Input_02.txt");


}
