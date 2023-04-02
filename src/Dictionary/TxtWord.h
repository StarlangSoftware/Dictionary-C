//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#ifndef DICTIONARY_TXTWORD_H
#define DICTIONARY_TXTWORD_H

#include "Word.h"
#include "HashMap/HashSet.h"

struct txt_word {
    Word_ptr word;
    Hash_set_ptr flags;
    char *morphology;
};

typedef struct txt_word Txt_word;
typedef Txt_word *Txt_word_ptr;

Txt_word_ptr create_txt_word(char *name);

Txt_word_ptr create_txt_word2(char *name, char *flag);

void free_txt_word(Txt_word_ptr txt_word);

void add_flag(Txt_word_ptr txt_word, char *flag);

void remove_flag(Txt_word_ptr txt_word, char *flag);

bool contains_flag(Txt_word_ptr txt_word, char *flag);

char *verb_type(Txt_word_ptr txt_word);

bool is_nominal(Txt_word_ptr txt_word);

bool is_passive(Txt_word_ptr txt_word);

bool is_abbreviation(Txt_word_ptr txt_word);

bool is_interjection(Txt_word_ptr txt_word);

bool is_duplicate(Txt_word_ptr txt_word);

bool is_code(Txt_word_ptr txt_word);

bool is_metric(Txt_word_ptr txt_word);

bool is_header(Txt_word_ptr txt_word);

bool is_adjective(Txt_word_ptr txt_word);

bool is_pure_adjective(Txt_word_ptr txt_word);

bool is_pronoun(Txt_word_ptr txt_word);

bool is_question(Txt_word_ptr txt_word);

bool is_verb(Txt_word_ptr txt_word);

bool is_portmanteau(Txt_word_ptr txt_word);

bool is_determiner(Txt_word_ptr txt_word);

bool is_conjunction(Txt_word_ptr txt_word);

bool is_adverb(Txt_word_ptr txt_word);

bool is_postp(Txt_word_ptr txt_word);

bool is_portmanteau_ending_with_si(Txt_word_ptr txt_word);

bool is_portmanteau_faced_vowel_ellipsis(Txt_word_ptr txt_word);

bool is_portmanteau_faced_softening(Txt_word_ptr txt_word);

bool is_suffix(Txt_word_ptr txt_word);

bool is_proper_noun(Txt_word_ptr txt_word);

bool is_plural(Txt_word_ptr txt_word);

bool is_numeral(Txt_word_ptr txt_word);

bool is_real(Txt_word_ptr txt_word);

bool is_fraction(Txt_word_ptr txt_word);

bool is_time2(Txt_word_ptr txt_word);

bool is_date(Txt_word_ptr txt_word);

bool is_percent(Txt_word_ptr txt_word);

bool is_range(Txt_word_ptr txt_word);

bool is_ordinal(Txt_word_ptr txt_word);

bool not_obeys_vowel_harmony_during_agglutination(Txt_word_ptr txt_word);

bool obeys_and_not_obeys_vowel_harmony_during_agglutination(Txt_word_ptr txt_word);

bool root_soften_during_suffixation(Txt_word_ptr txt_word);

bool root_soften_and_not_soften_during_suffixation(Txt_word_ptr txt_word);

bool verb_soften_during_suffixation(Txt_word_ptr txt_word);

bool noun_soften_during_suffixation(Txt_word_ptr txt_word);

bool ending_k_changes_into_g(Txt_word_ptr txt_word);

bool is_exceptional(Txt_word_ptr txt_word);

bool duplicates_during_suffixation(Txt_word_ptr txt_word);

bool duplicates_and_not_duplicates_during_suffixation(Txt_word_ptr txt_word);

bool last_i_drops_during_suffixation(Txt_word_ptr txt_word);

bool last_i_drops_and_not_drop_during_suffixation(Txt_word_ptr txt_word);

bool takes_relative_suffix_ki(Txt_word_ptr txt_word);

bool takes_relative_suffix_ku(Txt_word_ptr txt_word);

bool consonant_s_may_inserted_during_possesive_suffixation(Txt_word_ptr txt_word);

bool last_i_drops_during_passive_suffixation(Txt_word_ptr txt_word);

bool vowel_a_changes_to_i_during_y_suffixation(Txt_word_ptr txt_word);

bool vowel_e_changes_to_i_during_y_suffixation(Txt_word_ptr txt_word);

bool takes_suffix_ir_as_aorist(Txt_word_ptr txt_word);

bool takes_suffix_dir_as_factitive(Txt_word_ptr txt_word);

bool shows_su_regularities(Txt_word_ptr txt_word);

bool same_pos(Txt_word_ptr txt_word1, Txt_word_ptr txt_word2);

unsigned int hash_function_word(Txt_word_ptr word, int N);

int compare_txt_word(Txt_word_ptr first, Txt_word_ptr second);

#endif //DICTIONARY_TXTWORD_H
