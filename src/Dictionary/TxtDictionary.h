//
// Created by Olcay Taner YILDIZ on 18.03.2023.
//

#ifndef DICTIONARY_TXTDICTIONARY_H
#define DICTIONARY_TXTDICTIONARY_H

#include "Dictionary.h"
#include "Trie/Trie.h"

struct txt_dictionary {
    Dictionary_ptr dictionary;
    Hash_map_ptr misspelled_words;
    char *file_name;
};

typedef struct txt_dictionary Txt_dictionary;
typedef Txt_dictionary *Txt_dictionary_ptr;

Txt_dictionary_ptr create_txt_dictionary3(char *file_name,
                                          char *misspelled_file_name,
                                          char *morphological_lexicon);

Txt_dictionary_ptr create_txt_dictionary2(char *file_name);

Txt_dictionary_ptr create_txt_dictionary();

void free_txt_dictionary(Txt_dictionary_ptr txt_dictionary);

void load_from_text(Txt_dictionary_ptr txt_dictionary);

int longest_word_size_txt(Txt_dictionary_ptr txt_dictionary);

void load_misspelled_words(Txt_dictionary_ptr txt_dictionary, char *misspelled_file_name);

void load_morphological_lexicon(Txt_dictionary_ptr txt_dictionary, char *file_name);

Txt_word_ptr get_word_txt(Txt_dictionary_ptr txt_dictionary, char *name);

void sort_txt(Txt_dictionary_ptr txt_dictionary);

void update_word_map_txt(Txt_dictionary_ptr txt_dictionary);

Txt_word_ptr get_word_with_index_txt(Txt_dictionary_ptr txt_dictionary, int index);

bool add_with_flag(Txt_dictionary_ptr txt_dictionary, char* name, char* flag);

int binary_search_txt(Txt_dictionary_ptr txt_dictionary, Txt_word_ptr txt_word);

void add_number(Txt_dictionary_ptr txt_dictionary, char* name);

void add_real_number(Txt_dictionary_ptr txt_dictionary, char* name);

void add_fraction(Txt_dictionary_ptr txt_dictionary, char* name);

void add_time(Txt_dictionary_ptr txt_dictionary, char* name);

void add_proper_noun(Txt_dictionary_ptr txt_dictionary, char* name);

void add_noun(Txt_dictionary_ptr txt_dictionary, char* name);

void add_verb(Txt_dictionary_ptr txt_dictionary, char* name);

void add_adjective(Txt_dictionary_ptr txt_dictionary, char* name);

void add_adverb(Txt_dictionary_ptr txt_dictionary, char* name);

void add_pronoun(Txt_dictionary_ptr txt_dictionary, char* name);

void add_word_when_root_soften(Trie_ptr trie, char* last, char* root, Txt_word_ptr word);

Trie_ptr prepare_trie(Txt_dictionary_ptr txt_dictionary);

char* get_correct_form(Txt_dictionary_ptr txt_dictionary, char* misspelled_word);

#endif //DICTIONARY_TXTDICTIONARY_H
