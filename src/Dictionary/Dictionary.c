//
// Created by Olcay Taner YILDIZ on 5.03.2023.
//

#include <stdlib.h>
#include <string.h>
#include "Dictionary.h"
#include "Word.h"

/**
 * An empty constructor of Dictionary class.
 */
Dictionary_ptr create_dictionary() {
    Dictionary_ptr result = malloc(sizeof(Dictionary));
    result->words = create_array_list();
    result->word_map = create_string_hash_map();
    return result;
}

void free_dictionary(Dictionary_ptr dictionary) {
    free_array_list(dictionary->words, (void (*)(void *)) free_word);
    free_hash_map(dictionary->word_map, free);
    free(dictionary);
}

/**
 * The getWord method takes a String name as an input and performs binary search within words vector and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the item at index middle of words vector, null otherwise.
 *
 * @param name String input.
 * @return the item at found index of words vector, null if cannot be found.
 */
Word_ptr get_word(const Dictionary* dictionary, const char *name) {
    if (word_exists(dictionary, name)) {
        int index = *(int *) (hash_map_get(dictionary->word_map, name));
        return array_list_get(dictionary->words, index);
    }
    return NULL;
}

/**
 * RemoveWord removes a word with the given name
 * @param name Name of the word to be removed.
 */
void remove_word(Dictionary_ptr dictionary, const char *name) {
    if (word_exists(dictionary, name)) {
        int index = *(int *) (hash_map_get(dictionary->word_map, name));
        array_list_remove(dictionary->words, index, (void (*)(void *)) free_word);
    }
    update_word_map(dictionary);
}

int binary_search(const Dictionary* dictionary, const Word* word) {
    int lo = 0;
    int hi = dictionary->words->size - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (strcmp(((Word_ptr) array_list_get(dictionary->words, mid))->name, word->name) == 0) {
            return mid;
        }
        if (strcmp(((Word_ptr) array_list_get(dictionary->words, mid))->name, word->name) < 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -(lo + 1);
}

/**
 * The getWordIndex method takes a String name as an input and performs binary search within words vector and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the index middle, -1 otherwise.
 *
 * @param name String input.
 * @return found index of words vector, -1 if cannot be found.
 */
int get_word_index(const Dictionary* dictionary, const char *name) {
    if (word_exists(dictionary, name)) {
        return *(int *) (hash_map_get(dictionary->word_map, name));
    } else {
        return -1;
    }
}

bool word_exists(const Dictionary* dictionary, const char *name) {
    return hash_map_contains(dictionary->word_map, name);
}

int size(const Dictionary* dictionary) {
    return dictionary->words->size;
}

/**
 * The getWord method which takes an index as an input and returns the value at given index of words vector.
 *
 * @param index to get the value.
 * @return the value at given index of words vector.
 */
Word_ptr get_word_with_index(const Dictionary* dictionary, int index) {
    return array_list_get(dictionary->words, index);
}

/**
 * The longestWordSize method loops through the words vector and returns the item with the maximum word length.
 *
 * @return the item with the maximum word length.
 */
int longest_word_size(const Dictionary* dictionary) {
    int max = 0;
    for (int i = 0; i < dictionary->words->size; i++) {
        Word_ptr word = array_list_get(dictionary->words, i);
        if (word_size(word->name) > max) {
            max = word_size(word->name);
        }
    }
    return max;
}

/**
 * The getWordStartingWith method takes a String hash as an input and performs binary search within words ArrayList and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the index middle, -middle-1 otherwise.
 *
 * @param hash String input.
 * @return found index of words vector, -middle-1 if cannot be found.
 */
int get_word_starting_with(const Dictionary* dictionary, const char *hash) {
    Word_ptr word = create_word(hash);
    int result = binary_search(dictionary, word);
    free_word(word);
    return result;
}

void update_word_map(Dictionary_ptr dictionary) {
    for (int i = 0; i < dictionary->words->size; i++) {
        Word_ptr word = array_list_get(dictionary->words, i);
        int *index = malloc(sizeof(int));
        *index = i;
        hash_map_insert(dictionary->word_map, word->name, index);
    }
}

void sort(Dictionary_ptr dictionary) {
    array_list_sort(dictionary->words, (int (*)(const void *, const void *)) compare_word);
    update_word_map(dictionary);
}
