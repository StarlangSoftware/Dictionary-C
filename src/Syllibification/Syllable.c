//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#include <Memory/Memory.h>
#include "Syllable.h"
#include "StringUtils.h"

/**
 * A constructor of Syllable class which takes a String as an input and initializes _syllable variable with given input.
 *
 * @param syllable String input.
 */
Syllable_ptr create_syllable(const char *syllable) {
    Syllable_ptr result = malloc_(sizeof(Syllable));
    result->syllable = str_copy(result->syllable, syllable);
    return result;
}

/**
 * Freees memory allocated for a single syllable.
 * @param syllable Syllable.
 */
void free_syllable(Syllable_ptr syllable) {
    free_(syllable->syllable);
    free_(syllable);
}

