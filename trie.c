#include <stdio.h>
#include <stdlib.h>
#include "trie.h"

struct trie {
    char v;
    int data, next_count;
    struct trie **next;
    struct trie *parent;
};

Trie * trie_alloc()
{
    Trie * trie = calloc(1, sizeof(Trie));
    if (trie == NULL)
    {
        printf ("trie calloc failed\n");
    }
    trie->next = calloc(256, sizeof(Trie*));
    if (trie->next == NULL)
    {
        printf ("trie->next calloc failed\n");
    }
    trie->data = 0;
    trie->next_count = 0;
    trie->parent = NULL;
    return trie;
}

Trie * trie_add(Trie * trie, char * word, int len)
{
    if (trie == NULL)
    {
        trie = trie_alloc();
    }

    Trie * cur = trie; 
    unsigned int ind;
    for (int i = 0; i < len; i++)
    {
        ind = word[i];
        if (cur->next[ind] == NULL)
        {
            cur->next[ind] = trie_alloc();
            cur->next[ind]->v = word[i];
            cur->next[ind]->parent = cur;
            cur->next_count++;
        }
        cur = cur->next[ind];
    }

    cur->data++;

    return trie;
}

static Trie * trie_find(Trie* trie, char * word, int len)
{
    Trie * cur = trie, *next;
    int i = 0, count = 0;

    while(cur != NULL)
    {
        next = cur->next[word[i]];
        if (next == NULL && i < len)
        {
            count = 0;
            break;
        } else if (next == NULL && i == len)
        {
          count = cur->data;
          break;
        }

        cur = next;
        i++;
    }
    
    if (count == 0) return NULL;
    return cur;
}

int trie_get(Trie* trie, char * word, int len)
{
    Trie * cur = trie_find(trie, word, len);
    if (cur == NULL) return 0;
    else return cur->data;
}

Trie * trie_remove(Trie * trie, char * word, int len)
{
    Trie * cur = trie, *next = NULL, *parent = NULL;
    int i = 0, count = 0;

    if (trie == NULL) return NULL;
     
    cur = trie_find(trie, word, len);
    if (cur) {
        int j = len - 1;
        if (cur->data > 0) {
            cur->data--;
        }
    
        while (cur != trie) {
            parent = cur->parent;

            if (cur->next_count > 0) {
                cur->next_count--;
            }

            if (cur->next_count == 0 && cur->data == 0) {
                // printf ("%p, %p\n", cur, parent->next[word[j]]);
                free(cur);
                parent->next[word[j]] = NULL;
            }
            
            cur = parent;
            j--;
        }
    }
    
    return trie;
}

void trie_free(Trie * trie)
{
    while (trie != NULL) {
        if (trie->next_count > 0) {
            for (int i = 0; i < 256; i++) {
                if (trie->next[i] != NULL) {
                    trie_free(trie->next[i]);
                }
            }
        }

        free(trie);
    }
}

int main() {
    
    Trie* tree = trie_alloc();
    tree = trie_add(tree, "dictionary", 10);
    printf("%d", tree -> next_count);

    return 0;
}