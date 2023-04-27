#include <iostream>
#include "Trie.h"

using namespace std;

TrieNode* getNewNode(void)
{
    struct TrieNode* pNode = new TrieNode;

    pNode->isEndOfWord = false;

    for (int i = 0; i < ALPHABET_SIZE; i++)
        pNode->children[i] = nullptr;

    return pNode;
}


void insert(TrieNode* root, string key)
{
    TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';

        if (!node->children[index])
            node->children[index] = getNewNode();

        node = node->children[index];
    }

    node->isEndOfWord = true;
}

bool search(struct TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return false;

        node = node->children[index];
    }

    return (node != nullptr && node->isEndOfWord);
}

bool isEmpty(TrieNode* root)
{
    for (int i = 0; i < ALPHABET_SIZE; i++)
        if (root->children[i])
            return false;
    return true;
}

TrieNode* remove(TrieNode* root, string key, int depth)
{
    if (!root)
        return nullptr;

    if (depth == key.size()) {

        if (root->isEndOfWord)
            root->isEndOfWord = false;

        if (isEmpty(root)) {
            delete (root);
            root = nullptr;
        }

        return root;
    }

    int index = key[depth] - 'a';
    root->children[index] = remove(root->children[index], key, depth + 1);

    if (isEmpty(root) && root->isEndOfWord == false) {
        delete (root);
        root = nullptr;
    }
    return root;
}

TrieNode* searchReturn(TrieNode* root, string key)
{
    struct TrieNode* node = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!node->children[index])
            return nullptr;

        node = node->children[index];
    }

    return node;
}

void autocomplete(TrieNode* root, string key)
{
    if (!root) return;
    int ind = 0;
    char buf[64];
    string res;
    for (int i = 0; i < 64; i++) {
        buf[i] = '\0';
    }
    autocomplete(root, buf, ind, key, res);
    
}

void autocomplete(TrieNode* root, char buf[], int ind, string key, string& res)
{
    if (!root) return;
    TrieNode* node = root;
    node = searchReturn(node, key);
    for (int i = 0; i < ALPHABET_SIZE; ++i)
    {
        if (node->isEndOfWord)
        {
            buf[ind] = '\0';
            res += buf;
            res += ' ';
            cout << res << endl;
            return;
        }

        if (node->children[i])
        {
            char buf1[64];
            for (int i = 0; i < 64; i++)
                buf1[i] = buf[i];
            buf1[ind] = char(i + static_cast<int>('a'));

            int ind1 = ind + 1;
            node = node->children[i];
            autocomplete(node, buf1, ind1, key, res);
        }
        return;

    }


}