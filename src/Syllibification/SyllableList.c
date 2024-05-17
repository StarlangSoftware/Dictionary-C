//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <Memory/Memory.h>
#include "SyllableList.h"
#include "../Dictionary/Word.h"
#include "../Language/TurkishLanguage.h"
#include "Syllable.h"

/**
 * A constructor of SyllableList class which takes a String word as an input. First it creates a syllable vector
 * and a string sbSyllable. Then it loops i times, where i ranges from 0 to length of given word, first
 * it gets the ith character of given word and checks whether it is a vowel and the last character of the word.
 * <p>
 * If it is a vowel it appends it to the sbSyllable and if it is the last vowel it also appends the next character to the sbSyllable.
 * Then, it adds the sbSyllable tot he syllables vector.
 * <p>
 * If it is not a vowel, and the sbSyllable's length is 1 also the previous character is a consonant it gets the last item of
 * syllables vector since there cannot be a Turkish word which starts with two consonants. However, if it is
 * two last characters of word, then it adds it to the syllable ArrayList. At the end, it updatse the syllables vector.
 *
 * @param word String input.
 */
Syllable_list_ptr create_syllable_list(const char *word) {
    Syllable_list_ptr result = malloc_(sizeof(Syllable_list), "create_syllable_list");
    String_ptr sbSyllable = create_string();
    result->syllables = create_array_list();
    for (int i = 0; i < word_size(word); i++) {
        String_ptr c = char_at(word, i);
        int isVowel = is_vowel(c->s);
        int isLastChar = i == word_size(word) - 1;
        if (isVowel) {
            string_append(sbSyllable, c->s);
            // If it is the last vowel.
            if (i == word_size(word) - 2) {
                String_ptr ch = char_at(word, i + 1);
                string_append(sbSyllable, ch->s);
                free_string_ptr(ch);
                i++;
            }
            array_list_add(result->syllables, create_syllable(sbSyllable->s));
            clean_string(sbSyllable);
        } else {
            // A syllable should not start with two consonants.
            char *tempSyl = string_copy(sbSyllable);
            if (word_size(tempSyl) == 1) {
                // The previous character was also a consonant.
                String_ptr ch = char_at(tempSyl, 0);
                if (!is_vowel(ch->s)) {
                    if (result->syllables->size == 0) {
                        string_append(sbSyllable, c->s);
                        free_string_ptr(c);
                        free_string_ptr(ch);
                        free_(tempSyl);
                        continue;
                    }
                    int lastPos = result->syllables->size - 1;
                    String_ptr str = create_string2(
                            ((Syllable_ptr) array_list_get(result->syllables, lastPos))->syllable);
                    string_append(str, tempSyl);
                    if (isLastChar) {
                        // If the last char is also a consonant, add it to latest syllable. Ex: 'park'.
                        string_append(str, c->s);
                    }
                    // Update previous syllable.
                    array_list_replace(result->syllables,
                                       lastPos,
                                       create_syllable(str->s),
                                       (void (*)(void *)) free_syllable);
                    clean_string(sbSyllable);
                    free_string_ptr(str);
                }
                free_string_ptr(ch);
            }
            free_(tempSyl);
            string_append(sbSyllable, c->s);
        }
        free_string_ptr(c);
    }
    free_string_ptr(sbSyllable);
    return result;
}

/**
 * The getSyllables method creates a new vector syllables and loops through the globally defined syllables
 * vector and adds each item to the newly created syllables vector.
 *
 * @return vector syllables.
 */
Array_list_ptr get_syllables(const Syllable_list* syllable_list) {
    Array_list_ptr result = create_array_list();
    for (int i = 0; i < syllable_list->syllables->size; i++) {
        array_list_add(result, ((Syllable_ptr) array_list_get(syllable_list->syllables, i))->syllable);
    }
    return result;
}

/**
 * Frees memory allocated for the syllable list.
 * @param syllable_list Syllable list to be freed.
 */
void free_syllable_list(Syllable_list_ptr syllable_list) {
    free_array_list(syllable_list->syllables, (void (*)(void *)) free_syllable);
    free_(syllable_list);
}
