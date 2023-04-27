#include <iostream>
#include "trie.h"

int main()
{
	int ind = 0;
	string enter;
	string keys1[] = { "cat", "call", "cult", "run", "rut" };
	int n1 = sizeof(keys1) / sizeof(keys1[0]);

	TrieNode* root1 = getNewNode();
	
	for (int i = 0; i < n1; i++) {
		insert(root1, keys1[i]);
	}
	std::cout << "Enter part of a word: " << std::endl;
	std::cin >> enter;
	std::cout << std::endl;
	autocomplete(root1, enter);

	return 0;
}