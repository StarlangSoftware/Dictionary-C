//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#include <stdlib.h>
#include <HashMap/HashMap.h>
#include <Memory/Memory.h>
#include "VectorizedWord.h"

Vectorized_word_ptr create_vectorized_word(const char *name, Vector_ptr vector) {
    Vectorized_word_ptr result = malloc_(sizeof(Vectorized_word), "create_vectorized_word");
    result->word = str_copy(result->word, name);
    result->vector = vector;
    return result;
}

void free_vectorized_word(Vectorized_word_ptr vectorized_word) {
    free_vector(vectorized_word->vector);
    free_(vectorized_word->word);
    free_(vectorized_word);
}

int compare_vectorized_word(const Vectorized_word* first, const Vectorized_word* second) {
    return compare_string(first->word, second->word);
}
