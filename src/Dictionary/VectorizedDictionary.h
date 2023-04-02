//
// Created by Olcay Taner YILDIZ on 2.04.2023.
//

#ifndef DICTIONARY_VECTORIZEDDICTIONARY_H
#define DICTIONARY_VECTORIZEDDICTIONARY_H

#include "Dictionary.h"
#include "VectorizedWord.h"

struct vectorized_dictionary {
    Dictionary_ptr dictionary;
    char *file_name;
};

typedef struct vectorized_dictionary Vectorized_dictionary;
typedef Vectorized_dictionary *Vectorized_dictionary_ptr;

Vectorized_dictionary_ptr create_vectorized_dictionary();
void free_vectorized_dictionary(Vectorized_dictionary_ptr vectorized_dictionary);
Vectorized_dictionary_ptr create_vectorized_dictionary2(char* file_name);
void sort_vectorized(Vectorized_dictionary_ptr vectorized_dictionary);
void update_word_map_vectorized(Vectorized_dictionary_ptr vectorized_dictionary);
void add_word_vectorized(Vectorized_dictionary_ptr vectorized_dictionary, Vectorized_word_ptr vectorized_word);

#endif //DICTIONARY_VECTORIZEDDICTIONARY_H
