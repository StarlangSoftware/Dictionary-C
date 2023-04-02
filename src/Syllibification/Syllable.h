//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#ifndef DICTIONARY_SYLLABLE_H
#define DICTIONARY_SYLLABLE_H

struct syllable {
    char *syllable;
};

typedef struct syllable Syllable;
typedef Syllable *Syllable_ptr;

Syllable_ptr create_syllable(char *syllable);

void free_syllable(Syllable_ptr syllable);

#endif //DICTIONARY_SYLLABLE_H
