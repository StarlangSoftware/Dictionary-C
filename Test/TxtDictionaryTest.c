//
// Created by Olcay Taner YILDIZ on 2.04.2023.
//

#include <string.h>
#include "../src/Dictionary/TxtDictionary.h"
#include <stdio.h>
#include <Memory/Memory.h>

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
        Txt_word_ptr word2 = get_word_txt(txt_dictionary, word1->name);
        if (word2 == NULL){
            printf("Error in finding name %s\n", word1->name);
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

void test_prepare_trie_single(Trie_ptr trie, char* _word, char* root, int index){
    Hash_set_ptr set = get_words_with_prefix(trie, _word);
    Txt_word_ptr word = create_txt_word(root);
    if (!hash_set_contains(set, word)){
        printf("Error in prepare trie %d\n", index);
    }
    free_txt_word(word);
    free_hash_set(set, (void (*)(void *)) free_txt_word);
}

void test_prepare_trie(Txt_dictionary_ptr txt_dictionary){
    Trie_ptr trie = prepare_trie(txt_dictionary);
    test_prepare_trie_single(trie, "bana", "ben", 1);
    test_prepare_trie_single(trie, "ayrıldı", "ayır", 2);
    test_prepare_trie_single(trie, "metni", "metin", 3);
    test_prepare_trie_single(trie, "deveboyunları", "deveboynu", 4);
    test_prepare_trie_single(trie, "fiyongu", "fiyonk", 5);
    test_prepare_trie_single(trie, "yiyor", "ye", 6);
    test_prepare_trie_single(trie, "depoluyor", "depola", 7);
    test_prepare_trie_single(trie, "ağaçlığı", "ağaçlık", 8);
    test_prepare_trie_single(trie, "kutbu", "kutup", 9);
    free_trie(trie);
}

int main(){
    Txt_dictionary_ptr txt_dictionary = create_txt_dictionary();
    test_morphology(txt_dictionary);
    test_all_words(txt_dictionary);
    test_correct_form(txt_dictionary);
    test_prepare_trie(txt_dictionary);
    free_txt_dictionary(txt_dictionary);
}