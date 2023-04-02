//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#ifndef DICTIONARY_WORD_H
#define DICTIONARY_WORD_H

#include "StringUtils.h"

struct word {
    char *name;
};

typedef struct word Word;
typedef Word *Word_ptr;

Word_ptr create_word(char *name);

void free_word(Word_ptr word);

int word_size(char *surface_form);

String_ptr char_at(char *surface_form, int index);

int char_count(Word_ptr word);

bool starts_with(char *large_string, char *small_string);

char *to_lowercase(char *surface_form);

char *to_uppercase(char *surface_form);

Array_list_ptr all_characters(char *surface_form);

String_ptr substring(char *surface_form, int index, int length);

String_ptr substring2(char *surface_form, int index);

String_ptr substring3(char *surface_form, const char *end);

String_ptr before_last_vowel(char *stem);

String_ptr last_vowel(char *stem);

String_ptr last_phoneme(char *stem);

String_ptr last_char(char *surface_form);

bool is_capital(char *surface_form);

bool is_punctuation(char *surface_form);

bool is_honorific(char *surface_form);

bool is_organization(char *surface_form);

bool is_money(char *surface_form);

Array_list_ptr to_characters(char *surface_form);

bool is_time(char *surface_form);

bool ends_with(char *large_string, char *small_string);

String_ptr to_capital(char *surface_form);

Array_list_ptr split(char *line);

Array_list_ptr split_with_char(char *line, char *separators);

String_ptr substring_except_last_char(char *surface_form);

String_ptr substring_except_last_two_chars(char *surface_form);

String_ptr trim(char *surface_form);

int compare_word(Word_ptr first, Word_ptr second);

#endif //DICTIONARY_WORD_H
