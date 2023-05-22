//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#include <stdlib.h>
#include <HashMap/HashMap.h>
#include "VectorizedWord.h"

Vectorized_word_ptr create_vectorized_word(const char *name, Vector_ptr vector) {
    Vectorized_word_ptr result = malloc(sizeof(Vectorized_word));
    result->word = create_word(name);
    result->vector = vector;
    return result;
}

void free_vectorized_word(Vectorized_word_ptr vectorized_word) {
    free_word(vectorized_word->word);
    free(vectorized_word);
}

int compare_vectorized_word(const Vectorized_word* first, const Vectorized_word* second) {
    return compare_string(first->word->name, second->word->name);
}
