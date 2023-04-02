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
int is_vowel(char *s) {
    return strstr(VOWELS, s) != NULL;
}

/**
 * The isBackVowel method takes a character as an input and returns true if given character is a back vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back vowel.
 */
int is_back_vowel(char *s) {
    return strstr(BACK_VOWELS, s) != NULL;
}

/**
 * The isFrontVowel method takes a character as an input and returns true if given character is a front vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front vowel.
 */
int is_front_vowel(char *s) {
    return strstr(FRONT_VOWELS, s) != NULL;
}

/**
 * The isBackRoundedVowel method takes a character as an input and returns true if given character is a back rounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back rounded vowel.
 */
int is_back_rounded_vowel(char *s) {
    return strstr(BACK_ROUNDED_VOWELS, s) != NULL;
}

/**
 * The isFrontRoundedVowel method takes a character as an input and returns true if given character is a front rounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front rounded vowel.
 */
int is_front_rounded_vowel(char *s) {
    return strstr(FRONT_ROUNDED_VOWELS, s) != NULL;
}

/**
 * The isBackUnroundedVowel method takes a character as an input and returns true if given character is a back unrounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a back unrounded vowel.
 */
int is_back_unrounded_vowel(char *s) {
    return strstr(BACK_UNROUNDED_VOWELS, s) != NULL;
}

/**
 * The isFrontUnroundedVowel method takes a character as an input and returns true if given character is a front unrounded vowel.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a front unrounded vowel.
 */
int is_front_unrounded_vowel(char *s) {
    return strstr(FRONT_UNROUNDED_VOWELS, s) != NULL;
}

/**
 * The isConsonantDrop method takes a character as an input and returns true if given character is a dropping consonant.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a dropping consonant.
 */
int is_consonant_drop(char *s) {
    return strstr(CONSONANT_DROPS, s) != NULL;
}

/**
 * The isConsonant method takes a character as an input and returns true if given character is a consonant.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a consonant.
 */
int is_consonant(char *s) {
    return strstr(CONSONANTS, s) != NULL;
}

/**
 * The isUppercase method takes a character as an input and returns true if given character is uppercase.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is uppercase.
 */
int is_uppercase(char *s) {
    return strstr(TURKISH_UPPERCASE_LETTERS, s) != NULL;
}

/**
 * The isSertSessiz method takes a character as an input and returns true if given character is a sert sessiz.
 *
 * @param ch {@link char} input to check.
 * @return true if given character is a sert sessiz.
 */
int is_sert_sessiz(char *s) {
    return strstr(SERT_SESSIZ, s) != NULL;
}
