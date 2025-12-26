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
    Vectorized_dictionary_ptr result = malloc_(sizeof(Vectorized_dictionary));
    result->dictionary.words = create_array_list();
    result->dictionary.word_map = create_string_hash_map();
    return result;
}

/**
 * Frees memory allocated for the VectorizedDictionary. Frees words array, word_map hash map, dictionary, file_name.
 * @param vectorized_dictionary
 */
void free_vectorized_dictionary(Vectorized_dictionary_ptr vectorized_dictionary) {
    free_array_list(vectorized_dictionary->dictionary.words, (void (*)(void *)) free_vectorized_word);
    free_hash_map(vectorized_dictionary->dictionary.word_map, free_);
    free_(vectorized_dictionary->file_name);
}

/**
 * Another constructor of VectorizedDictionary class that takes an input file
 * containing the word vectors as input. Line j contains an array of numbers that represent the word vector for
 * that corresponding word at index j.
 * @param file_name Name of the input file that contains the word vectors
 */
Vectorized_dictionary_ptr create_vectorized_dictionary2(const char *file_name) {
    FILE* input_file;
    Vectorized_dictionary_ptr result = malloc_(sizeof(Vectorized_dictionary));
    result->dictionary.words = create_array_list();
    result->dictionary.word_map = create_string_hash_map();
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
            add_word((Dictionary_ptr)result, (Word_ptr)currentWord);
        }
        free_array_list(tokens, free_);
    }
    fclose(input_file);
    sort((Dictionary_ptr)result);
    return result;
}