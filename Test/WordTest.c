//
// Created by Olcay Taner YILDIZ on 23.02.2023.
//

#include "../src/Dictionary/Word.h"
#include <stdio.h>
#include <string.h>
#include <Memory/Memory.h>

void starts_with_test() {
    char *l = "çöğüş";
    char *s = "çö";
    if (!starts_with(l, s)) {
        printf("Error in starts with test");
    }
}

void test_to_lowercase() {
    char* lowercase = to_lowercase("ABCDEFGHJKLMNOPQRSTUVWXYZÇÖĞÜŞIİ");
    if (strcmp(lowercase, "abcdefghjklmnopqrstuvwxyzçöğüşıi") != 0) {
        printf("Error in test to_lowercase");
    }
    free_(lowercase);
}

void test_to_uppercase() {
    char* uppercase = to_uppercase("abcdefghjklmnopqrstuvwxyzçöğüşıi");
    if (strcmp(uppercase, "ABCDEFGHJKLMNOPQRSTUVWXYZÇÖĞÜŞIİ") != 0) {
        printf("Error in test to_uppercase");
    }
    free_(uppercase);
}

void test_all_characters(){
    char *s = "çöğüşı";
    Array_list_ptr chars = all_characters(s);
    if (strcmp(((String_ptr) array_list_get(chars, 0))->s, "ç") != 0){
        printf("Error in test all characters 1\n");
    }
    if (strcmp(((String_ptr) array_list_get(chars, 2))->s, "ğ") != 0){
        printf("Error in test all characters 2\n");
    }
    if (strcmp(((String_ptr) array_list_get(chars, 5))->s, "ı") != 0){
        printf("Error in test all characters 3\n");
    }
    free_array_list(chars, (void (*)(void *)) free_string_ptr);
}

void test_before_last_vowel(){
    String_ptr v = before_last_vowel("kula");
    if (strcmp("u", v->s) != 0){
        printf("Error in test before last vowel 1\n");
    }
    free_string_ptr(v);
}

void test_last_char(){
    String_ptr l = last_char("4");
    if (strcmp("4", l->s) != 0){
        printf("Error in test before last char 1\n");
    }
    free_string_ptr(l);
    l = last_char("çöğüşı");
    if (strcmp("ı", l->s) != 0){
        printf("Error in test before last char 2\n");
    }
    free_string_ptr(l);
}

void test_char_count(){
    char* s = "ali";
    if (3 != word_size(s)){
        printf("Error in word_size 1\n");
    }
    s = "Veli";
    if (4 != word_size(s)){
        printf("Error in word_size 2\n");
    }
    s = "ahmet";
    if (5 != word_size(s)){
        printf("Error in word_size 3\n");
    }
    s = "çöğüşı";
    if (6 != word_size(s)){
        printf("Error in word_size 4\n");
    }
}

void test_is_capital(){
    if (is_capital("ali") != 0){
        printf("Error in is_capital 1\n");
    }
    if (is_capital("Ali") == 0){
        printf("Error in is_capital 2\n");
    }
    if (is_capital("ısı") != 0){
        printf("Error in is_capital 3\n");
    }
    if (is_capital("Isıtıcı") == 0){
        printf("Error in is_capital 4\n");
    }
    if (is_capital("çin") != 0){
        printf("Error in is_capital 5\n");
    }
    if (is_capital("Çin") == 0){
        printf("Error in is_capital 6\n");
    }
    if (is_capital("ödül") != 0){
        printf("Error in is_capital 7\n");
    }
    if (is_capital("Ödül") == 0){
        printf("Error in is_capital 8\n");
    }
    if (is_capital("şişe") != 0){
        printf("Error in is_capital 9\n");
    }
    if (is_capital("Şişe") == 0){
        printf("Error in is_capital 10\n");
    }
    if (is_capital("üretici") != 0){
        printf("Error in is_capital 11\n");
    }
    if (is_capital("Üretici") == 0){
        printf("Error in is_capital 12\n");
    }
}

void test_is_punctuation(){
    if (!is_punctuation(".")){
        printf("Error in is_punctuation 1\n");
    }
    if (!is_punctuation("...")){
        printf("Error in is_punctuation 2\n");
    }
    if (!is_punctuation("[")){
        printf("Error in is_punctuation 2\n");
    }
}

void test_is_honorific(){
    if (!is_honorific("bay")){
        printf("Error in is_honorific 1\n");
    }
    if (!is_honorific("Bay")){
        printf("Error in is_honorific 2\n");
    }
    if (!is_honorific("BAY")){
        printf("Error in is_honorific 3\n");
    }
    if (!is_honorific("bayan")){
        printf("Error in is_honorific 4\n");
    }
    if (!is_honorific("Bayan")){
        printf("Error in is_honorific 5\n");
    }
    if (!is_honorific("BAYAN")){
        printf("Error in is_honorific 6\n");
    }
}

void test_is_organization(){
    if (!is_organization("corp")){
        printf("Error in is_organization 1\n");
    }
    if (!is_organization("Corp")){
        printf("Error in is_organization 2\n");
    }
    if (!is_organization("inc.")){
        printf("Error in is_organization 3\n");
    }
    if (!is_organization("co.")){
        printf("Error in is_organization 4\n");
    }
    if (!is_organization("Co.")){
        printf("Error in is_organization 5\n");
    }
}

void test_is_money(){
    if (!is_money("dolar")){
        printf("Error in is_money 1\n");
    }
    if (!is_money("paunt")){
        printf("Error in is_money 2\n");
    }
    if (!is_money("Sterlin")){
        printf("Error in is_money 3\n");
    }
    if (!is_money("3000$")){
        printf("Error in is_money 4\n");
    }
    if (is_money("3000")){
        printf("Error in is_money 5\n");
    }
}

void test_is_time(){
    if (!is_time("ocak")){
        printf("Error in is_time 1\n");
    }
    if (!is_time("Ocak")){
        printf("Error in is_time 2\n");
    }
    if (!is_time("pazartesi")){
        printf("Error in is_time 3\n");
    }
    if (!is_time("1934")){
        printf("Error in is_time 4\n");
    }
    if (is_time("1834")){
        printf("Error in is_time 5\n");
    }
}

void ends_with_test() {
    char *l = "çöğüş";
    char *s = "üş";
    if (!ends_with(l, s)) {
        printf("Error in ends with test 1");
    }
    s = "ğüş";
    if (!ends_with(l, s)) {
        printf("Error in ends with test 2");
    }
}

void test_to_capital() {
    String_ptr c = to_capital("ali");
    if (strcmp(c->s, "Ali") != 0) {
        printf("Error in test to_capital 1");
    }
    free_string_ptr(c);
    c = to_capital("ilginç");
    if (strcmp(c->s, "İlginç") != 0) {
        printf("Error in test to_capital 2");
    }
    free_string_ptr(c);
    c = to_capital("çemişgezek");
    if (strcmp(c->s, "Çemişgezek") != 0) {
        printf("Error in test to_capital 3");
    }
    free_string_ptr(c);
    c = to_capital("ö");
    if (strcmp(c->s, "Ö") != 0) {
        printf("Error in test to_capital 4");
    }
    free_string_ptr(c);
}

void test_split() {
    char test[] = "ali topu at";
    Array_list_ptr result = split(test);
    if (result->size != 3){
        printf("Error in test split 1");
    }
    free_array_list(result, (void (*)(void *)) free_string_ptr);
    char* test2 = malloc_(20 * sizeof(char));
    strcpy(test2, "Ali topu at");
    result = split(test2);
    if (result->size != 3){
        printf("Error in test split 2");
    }
    free_(test2);
    free_array_list(result, (void (*)(void *)) free_string_ptr);
}

void test_split_with_char() {
    char test[] = "ali;topu,at şimdi";
    Array_list_ptr result = split_with_char(test, ";, ");
    if (result->size != 4){
        printf("Error in test split with char 1");
    }
    free_array_list(result, (void (*)(void *)) free_string_ptr);
    char* test2 = malloc_(20 * sizeof(char));
    strcpy(test2, "ali;topu,at şimdi");
    result = split_with_char(test2, ";, ");
    if (result->size != 4){
        printf("Error in test split with char 2");
    }
    free_(test2);
    free_array_list(result, (void (*)(void *)) free_string_ptr);
}

void test_substring_except(){
    String_ptr s = substring_except_last_char("çöğüş");
    if (strcmp(s->s, "çöğü") != 0){
        printf("Error in test substring except 1");
    }
    free_string_ptr(s);
    s = substring_except_last_two_chars("çöğüş");
    if (strcmp(s->s, "çöğ") != 0){
        printf("Error in test substring except 2");
    }
    free_string_ptr(s);
    s = substring_except_last_two_chars("çöğaş");
    if (strcmp(s->s, "çöğ") != 0){
        printf("Error in test substring except 3");
    }
    free_string_ptr(s);
}

void test_trim(){
    String_ptr result = trim(" ali  ");
    if (strcmp(result->s, "ali") != 0){
        printf("Error in test trim 1");
    }
    free_string_ptr(result);
}

void test_find_c(){
    char* s = "açöcğüşzac";
    if (str_find_c(s, "a") != 0){
        printf("Error in test find c 1");
    }
    if (str_find_c(s, "c") != 3){
        printf("Error in test find c 2");
    }
    if (str_find_c(s, "z") != 7){
        printf("Error in test find c 3");
    }
    if (str_find_last_c(s, "a") != 8){
        printf("Error in test find c 4");
    }
    if (str_find_last_c(s, "c") != 9){
        printf("Error in test find c 5");
    }
}

void test_replace_all(){
    char* tmp = replace_all("aysealiahmet", "ali", "ayse");
    if (strcmp(tmp, "ayseayseahmet") != 0){
        printf("Error in %s", tmp);
    }
    free_(tmp);
    tmp = replace_all("aliaysealiahmet", "ali", "ayse");
    if (strcmp(tmp, "ayseayseayseahmet") != 0){
        printf("Error in %s", tmp);
    }
    free_(tmp);
    tmp = replace_all("aliaysealiahmetali", "ali", "ayse");
    if (strcmp(tmp, "ayseayseayseahmetayse") != 0){
        printf("Error in %s", tmp);
    }
    free_(tmp);
}

void test_reverse_string(){
    char* reverse = reverse_string("aliayse");
    if (strcmp(reverse, "esyaila") != 0){
        printf("Error in %s\n", reverse);
    }
    free_(reverse);
}

int main() {
    start_memory_check();
    starts_with_test();
    test_to_lowercase();
    test_to_uppercase();
    test_all_characters();
    test_before_last_vowel();
    test_last_char();
    test_char_count();
    test_is_capital();
    test_is_punctuation();
    test_is_honorific();
    test_is_organization();
    test_is_money();
    test_is_time();
    ends_with_test();
    test_to_uppercase();
    test_split();
    test_split_with_char();
    test_substring_except();
    test_trim();
    test_find_c();
    test_replace_all();
    test_reverse_string();
    end_memory_check();
}