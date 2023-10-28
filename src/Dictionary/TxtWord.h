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

Txt_word_ptr create_txt_word(const char *name);

Txt_word_ptr create_txt_word2(const char *name, char *flag);

Txt_word_ptr clone_txt_word(Txt_word_ptr word);

void free_txt_word(Txt_word_ptr txt_word);

void add_flag(Txt_word_ptr txt_word, char *flag);

void remove_flag(Txt_word_ptr txt_word, char *flag);

bool contains_flag(const Txt_word* txt_word, const char *flag);

char *verb_type(const Txt_word* txt_word);

bool is_nominal(const Txt_word* txt_word);

bool is_passive(const Txt_word* txt_word);

bool is_abbreviation(const Txt_word* txt_word);

bool is_interjection(const Txt_word* txt_word);

bool is_duplicate(const Txt_word* txt_word);

bool is_code(const Txt_word* txt_word);

bool is_metric(const Txt_word* txt_word);

bool is_header(const Txt_word* txt_word);

bool is_adjective(const Txt_word* txt_word);

bool is_pure_adjective(const Txt_word* txt_word);

bool is_pronoun(const Txt_word* txt_word);

bool is_question(const Txt_word* txt_word);

bool is_verb(const Txt_word* txt_word);

bool is_portmanteau(const Txt_word* txt_word);

bool is_determiner(const Txt_word* txt_word);

bool is_conjunction(const Txt_word* txt_word);

bool is_adverb(const Txt_word* txt_word);

bool is_postp(const Txt_word* txt_word);

bool is_portmanteau_ending_with_si(const Txt_word* txt_word);

bool is_portmanteau_faced_vowel_ellipsis(const Txt_word* txt_word);

bool is_portmanteau_faced_softening(const Txt_word* txt_word);

bool is_suffix(const Txt_word* txt_word);

bool is_proper_noun(const Txt_word* txt_word);

bool is_plural(const Txt_word* txt_word);

bool is_numeral(const Txt_word* txt_word);

bool is_real(const Txt_word* txt_word);

bool is_fraction(const Txt_word* txt_word);

bool is_time2(const Txt_word* txt_word);

bool is_date(const Txt_word* txt_word);

bool is_percent(const Txt_word* txt_word);

bool is_range(const Txt_word* txt_word);

bool is_ordinal(const Txt_word* txt_word);

bool not_obeys_vowel_harmony_during_agglutination(const Txt_word* txt_word);

bool obeys_and_not_obeys_vowel_harmony_during_agglutination(const Txt_word* txt_word);

bool root_soften_during_suffixation(const Txt_word* txt_word);

bool root_soften_and_not_soften_during_suffixation(const Txt_word* txt_word);

bool verb_soften_during_suffixation(const Txt_word* txt_word);

bool noun_soften_during_suffixation(const Txt_word* txt_word);

bool ending_k_changes_into_g(const Txt_word* txt_word);

bool is_exceptional(const Txt_word* txt_word);

bool duplicates_during_suffixation(const Txt_word* txt_word);

bool duplicates_and_not_duplicates_during_suffixation(const Txt_word* txt_word);

bool last_i_drops_during_suffixation(const Txt_word* txt_word);

bool last_i_drops_and_not_drop_during_suffixation(const Txt_word* txt_word);

bool takes_relative_suffix_ki(const Txt_word* txt_word);

bool takes_relative_suffix_ku(const Txt_word* txt_word);

bool consonant_s_may_inserted_during_possesive_suffixation(const Txt_word* txt_word);

bool last_i_drops_during_passive_suffixation(const Txt_word* txt_word);

bool vowel_a_changes_to_i_during_y_suffixation(const Txt_word* txt_word);

bool vowel_e_changes_to_i_during_y_suffixation(const Txt_word* txt_word);

bool takes_suffix_ir_as_aorist(const Txt_word* txt_word);

bool takes_suffix_dir_as_factitive(const Txt_word* txt_word);

bool shows_su_regularities(const Txt_word* txt_word);

bool same_pos(const Txt_word* txt_word1, const Txt_word* txt_word2);

unsigned int hash_function_txt_word(const Txt_word* word, int N);

int compare_txt_word(const Txt_word* first, const Txt_word* second);

#endif //DICTIONARY_TXTWORD_H
