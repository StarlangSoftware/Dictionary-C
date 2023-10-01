//
// Created by Olcay Taner YILDIZ on 2.04.2023.
//

#include <stdlib.h>
#include <stdio.h>
#include <FileUtils.h>
#include "VectorizedDictionary.h"
#include "VectorizedWord.h"

/**
 * A constructor of {@link VectorizedDictionary} class which takes a {@link WordComparator} as an input and calls its
 * super class {@link Dictionary} with {@link WordComparator} input.
 *
 * @param comparator {@link WordComparator} type input.
 */
Vectorized_dictionary_ptr create_vectorized_dictionary() {
    Vectorized_dictionary_ptr result = malloc(sizeof(Vectorized_dictionary));
    result->dictionary = create_dictionary();
    return result;
}

void free_vectorized_dictionary(Vectorized_dictionary_ptr vectorized_dictionary) {
    free_dictionary(vectorized_dictionary->dictionary);
    free(vectorized_dictionary);
}

Vectorized_dictionary_ptr create_vectorized_dictionary2(const char *file_name) {
    FILE* input_file;
    Vectorized_dictionary_ptr result = malloc(sizeof(Vectorized_dictionary));
    result->dictionary = create_dictionary();
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
    }
    fclose(input_file);
    sort_vectorized(result);
    return result;
}

void sort_vectorized(Vectorized_dictionary_ptr vectorized_dictionary) {
    array_list_sort(vectorized_dictionary->dictionary->words, (int (*)(const void *, const void *)) compare_vectorized_word);
    update_word_map_vectorized(vectorized_dictionary);
}

void update_word_map_vectorized(Vectorized_dictionary_ptr vectorized_dictionary) {
    for (int i = 0; i < vectorized_dictionary->dictionary->words->size; i++) {
        Vectorized_word_ptr word = array_list_get(vectorized_dictionary->dictionary->words, i);
        int *index = malloc(sizeof(int));
        *index = i;
        hash_map_insert(vectorized_dictionary->dictionary->word_map, word->word->name, index);
    }
}

/**
 * The addWord method takes a {@link VectorizedWord} as an input and adds it to the words {@link ArrayList}.
 *
 * @param word {@link VectorizedWord} input.
 */
void add_word_vectorized(Vectorized_dictionary_ptr vectorized_dictionary, Vectorized_word_ptr vectorized_word) {
    array_list_add(vectorized_dictionary->dictionary->words, vectorized_word);
}

Vectorized_word_ptr get_word2(const Vectorized_dictionary *dictionary, const char *name) {
    if (word_exists(dictionary->dictionary, name)) {
        int index = *(int *) (hash_map_get(dictionary->dictionary->word_map, name));
        return array_list_get(dictionary->dictionary->words, index);
    }
    return NULL;
}
