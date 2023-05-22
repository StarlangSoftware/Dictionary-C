//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#ifndef DICTIONARY_TRIE_H
#define DICTIONARY_TRIE_H

#include "TrieNode.h"

struct trie {
    Trie_node_ptr root_node;
};

typedef struct trie Trie;
typedef Trie *Trie_ptr;

Trie_ptr create_trie();

void free_trie(Trie_ptr trie);

void add_word_to_trie(Trie_ptr trie, const char *word, Txt_word_ptr root);

Hash_set_ptr get_words_with_prefix(const Trie* trie, const char *surface_form);

Txt_word_ptr get_compound_word_starting_with(const Trie* trie, const char *hash);


#endif //DICTIONARY_TRIE_H
