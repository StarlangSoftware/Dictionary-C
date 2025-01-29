//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#include <HashMap/HashMap.h>
#include <Memory/Memory.h>
#include "VectorizedWord.h"

/**
 * A constructor of VectorizedWord class which takes a String and a Vector as inputs and initializes name and vector
 * variable with given input.
 *
 * @param name   String input.
 * @param vector Vector type input.
 */
Vectorized_word_ptr create_vectorized_word(const char *name, Vector_ptr vector) {
    Vectorized_word_ptr result = malloc_(sizeof(Vectorized_word), "create_vectorized_word");
    result->word = str_copy(result->word, name);
    result->vector = vector;
    return result;
}

/**
 * Frees memory allocated for the vectorized word. Frees vector and name.
 * @param vectorized_word Vectorized word to be freed.
 */
void free_vectorized_word(Vectorized_word_ptr vectorized_word) {
    free_vector(vectorized_word->vector);
    free_(vectorized_word->word);
    free_(vectorized_word);
}

/**
 * Comparator function for two VectorizedWords. Comparator function to compare two strings lexicographically. Uses
 * compare_string for the comparison.
 * @param first First VectorizedWord to compare
 * @param second Second VectorizedWord to compare
 * @return An integer greater than, equal to, or less than 0, according as the string first is greater than, equal to,
 * or less than the string second.
 */
int compare_vectorized_word(const Vectorized_word* first, const Vectorized_word* second) {
    return compare_string(first->word, second->word);
}
