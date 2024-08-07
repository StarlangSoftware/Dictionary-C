//
// Created by Olcay Taner YILDIZ on 5.03.2023.
//

#include <stdlib.h>
#include <string.h>
#include <Memory/Memory.h>
#include "Dictionary.h"
#include "Word.h"

/**
 * An empty constructor of Dictionary class.
 */
Dictionary_ptr create_dictionary() {
    Dictionary_ptr result = malloc_(sizeof(Dictionary), "create_dictionary");
    result->words = create_array_list();
    result->word_map = create_string_hash_map();
    return result;
}

/**
 * Frees memory allocated for the dictionary. Frees memory allocated for the words and word hash map.
 * @param dictionary Dictionary to be freed.
 */
void free_dictionary(Dictionary_ptr dictionary) {
    free_array_list(dictionary->words, (void (*)(void *)) free_);
    free_hash_map(dictionary->word_map, free_);
    free_(dictionary);
}

/**
 * The getWord method takes a String name as an input and performs binary search within words vector and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the item at index middle of words vector, null otherwise.
 *
 * @param dictionary Current dictionary
 * @param name String input.
 * @return the item at found index of words vector, NULL if cannot be found.
 */
char* get_word(const Dictionary* dictionary, const char *name) {
    if (word_exists(dictionary, name)) {
        int index = *(int *) (hash_map_get(dictionary->word_map, name));
        return array_list_get(dictionary->words, index);
    }
    return NULL;
}

/**
 * Removes a word with the given name
 * @param dictionary Current dictionary
 * @param name Name of the word to be removed.
 */
void remove_word(Dictionary_ptr dictionary, const char *name) {
    if (word_exists(dictionary, name)) {
        int index = *(int *) (hash_map_get(dictionary->word_map, name));
        array_list_remove(dictionary->words, index, (void (*)(void *)) free_);
    }
    update_word_map(dictionary);
}

/**
 * Checks if a given word exists in the dictionary by performing a binary search on the words array.
 * @param dictionary Dictionary to be searched.
 * @param word Searched word
 * @return the index of the search word, if it is contained in the words array; otherwise, (-(insertion point) - 1). The
 * insertion point is defined as the point at which the word would be inserted into the words array.
 */
int binary_search(const Dictionary* dictionary, const char* word) {
    int lo = 0;
    int hi = dictionary->words->size - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (strcmp(array_list_get(dictionary->words, mid), word) == 0) {
            return mid;
        }
        if (strcmp(array_list_get(dictionary->words, mid), word) < 0) {
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
 * @param dictionary Current dictionary.
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

/**
 * Checks if a word in the dictionary exists for a given name.
 * @param dictionary Current dictionary.
 * @param name Input word
 * @return True, if the word exists, false otherwise.
 */
bool word_exists(const Dictionary* dictionary, const char *name) {
    return hash_map_contains(dictionary->word_map, name);
}

/**
 * Returns size of the dictionary
 * @param dictionary Current dictionary
 * @return Size of the dictionary
 */
int size(const Dictionary* dictionary) {
    return dictionary->words->size;
}

/**
 * The getWord method which takes an index as an input and returns the value at given index of words vector.
 *
 * @param dictionary Current dictionary
 * @param index to get the value.
 * @return the value at given index of words vector.
 */
char* get_word_with_index(const Dictionary* dictionary, int index) {
    return array_list_get(dictionary->words, index);
}

/**
 * The longestWordSize method loops through the words vector and returns the item with the maximum word length.
 *
 * @param dictionary Current dictionary
 * @return the item with the maximum word length.
 */
int longest_word_size(const Dictionary* dictionary) {
    int max = 0;
    for (int i = 0; i < dictionary->words->size; i++) {
        char* word = array_list_get(dictionary->words, i);
        if (word_size(word) > max) {
            max = word_size(word);
        }
    }
    return max;
}

/**
 * The getWordStartingWith method takes a String hash as an input and performs binary search within words ArrayList and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the index middle, -middle-1 otherwise.
 *
 * @param dictionary Current dictionary
 * @param hash String input.
 * @return found index of words vector, -middle-1 if cannot be found.
 */
int get_word_starting_with(const Dictionary* dictionary, const char *hash) {
    int result = binary_search(dictionary, hash);
    return result;
}

/**
 * Updates word map so that word index at i is in the hash map with key word and value i.
 * @param dictionary Current dictionary
 */
void update_word_map(Dictionary_ptr dictionary) {
    for (int i = 0; i < dictionary->words->size; i++) {
        char* word = array_list_get(dictionary->words, i);
        int *index = malloc_(sizeof(int), "update_word_map");
        *index = i;
        hash_map_insert(dictionary->word_map, word, index);
    }
}

/**
 * Sorts the words array according to the comparator function.
 * @param dictionary Current dictionary
 */
void sort(Dictionary_ptr dictionary) {
    array_list_sort(dictionary->words, (int (*)(const void *, const void *)) compare_string);
    update_word_map(dictionary);
}
