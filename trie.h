#pragma once
#pragma once
#ifndef TRIE_H
#define TRIE_H

#include <string>
using namespace std;

const int ALPHABET_SIZE = 26;

struct TrieNode
{
    struct TrieNode* children[ALPHABET_SIZE];
    bool isEndOfWord;
};

TrieNode* getNewNode(void);
void insert(TrieNode*, string);
bool search(TrieNode*, string);
bool isEmpty(TrieNode*);
TrieNode* remove(TrieNode*, string, int depth = 0);
void autocomplete(TrieNode* root, string key);
void autocomplete(TrieNode* root, char[], int, string, string& res);
TrieNode* searchReturn(TrieNode*, string);


#endif