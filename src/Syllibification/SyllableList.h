//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#ifndef DICTIONARY_SYLLABLELIST_H
#define DICTIONARY_SYLLABLELIST_H

#include <ArrayList.h>

struct syllable_list {
    Array_list_ptr syllables;
};

typedef struct syllable_list Syllable_list;
typedef Syllable_list *Syllable_list_ptr;

Syllable_list_ptr create_syllable_list(const char *word);

Array_list_ptr get_syllables(const Syllable_list* syllable_list);

void free_syllable_list(Syllable_list_ptr syllable_list);

#endif //DICTIONARY_SYLLABLELIST_H
