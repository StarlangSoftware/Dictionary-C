//
// Created by Olcay Taner YILDIZ on 2.04.2023.
//

#ifndef DICTIONARY_VECTORIZEDDICTIONARY_H
#define DICTIONARY_VECTORIZEDDICTIONARY_H

#include "Dictionary.h"
#include "VectorizedWord.h"

struct vectorized_dictionary {
    Dictionary dictionary;
    char *file_name;
};

typedef struct vectorized_dictionary Vectorized_dictionary;
typedef Vectorized_dictionary *Vectorized_dictionary_ptr;

Vectorized_dictionary_ptr create_vectorized_dictionary();

void free_vectorized_dictionary(Vectorized_dictionary_ptr vectorized_dictionary);

Vectorized_dictionary_ptr create_vectorized_dictionary2(const char* file_name);

void sort_vectorized(Vectorized_dictionary_ptr vectorized_dictionary);

void update_word_map_vectorized(Vectorized_dictionary_ptr vectorized_dictionary);

void add_word_vectorized(Vectorized_dictionary_ptr vectorized_dictionary, Vectorized_word_ptr vectorized_word);

Vectorized_word_ptr get_word2(const Vectorized_dictionary* dictionary, const char *name);

#endif //DICTIONARY_VECTORIZEDDICTIONARY_H
