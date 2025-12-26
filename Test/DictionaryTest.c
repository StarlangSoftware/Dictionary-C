//
// Created by Olcay Taner YILDIZ on 18.03.2023.
//

#include "../src/Dictionary/TxtDictionary.h"
#include <stdio.h>
#include <Memory/Memory.h>

int main(){
    start_memory_check();
    Txt_dictionary_ptr dictionary = create_txt_dictionary2("lowercase.txt");
    if (dictionary->dictionary.words->size != 29){
        printf("Error in size 1");
    }
    if (longest_word_size((Dictionary_ptr)dictionary) != 1){
        printf("Error in longest name 1");
    }
    free_txt_dictionary(dictionary);
    dictionary = create_txt_dictionary2("mixedcase.txt");
    if (dictionary->dictionary.words->size != 58){
        printf("Error in size 2");
    }
    if (longest_word_size((Dictionary_ptr)dictionary) != 1){
        printf("Error in longest name 2");
    }
    free_txt_dictionary(dictionary);
    end_memory_check();
}
