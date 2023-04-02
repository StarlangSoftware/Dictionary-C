//
// Created by Olcay Taner YILDIZ on 18.03.2023.
//

#include "../src/Dictionary/TxtDictionary.h"
#include <stdio.h>

int main(){
    Txt_dictionary_ptr dictionary = create_txt_dictionary2("lowercase.txt");
    if (dictionary->dictionary->words->size != 29){
        printf("Error in size 1");
    }
    if (longest_word_size_txt(dictionary) != 1){
        printf("Error in longest word 1");
    }
    free_txt_dictionary(dictionary);
    dictionary = create_txt_dictionary2("mixedcase.txt");
    if (dictionary->dictionary->words->size != 58){
        printf("Error in size 2");
    }
    if (longest_word_size_txt(dictionary) != 1){
        printf("Error in longest word 2");
    }
    free_txt_dictionary(dictionary);
}