//
// Created by Olcay Taner YILDIZ on 2.04.2023.
//

#include <string.h>
#include "../src/Dictionary/TxtDictionary.h"
#include "../src/Dictionary/VectorizedDictionary.h"
#include <stdio.h>
#include <stdlib.h>

void test_morphology(Txt_dictionary_ptr txt_dictionary){
    Txt_word_ptr word = get_word_txt(txt_dictionary, "ab");
    if (strcmp(word->morphology, "ab") != 0){
        printf("Error in morphology 1");
    }
    word = get_word_txt(txt_dictionary, "çarpıcılık");
    if (strcmp(word->morphology, "çarp+HcH+lHk") != 0){
        printf("Error in morphology 2");
    }
    word = get_word_txt(txt_dictionary, "akışkanlaştırıcı");
    if (strcmp(word->morphology, "ak+Hş+GAn+lAş+DHr+HcH") != 0){
        printf("Error in morphology 3");
    }
}

void test_all_words(Txt_dictionary_ptr txt_dictionary){
    for (int i = 0; i < txt_dictionary->dictionary->words->size; i++){
        Txt_word_ptr word1 = get_word_with_index_txt(txt_dictionary, i);
        Txt_word_ptr word2 = get_word_txt(txt_dictionary, word1->word->name);
        if (word2 == NULL){
            printf("Error in finding word %s\n", word1->word->name);
        }
    }
}

void test_correct_form(Txt_dictionary_ptr txt_dictionary){
    char* correct = get_correct_form(txt_dictionary, "harıcındekılerden");
    if (correct == NULL || strcmp(correct, "haricindekilerden") != 0){
        printf("Error in correct form 1\n");
    }
    correct = get_correct_form(txt_dictionary, "potresi");
    if (correct == NULL || strcmp(correct, "portre") != 0){
        printf("Error in correct form 2\n");
    }
    correct = get_correct_form(txt_dictionary, "ucretlı");
    if (correct == NULL || strcmp(correct, "ücretli") != 0){
        printf("Error in correct form 3\n");
    }
}

void test_prepare_trie(Txt_dictionary_ptr txt_dictionary){
    Trie_ptr trie = prepare_trie(txt_dictionary);
    Hash_set_ptr set = get_words_with_prefix(trie, "bana");
    if (!hash_set_contains(set, create_txt_word("ben"))){
        printf("Error in prepare trie 1\n");
    }
    free_hash_set(set, NULL);
    set = get_words_with_prefix(trie, "ayrıldı");
    if (!hash_set_contains(set, create_txt_word("ayır"))){
        printf("Error in prepare trie 2\n");
    }
    free_hash_set(set, NULL);
    set = get_words_with_prefix(trie, "metni");
    if (!hash_set_contains(set, create_txt_word("metin"))){
        printf("Error in prepare trie 3\n");
    }
    free_hash_set(set, NULL);
    set = get_words_with_prefix(trie, "deveboyunları");
    if (!hash_set_contains(set, create_txt_word("deveboynu"))){
        printf("Error in prepare trie 4\n");
    }
    free_hash_set(set, NULL);
    set = get_words_with_prefix(trie, "fiyongu");
    if (!hash_set_contains(set, create_txt_word("fiyonk"))){
        printf("Error in prepare trie 5\n");
    }
    free_hash_set(set, NULL);
    set = get_words_with_prefix(trie, "yiyor");
    if (!hash_set_contains(set, create_txt_word("ye"))){
        printf("Error in prepare trie 6\n");
    }
    free_hash_set(set, NULL);
    set = get_words_with_prefix(trie, "depoluyor");
    if (!hash_set_contains(set, create_txt_word("depola"))){
        printf("Error in prepare trie 7\n");
    }
    free_hash_set(set, NULL);
    set = get_words_with_prefix(trie, "ağaçlığı");
    if (!hash_set_contains(set, create_txt_word("ağaçlık"))){
        printf("Error in prepare trie 8\n");
    }
    free_hash_set(set, NULL);
    set = get_words_with_prefix(trie, "kutbu");
    if (!hash_set_contains(set, create_txt_word("kutup"))){
        printf("Error in prepare trie 9\n");
    }
    free_hash_set(set, NULL);
}

int main(){
    Txt_dictionary_ptr txt_dictionary = create_txt_dictionary();
    test_morphology(txt_dictionary);
    test_all_words(txt_dictionary);
    test_correct_form(txt_dictionary);
    test_prepare_trie(txt_dictionary);
    free_txt_dictionary(txt_dictionary);
}