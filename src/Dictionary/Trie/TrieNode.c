//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#include <Memory/Memory.h>
#include "TrieNode.h"

/**
 * A constructor of TrieNode class which creates a new children map.
 */
Trie_node_ptr create_trie_node() {
    Trie_node_ptr result = malloc_(sizeof(Trie_node), "create_trie_node");
    result->children = create_string_hash_map();
    result->words = create_hash_set((unsigned int (*)(const void *, int)) hash_function_txt_word,
                                    (int (*)(const void *, const void *)) compare_txt_word);
    return result;
}

/**
 * Frees memory allocated for a TrieNode. Frees memory allocated for children hash map, the words in the
 * trie node.
 * @param trie_node Trie node.
 */
void free_trie_node(Trie_node_ptr trie_node) {
    free_hash_map2(trie_node->children, free_, (void (*)(void *)) free_trie_node);
    free_hash_set(trie_node->words, (void (*)(void *)) free_txt_word);
    free_(trie_node);
}

/**
 * The addWord method takes a String word, an index, and a Word root as inputs. First it creates a TrieNode child
 * and if words {@link unordered_set} is null it creates a new {@link unordered_set} and add the given root word to this {@link unordered_set}, if it
 * is not null, it directly adds it to the {@link unordered_set} when the given index is equal to the length of given word.
 * <p>
 * Then, it extracts the character at given index of given word and if children map contains a mapping for the
 * extracted character, it assigns it to the TrieNode child, else it creates a new TrieNode and assigns it to the
 * child. At the end, it recursively calls the addWord method with the next index of child and puts the character with
 * the child into the children map.
 *
 * @param trie_node Trie node
 * @param word  String input.
 * @param index Integer index.
 * @param root  Word input to add.
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
        add_word_to_trie_node2(child, word, index + 1, root);
    } else {
        child = create_trie_node();
        add_word_to_trie_node2(child, word, index + 1, root);
        hash_map_insert(trie_node->children, clone_string(ch->s), child);
    }
    free_string_ptr(ch);
}

/**
 * The addWord method takes a String word and a Word type root as inputs. It calls addWord method with index 0.
 *
 * @param trie_node Trie node
 * @param word String input.
 * @param root Word type input.
 */
void add_word_to_trie_node(Trie_node_ptr trie_node, const char *word, Txt_word_ptr root) {
    add_word_to_trie_node2(trie_node, word, 0, root);
}

/**
 * The getChild method takes a Character and gets its corresponding value from children HashMap.
 *
 * @param trie_node Trie node
 * @param ch Character input.
 * @return the value from children HashMap.
 */
Trie_node_ptr get_child(const Trie_node* trie_node, const char *ch) {
    return (Trie_node_ptr) hash_map_get(trie_node->children, ch);
}

/**
 * Checks if the given child exists for a given character for the current TrieNode in the Trie.
 * @param trie_node Trie node
 * @param ch Character for which search is done.
 * @return True if th child exists for that character, false otherwise.
 */
bool child_exists(const Trie_node* trie_node, const char *ch) {
    return hash_map_contains(trie_node->children, ch);
}
