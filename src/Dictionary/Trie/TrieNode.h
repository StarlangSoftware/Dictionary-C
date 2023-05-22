//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#ifndef DICTIONARY_TRIENODE_H
#define DICTIONARY_TRIENODE_H

#include <HashMap/HashMap.h>
#include <HashMap/HashSet.h>
#include "../Word.h"
#include "../TxtWord.h"

struct trie_node {
    Hash_map_ptr children;
    Hash_set_ptr words;
};

typedef struct trie_node Trie_node;
typedef Trie_node *Trie_node_ptr;

Trie_node_ptr create_trie_node();

void free_trie_node(Trie_node_ptr trie_node);

void add_word_to_trie_node2(Trie_node_ptr trie_node, const char *word, int index, Txt_word_ptr root);

void add_word_to_trie_node(Trie_node_ptr trie_node, const char *word, Txt_word_ptr root);

Trie_node_ptr get_child(const Trie_node* trie_node, const char *ch);

bool child_exists(const Trie_node* trie_node, const char *ch);

#endif //DICTIONARY_TRIENODE_H
