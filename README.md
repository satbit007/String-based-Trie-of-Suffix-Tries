# String-based-Trie-of-Suffix-Tries
Data Structure to implement: String-based Trie of Suffix Tries


Operations to support: All operations of an integer binary search tree as well as the precursor and successor functions to enable tree traversal based on probabilistic branching


Problem to solve: Generating auto-correction suggestions using keyboard user-input by traversing the suffix trie based on the user input data so far and offering the most-likely string outcome based on a simplistic counter mechanism to track the user’s most used paths taken based on that scenario (similarly to a fusion tree)


Claims: Auto-correction generation in o(k) or less, where k is the number of child nodes, Tree traversal in o(h) or less, where h is the height of the trie


Implementation: A string trie enabling word search built on the underlying BST structure, containing branching characters represeting every subsequent possibility for a character in a node

Testing: VSCode and Online compiler. Predefined functions hold up to usage of find, get, insert and delete. Executing the main function creates the tree and enables it to be used

Instructions: Store trie.c and trie.h in the same directory. Run trie.c in a C compiler. Use additional functions to add your search term to the trie
