# String-based-Trie-of-Suffix-Tries
Data Structure to implement: String-based Trie of Suffix Tries


Operations to support: All operations of an integer binary search tree as well as the precursor and successor functions to enable tree traversal based on probabilistic branching


Problem to solve: Generating auto-correction suggestions using keyboard user-input by traversing the suffix trie based on the user input data so far and offering the most-likely string outcome based on a simplistic counter mechanism to track the user’s most used paths taken based on that scenario (similarly to a fusion tree)


Claims: Auto-correction generation in o(k) or less, where k is the number of child nodes, Tree traversal in o(h) or less, where h is the height of the trie
