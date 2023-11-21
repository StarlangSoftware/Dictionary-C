//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <string.h>
#include <ctype.h>
#include <HashMap/HashMap.h>
#include <FileUtils.h>
#include "Word.h"
#include "../Language/TurkishLanguage.h"

int word_size(const char *surface_form) {
    int count = 0;
    while (*surface_form) {
        if ((*surface_form & 0xC0) != 0x80) {
            count++;
        }
        surface_form++;
    }
    return count;
}

String_ptr char_at(const char *surface_form, int index) {
    String_ptr result = create_string();
    int current = 0;
    while (*surface_form) {
        if ((*surface_form & 0xC0) != 0x80) {
            if (current == index) {
                do {
                    string_append_char(result, *surface_form);
                    surface_form++;
                } while ((*surface_form & 0xC0) == 0x80);
                return result;
            } else {
                current++;
            }
        }
        surface_form++;
    }
    return create_string();
}

/**
 * The charCount method returns the length of name variable.
 *
 * @return the length of name variable.
 */
int char_count(const char *word) {
    return word_size(word);
}

bool starts_with(const char *large_string, const char *small_string) {
    return strstr(large_string, small_string) == large_string;
}

char *to_lowercase(const char *surface_form) {
    String_ptr result = create_string();
    String_ptr currentChar = create_string();
    const char *charPtr = surface_form;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            do {
                string_append_char(currentChar, *charPtr);
                charPtr++;
            } while ((*charPtr & 0xC0) == 0x80);
            if (string_equals2(currentChar, "ç") || string_equals2(currentChar, "ö") ||
                string_equals2(currentChar, "ğ") || string_equals2(currentChar, "ı") ||
                string_equals2(currentChar, "ü") || string_equals2(currentChar, "ş") ||
                string_equals2(currentChar, "â") || string_equals2(currentChar, "û") ||
                string_equals2(currentChar, "î")) {
                string_append(result, currentChar->s);
            } else {
                if (string_equals2(currentChar, "Ç")) {
                    string_append(result, "ç");
                } else {
                    if (string_equals2(currentChar, "Ö")) {
                        string_append(result, "ö");
                    } else {
                        if (string_equals2(currentChar, "Ğ")) {
                            string_append(result, "ğ");
                        } else {
                            if (string_equals2(currentChar, "Ü")) {
                                string_append(result, "ü");
                            } else {
                                if (string_equals2(currentChar, "Ş")) {
                                    string_append(result, "ş");
                                } else {
                                    if (string_equals2(currentChar, "İ")) {
                                        string_append(result, "i");
                                    } else {
                                        if (string_equals2(currentChar, "I")) {
                                            string_append(result, "ı");
                                        } else {
                                            if (string_equals2(currentChar, "Â")) {
                                                string_append(result, "â");
                                            } else {
                                                if (string_equals2(currentChar, "Î")) {
                                                    string_append(result, "î");
                                                } else {
                                                    if (string_equals2(currentChar, "Û")) {
                                                        string_append(result, "û");
                                                    } else {
                                                        string_append_char(result, tolower(currentChar->s[0]));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            clean_string(currentChar);
        } else {
            charPtr++;
        }
    }
    char *tmp = string_copy(result);
    free_string_ptr(result);
    free_string_ptr(currentChar);
    return tmp;
}

char *to_uppercase(const char *surface_form) {
    String_ptr result = create_string();
    String_ptr currentChar = create_string();
    const char *charPtr = surface_form;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            do {
                string_append_char(currentChar, *charPtr);
                charPtr++;
            } while ((*charPtr & 0xC0) == 0x80);
            if (string_equals2(currentChar, "Ç") || string_equals2(currentChar, "Ö") ||
                string_equals2(currentChar, "Ğ") || string_equals2(currentChar, "I") ||
                string_equals2(currentChar, "Ü") || string_equals2(currentChar, "Ş") ||
                string_equals2(currentChar, "Â") || string_equals2(currentChar, "Û") ||
                string_equals2(currentChar, "Î") || string_equals2(currentChar, "İ")) {
                string_append(result, currentChar->s);
            } else {
                if (string_equals2(currentChar, "ç")) {
                    string_append(result, "Ç");
                } else {
                    if (string_equals2(currentChar, "ö")) {
                        string_append(result, "Ö");
                    } else {
                        if (string_equals2(currentChar, "ğ")) {
                            string_append(result, "Ğ");
                        } else {
                            if (string_equals2(currentChar, "ü")) {
                                string_append(result, "Ü");
                            } else {
                                if (string_equals2(currentChar, "ş")) {
                                    string_append(result, "Ş");
                                } else {
                                    if (string_equals2(currentChar, "i")) {
                                        string_append(result, "İ");
                                    } else {
                                        if (string_equals2(currentChar, "ı")) {
                                            string_append(result, "I");
                                        } else {
                                            if (string_equals2(currentChar, "â")) {
                                                string_append(result, "Â");
                                            } else {
                                                if (string_equals2(currentChar, "î")) {
                                                    string_append(result, "Î");
                                                } else {
                                                    if (string_equals2(currentChar, "û")) {
                                                        string_append(result, "Û");
                                                    } else {
                                                        string_append_char(result, toupper(currentChar->s[0]));
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
            clean_string(currentChar);
        } else {
            charPtr++;
        }
    }
    char *tmp = string_copy(result);
    free_string_ptr(result);
    free_string_ptr(currentChar);
    return tmp;
}

Array_list_ptr all_characters(const char *surface_form) {
    Array_list_ptr result = create_array_list();
    String_ptr ch = create_string();
    do {
        string_append_char(ch, *surface_form);
        surface_form++;
        if ((*surface_form & 0xC0) != 0x80) {
            array_list_add(result, ch);
            ch = create_string();
        }
    } while (*surface_form);
    free_string_ptr(ch);
    return result;
}

String_ptr substring(const char *surface_form, int index, int length) {
    String_ptr result = create_string();
    int current = 0, currentLength = 0;
    if (length <= 0 || index < 0) {
        return create_string();
    }
    while (*surface_form) {
        if ((*surface_form & 0xC0) != 0x80) {
            if (current == index) {
                do {
                    string_append_char(result, *surface_form);
                    surface_form++;
                    if ((*surface_form & 0xC0) != 0x80) {
                        currentLength++;
                    }
                } while (currentLength < length && *surface_form);
                return result;
            } else {
                current++;
            }
        }
        surface_form++;
    }
    return create_string();
}

String_ptr substring2(const char *surface_form, int index) {
    String_ptr result = create_string();
    int current = 0;
    while (*surface_form) {
        if ((*surface_form & 0xC0) != 0x80) {
            if (current == index) {
                do {
                    string_append_char(result, *surface_form);
                    surface_form++;
                } while (*surface_form);
                return result;
            } else {
                current++;
            }
        }
        surface_form++;
    }
    return create_string();
}

String_ptr substring3(const char *surface_form, const char *end) {
    String_ptr result = create_string();
    while (surface_form != end) {
        string_append_char(result, *surface_form);
        surface_form++;
    }
    return result;
}

/**
 * The beforeLastVowel method takes a String stem as an input. It loops through the given stem and returns
 * the second last vowel.
 *
 * @param stem String input.
 * @return the last vowel.
 */
String_ptr before_last_vowel(const char *stem) {
    int before = 1;
    String_ptr ch, last = create_string2("0");
    Array_list_ptr stemChars = all_characters(stem);
    for (int i = word_size(stem) - 1; i >= 0; i--) {
        ch = array_list_get(stemChars, i);
        if (is_vowel(ch->s)) {
            if (before == 1) {
                last = ch;
                before--;
                continue;
            }
            String_ptr result = create_string2(ch->s);
            free_array_list(stemChars, (void (*)(void *)) free_string_ptr);
            return result;
        }
    }
    String_ptr result = create_string2(last->s);
    free_array_list(stemChars, (void (*)(void *)) free_string_ptr);
    return result;
}

/**
 * The lastVowel method takes a String stem as an input. It loops through the given stem and returns
 * the last vowel.
 *
 * @param stem String input.
 * @return the last vowel.
 */
String_ptr last_vowel(const char *stem) {
    String_ptr ch;
    Array_list_ptr stemChars = all_characters(stem);
    for (int i = word_size(stem) - 1; i >= 0; i--) {
        ch = array_list_get(stemChars, i);
        if (is_vowel(ch->s)) {
            String_ptr result = create_string2(ch->s);
            free_array_list(stemChars, (void (*)(void *)) free_string_ptr);
            return result;
        }
    }
    for (int i = word_size(stem) - 1; i >= 0; i--) {
        ch = array_list_get(stemChars, i);
        if (*(ch->s) >= '0' && *(ch->s) <= '9') {
            String_ptr result = create_string2(ch->s);
            free_array_list(stemChars, (void (*)(void *)) free_string_ptr);
            return result;
        }
    }
    free_array_list(stemChars, (void (*)(void *)) free_string_ptr);
    return create_string2("0");
}

/**
 * The lastPhoneme method takes a String stem as an input. It then returns the last phoneme of the given stem.
 *
 * @param stem String input.
 * @return the last phoneme.
 */
String_ptr last_phoneme(const char *stem) {
    if (word_size(stem) == 0) {
        return create_string2(" ");
    }
    String_ptr l = last_char(stem);
    if (strcmp(l->s, "'") != 0) {
        return l;
    } else {
        return char_at(stem, word_size(stem) - 2);
    }
}

String_ptr last_char(const char *surface_form) {
    int size = strlen(surface_form);
    if ((*(surface_form + size - 1) & 0xC0) != 0x80) {
        return create_string2(surface_form + size - 1);
    } else {
        return create_string2(surface_form + size - 2);
    }
}

/**
 * The isCapital method takes a String surfaceForm as an input and returns true if the character at first index of surfaceForm
 * is a capital letter, false otherwise.
 *
 * @param surfaceForm String input to check the first character.
 * @return true if the character at first index of surfaceForm is a capital letter, false otherwise.
 */
bool is_capital(const char *surface_form) {
    String_ptr ch = char_at(surface_form, 0);
    char *s = strstr(TURKISH_UPPERCASE_LETTERS, ch->s);
    free_string_ptr(ch);
    return s != NULL;
}

/**
 * The isPunctuation method takes a String surfaceForm as an input and returns true if it is a punctuation, false otherwise.
 * Grave accent : \u0060
 * Left quotation mark : \u201C
 * Right quotation mark : \u201D
 * Left single quotation mark : \u2018
 *Horizontal ellipsis : \u2026
 *
 * @param surfaceForm String input to check.
 * @return true if it is a punctuation, false otherwise.
 */
bool is_punctuation(const char *surface_form) {
    return string_in_list(surface_form, (char *[]) {".", "...", "[", "]", "\u2026",
                                                    "%", "&", "=", "\u0060\u0060", "\u0060",
                                                    "''", "$", "!", "?", ",", ":",
                                                    "--", ";", "(", ")", "'", "\"",
                                                    "\u201C", "\u2018", "\u201D", "…",
                                                    "\u25CF", "/","-", "+", "-LRB-",
                                                    "-RRB-", "-LCB-", "-RCB-", "-LSB-",
                                                    "-RSB-"},36);
}

/**
 * The isHonorific method takes a String surfaceForm as an input and after converting it to lower case it returns true
 * if it equals to "bay" or "bayan", false otherwise.
 *
 * @param surfaceForm String input to check.
 * @return true if it equals to "bay" or "bayan", false otherwise.
 */
bool is_honorific(const char *surface_form) {
    bool result;
    char *lowercase = to_lowercase(surface_form);
    if (strcmp(lowercase, "bay") == 0 || strcmp(lowercase, "bayan") == 0) {
        result = true;
    } else {
        result = false;
    }
    free(lowercase);
    return result;
}

/**
 * The isOrganization method takes a String surfaceForm as an input and after converting it to lower case it returns true
 * if it equals to "şirket", "corp", "inc.", or "co.", and false otherwise.
 *
 * @param surfaceForm String input to check.
 * @return true if it equals to "şirket", "corp", "inc.", or "co.", and false otherwise.
 */
bool is_organization(const char *surface_form) {
    bool result;
    char *lowercase = to_lowercase(surface_form);
    if (string_in_list(lowercase, (char*[]) {"corp", "inc.", "co."}, 3)) {
        result = true;
    } else {
        result = false;
    }
    free(lowercase);
    return result;
}

/**
 * The isMoney method takes a String surfaceForm as an input and after converting it to lower case it returns true
 * if it equals to one of the dolar, sterlin, paunt, ons, ruble, mark, frank, yan, sent, yen' or $, and false otherwise.
 *
 * @param surfaceForm String input to check.
 * @return true if it equals to one of the dolar, sterlin, paunt, ons, ruble, mark, frank, yan, sent, yen' or $, and false otherwise.
 */
bool is_money(const char *surface_form) {
    bool result;
    char *lowercase = to_lowercase(surface_form);
    if (starts_with(lowercase, "dolar") || starts_with(lowercase, "sterlin") || starts_with(lowercase, "paunt") ||
        starts_with(lowercase, "ons") || starts_with(lowercase, "ruble") || starts_with(lowercase, "mark") ||
        starts_with(lowercase, "frank") || strcmp(lowercase, "yen") == 0 || starts_with(lowercase, "sent") ||
        starts_with(lowercase, "cent") || starts_with(lowercase, "yen'") || strchr(lowercase, '$') != NULL) {
        result = true;
    } else {
        result = false;
    }
    free(lowercase);
    return result;
}

/**
 * The toCharacters method creates a Word type characters vector and adds characters of name variable
 * to newly created vector.
 *
 * @return Word type vector.
 */
Array_list_ptr to_characters(const char *surface_form) {
    Array_list_ptr result = create_array_list();
    String_ptr ch = create_string();
    do {
        string_append_char(ch, *surface_form);
        surface_form++;
        if ((*surface_form & 0xC0) != 0x80) {
            array_list_add(result, ch->s);
            free_string_ptr(ch);
            ch = create_string();
        }
    } while (*surface_form);
    free_string_ptr(ch);
    return result;
}

/**
 * The isTime method takes a String surfaceForm as an input and after converting it to lower case it checks some cases.
 * If it is in the form of 12:23:34 or 12:23 ir returns true.
 * If it starts with name of months; ocak, şubat, mart, nisan, mayıs, haziran, temmuz, ağustos, eylül, ekim, kasım, aralık it returns true.
 * If it equals to the name of days; pazar, pazartesi, salı, çarşamba, perşembe, cuma, cumartesi it returns true.
 *
 * @param surfaceForm String input to check.
 * @return true if it presents time, and false otherwise.
 */
bool is_time(const char *surface_form) {
    //regex missing
    char *lowercase = to_lowercase(surface_form);
    if (starts_with(lowercase, "ocak") || starts_with(lowercase, "şubat") || starts_with(lowercase, "mart") ||
        starts_with(lowercase, "nisan") || starts_with(lowercase, "mayıs") || starts_with(lowercase, "haziran") ||
        starts_with(lowercase, "temmuz") || starts_with(lowercase, "ağustos") || starts_with(lowercase, "eylül") ||
        starts_with(lowercase, "ekim") || starts_with(lowercase, "kasım") || strcmp(lowercase, "aralık") == 0) {
        return true;
    }
    if (strcmp(lowercase, "pazar") == 0 || strcmp(lowercase, "salı") == 0 || starts_with(lowercase, "çarşamba") ||
        starts_with(lowercase, "perşembe") || strcmp(lowercase, "cuma") == 0 || starts_with(lowercase, "cumartesi") ||
        starts_with(lowercase, "pazartesi")) {
        return true;
    }
    if (strchr(lowercase, '\'') != NULL) {
        String_ptr tmp = substring3(lowercase, strchr(lowercase, '\''));
        free(lowercase);
        lowercase = str_copy(lowercase, tmp->s);
        free_string_ptr(tmp);
    }
    long time = strtol(lowercase, NULL, 10);
    free(lowercase);
    if (time > 1900 && time < 2200) {
        return true;
    }
    return false;
}

bool ends_with(const char *large_string, const char *small_string) {
    if (strlen(large_string) < strlen(small_string)) {
        return false;
    }
    if (strstr(large_string + strlen(large_string) - strlen(small_string), small_string) != NULL) {
        return true;
    }
    return false;
}

String_ptr to_capital(const char *surface_form) {
    String_ptr first_char = substring(surface_form, 0, 1);
    String_ptr remaining_char = substring2(surface_form, 1);
    char *uppercase = to_uppercase(first_char->s);
    String_ptr result = create_string2(uppercase);
    free(uppercase);
    string_append(result, remaining_char->s);
    free_string_ptr(first_char);
    free_string_ptr(remaining_char);
    return result;
}

Array_list_ptr split(char *line) {
    Array_list_ptr result = create_array_list();
    char *token = strtok(line, " ");
    while (token != NULL) {
        array_list_add(result, create_string2(token));
        token = strtok(NULL, " ");
    }
    return result;
}

Array_list_ptr split_with_char(char *line, const char *separators) {
    Array_list_ptr result = create_array_list();
    char *token = strtok(line, separators);
    while (token != NULL) {
        array_list_add(result, create_string2(token));
        token = strtok(NULL, separators);
    }
    return result;
}

String_ptr substring_except_last_char(const char *surface_form) {
    int size = strlen(surface_form);
    if (size < 2){
        return create_string();
    }
    char *tmp;
    if ((*(surface_form + size - 1) & 0xC0) != 0x80) {
        tmp = malloc(size);
        strncpy(tmp, surface_form, size - 1);
        tmp[size - 1] = '\0';
    } else {
        tmp = malloc(size - 1);
        strncpy(tmp, surface_form, size - 2);
        tmp[size - 2] = '\0';
    }
    String_ptr result = create_string2(tmp);
    free(tmp);
    return result;
}

String_ptr substring_except_last_two_chars(const char *surface_form) {
    int size = strlen(surface_form);
    if (size < 3){
        return create_string();
    }
    char *tmp;
    if ((*(surface_form + size - 1) & 0xC0) != 0x80) {
        if (((*(surface_form + size - 2) & 0xC0) != 0x80)) {
            tmp = malloc(size - 1);
            strncpy(tmp, surface_form, size - 2);
            tmp[size - 2] = '\0';
        } else {
            tmp = malloc(size - 2);
            strncpy(tmp, surface_form, size - 3);
            tmp[size - 3] = '\0';
        }
    } else {
        if (((*(surface_form + size - 3) & 0xC0) != 0x80)) {
            tmp = malloc(size - 2);
            strncpy(tmp, surface_form, size - 3);
            tmp[size - 3] = '\0';
        } else {
            tmp = malloc(size - 3);
            strncpy(tmp, surface_form, size - 4);
            tmp[size - 4] = '\0';
        }
    }
    String_ptr result = create_string2(tmp);
    free(tmp);
    return result;
}

String_ptr trim(const char *surface_form) {
    int start = -1, end = -1;
    char *tmp;
    for (int i = 0; i < strlen(surface_form); i++) {
        if (surface_form[i] != ' ') {
            start = i;
            break;
        }
    }
    for (int i = strlen(surface_form) - 1; i >= 0; i--) {
        if (surface_form[i] != ' ') {
            end = i;
            break;
        }
    }
    tmp = malloc(end - start + 2);
    strncpy(tmp, surface_form + start, end - start + 1);
    tmp[end - start + 1] = '\0';
    String_ptr result = create_string2(tmp);
    free(tmp);
    return result;
}

int str_find_c(const char *surface_form, const char *ch) {
    int current = 0;
    const char *charPtr = surface_form;
    String_ptr currentChar = create_string();
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            do {
                string_append_char(currentChar, *charPtr);
                charPtr++;
            } while ((*charPtr & 0xC0) == 0x80);
            if (string_equals2(currentChar, ch)) {
                return current;
            }
            current++;
            clean_string(currentChar);
        } else {
            charPtr++;
        }
    }
    free_string_ptr(currentChar);
    return -1;
}

int str_find_last_c(const char *surface_form, const char *ch) {
    int current = 0, last = -1;
    const char *charPtr = surface_form;
    String_ptr currentChar = create_string();
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            do {
                string_append_char(currentChar, *charPtr);
                charPtr++;
            } while ((*charPtr & 0xC0) == 0x80);
            if (string_equals2(currentChar, ch)) {
                last = current;
            }
            current++;
            clean_string(currentChar);
        } else {
            charPtr++;
        }
    }
    free_string_ptr(currentChar);
    return last;
}

char *replace_all(char *str, const char *from, const char *to) {
    char tmp[MAX_LINE_LENGTH] = "";
    Array_list_ptr items = str_split2(str, from);
    if (strstr(str, from) == str){
        sprintf(tmp, "%s", to);
    }
    for (int i = 0; i < items->size - 1; i++){
        sprintf(tmp, "%s%s%s", tmp, (char*)array_list_get(items, i), to);
    }
    if (strstr(str + strlen(str) - strlen(from), from) != NULL){
        sprintf(tmp, "%s%s%s", tmp, (char*)array_list_get(items, items->size - 1), to);
    } else {
        sprintf(tmp, "%s%s", tmp, (char*)array_list_get(items, items->size - 1));
    }
    free_array_list(items, free);
    char *result = NULL;
    result = str_copy(result, tmp);
    return result;
}

char *reverse_string(const char *st) {
    char* result = calloc(strlen(st) + 1, sizeof(char));
    for (int i = word_size(st) - 1; i >= 0; i--){
        String_ptr ch = char_at(st, i);
        sprintf(result, "%s%s", result, ch->s);
        free_string_ptr(ch);
    }
    return result;
}
