//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#include <stdlib.h>
#include "Trie.h"
#include "../TxtWord.h"

/**
 * A constructor of {@link Trie} class which creates a new {@link TrieNode} as rootNode.
 */
Trie_ptr create_trie() {
    Trie_ptr result = malloc(sizeof(Trie));
    result->root_node = create_trie_node();
    return result;
}

void free_trie(Trie_ptr trie) {
    free_trie_node(trie->root_node);
    free(trie);
}

/**
 * The addWord method which takes a String word and a {@link Word} root as inputs and adds given word and root to the rootNode.
 *
 * @param word String input.
 * @param root {@link Word} input.
 */
void add_word_to_trie(Trie_ptr trie, char *word, Txt_word_ptr root) {
    add_word_to_trie_node(trie->root_node, word, root);
}

/**
 * The getWordsWithPrefix method which takes a String surfaceForm as an input. First it creates a {@link TrieNode} current and assigns
 * the rootNode to it, then it creates a new {@link HashSet} words. It loops i times where i ranges from 0 to length of surfaceForm
 * and assigns current's child that corresponds to the surfaceForm's char at index i and assigns it as {@link TrieNode} current.
 * If current is not null, it adds all words of current to the words {@link HashSet}.
 *
 * @param surfaceForm String input.
 * @return words {@link unordered_set}.
 */
Hash_set_ptr get_words_with_prefix(Trie_ptr trie, char *surface_form) {
    Trie_node_ptr current = trie->root_node;
    Hash_set_ptr words = create_hash_set((unsigned int (*)(void *, int)) hash_function_word,
                                         (int (*)(void *, void *)) compare_txt_word);
    for (int i = 0; i < word_size(surface_form); i++) {
        String_ptr ch = char_at(surface_form, i);
        if (child_exists(current, ch->s)) {
            current = get_child(current, ch->s);
            if (!hash_set_is_empty(current->words)) {
                Hash_set_ptr wordsToBeAdded = current->words;
                hash_set_merge(words, wordsToBeAdded);
            }
        } else {
            free_string_ptr(ch);
            break;
        }
        free_string_ptr(ch);
    }
    return words;
}

/**
 * The getCompoundWordStartingWith method takes a String hash. First it creates a {@link TrieNode} current and assigns
 * the rootNode to it. Then it loops i times where i ranges from 0 to length of given hash and assigns current's child that
 * corresponds to the hash's char at index i and assigns it as current. If current is null, it returns null.
 * <p>
 * If current is not null,  it loops through the words of current {@link TrieNode} and if it is a Portmanteau word, it
 * directly returns the word.
 *
 * @param hash String input.
 * @return null if {@link TrieNode} is null, otherwise portmanteau word.
 */
Txt_word_ptr get_compound_word_starting_with(Trie_ptr trie, char *hash) {
    Trie_node_ptr current = trie->root_node;
    for (int i = 0; i < word_size(hash); i++) {
        String_ptr ch = char_at(hash, i);
        if (child_exists(current, ch->s)) {
            current = get_child(current, ch->s);
        } else {
            free_string_ptr(ch);
            return NULL;
        }
        free_string_ptr(ch);
    }
    if (!hash_set_is_empty(current->words)) {
        Array_list_ptr key_list = hash_set_key_list(current->words);
        for (int i = 0; i < key_list->size; i++) {
            Txt_word_ptr word = (Txt_word_ptr) array_list_get(key_list, i);
            if (is_portmanteau(word)) {
                free_array_list(key_list, NULL);
                return word;
            }
        }
        free_array_list(key_list, NULL);
    }
    return NULL;
}
