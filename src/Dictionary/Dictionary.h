//
// Created by Olcay Taner YILDIZ on 5.03.2023.
//

#ifndef DICTIONARY_DICTIONARY_H
#define DICTIONARY_DICTIONARY_H

#include <HashMap/HashMap.h>
#include "TxtWord.h"

struct dictionary {
    Hash_map_ptr word_map;
    Array_list_ptr words;
};

typedef struct dictionary Dictionary;
typedef Dictionary *Dictionary_ptr;

Dictionary_ptr create_dictionary();

void free_dictionary(Dictionary_ptr dictionary);

Word_ptr get_word(const Dictionary* dictionary, const char *name);

void remove_word(Dictionary_ptr dictionary, const char *name);

int binary_search(const Dictionary* dictionary, const Word* word);

int get_word_index(const Dictionary* dictionary, const char *name);

bool word_exists(const Dictionary* dictionary, const char *name);

int size(const Dictionary* dictionary);

Word_ptr get_word_with_index(const Dictionary* dictionary, int index);

int longest_word_size(const Dictionary* dictionary);

int get_word_starting_with(const Dictionary* dictionary, const char *hash);

void update_word_map(Dictionary_ptr dictionary);

void sort(Dictionary_ptr dictionary);

#endif //DICTIONARY_DICTIONARY_H
