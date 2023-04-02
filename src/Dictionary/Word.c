//
// Created by Olcay Taner YILDIZ on 21.02.2023.
//

#include <stdlib.h>
#include <StringUtils.h>
#include <string.h>
#include <ctype.h>
#include <HashMap/HashMap.h>
#include "Word.h"
#include "../Language/TurkishLanguage.h"

/**
 * A constructor of {@link Word} class which gets a String name as an input and assigns to the name variable.
 *
 * @param _name String input.
 */
Word_ptr create_word(char *name) {
    Word_ptr result = malloc(sizeof(Word));
    result->name = str_copy(result->name, name);
    return result;
}

int word_size(char *surface_form) {
    int count = 0;
    while (*surface_form) {
        if ((*surface_form & 0xC0) != 0x80) {
            count++;
        }
        surface_form++;
    }
    return count;
}

String_ptr char_at(char *surface_form, int index) {
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
int char_count(Word_ptr word) {
    return word_size(word->name);
}

bool starts_with(char *large_string, char *small_string) {
    return strstr(large_string, small_string) == large_string;
}

char *to_lowercase(char *surface_form) {
    String_ptr result = create_string();
    String_ptr currentChar = create_string();
    char *charPtr = surface_form;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            do {
                string_append_char(currentChar, *charPtr);
                charPtr++;
            } while ((*charPtr & 0xC0) == 0x80);
            if (strcmp(currentChar->s, "ç") == 0 || strcmp(currentChar->s, "ö") == 0 ||
                strcmp(currentChar->s, "ğ") == 0 ||
                strcmp(currentChar->s, "ü") == 0 || strcmp(currentChar->s, "ş") == 0 ||
                strcmp(currentChar->s, "ı") == 0 ||
                strcmp(currentChar->s, "â") == 0 || strcmp(currentChar->s, "û") == 0 ||
                strcmp(currentChar->s, "î") == 0) {
                string_append(result, currentChar->s);
            } else {
                if (strcmp(currentChar->s, "Ç") == 0) {
                    string_append(result, "ç");
                } else {
                    if (strcmp(currentChar->s, "Ö") == 0) {
                        string_append(result, "ö");
                    } else {
                        if (strcmp(currentChar->s, "Ğ") == 0) {
                            string_append(result, "ğ");
                        } else {
                            if (strcmp(currentChar->s, "Ü") == 0) {
                                string_append(result, "ü");
                            } else {
                                if (strcmp(currentChar->s, "Ş") == 0) {
                                    string_append(result, "ş");
                                } else {
                                    if (strcmp(currentChar->s, "İ") == 0) {
                                        string_append(result, "i");
                                    } else {
                                        if (strcmp(currentChar->s, "I") == 0) {
                                            string_append(result, "ı");
                                        } else {
                                            if (strcmp(currentChar->s, "Â") == 0) {
                                                string_append(result, "â");
                                            } else {
                                                if (strcmp(currentChar->s, "Î") == 0) {
                                                    string_append(result, "î");
                                                } else {
                                                    if (strcmp(currentChar->s, "Û") == 0) {
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

char *to_uppercase(char *surface_form) {
    String_ptr result = create_string();
    String_ptr currentChar = create_string();
    char *charPtr = surface_form;
    while (*charPtr) {
        if ((*charPtr & 0xC0) != 0x80) {
            do {
                string_append_char(currentChar, *charPtr);
                charPtr++;
            } while ((*charPtr & 0xC0) == 0x80);
            if (strcmp(currentChar->s, "Ç") == 0 || strcmp(currentChar->s, "Ö") == 0 ||
                strcmp(currentChar->s, "Ğ") == 0 ||
                strcmp(currentChar->s, "Ü") == 0 || strcmp(currentChar->s, "Ş") == 0 ||
                strcmp(currentChar->s, "I") == 0 ||
                strcmp(currentChar->s, "Â") == 0 || strcmp(currentChar->s, "Û") == 0 ||
                strcmp(currentChar->s, "Î") == 0 || strcmp(currentChar->s, "İ") == 0) {
                string_append(result, currentChar->s);
            } else {
                if (strcmp(currentChar->s, "ç") == 0) {
                    string_append(result, "Ç");
                } else {
                    if (strcmp(currentChar->s, "ö") == 0) {
                        string_append(result, "Ö");
                    } else {
                        if (strcmp(currentChar->s, "ğ") == 0) {
                            string_append(result, "Ğ");
                        } else {
                            if (strcmp(currentChar->s, "ü") == 0) {
                                string_append(result, "Ü");
                            } else {
                                if (strcmp(currentChar->s, "ş") == 0) {
                                    string_append(result, "Ş");
                                } else {
                                    if (strcmp(currentChar->s, "i") == 0) {
                                        string_append(result, "İ");
                                    } else {
                                        if (strcmp(currentChar->s, "ı") == 0) {
                                            string_append(result, "I");
                                        } else {
                                            if (strcmp(currentChar->s, "â") == 0) {
                                                string_append(result, "Â");
                                            } else {
                                                if (strcmp(currentChar->s, "î") == 0) {
                                                    string_append(result, "Î");
                                                } else {
                                                    if (strcmp(currentChar->s, "û") == 0) {
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

Array_list_ptr all_characters(char *surface_form) {
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

String_ptr substring(char *surface_form, int index, int length) {
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

String_ptr substring2(char *surface_form, int index) {
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

String_ptr substring3(char *surface_form, const char *end) {
    String_ptr result = create_string();
    while (surface_form != end) {
        string_append_char(result, *surface_form);
        surface_form++;
    }
    return result;
}

/**
 * The beforeLastVowel method takes a {@link String} stem as an input. It loops through the given stem and returns
 * the second last vowel.
 *
 * @param stem String input.
 * @return the last vowel.
 */
String_ptr before_last_vowel(char *stem) {
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
 * The lastVowel method takes a {@link String} stem as an input. It loops through the given stem and returns
 * the last vowel.
 *
 * @param stem String input.
 * @return the last vowel.
 */
String_ptr last_vowel(char *stem) {
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
 * The lastPhoneme method takes a {@link String} stem as an input. It then returns the last phoneme of the given stem.
 *
 * @param stem String input.
 * @return the last phoneme.
 */
String_ptr last_phoneme(char *stem) {
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

String_ptr last_char(char *surface_form) {
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
bool is_capital(char *surface_form) {
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
bool is_punctuation(char *surface_form) {
    return (strcmp(surface_form, ".") == 0 || strcmp(surface_form, "...") == 0 || strcmp(surface_form, "[") == 0 ||
            strcmp(surface_form, "]") == 0 ||
            strcmp(surface_form, "\u2026") == 0 || strcmp(surface_form, "%") == 0 || strcmp(surface_form, "&") == 0 ||
            strcmp(surface_form, "=") == 0 ||
            strcmp(surface_form, "\u0060\u0060") == 0 || strcmp(surface_form, "\u0060") == 0 ||
            strcmp(surface_form, "''") == 0 || strcmp(surface_form, "$") == 0 ||
            strcmp(surface_form, "!") == 0 || strcmp(surface_form, "?") == 0 || strcmp(surface_form, ",") == 0 ||
            strcmp(surface_form, ":") == 0 ||
            strcmp(surface_form, "--") == 0 || strcmp(surface_form, ";") == 0 || strcmp(surface_form, "(") == 0 ||
            strcmp(surface_form, ")") == 0 ||
            strcmp(surface_form, "'") == 0 || strcmp(surface_form, "\"") == 0 || strcmp(surface_form, "\u201C") == 0 ||
            strcmp(surface_form, "\u2018") == 0 ||
            strcmp(surface_form, "\u201D") == 0 || strcmp(surface_form, "…") == 0 ||
            strcmp(surface_form, "\u25CF") == 0 || strcmp(surface_form, "/") == 0 ||
            strcmp(surface_form, "-") == 0 || strcmp(surface_form, "+") == 0 || strcmp(surface_form, "-LRB-") == 0 ||
            strcmp(surface_form, "-RRB-") == 0 ||
            strcmp(surface_form, "-LCB-") == 0 || strcmp(surface_form, "-RCB-") == 0 ||
            strcmp(surface_form, "-LSB-") == 0 || strcmp(surface_form, "-RSB-") == 0);
}

/**
 * The isHonorific method takes a String surfaceForm as an input and after converting it to lower case it returns true
 * if it equals to "bay" or "bayan", false otherwise.
 *
 * @param surfaceForm String input to check.
 * @return true if it equals to "bay" or "bayan", false otherwise.
 */
bool is_honorific(char *surface_form) {
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
bool is_organization(char *surface_form) {
    bool result;
    char *lowercase = to_lowercase(surface_form);
    if (strcmp(lowercase, "corp") == 0 || strcmp(lowercase, "inc.") == 0 || strcmp(lowercase, "co.") == 0) {
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
bool is_money(char *surface_form) {
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
 * The toCharacters method creates a {@link Word} type characters {@link vector} and adds characters of name variable
 * to newly created {@link vector}.
 *
 * @return Word type {@link vector}.
 */
Array_list_ptr to_characters(char *surface_form) {
    Array_list_ptr result = create_array_list();
    String_ptr ch = create_string();
    do {
        string_append_char(ch, *surface_form);
        surface_form++;
        if ((*surface_form & 0xC0) != 0x80) {
            array_list_add(result, create_word(ch->s));
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
bool is_time(char *surface_form) {
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

bool ends_with(char *large_string, char *small_string) {
    if (strlen(large_string) < strlen(small_string)) {
        return false;
    }
    if (strstr(large_string + strlen(large_string) - strlen(small_string), small_string) != NULL) {
        return true;
    }
    return false;
}

String_ptr to_capital(char *surface_form) {
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

Array_list_ptr split_with_char(char *line, char *separators) {
    Array_list_ptr result = create_array_list();
    char *token = strtok(line, separators);
    while (token != NULL) {
        array_list_add(result, create_string2(token));
        token = strtok(NULL, separators);
    }
    return result;
}

String_ptr substring_except_last_char(char *surface_form) {
    int size = strlen(surface_form);
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

String_ptr substring_except_last_two_chars(char *surface_form) {
    int size = strlen(surface_form);
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

String_ptr trim(char *surface_form) {
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

void free_word(Word_ptr word) {
    free(word->name);
    free(word);
}

int compare_word(Word_ptr first, Word_ptr second) {
    return compare_string(first->name, second->name);
}
