//
// Created by Olcay Taner YILDIZ on 18.03.2023.
//

#include <stdio.h>
#include <string.h>
#include <Memory/Memory.h>
#include "TxtDictionary.h"
#include "FileUtils.h"
#include "Trie/Trie.h"

/**
 * Empty constructor of TxtDictionary class. Sets the WordComparator to TurkishWordComparator, loads the
 * default Turkish dictionary, Turkish misspellings file and Turkish morphological lexicon, which contains the
 * subword units to Turkish root words.
 */
Txt_dictionary_ptr create_txt_dictionary() {
    return create_txt_dictionary3("turkish_dictionary.txt",
                                  "turkish_misspellings.txt",
                                  "turkish_morphological_lexicon.txt");
}

/**
 * Another constructor of TxtDictionary class which takes a String filename and a WordComparator as inputs.
 * And calls its super class Dictionary with given WordComparator, assigns given filename input to the
 * filename variable. Then, it calls loadFromText method with given filename.
 *
 * @param file_name   String input.
 */
Txt_dictionary_ptr create_txt_dictionary2(const char *file_name) {
    Txt_dictionary_ptr result;
    result = malloc_(sizeof(Txt_dictionary), "create_txt_dictionary2");
    result->dictionary = create_dictionary();
    result->file_name = str_copy(result->file_name, file_name);
    result->misspelled_words = create_string_hash_map();
    load_from_text(result);
    return result;
}

/**
 * Another constructor of TxtDictionary class which takes a String filename, a WordComparator and
 * a misspelled word dictionary file as inputs. And calls its super class Dictionary with given
 * WordComparator, assigns given filename input to the filename variable. Then, it calls loadFromText
 * method with given filename. It also loads the misspelling file.
 *
 * @param file_name   String input.
 * @param misspelled_file_name String input.
 * @param morphological_lexicon String input.
 */
Txt_dictionary_ptr create_txt_dictionary3(const char *file_name,
                                          const char *misspelled_file_name,
                                          const char *morphological_lexicon) {
    Txt_dictionary_ptr result;
    result = malloc_(sizeof(Txt_dictionary), "create_txt_dictionary3");
    result->dictionary = create_dictionary();
    result->file_name = str_copy(result->file_name, file_name);
    load_from_text(result);
    load_misspelled_words(result, misspelled_file_name);
    load_morphological_lexicon(result, morphological_lexicon);
    return result;
}

/**
 * Frees memory allocated for the TxtDictionary.
 * @param txt_dictionary TxtDictionary to be freed.
 */
void free_txt_dictionary(Txt_dictionary_ptr txt_dictionary) {
    free_array_list(txt_dictionary->dictionary->words, (void (*)(void *)) free_txt_word);
    free_hash_map(txt_dictionary->dictionary->word_map, free_);
    free_(txt_dictionary->dictionary);
    free_(txt_dictionary->file_name);
    free_hash_map2(txt_dictionary->misspelled_words, free_, free_);
    free_(txt_dictionary);
}

/**
 * Takes a String filename as an input. It reads given file line by line and splits according to space
 * and assigns each word to the String array. Then, adds these word with their flags to the words array list.
 * At the end it sorts the words array list.
 *
 * @param txt_dictionary TxtDictionary to be read.
 */
void load_from_text(Txt_dictionary_ptr txt_dictionary) {
    int i;
    FILE *input_file;
    Txt_word_ptr currentWord;
    input_file = fopen(txt_dictionary->file_name, "r");
    if (input_file == NULL) {
        fclose(input_file);
        return;
    }
    while (!feof(input_file)) {
        Array_list_ptr tokens = read_items(input_file, ' ');
        if (tokens->size != 0) {
            currentWord = create_txt_word(array_list_get(tokens, 0));
            for (i = 1; i < tokens->size; i++) {
                add_flag(currentWord, array_list_get(tokens, i));
            }
            array_list_add(txt_dictionary->dictionary->words, currentWord);
        }
        free_array_list(tokens, free_);
    }
    fclose(input_file);
    sort_txt(txt_dictionary);
}

/**
 * The longestWordSize method loops through the words vector and returns the item with the maximum word length.
 *
 * @param txt_dictionary Current dictionary.
 * @return the item with the maximum word length.
 */
int longest_word_size_txt(const Txt_dictionary* txt_dictionary) {
    int max = 0;
    for (int i = 0; i < txt_dictionary->dictionary->words->size; i++) {
        Txt_word_ptr word = array_list_get(txt_dictionary->dictionary->words, i);
        if (word_size(word->name) > max) {
            max = word_size(word->name);
        }
    }
    return max;
}

/**
 * The loadMisspellWords method takes a String filename as an input. It reads given file line by line and splits
 * according to space and assigns each word with its misspelled form to the the misspelledWords hashMap.
 *
 * @param txt_dictionary Current dictionary.
 * @param misspelled_file_name Name of the misspellings file.
 */
void load_misspelled_words(Txt_dictionary_ptr txt_dictionary, const char *misspelled_file_name) {
    txt_dictionary->misspelled_words = read_hash_map(misspelled_file_name);
}

/**
 * Loads the morphological lexicon of a given language. Only Turkish is currently supported. Morphological lexicon
 * contains subwords (possibly meaningful words or metamorphemes) of each root word in the Turkish dictionary. For
 * example, abacılık has subwords aba+CH+LHK.
 * @param txt_dictionary Current dictionary.
 * @param file_name Name of the morphological lexicon file
 */
void load_morphological_lexicon(Txt_dictionary_ptr txt_dictionary, const char *file_name) {
    FILE *input_file;
    input_file = fopen(file_name, "r");
    if (input_file == NULL) {
        fclose(input_file);
        return;
    }
    while (!feof(input_file)) {
        Array_list_ptr tokens = read_items(input_file, ' ');
        if (tokens->size == 2) {
            Txt_word_ptr word = get_word_txt(txt_dictionary, array_list_get(tokens, 0));
            if (word != NULL && word->morphology == NULL) {
                word->morphology = str_copy(word->morphology, array_list_get(tokens, 1));
            }
        }
        free_array_list(tokens, free_);
    }
    fclose(input_file);
}

/**
 * The getWord method takes a String name as an input and performs binary search within words vector and assigns the result
 * to integer variable middle. If the middle is greater than 0, it returns the item at index middle of words vector, null otherwise.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 * @return the item at found index of words vector, null if cannot be found.
 */
Txt_word_ptr get_word_txt(const Txt_dictionary* txt_dictionary, const char *name) {
    if (word_exists(txt_dictionary->dictionary, name)) {
        int index = *(int *) (hash_map_get(txt_dictionary->dictionary->word_map, name));
        return array_list_get(txt_dictionary->dictionary->words, index);
    }
    return NULL;
}

/**
 * Updates word map so that word index at i is in the hash map with key word and value i.
 * @param txt_dictionary Current dictionary
 */
void update_word_map_txt(Txt_dictionary_ptr txt_dictionary) {
    for (int i = 0; i < txt_dictionary->dictionary->words->size; i++) {
        Txt_word_ptr word = array_list_get(txt_dictionary->dictionary->words, i);
        int *index = malloc_(sizeof(int), "update_word_map_txt");
        *index = i;
        hash_map_insert(txt_dictionary->dictionary->word_map, word->name, index);
    }
}

/**
 * Sorts the words array according to the comparator function.
 * @param txt_dictionary Current dictionary
 */
void sort_txt(Txt_dictionary_ptr txt_dictionary) {
    array_list_sort(txt_dictionary->dictionary->words, (int (*)(const void *, const void *)) compare_txt_word);
    update_word_map_txt(txt_dictionary);
}

/**
 * The getWord method which takes an index as an input and returns the value at given index of words vector.
 *
 * @param txt_dictionary Current dictionary.
 * @param index to get the value.
 * @return the value at given index of words vector.
 */
Txt_word_ptr get_word_with_index_txt(const Txt_dictionary* txt_dictionary, int index){
    return array_list_get(txt_dictionary->dictionary->words, index);
}

/**
 * Checks if a given word exists in the dictionary by performing a binary search on the words array.
 * @param txt_dictionary Dictionary to be searched.
 * @param txt_word Searched word
 * @return the index of the search word, if it is contained in the words array; otherwise, (-(insertion point) - 1). The
 * insertion point is defined as the point at which the word would be inserted into the words array.
 */
int binary_search_txt(const Txt_dictionary* txt_dictionary, const Txt_word* txt_word) {
    int lo = 0;
    int hi = txt_dictionary->dictionary->words->size - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        if (strcmp(array_list_get(txt_dictionary->dictionary->words, mid), txt_word->name) == 0) {
            return mid;
        }
        if (strcmp(array_list_get(txt_dictionary->dictionary->words, mid), txt_word->name) < 0) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }
    return -(lo + 1);
}

/**
 * The addWithFlag method takes a String name and a flag as inputs. First it creates a TxtWord word, then if
 * given name is not in words vector it creates new TxtWord with given name and assigns it to
 * the word and adds given flag to the word, it also add newly created word to the words vector's index
 * found by performing a binary search and return true at the end. If given name is in words array,
 * it adds it the given flag to the word.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 * @param flag String flag.
 * @return true if given name is in words {@link java.util.ArrayList}, false otherwise.
 */
bool add_with_flag(Txt_dictionary_ptr txt_dictionary, const char *name, char *flag) {
    char* lowercase = to_lowercase(name);
    Txt_word_ptr word = get_word_txt(txt_dictionary, lowercase);
    if (word == NULL){
        word = create_txt_word2(name, flag);
        int insert_index = -binary_search_txt(txt_dictionary, word) - 1;
        if (insert_index >= 0){
            array_list_insert(txt_dictionary->dictionary->words, insert_index, word);
        }
        return true;
    } else {
        if (!contains_flag(word, flag)){
            add_flag(word, flag);
        }
    }
    return false;
}

/**
 * The addNumber method takes a String name and calls addWithFlag method with given name and IS_SAYI flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 */
void add_number(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "IS_SAYI");
}

/**
 * The addRealNumber method takes a String name and calls addWithFlag method with given name and IS_REELSAYI flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 */
void add_real_number(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "IS_REELSAYI");
}

/**
 * The addFraction method takes a String name and calls addWithFlag method with given name and IS_KESIR flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 */
void add_fraction(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "IS_KESIR");
}

/**
 * The addTime method takes a String name and calls addWithFlag method with given name and IS_ZAMAN flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
*/
void add_time(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "IS_ZAMAN");
}

/**
 * The addProperNoun method takes a String name and calls addWithFlag method with given name and IS_OA flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
void add_proper_noun(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "IS_OA");
}

/**
 * The addNoun method takes a String name and calls addWithFlag method with given name and CL_ISIM flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
void add_noun(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "CL_ISIM");
}

/**
 * The addVerb method takes a String name and calls addWithFlag method with given name and CL_FIIL flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
void add_verb(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "CL_FIIL");
}

/**
 * The addAdjective method takes a String name and calls addWithFlag method with given name and IS_ADJ flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
void add_adjective(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "IS_ADJ");
}

/**
 * The addAdverb method takes a String name and calls addWithFlag method with given name and IS_ADVERB flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
void add_adverb(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "IS_ADVERB");
}

/**
 * The addPronoun method takes a String name and calls addWithFlag method with given name and IS_ZM flag.
 *
 * @param txt_dictionary Current dictionary.
 * @param name String input.
 * @return true if given name is in words {@link unordered_set}, false otherwise.
 */
void add_pronoun(Txt_dictionary_ptr txt_dictionary, const char *name) {
    add_with_flag(txt_dictionary, name, "IS_ZM");
}

/**
 * The addWordWhenRootSoften is used to add word to Trie whose last consonant will be soften.
 * For instance, in the case of Dative Case Suffix, the word is 'müzik' when '-e' is added to the word, the last
 * char is drooped and root became 'müzi' and by changing 'k' into 'ğ' the word transformed into 'müziğe' as in the
 * example of 'Herkes müziğe doğru geldi'.
 * <p>
 * In the case of accusative, possessive of third person and a derivative suffix, the word is 'kanat' when '-i' is
 * added to word, last char is dropped, root became 'kana' then 't' transformed into 'd' and added to Trie. The word is
 * changed into 'kanadı' as in the case of 'Kuşun kırık kanadı'.
 *
 * @param trie the name of the Trie to add the word.
 * @param last the last char of the word to be soften.
 * @param root the substring of the word whose last one or two chars are omitted from the word to bo softed.
 * @param word the original word.
 */
void add_word_when_root_soften(Trie_ptr trie, const char *last, const char *root, Txt_word_ptr word) {
    char* tmp = NULL;
    if (strcmp(last, "p") == 0){
        tmp = str_concat(root, "b");
    } else {
        if (strcmp(last, "ç") == 0){
            tmp = str_concat(root, "c");
        } else {
            if (strcmp(last, "t") == 0){
                tmp = str_concat(root, "d");
            } else {
                if (strcmp(last, "k") == 0 || strcmp(last, "g") == 0){
                    tmp = str_concat(root, "ğ");
                }
            }
        }
    }
    if (tmp != NULL){
        add_word_to_trie(trie, tmp, clone_txt_word(word));
        free_(tmp);
    }
}

/**
 * The prepareTrie method is used to create a Trie with the given dictionary. First, it gets the word from dictionary,
 * then checks some exceptions like 'ben' which does not fit in the consonant softening rule and transforms into 'bana',
 * and later on it generates a root by removing the last char from the word however if the length of the word is greater
 * than 1, it also generates the root by removing the last two chars from the word.
 * <p>
 * Then, it gets the last char of the root and adds root and word to the result Trie. There are also special cases such as;
 * lastIdropsDuringSuffixation condition, if it is true then addWordWhenRootSoften method will be used rather than addWord.
 * Ex : metin + i = metni
 * isPortmanteauEndingWithSI condition, if it is true then addWord method with rootWithoutLastTwo will be used.
 * Ex : ademelması + lar = ademelmaları
 * isPortmanteau condition, if it is true then addWord method with rootWithoutLast will be used.
 * Ex : mısıryağı + lar = mısıryağları
 * vowelEChangesToIDuringYSuffixation condition, if it is then addWord method with rootWithoutLast will be used
 * depending on the last char whether it is 'e' or 'a'.
 * Ex : ye + iniz - yiyiniz
 * endingKChangesIntoG condition, if it is true then addWord method with rootWithoutLast will be used with added 'g'.
 * Ex : ahenk + i = ahengi
 *
 * @param txt_dictionary the dictionary that Trie will be created.
 * @return the resulting Trie.
 */
Trie_ptr prepare_trie(Txt_dictionary_ptr txt_dictionary) {
    Trie_ptr result = create_trie();
    char *root;
    String_ptr rootWithoutLast, rootWithoutLastTwo, lastBefore, last, tmp;
    for (int i = 0; i < txt_dictionary->dictionary->words->size; i++) {
        Txt_word_ptr word = get_word_with_index_txt(txt_dictionary, i);
        root = word->name;
        if (strcmp(root, "ben") == 0){
            add_word_to_trie(result, "bana", clone_txt_word(word));
        }
        if (strcmp(root, "sen") == 0){
            add_word_to_trie(result, "sana", clone_txt_word(word));
        }
        rootWithoutLast = substring_except_last_char(root);
        if (word_size(root) > 1) {
            rootWithoutLastTwo = substring_except_last_two_chars(root);
        } else {
            rootWithoutLastTwo = create_string();
        }
        if (word_size(root) > 1){
            lastBefore = char_at(root, word_size(root) - 2);
        } else {
            lastBefore = NULL;
        }
        last = last_char(root);
        add_word_to_trie(result, root, clone_txt_word(word));
        if (last_i_drops_during_suffixation(word) || last_i_drops_during_passive_suffixation(word)) {
            if (root_soften_during_suffixation(word)) {
                add_word_when_root_soften(result, last->s, rootWithoutLastTwo->s, word);
            } else {
                tmp = create_string2(rootWithoutLastTwo->s);
                string_append_s(tmp, last);
                add_word_to_trie(result, tmp->s, clone_txt_word(word));
                free_string_ptr(tmp);
            }
        }
        // NominalRootNoPossesive
        if (is_portmanteau_ending_with_si(word)) {
            add_word_to_trie(result, rootWithoutLastTwo->s, clone_txt_word(word));
        }
        if (root_soften_during_suffixation(word)) {
            add_word_when_root_soften(result, last->s, rootWithoutLast->s, word);
        }
        if (is_portmanteau(word)) {
            tmp = create_string2(rootWithoutLastTwo->s);
            if (is_portmanteau_faced_vowel_ellipsis(word)){
                string_append_s(tmp, last);
                string_append_s(tmp, lastBefore);
                add_word_to_trie(result, tmp->s, clone_txt_word(word));
            } else {
                if (is_portmanteau_faced_softening(word)){
                    if (strcmp(lastBefore->s, "b") == 0){
                        string_append(tmp, "p");
                        add_word_to_trie(result, tmp->s, clone_txt_word(word));
                    } else {
                        if (strcmp(lastBefore->s, "c") == 0){
                            string_append(tmp, "ç");
                            add_word_to_trie(result, tmp->s, clone_txt_word(word));
                        } else {
                            if (strcmp(lastBefore->s, "d") == 0){
                                string_append(tmp, "t");
                                add_word_to_trie(result, tmp->s, clone_txt_word(word));
                            } else {
                                if (strcmp(lastBefore->s, "ğ") == 0){
                                    string_append(tmp, "k");
                                    add_word_to_trie(result, tmp->s, clone_txt_word(word));
                                }
                            }
                        }
                    }
                } else {
                    add_word_to_trie(result, rootWithoutLast->s, clone_txt_word(word));
                }
            }
            free_string_ptr(tmp);
        }
        if (vowel_e_changes_to_i_during_y_suffixation(word) || vowel_a_changes_to_i_during_y_suffixation(word)) {
            if (strcmp(last->s, "e") == 0){
                add_word_to_trie(result, rootWithoutLast->s, clone_txt_word(word));
            } else {
                if (strcmp(last->s, "a") == 0){
                    add_word_to_trie(result, rootWithoutLast->s, clone_txt_word(word));
                }
            }
        }
        if (ending_k_changes_into_g(word)) {
            tmp = create_string2(rootWithoutLast->s);
            string_append_char(tmp, 'g');
            add_word_to_trie(result, tmp->s, clone_txt_word(word));
            free_string_ptr(tmp);
        }
        free_string_ptr(rootWithoutLast);
        free_string_ptr(rootWithoutLastTwo);
        if (lastBefore != NULL){
            free_string_ptr(lastBefore);
        }
        free_string_ptr(last);
    }
    return result;
}

/**
 * The getCorrectForm returns the correct form of a misspelled word.
 * @param txt_dictionary Current dictionary.
 * @param misspelled_word Misspelled form.
 * @return Correct form.
 */
char *get_correct_form(const Txt_dictionary* txt_dictionary, const char *misspelled_word) {
    if (hash_map_contains(txt_dictionary->misspelled_words, misspelled_word)){
        return hash_map_get(txt_dictionary->misspelled_words, misspelled_word);
    }
    return NULL;
}
