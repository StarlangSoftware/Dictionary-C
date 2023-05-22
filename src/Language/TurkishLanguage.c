//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#include <string.h>
#include "TurkishLanguage.h"

/**
 * The is_vowel method takes a character as an input and returns true if given character is a vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a vowel.
 */
bool is_vowel(const char *s) {
    return strstr(VOWELS, s) != NULL;
}

/**
 * The isBackVowel method takes a character as an input and returns true if given character is a back vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back vowel.
 */
bool is_back_vowel(const char *s) {
    return strstr(BACK_VOWELS, s) != NULL;
}

/**
 * The isFrontVowel method takes a character as an input and returns true if given character is a front vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front vowel.
 */
bool is_front_vowel(const char *s) {
    return strstr(FRONT_VOWELS, s) != NULL;
}

/**
 * The isBackRoundedVowel method takes a character as an input and returns true if given character is a back rounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back rounded vowel.
 */
bool is_back_rounded_vowel(const char *s) {
    return strstr(BACK_ROUNDED_VOWELS, s) != NULL;
}

/**
 * The isFrontRoundedVowel method takes a character as an input and returns true if given character is a front rounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front rounded vowel.
 */
bool is_front_rounded_vowel(const char *s) {
    return strstr(FRONT_ROUNDED_VOWELS, s) != NULL;
}

/**
 * The isBackUnroundedVowel method takes a character as an input and returns true if given character is a back unrounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back unrounded vowel.
 */
bool is_back_unrounded_vowel(const char *s) {
    return strstr(BACK_UNROUNDED_VOWELS, s) != NULL;
}

/**
 * The isFrontUnroundedVowel method takes a character as an input and returns true if given character is a front unrounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front unrounded vowel.
 */
bool is_front_unrounded_vowel(const char *s) {
    return strstr(FRONT_UNROUNDED_VOWELS, s) != NULL;
}

/**
 * The isConsonantDrop method takes a character as an input and returns true if given character is a dropping consonant.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a dropping consonant.
 */
bool is_consonant_drop(const char *s) {
    return strstr(CONSONANT_DROPS, s) != NULL;
}

/**
 * The isConsonant method takes a character as an input and returns true if given character is a consonant.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a consonant.
 */
bool is_consonant(const char *s) {
    return strstr(CONSONANTS, s) != NULL;
}

/**
 * The isUppercase method takes a character as an input and returns true if given character is uppercase.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is uppercase.
 */
bool is_uppercase(const char *s) {
    return strstr(TURKISH_UPPERCASE_LETTERS, s) != NULL;
}

/**
 * The isSertSessiz method takes a character as an input and returns true if given character is a sert sessiz.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a sert sessiz.
 */
bool is_sert_sessiz(const char *s) {
    return strstr(SERT_SESSIZ, s) != NULL;
}
