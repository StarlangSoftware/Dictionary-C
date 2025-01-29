//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#ifndef DICTIONARY_WORD_H
#define DICTIONARY_WORD_H

#include "StringUtils.h"

#define MAX_WORD_LENGTH 1024

int word_size(const char *surface_form);

String_ptr char_at(const char *surface_form, int index);

int char_count(const char* word);

bool starts_with(const char *large_string, const char *small_string);

char *to_lowercase(const char *surface_form);

char *to_uppercase(const char *surface_form);

Array_list_ptr all_characters(const char *surface_form);

String_ptr substring(const char *surface_form, int index, int length);

String_ptr substring2(const char *surface_form, int index);

String_ptr substring3(const char *surface_form, const char *end);

String_ptr before_last_vowel(const char *stem);

String_ptr last_vowel(const char *stem);

String_ptr last_phoneme(const char *stem);

String_ptr last_char(const char *surface_form);

bool is_capital(const char *surface_form);

bool is_punctuation(const char *surface_form);

bool is_honorific(const char *surface_form);

bool is_organization(const char *surface_form);

bool is_money(const char *surface_form);

Array_list_ptr to_characters(const char *surface_form);

bool is_time(const char *surface_form);

bool ends_with(const char *large_string, const char *small_string);

String_ptr to_capital(const char *surface_form);

Array_list_ptr split(char *line);

Array_list_ptr split_with_char(char *line, const char *separators);

String_ptr substring_except_last_char(const char *surface_form);

String_ptr substring_except_last_two_chars(const char *surface_form);

String_ptr trim(const char *surface_form);

int str_find_c(const char* surface_form, const char* ch);

int str_find_last_c(const char* surface_form, const char* ch);

char* replace_all(const char* str, const char *from, const char *to);

char* reverse_string(const char* st);

#endif //DICTIONARY_WORD_H
