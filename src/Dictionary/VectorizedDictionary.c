//
// Created by Olcay Taner YILDIZ on 2.04.2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <FileUtils.h>
#include <Memory/Memory.h>
#include "VectorizedDictionary.h"
#include "VectorizedWord.h"

/**
 * A constructor of VectorizedDictionary class which takes a WordComparator as an input and calls its
 * super class Dictionary with WordComparator input.
 *
 */
Vectorized_dictionary_ptr create_vectorized_dictionary() {
    Vectorized_dictionary_ptr result = malloc_(sizeof(Vectorized_dictionary), "create_vectorized_dictionary");
    result->dictionary = create_dictionary();
    return result;
}

/**
 * Frees memory allocated for the VectorizedDictionary. Frees words array, word_map hash map, dictionary, file_name.
 * @param vectorized_dictionary
 */
void free_vectorized_dictionary(Vectorized_dictionary_ptr vectorized_dictionary) {
    free_array_list(vectorized_dictionary->dictionary->words, (void (*)(void *)) free_vectorized_word);
    free_hash_map(vectorized_dictionary->dictionary->word_map, free_);
    free_(vectorized_dictionary->dictionary);
    free_(vectorized_dictionary->file_name);
    free_(vectorized_dictionary);
}

/**
 * Another constructor of VectorizedDictionary class that takes an input file
 * containing the word vectors as input. Line j contains an array of numbers that represent the word vector for
 * that corresponding word at index j.
 * @param file_name Name of the input file that contains the word vectors
 */
Vectorized_dictionary_ptr create_vectorized_dictionary2(const char *file_name) {
    FILE* input_file;
    Vectorized_dictionary_ptr result = malloc_(sizeof(Vectorized_dictionary), "create_vectorized_dictionary2");
    result->dictionary = create_dictionary();
    result->file_name = str_copy(result->file_name, file_name);
    input_file = fopen(result->file_name, "r");
    if (input_file == NULL) {
        fclose(input_file);
        return NULL;
    }
    while (!feof(input_file)) {
        Array_list_ptr tokens = read_items(input_file, ' ');
        if (tokens->size != 0) {
            Vector_ptr vector = create_vector2(0, 0);
            for (int i = 1; i < tokens->size; i++){
                add_value_to_vector(vector, atof(array_list_get(tokens, i)));
            }
            Vectorized_word_ptr currentWord = create_vectorized_word(array_list_get(tokens, 0), vector);
            array_list_add(result->dictionary->words, currentWord);
        }
        free_array_list(tokens, free_);
    }
    fclose(input_file);
    sort_vectorized(result);
    return result;
}

/**
 * Sorts the words array according to the comparator function.
 * @param vectorized_dictionary Current vectorized dictionary
 */
void sort_vectorized(Vectorized_dictionary_ptr vectorized_dictionary) {
    array_list_sort(vectorized_dictionary->dictionary->words, (int (*)(const void *, const void *)) compare_vectorized_word);
    update_word_map_vectorized(vectorized_dictionary);
}

/**
 * Updates word map so that word index at i is in the hash map with key word and value i.
 * @param vectorized_dictionary Current vectorized dictionary
 */
void update_word_map_vectorized(Vectorized_dictionary_ptr vectorized_dictionary) {
    for (int i = 0; i < vectorized_dictionary->dictionary->words->size; i++) {
        Vectorized_word_ptr word = array_list_get(vectorized_dictionary->dictionary->words, i);
        int *index = malloc_(sizeof(int), "update_word_map_vectorized");
        *index = i;
        hash_map_insert(vectorized_dictionary->dictionary->word_map, word->word, index);
    }
}

/**
 * The addWord method takes a VectorizedWord as an input and adds it to the words ArrayList.
 *
 * @param vectorized_dictionary Dictionary to add word
 * @param vectorized_word VectorizedWord input.
 */
void add_word_vectorized(Vectorized_dictionary_ptr vectorized_dictionary, Vectorized_word_ptr vectorized_word) {
    array_list_add(vectorized_dictionary->dictionary->words, vectorized_word);
}

/**
 * The getWord2 method takes a String name as an input and performs binary search within words vector and assigns the
 * result to integer variable middle. If the middle is greater than 0, it returns the item at index middle of words
 * vector, NULL otherwise.
 *
 * @param dictionary Current dictionary
 * @param name String input.
 * @return the item at found index of words vector, NULL if cannot be found.
 */
Vectorized_word_ptr get_word2(const Vectorized_dictionary *dictionary, const char *name) {
    if (word_exists(dictionary->dictionary, name)) {
        int index = *(int *) (hash_map_get(dictionary->dictionary->word_map, name));
        return array_list_get(dictionary->dictionary->words, index);
    }
    return NULL;
}
