//
// Created by Olcay Taner YILDIZ on 4.03.2023.
//

#include <stdlib.h>
#include "TxtWord.h"

/**
 * A constructor of TxtWord class which takes a String name as an input and calls its super class Word
 * with given name.
 *
 * @param name String name.
 */
Txt_word_ptr create_txt_word(const char *name) {
    Txt_word_ptr result = malloc(sizeof(Txt_word));
    result->word = create_word(name);
    result->flags = create_hash_set((unsigned int (*)(const void *, int)) hash_function_string,
                                    (int (*)(const void *, const void *)) compare_string);
    result->morphology = NULL;
    return result;
}

void free_txt_word(Txt_word_ptr txt_word) {
    free_word(txt_word->word);
    if (txt_word->morphology != NULL) {
        free(txt_word->morphology);
    }
    free_hash_set(txt_word->flags, NULL);
    free(txt_word);
}

/**
 * The addFlag method takes a String flag as an input and adds given flag to the flags hash set.
 *
 * @param flag String input to add.
 */
void add_flag(Txt_word_ptr txt_word, char *flag) {
    hash_set_insert(txt_word->flags, flag);
}

/**
 * Another constructor of TxtWord class which takes a String name and a flag as inputs and calls its super class Word
 * with given name. Then, calls addFlag method with given flag.
 *
 * @param name String input.
 * @param flag String input.
 */
Txt_word_ptr create_txt_word2(const char *name, char *flag) {
    Txt_word_ptr result = create_txt_word(name);
    add_flag(result, flag);
    return result;
}

/**
 * The removeFlag method takes a String flag as an input and removes given flag from the flags {@link unordered_set}.
 *
 * @param flag String input to remove.
 */
void remove_flag(Txt_word_ptr txt_word, char *flag) {
    hash_set_remove(txt_word->flags, flag, NULL);
}

/**
 * The containsFlag method returns true if flags {@link unordered_set} contains flag.
 *
 * @return true if flags {@link unordered_set} contains flag.
 */
bool contains_flag(const Txt_word* txt_word, const char *flag) {
    return hash_set_contains(txt_word->flags, flag);
}

/**
 * The verbType method checks flags {@link unordered_set} and returns the corresponding cases.
 *
 * @return the corresponding cases.
 */
char *verb_type(const Txt_word* txt_word) {
    if (contains_flag(txt_word, "F1P1-NO-REF")) {
        /**
         *There is no example in the Turkish dictionary.
         */
        return "F1P1-NO-REF";
    }
    if (contains_flag(txt_word, "F2P1-NO-REF")) {
        /**
         *F2P1-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeT suffix. e.g. Doğ, göç, için
         */
        return "F2P1-NO-REF";
    }
    if (contains_flag(txt_word, "F3P1-NO-REF")) {
        /**
         *F3P1-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take Passive Hl suffix,
         *can take CausativeT suffix. e.g. Ak
         */
        return "F3P1-NO-REF";
    }
    if (contains_flag(txt_word, "F4P1-NO-REF")) {
        /**
         *F4P1-NO-REF: The bare-form is a verb and depending on this attribute, the verb can't take PassiveHn suffix, can take CausativeT suffix.
         *e.g. Aksa
         */
        return "F4P1-NO-REF";
    }
    if (contains_flag(txt_word, "F4PR-NO-REF")) {
        /**
         *F4PR-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeT suffix. e.g. Çevir, göster
         */
        return "F4PR-NO-REF";
    }
    if (contains_flag(txt_word, "F4PL-NO-REF")) {
        /**
         *F4PL-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix,
         *can take CausativeT suffix. e.g. Azal, çoğal
         */
        return "F4PL-NO-REF";
    }
    if (contains_flag(txt_word, "F4PW-NO-REF")) {
        /**
         *F4PW-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveN suffix,
         *can take CausativeT suffix. e.g. Birle, boya
         */
        return "F4PW-NO-REF";
    }
    if (contains_flag(txt_word, "F5PL-NO-REF")) {
        /**
         *F5PL-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix,
         *can take CausativeDHr suffix. e.g. Çal, kal
         */
        return "F5PL-NO-REF";
    }
    if (contains_flag(txt_word, "F5PR-NO-REF")) {
        /**
         *F5PR-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeDHr suffix. e.g. Birleş, çöz
         */
        return "F5PR-NO-REF";
    }
    if (contains_flag(txt_word, "F5PW-NO-REF")) {
        /**
         *F5PW-NO-REF: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeDHr suffix. e.g. Ye
         */
        return "F5PW-NO-REF";
    }
    if (contains_flag(txt_word, "F1P1")) {
        /**
         *F1P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeAr suffix, can take ReciprocalHs suffix. e.g. Çık, kop
         */
        return "F1P1";
    }
    if (contains_flag(txt_word, "F2P1")) {
        /**
         *F2P1: The bare-form is a verb and depending on this attribute, the verb can can not PassiveHn suffix, can take CausativeHr suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix. e.g. Bit, doy, düş
         */
        return "F2P1";
    }
    if (contains_flag(txt_word, "F2PL")) {
        /**
         *F2PL: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take CausativeHr suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix. e.g. Art, çök
         */
        return "F2PL";
    }
    if (contains_flag(txt_word, "F3P1")) {
        /**
         *F3P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeHl suffix, can take ReciprocalHs suffix. e.g. Kok, sark
         */
        return "F3P1";
    }
    if (contains_flag(txt_word, "F4P1")) {
        /**
         *F4P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix,
         *can take CausativeT suffix, can take ReciprocalHs suffix. e.g. Anla
         */
        return "F4P1";
    }
    if (contains_flag(txt_word, "F4PR")) {
        /**
         *F4PR: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeT suffix, can take ReciprocalHs suffix. e.g. Bitir, çağır
         */
        return "F4PR";
    }
    if (contains_flag(txt_word, "F4PL")) {
        /**
         *F4PL: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveN suffix,
         *can take CausativeT suffix, can take ReciprocalHs suffix. e.g. Bolal, çömel
         */
        return "F4PL";
    }
    if (contains_flag(txt_word, "F4PW")) {
        /**
         *F4PW: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveN suffix,
         *can take CausativeT suffix, can take ReciprocalHs suffix. e.g. Boyla, çağla
         */
        return "F4PW";
    }
    if (contains_flag(txt_word, "F5P1")) {
        /**
         *F5P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix, can take ReflexiveHn suffix. e.g. Giy
         */
        return "F5P1";
    }
    if (contains_flag(txt_word, "F5PL")) {
        /**
         *F5PL: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveHl suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix. e.g. Böl, dal
         */
        return "F5PL";
    }
    if (contains_flag(txt_word, "F5PR")) {
        /**
         *F5PR: The bare-form is a verb and depending on this attribute, the verb can take NominalVerb suffixes "-sHm, -SHn, -yHz, SHnHz, -lAr",
         *can take NominalVerb1 suffixes, "-yDH, -ysA
         ", can take NominalVerb2 suffix, "-ymHs", can take AdjectiveRoot suffix, "-SH",
         *can take Adjective suffix, "-ŞAr" e.g. Bilin, çalış
         */
        return "F5PR";
    }
    if (contains_flag(txt_word, "F5PW")) {
        /**
         *F5PW: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix,
         *can take CausativeDHr suffix, can take ReciprocalHs suffix. e.g. Boşver, cezbet
         */
        return "F5PW";
    }
    if (contains_flag(txt_word, "F6P1")) {
        /**
         *F6P1: The bare-form is a verb and depending on this attribute, the verb can not take PassiveHn suffix, can take PassiveN suffix,
         *can take ReciprocalHs suffix, can take ReflexiveHn suffix. e.g. Gizle, hazırla, kaşı
         */
        return "F6P1";
    }
    return NULL;
}

/**
 * The isNominal method returns true if flags {@link unordered_set} contains CL_ISIM.
 *
 * @return true if flags {@link unordered_set} contains CL_ISIM.
 */
bool is_nominal(const Txt_word* txt_word) {
    return contains_flag(txt_word, "CL_ISIM");
}

/**
 * The isPassive method returns true if flags {@link unordered_set} contains PASSIVE-HN.
 *
 * @return true if flags {@link unordered_set} contains PASSIVE-HN.
 */
bool is_passive(const Txt_word* txt_word) {
    return contains_flag(txt_word, "PASSIVE-HN");
}

/**
 * The isAbbreviation method returns true if flags {@link unordered_set} contains IS_KIS.
 *
 * @return true if flags {@link unordered_set} contains IS_KIS.
 */
bool is_abbreviation(const Txt_word* txt_word) {
    /**
     *IS_KIS: The bare-form of the word is an abbrevation which does not obey
     *vowel harmony while taking suffixes. Örn. Ab
     */
    return contains_flag(txt_word, "IS_KIS");
}

/**
 * The isInterjection method returns true if flags {@link unordered_set} contains IS_INTERJ.
 *
 * @return true if flags {@link unordered_set} contains IS_INTERJ.
 */
bool is_interjection(const Txt_word* txt_word) {
    /**
     *IS_INTERJ: An interjection is a part of speech that shows the emotion or feeling. e.g. Ah, aferin
     */
    return contains_flag(txt_word, "IS_INTERJ");
}

/**
 * The isDuplicate method returns true if flags {@link unordered_set} contains IS_DUP.
 *
 * @return true if flags {@link unordered_set} contains IS_DUP.
 */
bool is_duplicate(const Txt_word* txt_word) {
    /**
     *IS_DUP: The bare-form is part of a duplicate form. e.g. Abuk
     */
    return contains_flag(txt_word, "IS_DUP");
}

/**
 * The isCode method returns true if flags {@link unordered_set} contains IS_CODE.
 *
 * @return true if flags {@link unordered_set} contains IS_CODE.
 */
bool is_code(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_CODE");
}

/**
 * The isMetric method returns true if flags {@link unordered_set} contains IS_METRIC.
 *
 * @return true if flags {@link unordered_set} contains IS_METRIC.
 */
bool is_metric(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_METRIC");
}

/**
 * The isHeader method returns true if flags {@link unordered_set} contains IS_HEADER.
 *
 * @return true if flags {@link unordered_set} contains IS_HEADER.
 */
bool is_header(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_HEADER");
}

/**
 * The isAdjective method returns true if flags {@link unordered_set} contains IS_ADJ.
 *
 * @return true if flags {@link unordered_set} contains IS_ADJ.
 */
bool is_adjective(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_ADJ");
}

/**
 * The isPureAdjective method returns true if flags {@link unordered_set} contains IS_PUREADJ.
 *
 * @return true if flags {@link unordered_set} contains IS_PUREADJ.
 */
bool is_pure_adjective(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_PUREADJ");
}

/**
 * The isPronoun method returns true if flags {@link unordered_set} contains IS_ZM.
 *
 * @return true if flags {@link unordered_set} contains IS_ZM.
 */
bool is_pronoun(const Txt_word* txt_word) {
    /*
     *IS_ZM: The bare-form of the word is a pronoun. e.g. Hangi, hep, hiçbiri
     */
    return contains_flag(txt_word, "IS_ZM");
}

/**
 * The isQuestion method returns true if flags {@link unordered_set} contains IS_QUES.
 *
 * @return true if flags {@link unordered_set} contains IS_QUES.
 */
bool is_question(const Txt_word* txt_word) {
    /*The bare-form of the word is a question. e.g. Mi, mu, mü
     */
    return contains_flag(txt_word, "IS_QUES");
}

/**
 * The isVerb method returns true if flags {@link unordered_set} contains CL_FIIL.
 *
 * @return true if flags {@link unordered_set} contains CL_FIIL.
 */
bool is_verb(const Txt_word* txt_word) {
    return contains_flag(txt_word, "CL_FIIL");
}

/**
 * The isPortmanteau method returns true if flags {@link unordered_set} contains IS_BILEŞ.
 *
 * @return true if flags {@link unordered_set} contains IS_BILEŞ.
 */
bool is_portmanteau(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_BILEŞ");
}

/**
 * The isDeterminer method returns true if flags {@link unordered_set} contains IS_DET.
 *
 * @return true if flags {@link unordered_set} contains IS_DET.
 */
bool is_determiner(const Txt_word* txt_word) {
    /*
     *IS_DET: The bare-form of the word is a determiner. e.g. Bazı, bir
     */
    return contains_flag(txt_word, "IS_DET");
}

/**
 * The isConjunction method returns true if flags {@link unordered_set} contains IS_CONJ.
 *
 * @return true if flags {@link unordered_set} contains IS_CONJ.
 */
bool is_conjunction(const Txt_word* txt_word) {
    /*
     *IS_CONJ: The bare-form of the word is a conjunction. e.g. Gerek, halbuki
     */
    return contains_flag(txt_word, "IS_CONJ");
}

/**
 * The isAdverb method returns true if flags {@link unordered_set} contains IS_ADVERB.
 *
 * @return true if flags {@link unordered_set} contains IS_ADVERB.
 */
bool is_adverb(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_ADVERB");
}

/**
 * The isPostP method returns true if flags {@link unordered_set} contains IS_POSTP.
 *
 * @return true if flags {@link unordered_set} contains IS_POSTP.
 */
bool is_postp(const Txt_word* txt_word) {
    /*
     *The bare-form of the word is a postposition. e.g. Önce, takdirde, üzere
     */
    return contains_flag(txt_word, "IS_POSTP");
}

/**
 * The isPortmanteauEndingWithSI method returns true if flags {@link unordered_set} contains IS_B_SI.
 *
 * @return true if flags {@link unordered_set} contains IS_B_SI.
 */
bool is_portmanteau_ending_with_si(const Txt_word* txt_word) {
    /*
     *IS_B_SI: The bare-form is a portmanteau word ending with "sı". e.g. Giritlalesi
     */
    return contains_flag(txt_word, "IS_B_SI");
}

/**
 * The isPortmanteauFacedVowelEllipsis method returns true if flags {@link unordered_set} contains IS_B_UD.
 *
 * @return true if flags {@link unordered_set} contains IS_B_UD.
 */
bool is_portmanteau_faced_vowel_ellipsis(const Txt_word* txt_word) {
    /*
     *IS_B_UD: The bare-form of the word includes vowel epenthesis,
     *therefore the last inserted vowel drops during suffixation. e.g. İnsanoğlu
     */
    return contains_flag(txt_word, "IS_B_UD");
}

/**
 * The isPortmanteauFacedSoftening method returns true if flags {@link unordered_set} contains IS_B_UD.
 *
 * @return true if flags {@link unordered_set} contains IS_B_SD.
 */
bool is_portmanteau_faced_softening(const Txt_word* txt_word) {
    /*
     *IS_B_SD: The bare-form of the word includes softening. e.g. Çançiçeği
     */
    return contains_flag(txt_word, "IS_B_SD");
}

/**
 * The isSuffix method returns true if flags {@link unordered_set} contains EK.
 *
 * @return true if flags {@link unordered_set} contains EK.
 */
bool is_suffix(const Txt_word* txt_word) {
    /*
     * EK: This tag indicates complementary verbs. e.g. İdi, iken, imiş.
     */
    return contains_flag(txt_word, "EK");
}

/**
 * The isProperNoun method returns true if flags {@link unordered_set} contains IS_OA.
 *
 * @return true if flags {@link unordered_set} contains IS_OA.
 */
bool is_proper_noun(const Txt_word* txt_word) {
    /*
     *IS_OA: The bare-form of the word is a proper noun. e.g. Abant, Beşiktaş
     */
    return contains_flag(txt_word, "IS_OA");
}

/**
 * The isPlural method returns true if flags {@link unordered_set} contains IS_CA.
 *
 * @return true if flags {@link unordered_set} contains IS_CA.
 */
bool is_plural(const Txt_word* txt_word) {
    /*
     *IS_CA: The bare-form of the word is already in a plural form,
     *therefore can not take plural suffixes such as "ler" or "lar". e.g. Buğdaygiller
     */
    return contains_flag(txt_word, "IS_CA");
}

/**
 * The isNumeral method returns true if flags {@link unordered_set} contains IS_SAYI.
 *
 * @return true if flags {@link unordered_set} contains IS_SAYI.
 */
bool is_numeral(const Txt_word* txt_word) {
    /*
     *IS_SAYI: The word is a number. e.g. Dört
     */
    return contains_flag(txt_word, "IS_SAYI");
}

/**
 * The isReal method returns true if flags {@link unordered_set} contains IS_REELSAYI.
 *
 * @return true if flags {@link unordered_set} contains IS_REELSAYI.
 */
bool is_real(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_REELSAYI");
}

/**
 * The isFraction method returns true if flags {@link unordered_set} contains IS_KESIR.
 *
 * @return true if flags {@link unordered_set} contains IS_KESIR.
 */
bool is_fraction(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_KESIR");
}

/**
 * The isTime method returns true if flags {@link unordered_set} contains IS_ZAMAN.
 *
 * @return true if flags {@link unordered_set} contains IS_ZAMAN.
 */
bool is_time2(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_ZAMAN");
}

/**
 * The isDate method returns true if flags {@link unordered_set} contains IS_DATE.
 *
 * @return true if flags {@link unordered_set} contains IS_DATE.
 */
bool is_date(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_DATE");
}

/**
 * The isPercent method returns true if flags {@link unordered_set} contains IS_PERCENT.
 *
 * @return true if flags {@link unordered_set} contains IS_PERCENT.
 */
bool is_percent(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_PERCENT");
}

/**
 * The isRange method returns true if flags {@link unordered_set} contains IS_RANGE.
 *
 * @return true if flags {@link unordered_set} contains IS_RANGE.
 */
bool is_range(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_RANGE");
}

/**
 * The isOrdinal method returns true if flags {@link unordered_set} contains IS_ORD.
 *
 * @return true if flags {@link unordered_set} contains IS_ORD.
 */
bool is_ordinal(const Txt_word* txt_word) {
    /*
     *IS_ORD: The bare-form of the word can take suffixes and these suffixes define a ranking. e.g. Birinci
     */
    return contains_flag(txt_word, "IS_ORD");
}

/**
 * The notObeysVowelHarmonyDuringAgglutination method returns true if flags {@link unordered_set} contains IS_UU.
 *
 * @return true if flags {@link unordered_set} contains IS_UU.
 */
bool not_obeys_vowel_harmony_during_agglutination(const Txt_word* txt_word) {
    /*
     *IS_UU: The bare-form does not obey vowel harmony while taking suffixes. e.g. Dikkat
     */
    return contains_flag(txt_word, "IS_UU");
}

/**
 * The obeysAndNotObeysVowelHarmonyDuringAgglutination method returns true if flags {@link unordered_set} contain IS_UUU.
 *
 * @return true if flags {@link unordered_set} contains IS_UUU.
 */
bool obeys_and_not_obeys_vowel_harmony_during_agglutination(const Txt_word* txt_word) {
    /*
     *IS_UUU: The bare-form does not obey vowel harmony while taking suffixes. e.g. Bol, kalp
     */
    return contains_flag(txt_word, "IS_UUU");
}

/**
 * The rootSoftenDuringSuffixation method returns true if flags {@link unordered_set} contains IS_SD, F_SD.
 *
 * @return true if flags {@link unordered_set} contains IS_SD, F_SD.
 */
bool root_soften_during_suffixation(const Txt_word* txt_word) {
    /*
     *IS_SD: The bare-form final consonant gets devoiced during vowel-initial suffixation. e.g. Çakmak
     */
    return contains_flag(txt_word, "IS_SD") || contains_flag(txt_word, "F_SD");
}

/**
 * The rootSoftenAndNotSoftenDuringSuffixation method returns true if flags {@link unordered_set} contains IS_SDD.
 *
 * @return true if flags {@link unordered_set} contains IS_SDD.
 */
bool root_soften_and_not_soften_during_suffixation(const Txt_word* txt_word) {
    /*
     *The bare-form final consonant can (or can not) get devoiced during vowel-initial suffixation. e.g. Kalp
     */
    return contains_flag(txt_word, "IS_SDD");
}

/**
 * The verbSoftenDuringSuffixation method returns true if flags {@link unordered_set} contains F_SD.
 *
 * @return true if flags {@link unordered_set} contains F_SD.
 */
bool verb_soften_during_suffixation(const Txt_word* txt_word) {
    /*
     * F_SD: The bare-form final consonant gets devoiced during vowel-initial suffixation. e.g. Cezbet
     */
    return contains_flag(txt_word, "F_SD");
}

/**
 * The nounSoftenDuringSuffixation method returns true if flags {@link unordered_set} contains IS_SD.
 *
 * @return true if flags {@link unordered_set} contains IS_SD.
 */
bool noun_soften_during_suffixation(const Txt_word* txt_word) {
    /*
     *IS_SD: The bare-form final consonant already has an accusative suffix. e.g. Kabağı
     */
    return contains_flag(txt_word, "IS_SD");
}

/**
 * The endingKChangesIntoG method returns true if flags {@link unordered_set} contains IS_KG.
 *
 * @return true if flags {@link unordered_set} contains IS_KG.
 */
bool ending_k_changes_into_g(const Txt_word* txt_word) {
    /*
     *IS_KG: The bare-form includes vowel epenthesis, therefore the last inserted vowel drope
     *during suffixation. e.g. Çelenk
     */
    return contains_flag(txt_word, "IS_KG");
}

/**
 * The isExceptional method returns true if flags {@link unordered_set} contains IS_EX.
 *
 * @return true if flags {@link unordered_set} contains IS_EX.
 */
bool is_exceptional(const Txt_word* txt_word) {
    /*
     *IS_EX: This tag defines exception words. e.g. Delikanlı
     */
    return contains_flag(txt_word, "IS_EX");
}

/**
 * The duplicatesDuringSuffixation method returns true if flags {@link unordered_set} contains IS_ST.
 *
 * @return true if flags {@link unordered_set} contains IS_ST.
 */
bool duplicates_during_suffixation(const Txt_word* txt_word) {
    /*
     *IS_ST: The second consonant of the bare-form undergoes a resyllabification. e.g. His
     */
    return contains_flag(txt_word, "IS_ST");
}

/**
 * The duplicatesAndNotDuplicatesDuringSuffixation method returns true if flags {@link unordered_set} contains IS_STT.
 *
 * @return true if flags {@link unordered_set} contains IS_STT.
 */
bool duplicates_and_not_duplicates_during_suffixation(const Txt_word* txt_word) {
    /*
     *IS_STT: The second consonant of the bare-form undergoes a resyllabification. e.g. His
     */
    return contains_flag(txt_word, "IS_STT");
}

/**
 * The lastIdropsDuringSuffixation method returns true if flags {@link unordered_set} contains IS_UD.
 *
 * @return true if flags {@link unordered_set} contains IS_UD.
 */
bool last_i_drops_during_suffixation(const Txt_word* txt_word) {
    /*
     *IS_UD: The bare-form includes vowel epenthesis, therefore the last inserted vowel drops during suffixation.
     *e.g. Boyun
     */
    return contains_flag(txt_word, "IS_UD");
}

/**
 * The lastIDropsAndNotDropDuringSuffixation method returns true if flags {@link unordered_set} contains IS_UDD.
 *
 * @return true if flags {@link unordered_set} contains IS_UDD.
 */
bool last_i_drops_and_not_drop_during_suffixation(const Txt_word* txt_word) {
    /*
     *The bare-form includes vowel epenthesis, therefore the last inserted vowel can (or can not) drop during suffixation. e.g. Kadir
     */
    return contains_flag(txt_word, "IS_UDD");
}

/**
 * The takesRelativeSuffixKi method returns true if flags {@link unordered_set} contains IS_KI.
 *
 * @return true if flags {@link unordered_set} contains IS_KI.
 */
bool takes_relative_suffix_ki(const Txt_word* txt_word) {
    /*
     *IS_KI: The word can take a suffix such as "ki". e.g. Önce
     */
    return contains_flag(txt_word, "IS_KI");
}

/**
 * The takesRelativeSuffixKu method returns true if flags {@link unordered_set} contains IS_KU.
 *
 * @return true if flags {@link unordered_set} contains IS_KU.
 */
bool takes_relative_suffix_ku(const Txt_word* txt_word) {
    /*
     *IS_KU: The word can take a suffix such as "kü". e.g. Bugün
     */
    return contains_flag(txt_word, "IS_KU");
}

/**
 * The consonantSMayInsertedDuringPossesiveSuffixation method returns true if flags {@link unordered_set} contains IS_SII.
 *
 * @return true if flags {@link unordered_set} contains IS_SII.
 */
bool consonant_s_may_inserted_during_possesive_suffixation(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_SII");
}

/**
 * The lastIdropsDuringPassiveSuffixation method returns true if flags {@link unordered_set} contains F_UD.
 *
 * @return true if flags {@link unordered_set} contains F_UD.
 */
bool last_i_drops_during_passive_suffixation(const Txt_word* txt_word) {
    /*
     *F_UD: The bare-form includes vowel epenthesis, therefore the last "ı"
     *drops during passive suffixation. e.g. Çağır
     */
    return contains_flag(txt_word, "F_UD");
}

/**
 * The vowelAChangesToIDuringYSuffixation method returns true if flags {@link unordered_set} contains F_GUD.
 *
 * @return true if flags {@link unordered_set} contains F_GUD.
 */
bool vowel_a_changes_to_i_during_y_suffixation(const Txt_word* txt_word) {
    /*
     *F_GUD: The verb bare-form includes viwel reduction, the last vowel "a" of the bare-form is replaced with "ı"
     *e.g. Buzağıla
     */
    return contains_flag(txt_word, "F_GUD");
}

/**
 * The vowelEChangesToIDuringYSuffixation method returns true if flags {@link unordered_set} contains F_GUDO.
 *
 * @return true if flags {@link unordered_set} contains F_GUDO.
 */
bool vowel_e_changes_to_i_during_y_suffixation(const Txt_word* txt_word) {
    /*
     *F_GUDO: The verb bare-form includes viwel reduction, the last vowel "e" of the
     *bare-form is replaced with "i". e.g. Ye
     */
    return contains_flag(txt_word, "F_GUDO");
}

/**
 * The takesSuffixIRAsAorist method returns true if flags {@link unordered_set} contains F_GIR.
 *
 * @return true if flags {@link unordered_set} contains F_GIR.
 */
bool takes_suffix_ir_as_aorist(const Txt_word* txt_word) {
    /*
     *F_GIR: The bare-form of the word takes "ir" suffix. e.g. Geç
     */
    return !contains_flag(txt_word, "F_GIR");
}

/**
 * The takesSuffixDIRAsFactitive method returns true if flags {@link unordered_set} contains F_DIR.
 *
 * @return true if flags {@link unordered_set} contains F_DIR.
 */
bool takes_suffix_dir_as_factitive(const Txt_word* txt_word) {
    /*
     *F_DIR: The bare-form of the word takes "tır" suffix. e.g. Daral
     */
    return !contains_flag(txt_word, "F_DIR");
}

/**
 * The showsSuRegularities method returns true if flags {@link unordered_set} contains IS_SU.
 *
 * @return true if flags {@link unordered_set} contains IS_SU.
 */
bool shows_su_regularities(const Txt_word* txt_word) {
    return contains_flag(txt_word, "IS_SU");
}

/**
 * The samePos method takes TxtWord as input and returns true if;
 * <p>
 * flags {@link unordered_set} contains CL_ISIM or given word is CL_ISIM or
 * CL_ISIM: The bare-form of the word is a noun. e.g. Abla
 * <p>
 * flags {@link unordered_set} contains CL_FIIL or given word is CL_FIIL or
 * CL_FIIL: The bare-form of the word is a verb. e.g. Affet
 * <p>
 * flags {@link unordered_set} contains IS_ADJ or given word is IS_ADJ or
 * IS_ADJ: The bare-form of the word is a adjective. e.g. Acayip
 * <p>
 * flags {@link unordered_set} contains IS_ZM or given word is IS_ZM or
 * IS_ZM: The bare-form of the word is a pronoun. e.g. Başkası
 * <p>
 * flags {@link unordered_set} contains IS_ADVERB or given word is IS_ADVERB, false otherwise.
 * IS_ADVERB: The bare-form of the word is a adverb. e.g. Tekrar, açıktan, adeta
 *
 * @param word TxtWord type input.
 * @return true if given word is nominal, verb, adjective, pronoun or adverb, false otherwise.
 */
bool same_pos(const Txt_word* txt_word1, const Txt_word* txt_word2) {
    if (is_nominal(txt_word1) && is_nominal(txt_word2)) {
        return true;
    }
    if (is_verb(txt_word1) && is_verb(txt_word2)) {
        return true;
    }
    if (is_adjective(txt_word1) && is_adjective(txt_word2)) {
        return true;
    }
    if (is_pronoun(txt_word1) && is_pronoun(txt_word2)) {
        return true;
    }
    if (is_adverb(txt_word1) && is_adverb(txt_word2)) {
        return true;
    }
    return false;
}

unsigned int hash_function_txt_word(const Txt_word* word, int N) {
    return hash_function_string(word->word->name, N);
}

int compare_txt_word(const Txt_word* first, const Txt_word* second) {
    return compare_string(first->word->name, second->word->name);
}
