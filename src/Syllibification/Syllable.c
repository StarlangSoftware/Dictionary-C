//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#include <stdlib.h>
#include <Memory/Memory.h>
#include "Syllable.h"
#include "StringUtils.h"

Syllable_ptr create_syllable(const char *syllable) {
    Syllable_ptr result = malloc_(sizeof(Syllable), "create_syllable");
    result->syllable = str_copy(result->syllable, syllable);
    return result;
}

void free_syllable(Syllable_ptr syllable) {
    free_(syllable->syllable);
    free_(syllable);
}

