//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#include <stdlib.h>
#include "ExceptionalWord.h"

/**
 * A constructor of {@link ExceptionalWord} class which takes a {@link Pos} as a  part of speech and two Strings; name
 * and root as inputs. Then, calls its super class {@link Word} with given name and initialises root and pos variables
 * with given inputs.
 *
 * @param name String input.
 * @param root String input.
 * @param pos  {@link Pos} type input.
 */
Exceptional_word_ptr create_exceptional_word(char *name, char *root, Pos pos) {
    Exceptional_word_ptr result = malloc(sizeof(Exceptional_word));
    result->word = create_word(name);
    result->root = str_copy(result->root, root);
    result->pos = pos;
    return result;
}

void free_exceptional_word(Exceptional_word_ptr word) {
    free(word->root);
    free_word(word->word);
    free(word);
}
