//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#ifndef DICTIONARY_TURKISHLANGUAGE_H
#define DICTIONARY_TURKISHLANGUAGE_H

#include <stdbool.h>

static char *VOWELS = "aeıioöuüâî";
static char *BACK_VOWELS = "aıouâ";
static char *FRONT_VOWELS = "eiöüî";
static char *BACK_ROUNDED_VOWELS = "ou";
static char *BACK_UNROUNDED_VOWELS = "aıâ";
static char *FRONT_ROUNDED_VOWELS = "öü";
static char *FRONT_UNROUNDED_VOWELS = "eiî";
static char *CONSONANT_DROPS = "nsy";
static char *CONSONANTS = "bcçdfgğhjklmnprsştvyzxqw";
static char *SERT_SESSIZ = "çfhkpsşt";
static char *TURKISH_LOWERCASE_LETTERS = "abcçdefgğhıijklmnoöprsştuüvyz";
static char *TURKISH_UPPERCASE_LETTERS = "ABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";
static char *LETTERS = "abcçdefgğhıijklmnoöprsştuüvyzABCÇDEFGĞHIİJKLMNOÖPRSŞTUÜVYZ";

bool is_vowel(const char *s);

bool is_back_vowel(const char *s);

bool is_front_vowel(const char *s);

bool is_back_rounded_vowel(const char *s);

bool is_front_rounded_vowel(const char *s);

bool is_back_unrounded_vowel(const char *s);

bool is_front_unrounded_vowel(const char *s);

bool is_consonant_drop(const char *s);

bool is_consonant(const char *s);

bool is_uppercase(const char *s);

bool is_sert_sessiz(const char *s);

#endif //DICTIONARY_TURKISHLANGUAGE_H
