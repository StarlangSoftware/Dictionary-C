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

Word_ptr get_word(Dictionary_ptr dictionary, char *name);

void remove_word(Dictionary_ptr dictionary, char *name);

int binary_search(Dictionary_ptr dictionary, Word_ptr word);

int get_word_index(Dictionary_ptr dictionary, char *name);

bool word_exists(Dictionary_ptr dictionary, char *name);

int size(Dictionary_ptr dictionary);

Word_ptr get_word_with_index(Dictionary_ptr dictionary, int index);

int longest_word_size(Dictionary_ptr dictionary);

int get_word_starting_with(Dictionary_ptr dictionary, char *hash);

void update_word_map(Dictionary_ptr dictionary);

void sort(Dictionary_ptr dictionary);

#endif //DICTIONARY_DICTIONARY_H
