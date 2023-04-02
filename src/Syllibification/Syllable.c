//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#include <stdlib.h>
#include "Syllable.h"
#include "StringUtils.h"

Syllable_ptr create_syllable(char *syllable) {
    Syllable_ptr result = malloc(sizeof(Syllable));
    result->syllable = str_copy(result->syllable, syllable);
    return result;
}

void free_syllable(Syllable_ptr syllable) {
    free(syllable->syllable);
    free(syllable);
}

