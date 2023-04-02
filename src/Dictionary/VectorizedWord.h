//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#ifndef DICTIONARY_VECTORIZEDWORD_H
#define DICTIONARY_VECTORIZEDWORD_H

#include <Vector.h>
#include "Word.h"

struct vectorized_word {
    Word_ptr word;
    Vector_ptr vector;
};

typedef struct vectorized_word Vectorized_word;
typedef Vectorized_word *Vectorized_word_ptr;

Vectorized_word_ptr create_vectorized_word(char *name, Vector_ptr vector);

void free_vectorized_word(Vectorized_word_ptr vectorized_word);

int compare_vectorized_word(Vectorized_word_ptr first, Vectorized_word_ptr second);

#endif //DICTIONARY_VECTORIZEDWORD_H
