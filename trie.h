#ifndef TRIE_H
#define TRIE_H

struct trie;

typedef struct trie Trie;

Trie * trie_alloc();
Trie * trie_add(Trie * trie, char * word, int len);
int trie_get(Trie* trie, char * word, int len);
Trie * trie_remove(Trie * trie, char * word, int len);
void trie_free(Trie * trie);
#endif /* TRIE_H */