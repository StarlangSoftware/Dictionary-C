//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#ifndef DICTIONARY_EXCEPTIONALWORD_H
#define DICTIONARY_EXCEPTIONALWORD_H

#include "Word.h"
#include "Pos.h"

struct exceptional_word {
    Word_ptr word;
    char *root;
    Pos pos;
};

typedef struct exceptional_word Exceptional_word;
typedef Exceptional_word *Exceptional_word_ptr;

Exceptional_word_ptr create_exceptional_word(char *name, char *root, Pos pos);

void free_exceptional_word(Exceptional_word_ptr word);

#endif //DICTIONARY_EXCEPTIONALWORD_H
