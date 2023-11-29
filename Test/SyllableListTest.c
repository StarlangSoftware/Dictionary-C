//
// Created by Olcay Taner YILDIZ on 22.02.2023.
//

#include "../src/Syllibification/SyllableList.h"
#include <stdio.h>
#include <HashMap/HashMap.h>
#include <Memory/Memory.h>

void test_case(char *syllables[], int array_size, char *word, int caseNo) {
    Array_list_ptr array1 = create_array_list_of_string(syllables, array_size);
    Syllable_list_ptr list = create_syllable_list(word);
    Array_list_ptr array2 = get_syllables(list);
    if (!array_list_equals(array1, array2, (int (*)(const void *, const void *)) compare_string)) {
        printf("Test failed in %d\n", caseNo);
    }
    free_syllable_list(list);
    free_array_list(array1, NULL);
    free_array_list(array2, NULL);
}

int main() {
    char *syllables1[] = {"ba", "şöğ", "ret", "men"};
    test_case(syllables1, 4, "başöğretmen", 1);
    char *syllables2[] = {"fran", "sa"};
    test_case(syllables2, 2, "fransa", 2);
    char *syllables3[] = {"trak", "tör"};
    test_case(syllables3, 2, "traktör", 3);
    char *syllables4[] = {"kra", "ker"};
    test_case(syllables4, 2, "kraker", 4);
    char *syllables5[] = {"tra", "ke"};
    test_case(syllables5, 2, "trake", 5);
    char *syllables6[] = {"il", "köğ", "re", "tim"};
    test_case(syllables6, 4, "ilköğretim", 6);
    char *syllables7[] = {"se", "mi", "zo", "tu"};
    test_case(syllables7, 4, "semizotu", 7);
    char *syllables8[] = {"a", "li"};
    test_case(syllables8, 2, "ali", 8);
    char *syllables9[] = {"türk"};
    test_case(syllables9, 1, "türk", 9);
}