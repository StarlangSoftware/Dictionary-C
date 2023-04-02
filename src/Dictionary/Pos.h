//
// Created by Olcay Taner YILDIZ on 23.02.2023.
//

#ifndef DICTIONARY_POS_H
#define DICTIONARY_POS_H

enum pos {
/**
 * Adjective.
 */
    ADJECTIVE,
/**
* Noun.
*/
    NOUN,
/**
* Verb.
*/
    VERB,
/**
* Adverb.
*/
    ADVERB,
/**
* Conjunction.
*/
    CONJUNCTION,
/**
* Interjection.
*/
    INTERJECTION,
/**
* Preposition.
*/
    PREPOSITION,
/**
* Pronoun.
*/
    PRONOUN
};

typedef enum pos Pos;

#endif //DICTIONARY_POS_H
