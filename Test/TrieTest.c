//
// Created by Olcay Taner YILDIZ on 5.03.2023.
//

#include "../src/Dictionary/Trie/Trie.h"
#include <stdio.h>
#include <Memory/Memory.h>

int main(){
    Trie_ptr simple_trie = create_trie();
    add_word_to_trie(simple_trie, "azı", create_txt_word("azı"));
    add_word_to_trie(simple_trie, "az", create_txt_word("az"));
    add_word_to_trie(simple_trie, "ad", create_txt_word("ad"));
    add_word_to_trie(simple_trie, "adi", create_txt_word("adi"));
    add_word_to_trie(simple_trie, "adil", create_txt_word("adil"));
    add_word_to_trie(simple_trie, "a", create_txt_word("a"));
    add_word_to_trie(simple_trie, "adilane", create_txt_word("adilane"));
    add_word_to_trie(simple_trie, "ısı", create_txt_word("ısı"));
    add_word_to_trie(simple_trie, "ısıtıcı", create_txt_word("ısıtıcı"));
    add_word_to_trie(simple_trie, "ölü", create_txt_word("ölü"));
    add_word_to_trie(simple_trie, "ölüm", create_txt_word("ölüm"));
    add_word_to_trie(simple_trie, "ören", create_txt_word("ören"));
    add_word_to_trie(simple_trie, "örgü", create_txt_word("örgü"));
    Hash_set_ptr set = get_words_with_prefix(simple_trie, "a");
    if (set->hash_map->count != 1){
        printf("Error in trie test 1\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    set = get_words_with_prefix(simple_trie, "ad");
    if (set->hash_map->count != 2){
        printf("Error in trie test 2\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    set = get_words_with_prefix(simple_trie, "adi");
    if (set->hash_map->count != 3){
        printf("Error in trie test 3\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    set = get_words_with_prefix(simple_trie, "adil");
    if (set->hash_map->count != 4){
        printf("Error in trie test 4\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    set = get_words_with_prefix(simple_trie, "adilane");
    if (set->hash_map->count != 5){
        printf("Error in trie test 5\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    set = get_words_with_prefix(simple_trie, "ölü");
    if (set->hash_map->count != 1){
        printf("Error in trie test 6\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    set = get_words_with_prefix(simple_trie, "ölüm");
    if (set->hash_map->count != 2){
        printf("Error in trie test 7\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    set = get_words_with_prefix(simple_trie, "ısı");
    if (set->hash_map->count != 1){
        printf("Error in trie test 8\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    set = get_words_with_prefix(simple_trie, "ısıtıcı");
    if (set->hash_map->count != 2){
        printf("Error in trie test 9\n");
    }
    free_hash_set(set, (void (*)(void *)) free_txt_word);
    free_trie(simple_trie);
}