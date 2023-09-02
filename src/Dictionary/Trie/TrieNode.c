//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#include <stdlib.h>
#include "TrieNode.h"
#include "../TxtWord.h"

/**
 * A constructor of {@link TrieNode} class which creates a new children {@link map}.
 */
Trie_node_ptr create_trie_node() {
    Trie_node_ptr result = malloc(sizeof(Trie_node));
    result->children = create_string_hash_map();
    result->words = create_hash_set((unsigned int (*)(const void *, int)) hash_function_txt_word,
                                    (int (*)(const void *, const void *)) compare_word);
    return result;
}

void free_trie_node(Trie_node_ptr trie_node) {
    Array_list_ptr children = key_list(trie_node->children);
    for (int i = 0; i < children->size; i++) {
        char *child = (char *) array_list_get(children, i);
        Trie_node_ptr child_node = (Trie_node_ptr) hash_map_get(trie_node->children, child);
        free_trie_node(child_node);
    }
    free_array_list(children, NULL);
    free_hash_map(trie_node->children, NULL);
    free_hash_set(trie_node->words, (void (*)(void *)) free_txt_word);
    free(trie_node);
}

/**
 * The addWord method takes a String word, an index, and a {@link Word} root as inputs. First it creates a {@link TrieNode} child
 * and if words {@link unordered_set} is null it creates a new {@link unordered_set} and add the given root word to this {@link unordered_set}, if it
 * is not null, it directly adds it to the {@link unordered_set} when the given index is equal to the length of given word.
 * <p>
 * Then, it extracts the character at given index of given word and if children {@link map} contains a mapping for the
 * extracted character, it assigns it to the {@link TrieNode} child, else it creates a new {@link TrieNode} and assigns it to the
 * child. At the end, it recursively calls the addWord method with the next index of child and puts the character with
 * the child into the children {@link map}.
 *
 * @param word  String input.
 * @param index Integer index.
 * @param root  {@link Word} input to add.
 */
void add_word_to_trie_node2(Trie_node_ptr trie_node, const char *word, int index, Txt_word_ptr root) {
    Trie_node_ptr child;
    if (index == word_size(word)) {
        hash_set_insert(trie_node->words, root);
        return;
    }
    String_ptr ch = char_at(word, index);
    if (hash_map_contains(trie_node->children, ch->s)) {
        child = (Trie_node_ptr) hash_map_get(trie_node->children, ch->s);
    } else {
        child = create_trie_node();
    }
    add_word_to_trie_node2(child, word, index + 1, root);
    hash_map_insert(trie_node->children, ch->s, child);
    free(ch);
}

/**
 * The addWord method takes a String word and a {@link Word} type root as inputs. It calls addWord method with index 0.
 *
 * @param word String input.
 * @param root {@link Word} type input.
 */
void add_word_to_trie_node(Trie_node_ptr trie_node, const char *word, Txt_word_ptr root) {
    add_word_to_trie_node2(trie_node, word, 0, root);
}

/**
 * The getChild method takes a {@link Character} and gets its corresponding value from children {@link HashMap}.
 *
 * @param ch {@link Character} input.
 * @return the value from children {@link HashMap}.
 */
Trie_node_ptr get_child(const Trie_node* trie_node, const char *ch) {
    return (Trie_node_ptr) hash_map_get(trie_node->children, ch);
}

bool child_exists(const Trie_node* trie_node, const char *ch) {
    return hash_map_contains(trie_node->children, ch);
}
